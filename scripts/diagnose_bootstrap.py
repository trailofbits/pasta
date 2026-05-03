#!/usr/bin/env python3
"""
PASTA bootstrap-failure diagnoser (Step 16 of `snug-floating-finch`).

Reads a `scripts/bootstrap` log (or stdin) and matches the error text
against a known pattern table. For every match, prints a one-paragraph
diagnosis with the suggested fix.

Pattern coverage is intentionally narrow: only failure modes that have
been observed in this repo (mined from `pasta_bootstrap_environment.md`
+ commit history) are listed. New patterns are added as new failure
modes are encountered — see the "Pattern-table maintenance" section in
the skill doc.

Usage:
  scripts/diagnose_bootstrap.py [LOG_PATH]
  scripts/bootstrap … 2>&1 | scripts/diagnose_bootstrap.py
  scripts/diagnose_bootstrap.py --list   # show patterns

Exit codes:
  0  one or more patterns matched
  1  no pattern matched (unknown failure mode — surface log tail)
  2  bad input (unreadable file, invalid args, etc.)
"""

from __future__ import annotations

import argparse
import re
import sys
from dataclasses import dataclass
from pathlib import Path


# ---------------------------------------------------------------------------
# Pattern table
# ---------------------------------------------------------------------------

@dataclass
class Pattern:
    name: str
    regex: re.Pattern[str]
    cause: str
    fix: str
    refs: tuple[str, ...] = ()


