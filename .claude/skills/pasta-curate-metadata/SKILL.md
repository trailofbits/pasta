---
name: pasta-curate-metadata
description: Run the PASTA base metadata-curation heuristics (H1–H4 + H8) and emit a propose-only diff against `bin/BootstrapTypes/MethodRenames.cpp`. Use when the user says "curate pasta metadata", "audit metadata tables", "find blacklist candidates", "audit dead rename entries", or after a re-bootstrap that surfaced new Clang methods. Read-only — never applies its own proposals.
allowed-tools: Agent, Read
---

# pasta-curate-metadata

You are a thin orchestrator. You spawn one agent (`pasta-metadata-curator`) which runs `scripts/curate_metadata.py` and returns a Markdown report. You relay the report to the user verbatim, prefixed by a one-line header reminding the reviewer this is propose-only. You do NOT run the script yourself, parse its output, or modify any files.

## Inputs

Parse from the user prompt:

- `--repo-root <path>` — optional. Default: `$PWD` if it looks like the pasta repo (has `bin/BootstrapTypes/`); otherwise ask the user.
- `--only <list>` — optional comma-separated subset of `H1,H2,H3,H4,H8`. Default: all five.

## Workflow

### Step 1 — Spawn `pasta-metadata-curator`

Pass:
- `repo_root` — absolute path.
- `only` — heuristic filter if the user gave one, otherwise omit.

Wait for the agent to return one of:
- `PREFLIGHT_FAILED` → print the failure message verbatim and stop. Common case: MethodMetadata.h is still the placeholder, in which case advise the user to run `/pasta:rebootstrap` first.
- `FAIL` → print `❌ FAIL — curator script error.` followed by the stderr excerpt and stop.
- `OK` → continue to Step 2.

### Step 2 — Relay the report

Print:

```
ℹ️  Propose-only. Each finding is a candidate; review and accept/annotate before editing
    bin/BootstrapTypes/MethodRenames.cpp.
```

Then print the agent's `report:` block verbatim.

## Hard rules

- **One agent, propose only.** You orchestrate; the agent runs the script; the script proposes. No one in this chain edits source.
- **No own logic.** You don't preflight, you don't apply heuristics, you don't filter findings. The script does it.
- **Surface preflight failures verbatim.** When MethodMetadata.h is empty or the script can't find inputs, the user needs that exact message.
- **Don't auto-invoke /pasta:rebootstrap.** If MethodMetadata.h is empty, *suggest* the user run it; don't trigger it. Curation and re-bootstrap are separate user decisions.
