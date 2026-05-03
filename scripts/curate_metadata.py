#!/usr/bin/env python3
"""
PASTA metadata curator (Step 13 of `snug-floating-finch`).

Reads MethodMetadata.h + Generated.h + the metadata tables under
`bin/BootstrapTypes/` and the manual-override files under
`lib/AST/{Type,Stmt,Attr}Manual.cpp`, then emits a propose-only Markdown
report grouped by heuristic. **The script never applies** — review each
finding before editing kCxxMethodRenames or NullableReturns.cpp.

Heuristics implemented:
  H1  return-type denylist      (void*, intptr_t, OpaquePtr, ...)
  H2  doxygen / attribute scrap (deprecated, hidden visibility, "internal", ...)
  H3  name-pattern denylist     (*Internal, *Impl, unsafe*, getOpaque*, ...)
  H4  manual-override overlap   (already wrapped in lib/AST/*Manual.cpp)
  H8  dead-entry audit          (rename-table entries removable without effect)

Usage:
  scripts/curate_metadata.py [--repo-root PATH] [--only HEURISTIC[,...]]
"""

from __future__ import annotations

import argparse
import re
import sys
from dataclasses import dataclass, field
from pathlib import Path
from typing import Iterable


# ---------------------------------------------------------------------------
# File locations
# ---------------------------------------------------------------------------

DEFAULT_REPO_ROOT = Path(__file__).resolve().parent.parent

REL_GENERATED = "bin/BootstrapTypes/Generated.h"
REL_METHOD_METADATA = "bin/BootstrapTypes/MethodMetadata.h"
REL_METHOD_RENAMES = "bin/BootstrapTypes/MethodRenames.cpp"
REL_NULLABLE_RETURNS = "bin/BootstrapTypes/NullableReturns.cpp"
REL_MANUAL_FILES = (
    "lib/AST/TypeManual.cpp",
    "lib/AST/StmtManual.cpp",
    "lib/AST/AttrManual.cpp",
)


# ---------------------------------------------------------------------------
# Parsers
# ---------------------------------------------------------------------------

# PASTA_INSTANCE_METHOD_N(class, class_id, meth_id, method_name, (rt), ...)
# PASTA_OVERRIDE_METHOD_0(class, class_id, meth_id, method_name, (rt))
RE_GEN_METHOD = re.compile(
    r"PASTA_(?:INSTANCE|OVERRIDE)_METHOD_\d+\("
    r"\s*([A-Za-z_]\w*)\s*,"          # class
    r"\s*(\d+)\s*,"                    # class_id
    r"\s*(\d+)\s*,"                    # meth_id
    r"\s*([A-Za-z_]\w*)\s*,"          # method_name
)


def parse_generated(path: Path) -> list[tuple[str, str]]:
    """Return list of (class, clang_method_name) pairs from Generated.h."""
    methods = []
    for m in RE_GEN_METHOD.finditer(path.read_text()):
        methods.append((m.group(1), m.group(4)))
    return methods


@dataclass
class MethodMeta:
    cls: str
    meth_id: int
    name: str
    return_type: str          # parenthesised body, parens stripped
    is_inline: bool
    has_deprecated: bool
    has_hidden_visibility: bool
    body_classification: str  # SAFE / UNCONDITIONAL_ASSERT / CONDITIONAL_ASSERT / UNKNOWN
    crash_predicate: str      # raw escaped C-string text, quotes stripped
    doxygen: str              # raw escaped C-string text, quotes stripped


# Tokenizer for one PASTA_METHOD_METADATA(...) call: split on commas at
# depth 0 (so commas inside parens or strings are kept intact).
def _split_top_level_args(arg_str: str) -> list[str]:
    out: list[str] = []
    depth = 0
    start = 0
    in_string = False
    escape = False
    for i, ch in enumerate(arg_str):
        if in_string:
            if escape:
                escape = False
            elif ch == "\\":
                escape = True
            elif ch == '"':
                in_string = False
            continue
        if ch == '"':
            in_string = True
            continue
        if ch in "([{":
            depth += 1
        elif ch in ")]}":
            depth -= 1
        elif ch == "," and depth == 0:
            out.append(arg_str[start:i].strip())
            start = i + 1
    out.append(arg_str[start:].strip())
    return out