# Patterns are evaluated in order; the first match wins per line. Order
# from most-specific to least-specific so generic regexes don't preempt
# more precise ones.
PATTERNS: list[Pattern] = [
    Pattern(
        name="MISSING_REMAPPED_DECL",
        regex=re.compile(
            r"no member named ['\"]RemappedDecl['\"] in ['\"]clang::Decl['\"]"
        ),
        cause=(
            "Building against stock LLVM. PASTA's vendored Clang fork carries "
            "a `clang::Decl::RemappedDecl` patch that stock LLVM doesn't have."
        ),
        fix=(
            "Reconfigure with `CMAKE_INSTALL_PREFIX=<…>/mx-env` (the pre-"
            "built vendored tree) and re-run the bootstrap."
        ),
        refs=("memory: pasta_bootstrap_environment.md",),
    ),
    Pattern(
        name="MISSING_RECURSIVE_AST_VISITOR_HEADER",
        regex=re.compile(
            r"['\"]clang/AST/RecursiveASTVisitor\.h['\"] file not found"
        ),
        cause=(
            "Stage 1 (`bootstrap-macros`) can't find Clang's AST headers at "
            "runtime because `kInstallIncludePath` (derived from "
            "`CMAKE_INSTALL_PREFIX`) points somewhere without a Clang install."
        ),
        fix=(
            "Reconfigure with `-DCMAKE_INSTALL_PREFIX=<…>/mx-env` and "
            "regenerate `BootstrapConfig.h` (`cmake .` in the build dir)."
        ),
        refs=("memory: pasta_bootstrap_environment.md",),
    ),
    Pattern(
        name="LIBCXX_TEMPLATE_PARSE",
        regex=re.compile(
            r"['\"]_Tp['\"] does not refer to a value"
        ),
        cause=(
            "Two libc++ trees are visible to `bootstrap-macros` at runtime "
            "(typically Apple's default + the vendored or other tree). The "
            "template parser explodes deep inside libc++."
        ),
        fix=(
            "Match the build-time compiler with the runtime headers — set "
            "both `CMAKE_C_COMPILER` and `CMAKE_CXX_COMPILER` to the mx-env "
            "Clang and `CMAKE_INSTALL_PREFIX` to the same mx-env tree, then "
            "reconfigure."
        ),
        refs=("memory: pasta_bootstrap_environment.md",),
    ),
    Pattern(
        name="UNCATEGORIZED_CLASS",
        regex=re.compile(
            r"BootstrapTypes:\s*no category for class ['\"]?(?P<cls>\w+)['\"]?"
        ),
        cause=(
            "Step 4's strict-validation in `Main.cpp::ResolveCategory` caught "
            "a Clang AST class that doesn't fit any known category and isn't "
            "in the opt-out set."
        ),
        fix=(
            "Either (a) add the class to `kCategorizationOptOut` in "
            "`bin/BootstrapTypes/Globals.cpp` if it really has no Decl/Stmt/"
            "Type/Attr lineage, or (b) extend the categorization rules in "
            "`Main.cpp` to handle the new lineage."
        ),
        refs=("memory: pasta_bootstrap_environment.md",
              "bin/BootstrapTypes/Globals.cpp:kCategorizationOptOut"),
    ),
    Pattern(
        name="STD_FILESYSTEM_TRY_COMPILE",
        regex=re.compile(
            r"std::filesystem.*(?:try_compile|cannot|failed)",
            re.IGNORECASE,
        ),
        cause=(
            "CMake's `try_compile` for `std::filesystem` failed — usually "
            "because a vendored Clang is being used standalone without a "
            "default sysroot."
        ),
        fix=(
            "Configure against mx-env (the pre-installed vendored tree), "
            "which provides the sysroot. See "
            "`pasta_bootstrap_environment.md`."
        ),
        refs=("memory: pasta_bootstrap_environment.md",),
    ),
    Pattern(
        # Specific form: "no member named 'getX' in 'clang::SomeClass'".
        # Surfaces the captured names so the suggested fix is concrete.
        name="CLANG_RENAMED_METHOD",
        regex=re.compile(
            r"no member named ['\"](?P<meth>[A-Za-z_]\w*)['\"]\s+"
            r"in ['\"](?:clang::)?(?P<cls>[\w:]+)['\"]"
        ),
        cause=(
            "Generated wrapper code calls `{cls}::{meth}` but Clang no longer "
            "has that method — a recent Clang upgrade renamed or removed it."
        ),
        fix=(
            "Locate the new Clang name and add the mapping to "
            "`bin/BootstrapTypes/MethodRenames.cpp` (typically "
            "`kCxxMethodRenames` for a clean rename, or "
            "`kPreRenameOverrides` if the new name needs special handling). "
            "Then re-run `/pasta:rebootstrap`. If the method was deleted "
            "outright, remove the matching entry instead — `H8` of "
            "`/pasta:curate-metadata` would surface that on the next run."
        ),
        refs=("plan: snug-floating-finch.md Step 16",),
    ),
    Pattern(
        name="UNDECLARED_GETTER",
        regex=re.compile(
            r"use of undeclared identifier ['\"](?P<name>(?:get|is|has)\w+)['\"]"
        ),
        cause=(
            "Generated code references a getter `{name}()` that no longer "
            "exists in this Clang version — Clang likely removed it."
        ),
        fix=(
            "Delete the matching entry from "
            "`bin/BootstrapTypes/MethodRenames.cpp` (look for the post-strip "
            "key; e.g., for `getFoo` the entry key is usually `Foo`). Then "
            "re-run `/pasta:rebootstrap`."
        ),
        refs=("plan: snug-floating-finch.md Step 16",),
    ),
    Pattern(
        name="MISSING_VISITOR_CASE",
        regex=re.compile(
            r"non-exhaustive (?:patterns|switch).*Visit"
            r"|switch missing default label.*Visit"
            r"|case value not in enumerated type 'clang::"
            r"(?:Decl|Stmt|Type|Attr)::Kind'"
        ),
        cause=(
            "A `RecursiveASTVisitor` or similar enum-driven switch is "
            "missing a case — typically because `Generated.h` is stale "
            "relative to the Clang headers it was bootstrapped against."
        ),
        fix=(
            "Re-run `/pasta:rebootstrap` to regenerate `Generated.h`. If the "
            "regen produces no diff, the missing case is in PASTA-side code "
            "(e.g., `lib/AST/*Bootstrap.cpp`) and needs a hand fix."
        ),
        refs=("plan: snug-floating-finch.md Step 16",),
    ),
    Pattern(
        name="STAGE_FAILED",
        regex=re.compile(
            r"^>>>\s*--check FAILED.*divergence"
        ),
        cause=(
            "`scripts/bootstrap --check` re-bootstrapped successfully but "
            "the regenerated artifacts diverge from the pre-run snapshot — "
            "the bootstrap is non-deterministic on this tree."
        ),
        fix=(
            "Run `/pasta:rebootstrap` (without `--no-check`) to get the "
            "structured per-category report from the verifier, then "
            "investigate the offending generator change. Refactors of "
            "bootstrap orchestrator code MUST produce byte-identical "
            "outputs."
        ),
        refs=("CLAUDE.md: Working agreements for agents",),
    ),
]


