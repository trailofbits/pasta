#!/usr/bin/env python3
"""
Build vendor/llvm-project/PASTA_PATCHES.md (Step 17 of `snug-floating-finch`).

Walks `git log llvmorg-18-init..HEAD` in the vendored LLVM submodule,
filters to PASTA-authored commits, and emits a per-patch Markdown
manifest.

Each entry carries deterministic, re-derivable fields (SHA, author,
subject, files-touched, line-range hash). The `Intent:` field is
seeded as a TODO marker; intent summaries are written by hand (or by
an LLM agent) in a follow-up pass — they are the cross-version anchor
the future `pasta-llvm-patch-porter` agent (Step 19) will read when
cherry-pick conflicts force re-derivation.

Re-runnable: existing `Intent:` text in the current manifest is
preserved across regenerations, so adding a new PASTA commit doesn't
clobber prior intent work. (Seed text — anything starting with `TODO`
— is replaced.)

Usage:
  scripts/build_pasta_patches_manifest.py [--repo-root PATH]
                                          [--dry-run]
                                          [--check]

`--check` exits non-zero if any patch has a TODO Intent or if the
manifest's patch count differs from the raw git log result.
"""

from __future__ import annotations

import argparse
import hashlib
import re
import subprocess
import sys
from dataclasses import dataclass, field
from pathlib import Path


DEFAULT_REPO_ROOT = Path(__file__).resolve().parent.parent
SUBMODULE_REL = "vendor/llvm-project/src"
MANIFEST_REL = "docs/PASTA_PATCHES.md"
BASE_REF = "llvmorg-18-init"

# PASTA-author filter. The plan's awk pattern (`trailofbits\.com|...`) is
# broader than intended — it catches `advenam.tacet@trailofbits.com`
# whose 12 commits are upstream LLVM ASan/libc++ work that rides on the
# pasta fork branch but isn't PASTA-specific. The actual PASTA-author
# set on pasta-llvmorg-18.1.4 is enumerated explicitly:
#   - peter@trailofbits.com   — 60 commits
#   - peter.goodman@gmail.com —  1 commit
#   - *kumarak*               —  0 commits today (kept for forward-compat)
# Total: 61.
PASTA_AUTHOR_PATTERNS = (
    r"^peter@trailofbits\.com$",
    r"^peter\.goodman@gmail\.com$",
    r"kumarak",  # substring match — covers kumarak@anywhere
)
PASTA_AUTHOR_RE = re.compile("|".join(PASTA_AUTHOR_PATTERNS))

INTENT_TODO_PREFIX = "TODO"


# ---------------------------------------------------------------------------
# Discovery
# ---------------------------------------------------------------------------

def _git(submodule: Path, *args: str, ok_codes: tuple[int, ...] = (0,)) -> str:
    proc = subprocess.run(
        ["git", "-C", str(submodule), *args],
        capture_output=True, text=True,
    )
    if proc.returncode not in ok_codes:
        raise RuntimeError(
            f"git {' '.join(args)} failed (exit {proc.returncode}):\n"
            f"{proc.stderr.strip()}"
        )
    return proc.stdout


@dataclass
class Patch:
    sha: str
    author_email: str
    subject: str
    files_touched: list[str] = field(default_factory=list)
    line_range_hash: str = ""


def discover_patches(submodule: Path) -> list[Patch]:
    log = _git(
        submodule, "log", "--no-merges",
        f"--format=%H%x09%ae%x09%s",
        f"{BASE_REF}..HEAD",
    )
    out: list[Patch] = []
    for line in log.splitlines():
        parts = line.split("\t", 2)
        if len(parts) != 3:
            continue
        sha, email, subject = parts
        if not PASTA_AUTHOR_RE.search(email):
            continue
        out.append(Patch(sha=sha, author_email=email, subject=subject))
    return out