# Match only at line start (after optional leading whitespace) so the
# header comment "// One PASTA_METHOD_METADATA(...) per wrapped method"
# isn't picked up, and so doxygen text inside string literals (which can
# contain "PASTA_METHOD_METADATA" in theory) doesn't trigger.
RE_MM_CALL = re.compile(r"^\s*PASTA_METHOD_METADATA\(", re.MULTILINE)


def parse_method_metadata(path: Path) -> list[MethodMeta]:
    text = path.read_text()
    out: list[MethodMeta] = []
    pos = 0
    while True:
        m = RE_MM_CALL.search(text, pos)
        if not m:
            break
        # Walk to the matching close paren.
        depth = 1
        i = m.end()
        in_string = False
        escape = False
        while i < len(text) and depth > 0:
            ch = text[i]
            if in_string:
                if escape:
                    escape = False
                elif ch == "\\":
                    escape = True
                elif ch == '"':
                    in_string = False
            else:
                if ch == '"':
                    in_string = True
                elif ch == "(":
                    depth += 1
                elif ch == ")":
                    depth -= 1
            i += 1
        if depth != 0:
            raise ValueError(f"Unterminated PASTA_METHOD_METADATA at offset {m.start()}")
        body = text[m.end():i - 1]
        args = _split_top_level_args(body)
        if len(args) != 10:
            raise ValueError(
                f"PASTA_METHOD_METADATA expected 10 args, got {len(args)} at offset {m.start()}"
            )
        rt = args[3]
        if rt.startswith("(") and rt.endswith(")"):
            rt = rt[1:-1].strip()
        pred = args[8]
        if pred.startswith('"') and pred.endswith('"'):
            pred = pred[1:-1]
        doxy = args[9]
        if doxy.startswith('"') and doxy.endswith('"'):
            doxy = doxy[1:-1]
        out.append(MethodMeta(
            cls=args[0],
            meth_id=int(args[1]),
            name=args[2],
            return_type=rt,
            is_inline=args[4] == "1",
            has_deprecated=args[5] == "1",
            has_hidden_visibility=args[6] == "1",
            body_classification=args[7],
            crash_predicate=pred,
            doxygen=doxy,
        ))
        pos = i
    return out


# ---------------------------------------------------------------------------
# MethodRenames.cpp parsers (mirrors /tmp/audit_step7b.py)
# ---------------------------------------------------------------------------

@dataclass
class RenameTables:
    cxx_method_renames: list[tuple[str, str]]
    pre_rename_overrides: list[tuple[str, str]]
    post_rename_overrides: list[tuple[str, str]]
    pre_strip_disable_exact: list[str]
    pre_strip_disable_ends_with: list[str]
    pre_strip_disable_starts_with: list[str]
    post_strip_disable_ends_with: list[str]
    post_strip_disable_starts_with: list[str]
    suffix_transforms: list[tuple[str, str, bool]]


def _scan_pair_map(text: str, name: str) -> list[tuple[str, str]]:
    body = re.search(rf"{re.escape(name)}\{{(.*?)\n\}};", text, re.DOTALL)
    if not body:
        return []
    return [(k, v) for k, v in re.findall(r'\{"([^"]*)",\s*"([^"]*)"\}', body.group(1))]


def _scan_string_seq(text: str, name: str) -> list[str]:
    body = re.search(rf"{re.escape(name)}\{{(.*?)\n\}};", text, re.DOTALL)
    if not body:
        return []
    return [s for s in re.findall(r'"([^"]*)"', body.group(1))]


def _scan_suffix_transforms(text: str) -> list[tuple[str, str, bool]]:
    body = re.search(r"kSuffixTransforms\{(.*?)\n\};", text, re.DOTALL)
    if not body:
        return []
    return [
        (s, r, b == "true")
        for s, r, b in re.findall(r'\{"([^"]*)",\s*"([^"]*)",\s*(true|false)\}', body.group(1))
    ]


