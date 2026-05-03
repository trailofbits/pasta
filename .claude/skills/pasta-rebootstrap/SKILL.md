---
name: pasta-rebootstrap
description: Run the PASTA bootstrap pipeline and report a structured summary of wrapper/metadata changes. Use when the user says "rebootstrap pasta", "regenerate wrappers", "check bootstrap determinism", or after editing files in `bin/BootstrapTypes/` or `bin/BootstrapMacros/`. Wraps `scripts/bootstrap` from the repo and turns its raw output + diffs into a per-category report (classes added/removed, methods added/removed/renamed, Python bindings added/removed, MethodMetadata.h classification deltas).
allowed-tools: Bash, Read, Glob, Grep
---

# pasta-rebootstrap

You drive the PASTA bootstrap pipeline (`scripts/bootstrap` from the pasta repo) and turn its output into a structured report. The script does the orchestration; your job is interpretation.

## Inputs

Parse from the user prompt (no arg-parser needed; just look for these tokens):

- `--build-dir <path>` (or "build dir at <path>") → use this configured pasta build directory. **Required** if `$PWD` is not itself a configured pasta build directory.
- `--no-check` → just regenerate wrappers; don't enforce byte-equivalence against the pre-run snapshot.

If the user says "no diffs" or "fast", treat as `--no-check`.

## Preflight (hard-fail before running)

Refuse to proceed unless ALL of these hold. On failure, print the specific check that failed and exit — do NOT invoke `scripts/bootstrap`.

1. **Build directory exists.** `<build-dir>` must be a directory. If the user didn't pass `--build-dir`, default to `$PWD` and check the same way.
   - Failure message: `pasta-rebootstrap: build directory <path> not found. Pass --build-dir <path> or run from a configured pasta build directory.`

2. **Build directory is configured.** `<build-dir>/CMakeCache.txt` must exist.
   - Failure message: `pasta-rebootstrap: <path>/CMakeCache.txt not found — directory is not a CMake build tree. Run cmake to configure first.`

3. **Bootstrap flags are ON.** Both `PASTA_BOOTSTRAP_MACROS:BOOL=ON` and `PASTA_BOOTSTRAP_TYPES:BOOL=ON` must appear in `CMakeCache.txt`. Use `grep` to check.
   - Failure message: `pasta-rebootstrap: build directory was not configured with bootstrap flags. Re-run cmake with -DPASTA_BOOTSTRAP_MACROS=ON -DPASTA_BOOTSTRAP_TYPES=ON.`

4. **LLVM install path is reachable.** Read `<build-dir>/BootstrapConfig.h` and extract `kInstallIncludePath`. Verify the path exists AND contains `clang/AST/RecursiveASTVisitor.h` (the canonical header `bootstrap-macros` needs at runtime).
   - Failure message: `pasta-rebootstrap: clang headers not found at <kInstallIncludePath>. Install vendored LLVM to that prefix or reconfigure with -DCMAKE_INSTALL_PREFIX=<path-with-clang-headers>.`

5. **`scripts/bootstrap` exists in the repo.** Walk up from `<build-dir>` looking for `<repo>/scripts/bootstrap`. Abort if not found within 3 levels up.
   - Failure message: `pasta-rebootstrap: scripts/bootstrap not found. Are you sure <build-dir> is a pasta build tree?`

All five checks pass → proceed to the workflow.

## Workflow

1. **Locate repo root.** From the build dir, walk up looking for `scripts/bootstrap`. If not found, abort with a clear error.

2. **Run the bootstrap.** Use `Bash` with the long-running flag:
   ```
   <repo>/scripts/bootstrap [--check] --build-dir <build-dir>
   ```
   Capture stdout+stderr to a log file (`/tmp/pasta-rebootstrap-<timestamp>.log`).

3. **Parse stage outcomes.** Look for the `>>>` headers that `scripts/bootstrap` emits. For each stage report status (OK / FAILED) and time elapsed if visible.

4. **If a stage failed**, find the first compile error in the log and report it under "Failure" with `file:line: message`. Do not produce a wrapper diff in this case.