def enrich(submodule: Path, patches: list[Patch]) -> None:
    for p in patches:
        files = _git(submodule, "show", "--pretty=", "--name-only",
                     p.sha).splitlines()
        # `git show --pretty= --name-only` emits a blank line first; filter.
        p.files_touched = [f for f in files if f.strip()]
        # Hash the diff content (no metadata) so cosmetic message edits
        # don't change the line-range hash. Use --no-color to avoid ANSI
        # bytes in the hashed payload.
        diff = _git(submodule, "show", "--pretty=", "--no-color", p.sha)
        p.line_range_hash = "sha256:" + hashlib.sha256(
            diff.encode("utf-8", errors="replace")
        ).hexdigest()[:16]


# ---------------------------------------------------------------------------
# Manifest IO
# ---------------------------------------------------------------------------

# Section parser. The renderer below emits sections that start with
# `## <SHA>` and have labelled `- **Field:** value` lines plus an Intent
# block. The parser extracts only what we need to round-trip: the SHA
# and the intent body. Everything else is regenerated each run.
RE_SECTION_HEADER = re.compile(r"^## `([0-9a-f]{8,40})`", re.MULTILINE)
RE_INTENT_BLOCK = re.compile(
    r"^\*\*Intent:\*\*\s*\n(.*?)(?=^\#\#\s|\Z)",
    re.MULTILINE | re.DOTALL,
)


RE_FULL_SHA_FIELD = re.compile(r"^-\s*\*\*SHA:\*\*\s*`([0-9a-f]{40})`", re.MULTILINE)


def load_existing_intents(manifest_path: Path) -> dict[str, str]:
    """Return {full_sha → intent text} for sections whose Intent isn't a TODO seed.

    Keys on the FULL SHA from the `**SHA:**` field, not the abbreviated SHA
    in the section header — keeping intents joinable with `Patch.sha`.
    """
    if not manifest_path.exists():
        return {}
    text = manifest_path.read_text()
    out: dict[str, str] = {}
    headers = list(RE_SECTION_HEADER.finditer(text))
    for i, h in enumerate(headers):
        section_start = h.end()
        section_end = headers[i + 1].start() if i + 1 < len(headers) else len(text)
        section = text[section_start:section_end]
        sha_m = RE_FULL_SHA_FIELD.search(section)
        if not sha_m:
            continue
        full_sha = sha_m.group(1)
        intent_m = RE_INTENT_BLOCK.search(section)
        if not intent_m:
            continue
        intent = intent_m.group(1).strip()
        if not intent or intent.startswith(INTENT_TODO_PREFIX):
            continue
        out[full_sha] = intent
    return out


def render(patches: list[Patch], existing_intents: dict[str, str]) -> str:
    lines: list[str] = [
        "# PASTA patches manifest",
        "",
        "Authoritative list of every PASTA-specific patch on the vendored "
        "LLVM fork at `vendor/llvm-project/src` (currently branch "
        "`pasta-llvmorg-18.1.4`). Generated by "
        "`scripts/build_pasta_patches_manifest.py`; intent summaries are "
        "hand-curated.",
        "",
        f"- **Base ref:** `{BASE_REF}`",
        f"- **Patch count:** **{len(patches)}**",
        "- **Author filter:** `peter@trailofbits.com`, "
        "`peter.goodman@gmail.com`, or any address containing `kumarak`. "
        "(The plan's awk pattern `trailofbits.com` was broader and caught "
        "unrelated TOB upstream commits — see the script for the narrower "
        "filter actually used here.)",
        "",
        "## Why this file exists",
        "",
        "Every LLVM upgrade has to forward-port these patches onto the new "
        "base. The structural metadata (SHA, files, hash) is "
        "machine-extractable; the **intent summary** is the cross-version "
        "anchor — when a future cherry-pick fails because upstream "
        "refactored around the patch, the porter agent (Step 19 of the "
        "`snug-floating-finch` plan) re-derives the patch from the intent "
        "rather than from the literal diff.",
        "",
        "Re-running the builder preserves any non-TODO intent text already "
        "in this file. Add or refine intents directly in this Markdown.",
        "",
        "---",
        "",
    ]
    for p in patches:
        short = p.sha[:12]
        lines.append(f"## `{short}` — {p.subject}")
        lines.append("")
        lines.append(f"- **SHA:** `{p.sha}`")
        lines.append(f"- **Author:** `{p.author_email}`")
        lines.append(f"- **Line-range hash:** `{p.line_range_hash}`")
        if p.files_touched:
            lines.append(f"- **Files touched ({len(p.files_touched)}):**")
            for f in p.files_touched:
                lines.append(f"  - `{f}`")
        else:
            lines.append("- **Files touched:** _(none)_")
        lines.append("")
        lines.append("**Intent:**")
        intent = existing_intents.get(p.sha)
        if intent:
            lines.append(intent)
        else:
            lines.append(
                "TODO — read `git show " + p.sha[:12] + "` in the "
                "submodule and write 1–3 sentences capturing why this patch "
                "exists, what failure mode it avoids, and what behavior it "
                "expects from surrounding Clang."
            )
        lines.append("")
    return "\n".join(lines) + "\n"