def parse_rename_tables(path: Path) -> RenameTables:
    text = path.read_text()
    return RenameTables(
        cxx_method_renames=_scan_pair_map(text, "kCxxMethodRenames"),
        pre_rename_overrides=_scan_pair_map(text, "kPreRenameOverrides"),
        post_rename_overrides=_scan_pair_map(text, "kPostRenameOverrides"),
        pre_strip_disable_exact=_scan_string_seq(text, "kPreStripDisableExact"),
        pre_strip_disable_ends_with=_scan_string_seq(text, "kPreStripDisableEndsWith"),
        pre_strip_disable_starts_with=_scan_string_seq(text, "kPreStripDisableStartsWith"),
        post_strip_disable_ends_with=_scan_string_seq(text, "kPostStripDisableEndsWith"),
        post_strip_disable_starts_with=_scan_string_seq(text, "kPostStripDisableStartsWith"),
        suffix_transforms=_scan_suffix_transforms(text),
    )


# ---------------------------------------------------------------------------
# CxxName implementation (mirrors Util.cpp::CxxName + the prototype script)
# ---------------------------------------------------------------------------

def _capitalize(name: str) -> str:
    return (name[0].upper() + name[1:]) if name else name


def make_cxx_name(tables: RenameTables):
    rename_map = dict(tables.cxx_method_renames)
    pre_exact = set(tables.pre_strip_disable_exact)
    pre_ends = list(tables.pre_strip_disable_ends_with)
    pre_starts = list(tables.pre_strip_disable_starts_with)
    post_ends = list(tables.post_strip_disable_ends_with)
    post_starts = list(tables.post_strip_disable_starts_with)
    suffix_transforms = list(tables.suffix_transforms)
    pre_overrides = dict(tables.pre_rename_overrides)
    post_overrides = dict(tables.post_rename_overrides)

    def matches_any(name, exact, ends, starts):
        if exact is not None and name in exact:
            return True
        for s in ends:
            if name.endswith(s):
                return True
        for p in starts:
            if name.startswith(p):
                return True
        return False

    def impl(name: str) -> str:
        if matches_any(name, pre_exact, pre_ends, pre_starts):
            return ""
        if name.startswith("get") and not name.startswith("gets"):
            return impl(name[3:])
        if name.startswith("has") and not name.startswith("hash"):
            return "Has" + impl(name[3:])
        if name.startswith("is"):
            return "Is" + impl(name[2:])
        if matches_any(name, None, post_ends, post_starts):
            return ""
        if name.startswith("set") and not name.startswith("sets"):
            return ""
        for suffix, replacement, require_non_empty_prefix in suffix_transforms:
            if not name.endswith(suffix):
                continue
            if require_non_empty_prefix and len(suffix) >= len(name):
                continue
            return impl(name[:len(name) - len(suffix)]) + replacement
        if name in rename_map:
            return rename_map[name]
        if not name:
            return ""
        if name[0] == "_":
            return "_" + impl(name[1:])
        if name.endswith("_"):
            return impl(name[:-1]) + "_"
        if name[0].islower():
            return impl(_capitalize(name))
        # Multi-word camel-case: split.
        num_upper = 1
        seen_us = False
        for i in range(1, len(name)):
            if name[i] == "_":
                if not seen_us:
                    num_upper += 1
                    seen_us = True
            elif name[i].isupper() and not name[i - 1].isupper():
                num_upper += 1
                seen_us = False
            else:
                seen_us = False
        if num_upper >= 2:
            out: list[str] = []
            ss = name[0]
            for i in range(1, len(name)):
                if name[i].isupper():
                    if len(ss) > 1:
                        out.append(impl(ss))
                        ss = ""
                elif name[i] == "_":
                    out.append(impl(ss))
                    ss = ""
                if name[i] != "_":
                    ss += name[i]
            out.append(impl(ss))
            return "".join(out)
        if len(name) > 1 and name.endswith("s"):
            return impl(name[:-1]) + "s"
        return name

    def cxx_name(name: str) -> str:
        if name in pre_overrides:
            return pre_overrides[name]
        n = impl(name)
        if n in post_overrides:
            return post_overrides[n]
        return n

    return cxx_name