# ---------------------------------------------------------------------------
# Matching
# ---------------------------------------------------------------------------

@dataclass
class Match:
    pattern: Pattern
    line_no: int
    text: str
    captures: dict[str, str]


def diagnose(text: str) -> list[Match]:
    matches: list[Match] = []
    seen: set[tuple[str, str]] = set()
    for line_no, line in enumerate(text.splitlines(), start=1):
        for p in PATTERNS:
            m = p.regex.search(line)
            if not m:
                continue
            captures = {k: v for k, v in m.groupdict().items() if v is not None}
            # Dedupe on (pattern_name, sorted captures) so a flood of
            # repeated identical errors collapses to one diagnosis.
            key = (p.name, ",".join(f"{k}={v}" for k, v in sorted(captures.items())))
            if key in seen:
                break
            seen.add(key)
            matches.append(Match(pattern=p, line_no=line_no, text=line.rstrip(),
                                 captures=captures))
            break  # at most one pattern per line
    return matches


# ---------------------------------------------------------------------------
# Reporter
# ---------------------------------------------------------------------------

def _fmt(template: str, captures: dict[str, str]) -> str:
    if not captures:
        return template
    try:
        return template.format(**captures)
    except (KeyError, IndexError):
        return template


def render(matches: list[Match], log_tail: str) -> str:
    if not matches:
        return (
            "# /pasta:diagnose-bootstrap report\n\n"
            "❓ **No matching pattern.** This is either a non-bootstrap build "
            "failure or a new failure mode that isn't in the table yet.\n\n"
            "## Last 30 lines of the log\n\n"
            "```\n"
            f"{log_tail}\n"
            "```\n\n"
            "If this turns out to be a recurring bootstrap failure, add a "
            "new `Pattern(...)` entry to "
            "`scripts/diagnose_bootstrap.py::PATTERNS` so the next "
            "occurrence diagnoses cleanly.\n"
        )
    lines: list[str] = ["# /pasta:diagnose-bootstrap report\n"]
    lines.append(f"Matched **{len(matches)}** known failure mode(s).\n")
    for i, m in enumerate(matches, start=1):
        lines.append(f"## {i}. `{m.pattern.name}` (line {m.line_no})\n")
        lines.append(f"**Matched text:** `{m.text.strip()}`\n")
        lines.append(f"**Cause:** {_fmt(m.pattern.cause, m.captures)}\n")
        lines.append(f"**Fix:** {_fmt(m.pattern.fix, m.captures)}\n")
        if m.pattern.refs:
            lines.append("**References:**")
            for ref in m.pattern.refs:
                lines.append(f"- {ref}")
            lines.append("")
    return "\n".join(lines) + "\n"


def render_pattern_list() -> str:
    lines = [f"# diagnose-bootstrap pattern table ({len(PATTERNS)} entries)\n"]
    for p in PATTERNS:
        lines.append(f"## `{p.name}`\n")
        lines.append(f"**Regex:** `{p.regex.pattern}`\n")
        lines.append(f"**Cause:** {p.cause}\n")
        lines.append(f"**Fix:** {p.fix}\n")
        if p.refs:
            lines.append("**References:** " + ", ".join(p.refs))
            lines.append("")
    return "\n".join(lines) + "\n"


# ---------------------------------------------------------------------------
# Driver
# ---------------------------------------------------------------------------

def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[1])
    ap.add_argument("log", nargs="?", type=Path,
                    help="Bootstrap log file. If omitted, read from stdin.")
    ap.add_argument("--list", action="store_true",
                    help="Print the pattern table and exit.")
    args = ap.parse_args(argv)

    if args.list:
        print(render_pattern_list(), end="")
        return 0

    if args.log:
        try:
            text = args.log.read_text()
        except OSError as e:
            print(f"error: {e}", file=sys.stderr)
            return 2
    else:
        text = sys.stdin.read()

    if not text.strip():
        print("error: empty input", file=sys.stderr)
        return 2

    matches = diagnose(text)
    tail = "\n".join(text.splitlines()[-30:])
    print(render(matches, tail), end="")
    return 0 if matches else 1


if __name__ == "__main__":
    sys.exit(main())