5. **If `--check` succeeded with no diffs**, report:
   > **PASS** — bootstrap is deterministic. No regenerated files diverged.

6. **If `--check` reported divergences**, produce the **structured report** below.

## Structured report

Use `git diff -- <generated-paths>` (the diff is between the working tree after regen and the pre-run snapshot that `scripts/bootstrap --check` captured) against:

- `include/pasta/AST/{Forward,Decl,Stmt,Type,Attr}.h`
- `lib/AST/{Decl,Stmt,Type,Attr}.cpp`
- `bin/BootstrapTypes/Generated.h`
- `bin/BootstrapTypes/MethodMetadata.h`
- `bindings/python/src/AST/`

Group the findings:

### Wrapper class additions
Grep added lines (`^+class \w+`) in `Forward.h` and `{Decl,Stmt,Type,Attr}.h`. Report as:
```
+ class FooDecl  (Decl.h)
+ class BarType  (Type.h)
```

### Wrapper class removals
Grep removed lines (`^-class \w+`). Same format with `-`.

### Wrapper method additions/removals
Within each modified `lib/AST/<Cat>.cpp`, look for added/removed `T ClassName::MethodName(` definitions. Group by class:
```
ClassName (Type.cpp):
  + getNewThing(): clang::Foo *
  - getOldThing(): bool
```

### Wrapper method signature changes
Methods with the same name where the type changed:
```
ClassName.method() : T → U
```

### Python binding files
`git diff --name-status -- bindings/python/src/AST/`. Report added (`A`) and removed (`D`) per-class binding files:
```
+ bindings/python/src/AST/NewAttr.cpp
- bindings/python/src/AST/OldAttr.cpp
```

### MethodMetadata.h classification deltas
For each line in the diff, parse the `body_classification` field (8th comma-separated arg of `PASTA_METHOD_METADATA(...)`). Surface methods whose classification changed:
```
Decl::isExternallyVisible: SAFE → CONDITIONAL_ASSERT (predicate: !isInvalidDecl())
```
Also surface NEW conditional-asserts (methods that didn't exist before, now classified):
```
NEW CONDITIONAL_ASSERT entries (10):
  Decl::getFoo  predicate: hasFoo()
  Type::getBar  predicate: !isDependentType()
  ...
```

### Generated.h structural delta
Report counts only:
```
Generated.h: +N classes, -M classes, ±K method signatures
```
(Don't dump per-method diffs — too noisy. Refer the user to `git diff bin/BootstrapTypes/Generated.h` for detail.)

## Output format

Lead with the headline (PASS / FAIL / N divergences). Then sections in the order above, omitting empty ones. End with the path to the full log for forensic deep-dives.

Example successful run:
```
✅ PASS — bootstrap completed cleanly, no divergences.

Stage timings (approximate from log):
  stage 1 build:     2s
  stage 1 run:       1s
  stage 2 build:     1s
  stage 2 run:       1s
  stage 3 build:    47s

Log: /tmp/pasta-rebootstrap-1714680000.log
```

Example divergence:
```
⚠️  DIVERGED — regenerated files differ from the pre-run snapshot.

Wrapper class additions: 2
  + class CodeAlignAttr  (Attr.h)
  + class CountedByAttr  (Attr.h)

Wrapper method additions: 5 across 3 classes
  AttributedType (Type.cpp):
    + getAttrKind(): clang::attr::Kind
  ...

NEW CONDITIONAL_ASSERT entries: 3
  AlignedAttr::getAlignmentExpr  predicate: isalignmentExpr
  ...

Log: /tmp/pasta-rebootstrap-1714680000.log
```

## Hard rules

- **Do not modify any files.** This skill is propose/report only. The bootstrap itself regenerates files in the working tree (that's `scripts/bootstrap`'s job, not yours), but you do not edit code.
- **Do not commit.** Even if everything is clean, reporting "ready to commit" is the user's call.
- **Surface failures clearly.** If `scripts/bootstrap` exits non-zero, the report leads with FAIL and the specific error. Don't bury it under stage timings.
- **Never invent diffs.** If `git diff` is empty for a category, omit that section. Empty section ≠ "no changes there" — say nothing.