# Approximate the rename-table key for proposing a blacklist entry. Mirrors
# the leading get/has/is strips in `impl()` so the proposed entry slots into
# `kCxxMethodRenames` with the same key shape as existing entries.
def rename_key_for(name: str) -> str:
    n = name
    while True:
        if n.startswith("get") and not n.startswith("gets"):
            n = n[3:]
        elif n.startswith("has") and not n.startswith("hash"):
            n = n[3:]
        elif n.startswith("is"):
            n = n[2:]
        else:
            break
    if n and n[0].islower():
        n = _capitalize(n)
    return n


# ---------------------------------------------------------------------------
# NullableReturns parser (just enough for filtering)
# ---------------------------------------------------------------------------

def parse_nullable_pairs(path: Path) -> set[tuple[str, str]]:
    text = path.read_text()
    pairs: set[tuple[str, str]] = set()
    can_block = re.search(r"kCanReturnNullptr\{(.*?)\n\};", text, re.DOTALL)
    if can_block:
        for cls, meth in re.findall(r'\{"([^"]+)",\s*"([^"]+)"\}', can_block.group(1)):
            pairs.add((cls, meth))
    cond_block = re.search(r"kConditionalNullptr\{(.*?)\n\};", text, re.DOTALL)
    if cond_block:
        for cls, meth in re.findall(r'\{\{"([^"]+)",\s*"([^"]+)"\}', cond_block.group(1)):
            pairs.add((cls, meth))
    return pairs


# ---------------------------------------------------------------------------
# Manual-override scanner
# ---------------------------------------------------------------------------

# Match top-of-line C++ method definitions: `<rt>... ClassName::Method(`.
# Permits scope-resolution and qualifiers in the return type.
RE_MANUAL_DEF = re.compile(
    r"^[A-Za-z_][\w:< >*&,]*?\s+([A-Za-z_]\w*)::([A-Za-z_]\w*)\s*\(",
    re.MULTILINE,
)


def parse_manual_methods(paths: Iterable[Path]) -> set[tuple[str, str]]:
    out: set[tuple[str, str]] = set()
    for p in paths:
        if not p.exists():
            continue
        text = p.read_text()
        # Strip line comments and block comments to avoid false matches inside
        # commentary like "// returns Type::Foo".
        text = re.sub(r"/\*.*?\*/", "", text, flags=re.DOTALL)
        text = re.sub(r"//[^\n]*", "", text)
        for m in RE_MANUAL_DEF.finditer(text):
            cls, meth = m.group(1), m.group(2)
            # Skip C++ keywords / common helpers that match the regex shape.
            if cls in {"if", "for", "while", "switch", "return", "static_cast",
                       "reinterpret_cast", "const_cast", "dynamic_cast"}:
                continue
            out.add((cls, meth))
    return out


# ---------------------------------------------------------------------------
# Heuristics
# ---------------------------------------------------------------------------

@dataclass
class Finding:
    cls: str
    method: str               # original Clang method name
    rename_key: str           # proposed key in kCxxMethodRenames
    why: str
    detail: str = ""          # optional second line (e.g., doxygen excerpt)


def _is_already_blacklisted(method: str, key: str, tables: RenameTables,
                            cxx: callable) -> bool:
    if cxx(method) == "":
        return True
    for k, v in tables.cxx_method_renames:
        if k == key and v == "":
            return True
    return False


# H1 — return-type denylist
RT_DENY_PATTERNS = [
    (re.compile(r"\bvoid\s*\*"), "returns void*"),
    (re.compile(r"\bintptr_t\b"), "returns intptr_t"),
    (re.compile(r"\buintptr_t\b"), "returns uintptr_t"),
    (re.compile(r"\bOpaquePtr\b"), "returns OpaquePtr"),
    (re.compile(r"clang::OpaquePtr<"), "returns clang::OpaquePtr<...>"),
]


def heuristic_h1(metas: list[MethodMeta], tables: RenameTables,
                 cxx) -> list[Finding]:
    out: list[Finding] = []
    for m in metas:
        for pat, label in RT_DENY_PATTERNS:
            if pat.search(m.return_type):
                key = rename_key_for(m.name)
                if _is_already_blacklisted(m.name, key, tables, cxx):
                    break
                out.append(Finding(
                    cls=m.cls, method=m.name, rename_key=key,
                    why=f"H1 — {label}",
                    detail=f"return type: {m.return_type}",
                ))
                break
    return out


