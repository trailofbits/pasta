---
name: pasta-rebootstrap
description: Run the PASTA bootstrap pipeline and report a structured summary of wrapper/metadata changes. Use when the user says "rebootstrap pasta", "regenerate wrappers", "check bootstrap determinism", or after editing files in `bin/BootstrapTypes/` or `bin/BootstrapMacros/`. Orchestrates two agents in sequence: pasta-bootstrap-runner does the actual bootstrap, then pasta-bootstrap-verifier parses the diffs into a per-category report.
allowed-tools: Agent, Read
---

# pasta-rebootstrap

You are a thin orchestrator. Your job is to run two agents in sequence and relay their outputs to the user. You do NOT invoke `scripts/bootstrap` yourself, parse diffs, or modify any files. The work happens inside the agents.

## Inputs

Parse from the user prompt:

- `--build-dir <path>` — required if `$PWD` is not itself a configured pasta build directory.
- `--no-check` (or "no diffs", "fast") — skip the byte-equivalence check.

If neither is given and `$PWD/CMakeCache.txt` doesn't exist, ask the user for `--build-dir` before doing anything.

## Workflow

### Step 1 — Spawn `pasta-bootstrap-runner`

Pass:
- `build_dir` — resolved to absolute path.
- `check` — true unless `--no-check` was given.

Wait for the runner to return one of:
- `PREFLIGHT_FAILED` → print the failure message and stop. Do NOT spawn the verifier.
- `PASS` → print "✅ PASS — bootstrap is deterministic, no divergences." with the per-stage timings and log path. Stop.
- `FAIL` → print "❌ FAIL at stage <N>: <error excerpt>." with the log path. Stop. Do NOT spawn the verifier.
- `DIVERGED` → continue to Step 2.

### Step 2 — Spawn `pasta-bootstrap-verifier`

Only if the runner returned `DIVERGED`. Pass:
- `repo_root` — from runner's output.
- `changed_files` — from runner's output.
- `log_path` — from runner's output.

Wait for the verifier's structured report. Print it as-is to the user.

## Hard rules

- **Two agents, one direction.** Always runner first; verifier only on DIVERGED. Never re-spawn either agent.
- **No own logic.** You don't preflight, you don't parse diffs, you don't categorize. The agents do it. You orchestrate and relay.
- **Propose-only.** Neither you nor the agents modify pasta source. The bootstrap regenerates files as a side effect of running, but no agent edits code or commits.
- **Surface failures verbatim.** If the runner reports PREFLIGHT_FAILED or FAIL, copy its message to the user without rewording.
