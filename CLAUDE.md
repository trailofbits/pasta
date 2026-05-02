# PASTA — guide for AI agents

PASTA is a C++ library that wraps Clang's AST behind a stable, RAII-managed API. Large parts of it are auto-generated from Clang headers via a two-stage bootstrap. Most maintenance touches the bootstrap or the metadata that drives it.

## Where the LLVM version is pinned

- `vendor/llvm-project/CMakeLists.txt:26` — submodule branch.
- `.github/workflows/build.yml:32` — CI matrix (`llvm_version: [18]`).
- `vendor/llvm-project/src` — git submodule pointer.

Both files plus the submodule must move together when bumping LLVM.

## Bootstrap pipeline (regenerates wrappers from Clang headers)

Two stages, both produce code that the rest of PASTA depends on:

1. **`bin/BootstrapMacros/`** → produces `bin/BootstrapTypes/Generated.h` (~1.5 MB X-macro inventory of every Clang AST class + method we wrap).
2. **`bin/BootstrapTypes/`** → consumes `Generated.h`, emits the wrapper API:
   - `include/pasta/AST/{Forward,Decl,Stmt,Type,Attr}.h`
   - `lib/AST/{Decl,Stmt,Type,Attr}.cpp`
   - `bindings/python/src/AST/{Enums.cpp,AST.cpp,CMakeLists.txt}` and per-class binding files.

CMake flags that gate each stage live in `cmake/options.cmake:16-17`:
- `PASTA_BOOTSTRAP_MACROS=ON` enables stage 1
- `PASTA_BOOTSTRAP_TYPES=ON` enables stage 2

Either flag also disables installs (`cmake/options.cmake:20`) — bootstrap builds are dev-only.

Run order from a configured build dir:
```
ninja && ./bootstrap-macros && ninja && ./bootstrap-types && ninja
```

See `bin/README.md` for the full runbook including failure modes.

## Generated vs. checked-in files

| Path | Status |
|---|---|
| `include/pasta/AST/{Forward,Decl,Stmt,Type,Attr}.h` | **Generated** by `bootstrap-types`, checked in. |
| `lib/AST/{Decl,Stmt,Type,Attr}.cpp` | **Generated**, checked in. |
| `bin/BootstrapTypes/Generated.h` | **Generated** by `bootstrap-macros`, checked in. |
| `bindings/python/src/AST/*.cpp` (per-class) | **Generated**, checked in. |
| `lib/AST/{Type,Stmt,Attr}Manual.cpp` | **Hand-written** overrides for the auto-gen. |
| `include/pasta/AST/{Decl,Stmt,Type}Bootstrap.h` | **Hand-written**, used only when `PASTA_IN_BOOTSTRAP` is defined. |

Never edit a generated file directly — regenerate via the bootstrap pipeline.

## Metadata of record (drives the codegen)

`bin/BootstrapTypes/Globals.cpp` (~1,350 lines) holds all the hand-curated metadata:

- `kAllClassNames`, `kExtends` — class enumeration (driven by `Generated.h`).
- `kCxxMethodRenames` — ~700 entries; method renames + disables (entries mapping to `""` are blacklisted).
- `kCanReturnNullptr`, `kConditionalNullptr` — methods wrapped as `std::optional<T>`.
- `gClassIDs`, topological order arrays.

When Clang adds/removes/renames AST classes or methods, this file is where you reconcile the change.

## Bootstrap orchestrator

`bin/BootstrapTypes/Main.cpp` is the entry point for stage 2. Key sections:
- `Main.cpp:102-121` — class categorization (suffix matching; fragile, slated for refactor).
- `Main.cpp:131-150` — OMP base-class fixups (hardcoded; slated to move into data).
- `Main.cpp:152-175` — `topo_sort` lambda.
- `Main.cpp:183-210` — `transitive_rels` lambda.
- `Main.cpp:217-266` — generator dispatch (per-category H/Cpp emission).

## Working agreements for agents touching this repo

- **Bootstrap determinism is load-bearing.** Refactors of bootstrap orchestrator code MUST produce byte-for-byte identical generated wrappers. If you change codegen logic, run the full bootstrap loop and confirm `git diff` on generated files is empty.
- **Don't edit generated files.** Edit the generator or the metadata, then regenerate.
- **Hand-written overrides take precedence.** Anything in `lib/AST/*Manual.cpp` is authoritative; the auto-gen should not also wrap those methods.
- **`PASTA_IN_BOOTSTRAP` guards are real.** Code under `#ifdef PASTA_IN_BOOTSTRAP` only compiles during bootstrap builds. Don't gate it away without understanding why.