# H2 — doxygen / attribute scraping
DOXY_PHRASES = (
    "do not use",
    "for testing",
    "subject to change",
    "deprecated",
    "internal",
    "implementation detail",
    "should not be called",
)


def heuristic_h2(metas: list[MethodMeta], tables: RenameTables,
                 cxx) -> list[Finding]:
    out: list[Finding] = []
    for m in metas:
        why_parts: list[str] = []
        excerpt = ""
        if m.has_deprecated:
            why_parts.append("[[deprecated]] / [[unavailable]] attribute")
        if m.has_hidden_visibility:
            why_parts.append("hidden visibility attribute")
        if m.doxygen:
            doxy_lc = m.doxygen.lower()
            for phrase in DOXY_PHRASES:
                if phrase in doxy_lc:
                    why_parts.append(f'doxygen contains "{phrase}"')
                    # Excerpt around the first match for context.
                    idx = doxy_lc.find(phrase)
                    start = max(0, idx - 30)
                    end = min(len(m.doxygen), idx + len(phrase) + 30)
                    excerpt = m.doxygen[start:end].replace("\\n", " ").strip()
                    break
        if not why_parts:
            continue
        key = rename_key_for(m.name)
        if _is_already_blacklisted(m.name, key, tables, cxx):
            continue
        detail = f"doxygen: …{excerpt}…" if excerpt else ""
        out.append(Finding(
            cls=m.cls, method=m.name, rename_key=key,
            why="H2 — " + "; ".join(why_parts),
            detail=detail,
        ))
    return out


# H3 — name-pattern denylist
def _h3_match(name: str) -> str | None:
    if name.startswith("_"):
        return "leading-underscore name"
    if name.startswith("unsafe"):
        return "unsafe* prefix"
    # getOpaque*, asOpaque*
    for prefix in ("getOpaque", "asOpaque"):
        if name.startswith(prefix):
            return f"{prefix}* prefix"
    if name.endswith("Internal"):
        return "*Internal suffix"
    if name.endswith("Impl"):
        return "*Impl suffix"
    return None


def heuristic_h3(metas: list[MethodMeta], tables: RenameTables,
                 cxx) -> list[Finding]:
    out: list[Finding] = []
    for m in metas:
        label = _h3_match(m.name)
        if label is None:
            continue
        key = rename_key_for(m.name)
        if _is_already_blacklisted(m.name, key, tables, cxx):
            continue
        out.append(Finding(
            cls=m.cls, method=m.name, rename_key=key,
            why=f"H3 — {label}",
            detail=f"return type: {m.return_type}",
        ))
    return out


# H4 — manual-override overlap
def heuristic_h4(metas: list[MethodMeta], tables: RenameTables,
                 cxx, manual: set[tuple[str, str]]) -> list[Finding]:
    out: list[Finding] = []
    for m in metas:
        pasta_name = cxx(m.name)
        if not pasta_name:
            continue
        if (m.cls, pasta_name) not in manual:
            continue
        key = rename_key_for(m.name)
        if _is_already_blacklisted(m.name, key, tables, cxx):
            continue
        out.append(Finding(
            cls=m.cls, method=m.name, rename_key=key,
            why=f"H4 — already wrapped manually as {m.cls}::{pasta_name}",
            detail=f"return type: {m.return_type}",
        ))
    return out


# ---------------------------------------------------------------------------
# H8 — dead-entry audit (port of /tmp/audit_step7b.py)
# ---------------------------------------------------------------------------

H8_PROBE_ORDER = [
    "kCxxMethodRenames",
    "kSuffixTransforms",
    "kPostRenameOverrides",
    "kPreRenameOverrides",
    "kPreStripDisableExact",
    "kPreStripDisableEndsWith",
    "kPreStripDisableStartsWith",
    "kPostStripDisableEndsWith",
    "kPostStripDisableStartsWith",
]

