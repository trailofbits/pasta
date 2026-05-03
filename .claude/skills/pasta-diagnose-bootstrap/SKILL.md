---
name: pasta-diagnose-bootstrap
description: Diagnose a failed PASTA bootstrap by matching the log against the known failure-mode pattern table. Use when the user says "why did the bootstrap fail", "diagnose this build error", "what does this bootstrap log mean", or after `/pasta:rebootstrap` returns FAIL. Also chain after a manual `scripts/bootstrap …` run that fails. Returns the matched cause + suggested fix; surfaces "no matching pattern" with the log tail when the failure is unknown.
allowed-tools: Bash, Read
---

# pasta-diagnose-bootstrap

You take a bootstrap log path (or pasted log text) and run `scripts/diagnose_bootstrap.py` against it. The script does the pattern matching; your job is to find the log, invoke the script, and relay the report. You do NOT pattern-match yourself, you do NOT modify any source, and you do NOT apply any of the suggested fixes — the user reviews and applies.

## Inputs

Parse from the user prompt:

- A log path (e.g., `/tmp/pasta-bootstrap-1714680000.log`). If the user pasted log text directly into the prompt, write it to a temp file and use that path.
- `--repo-root <path>` — optional. Default: `$PWD` if it has `scripts/diagnose_bootstrap.py`; otherwise ask the user.

If no log path is given AND no log text was pasted: ask the user to either re-run with a log path or paste the relevant excerpt (last ~50 lines around the FAILED line is enough).

## Workflow

1. **Resolve the script path:** `<repo_root>/scripts/diagnose_bootstrap.py`. Verify it exists and is executable. If not, error with `script not found at <path> — pasta repo root may be wrong`.
2. **Run the script:** `<script> <log_path>`. Capture stdout + exit code.
3. **Relay the report:**
   - exit 0 (one or more patterns matched) → print the script's stdout verbatim. Add a one-line note: `ℹ️  Apply the suggested fix(es) and re-run /pasta:rebootstrap.`
   - exit 1 (no pattern matched) → print the script's stdout verbatim. The script already includes the log tail and a note about adding a new pattern. Suggest the user open `scripts/diagnose_bootstrap.py` and add a new `Pattern(...)` if this is a recurring failure.
   - exit 2 (input error) → print the stderr message and stop.

## Pattern-table maintenance

When the user asks `/pasta:diagnose-bootstrap` and gets a "no matching pattern" result, that's a signal a new failure mode has shown up. Offer (don't auto-do) to:

1. Identify the line(s) the user thinks should match.
2. Sketch a `Pattern(name=…, regex=…, cause=…, fix=…, refs=…)` entry.
3. Print it for the user to paste into `scripts/diagnose_bootstrap.py::PATTERNS`.

You do not edit the script directly — pattern additions are user-curated to keep the table from drifting.

## Composition with /pasta:rebootstrap

When `/pasta:rebootstrap` returns `FAIL` with a `log_path`, the user can immediately run `/pasta:diagnose-bootstrap <that-path>`. Future versions of `/pasta:rebootstrap` may auto-chain into this skill on FAIL; for now it's manual.

## Hard rules

- **Read-only.** Never edit source files, never run `scripts/bootstrap`, never modify the pattern table.
- **One script call.** All matching logic lives in `scripts/diagnose_bootstrap.py`. Don't duplicate or reinvent it here.
- **Surface failures verbatim.** When the script reports "no matching pattern", show the log tail as-is — don't try to guess.
- **No fix application.** The output describes what to fix; the user (or `/pasta:rebootstrap` after the fix) does the applying.