# ---------------------------------------------------------------------------
# Driver
# ---------------------------------------------------------------------------

def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[1])
    ap.add_argument("--repo-root", type=Path, default=DEFAULT_REPO_ROOT)
    ap.add_argument("--dry-run", action="store_true",
                    help="Print the manifest to stdout instead of writing it.")
    ap.add_argument("--check", action="store_true",
                    help="Exit non-zero if any patch still has a TODO Intent "
                         "or if the manifest count differs from the raw "
                         "git log count.")
    args = ap.parse_args(argv)

    repo = args.repo_root.resolve()
    submodule = repo / SUBMODULE_REL
    manifest_path = repo / MANIFEST_REL

    if not (submodule / ".git").exists() and not (submodule / "HEAD").exists():
        print(
            f"error: submodule not initialised at {submodule}. "
            "Run `git submodule update --init vendor/llvm-project/src`.",
            file=sys.stderr,
        )
        return 2

    patches = discover_patches(submodule)
    if not patches:
        print("error: no PASTA-authored patches found.", file=sys.stderr)
        return 2

    if args.check:
        existing_intents = load_existing_intents(manifest_path)
        bad: list[str] = []
        for p in patches:
            if p.sha not in existing_intents:
                bad.append(f"{p.sha[:12]}  {p.subject}")
        if not manifest_path.exists():
            print("error: manifest does not exist; run without --check first.",
                  file=sys.stderr)
            return 1
        # Count sections in the manifest, compare to discovery.
        text = manifest_path.read_text()
        sections = RE_SECTION_HEADER.findall(text)
        if len(sections) != len(patches):
            print(
                f"error: manifest has {len(sections)} sections but "
                f"git log returned {len(patches)} PASTA commits.",
                file=sys.stderr,
            )
            return 1
        if bad:
            print(f"error: {len(bad)} patch(es) still have TODO intents:",
                  file=sys.stderr)
            for line in bad:
                print(f"  {line}", file=sys.stderr)
            return 1
        print(f"✅ manifest clean: {len(patches)} patches, all with non-TODO intents.")
        return 0

    enrich(submodule, patches)
    existing_intents = load_existing_intents(manifest_path)
    rendered = render(patches, existing_intents)

    if args.dry_run:
        print(rendered, end="")
        return 0

    manifest_path.write_text(rendered)
    fresh = sum(1 for p in patches if p.sha in existing_intents)
    print(f"wrote {manifest_path.relative_to(repo)} "
          f"({len(patches)} patches; {fresh} with existing intents preserved, "
          f"{len(patches) - fresh} TODO).")
    return 0


if __name__ == "__main__":
    sys.exit(main())