H8_TABLE_ATTR = {
    "kCxxMethodRenames":           "cxx_method_renames",
    "kPreRenameOverrides":         "pre_rename_overrides",
    "kPostRenameOverrides":        "post_rename_overrides",
    "kPreStripDisableExact":       "pre_strip_disable_exact",
    "kPreStripDisableEndsWith":    "pre_strip_disable_ends_with",
    "kPreStripDisableStartsWith":  "pre_strip_disable_starts_with",
    "kPostStripDisableEndsWith":   "post_strip_disable_ends_with",
    "kPostStripDisableStartsWith": "post_strip_disable_starts_with",
    "kSuffixTransforms":           "suffix_transforms",
}


def _clone_tables(tables: RenameTables) -> RenameTables:
    return RenameTables(
        cxx_method_renames=list(tables.cxx_method_renames),
        pre_rename_overrides=list(tables.pre_rename_overrides),
        post_rename_overrides=list(tables.post_rename_overrides),
        pre_strip_disable_exact=list(tables.pre_strip_disable_exact),
        pre_strip_disable_ends_with=list(tables.pre_strip_disable_ends_with),
        pre_strip_disable_starts_with=list(tables.pre_strip_disable_starts_with),
        post_strip_disable_ends_with=list(tables.post_strip_disable_ends_with),
        post_strip_disable_starts_with=list(tables.post_strip_disable_starts_with),
        suffix_transforms=list(tables.suffix_transforms),
    )


def _outputs_unchanged(working: RenameTables, method_names: list[str],
                       baseline_outputs: list[str]) -> bool:
    cxx = make_cxx_name(working)
    for m, expected in zip(method_names, baseline_outputs):
        if cxx(m) != expected:
            return False
    return True


def heuristic_h8(generated_methods: list[tuple[str, str]],
                 tables: RenameTables) -> tuple[dict[str, list], int]:
    method_names = sorted({name for _, name in generated_methods})
    baseline_cxx = make_cxx_name(tables)
    baseline_outputs = [baseline_cxx(m) for m in method_names]

    working = _clone_tables(tables)
    dead: dict[str, list] = {t: [] for t in H8_PROBE_ORDER}
    changed = True
    passes = 0
    while changed:
        changed = False
        passes += 1
        for table_name in H8_PROBE_ORDER:
            attr = H8_TABLE_ATTR[table_name]
            current = getattr(working, attr)
            for entry in list(current):
                trial = _clone_tables(working)
                trial_attr = getattr(trial, attr)
                trial_attr.remove(entry)
                if _outputs_unchanged(trial, method_names, baseline_outputs):
                    setattr(working, attr, trial_attr)
                    dead[table_name].append(entry)
                    changed = True
    return dead, passes


# ---------------------------------------------------------------------------
# Reporter
# ---------------------------------------------------------------------------

def _render_findings(name: str, findings: list[Finding]) -> str:
    if not findings:
        return ""
    lines: list[str] = [f"## {name}: {len(findings)} finding(s)\n"]
    by_cls: dict[str, list[Finding]] = {}
    for f in findings:
        by_cls.setdefault(f.cls, []).append(f)
    for cls in sorted(by_cls):
        lines.append(f"### {cls}\n")
        for f in by_cls[cls]:
            lines.append(f'- `{{"{f.rename_key}", ""}},  // {f.cls}::{f.method}`')
            lines.append(f"  *Why:* {f.why}")
            if f.detail:
                lines.append(f"  *Detail:* {f.detail}")
        lines.append("")
    return "\n".join(lines) + "\n"


def _render_h8_entry(table: str, entry) -> str:
    if table in {"kCxxMethodRenames", "kPreRenameOverrides", "kPostRenameOverrides"}:
        k, v = entry
        return f'  {{"{k}", "{v}"}}'
    if table == "kSuffixTransforms":
        s, r, b = entry
        return f'  {{"{s}", "{r}", {"true" if b else "false"}}}'
    return f'  "{entry}"'


def _render_h8(dead: dict[str, list], passes: int) -> str:
    total = sum(len(v) for v in dead.values())
    lines = [f"## H8 — dead-entry audit: {total} finding(s) (greedy fixpoint, {passes} pass(es))\n"]
    if total == 0:
        lines.append("All rename-table entries are load-bearing against the current Generated.h corpus.\n")
        return "\n".join(lines) + "\n"
    lines.append(
        "*Why:* removing any of these entries (one at a time, in the order shown) "
        "leaves all CxxName outputs unchanged. Some are forward-compat hooks intentionally "
        "kept for future LLVM versions — review each before deleting.\n"
    )
    for table in H8_PROBE_ORDER:
        entries = dead[table]
        if not entries:
            continue
        lines.append(f"### `{table}`: {len(entries)} dead\n")
        for e in entries:
            lines.append(_render_h8_entry(table, e))
        lines.append("")
    return "\n".join(lines) + "\n"


# ---------------------------------------------------------------------------
# Driver
# ---------------------------------------------------------------------------

ALL_HEURISTICS = ("H1", "H2", "H3", "H4", "H8")


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[1])
    ap.add_argument("--repo-root", type=Path, default=DEFAULT_REPO_ROOT,
                    help=f"Pasta repo root (default: {DEFAULT_REPO_ROOT})")
    ap.add_argument("--only", default=",".join(ALL_HEURISTICS),
                    help=f"Comma-separated subset of {ALL_HEURISTICS}")
    args = ap.parse_args(argv)

    repo = args.repo_root.resolve()
    selected = {h.strip().upper() for h in args.only.split(",") if h.strip()}
    unknown = selected - set(ALL_HEURISTICS)
    if unknown:
        print(f"error: unknown heuristic(s): {sorted(unknown)}", file=sys.stderr)
        return 2

    mm_path = repo / REL_METHOD_METADATA
    gen_path = repo / REL_GENERATED
    mr_path = repo / REL_METHOD_RENAMES
    nr_path = repo / REL_NULLABLE_RETURNS

    metas = parse_method_metadata(mm_path)
    if not metas:
        print(
            "error: MethodMetadata.h is empty (placeholder). "
            "Run `scripts/bootstrap` first to populate it.",
            file=sys.stderr,
        )
        return 2

    tables = parse_rename_tables(mr_path)
    cxx = make_cxx_name(tables)
    nullable_pairs = parse_nullable_pairs(nr_path) if nr_path.exists() else set()
    manual = parse_manual_methods(repo / p for p in REL_MANUAL_FILES)

    print(f"# /pasta:curate-metadata report\n")
    print(f"- Repo: `{repo}`")
    print(f"- MethodMetadata entries: {len(metas)}")
    print(f"- Manual override pairs: {len(manual)}")
    print(f"- kCanReturnNullptr ∪ kConditionalNullptr pairs: {len(nullable_pairs)}")
    print(f"- Heuristics run: {', '.join(sorted(selected))}\n")
    print("> **Propose-only.** Review each finding before editing "
          "`bin/BootstrapTypes/MethodRenames.cpp`.\n")

    section_outputs: list[str] = []
    if "H1" in selected:
        section_outputs.append(_render_findings("H1 — return-type denylist",
                                                 heuristic_h1(metas, tables, cxx)))
    if "H2" in selected:
        section_outputs.append(_render_findings("H2 — doxygen / attribute scraping",
                                                 heuristic_h2(metas, tables, cxx)))
    if "H3" in selected:
        section_outputs.append(_render_findings("H3 — name-pattern denylist",
                                                 heuristic_h3(metas, tables, cxx)))
    if "H4" in selected:
        section_outputs.append(_render_findings("H4 — manual-override overlap",
                                                 heuristic_h4(metas, tables, cxx, manual)))
    if "H8" in selected:
        gen_methods = parse_generated(gen_path)
        dead, passes = heuristic_h8(gen_methods, tables)
        section_outputs.append(_render_h8(dead, passes))

    rendered = [s for s in section_outputs if s]
    if not rendered:
        print("✅ No findings — all selected heuristics are clean against the "
              "current Generated.h / MethodMetadata.h.")
    else:
        print("\n".join(rendered))

    return 0


if __name__ == "__main__":
    sys.exit(main())
