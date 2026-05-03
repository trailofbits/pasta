# `Generated.h` schema

`Generated.h` is the X-macro inventory of every Clang AST class, base-class edge, method, field, and enum that PASTA wraps. It is the single shared input to:

- `Globals.cpp` (builds `kAllClassNames`, `kExtends`, `gMethodNames`, `gClassIDs`).
- The eight `Generate{Decl,Stmt,Type,Attr}{H,Cpp}.cpp` codegen files in this directory.
- Any future tooling that needs a structured view of what PASTA wraps (`bin/Inventory/lift.py`, the planned `pasta-clang-api-diff` agent, the metadata-curation skills).

This document specifies the macro vocabulary and block structure so consumers can be written without reverse-engineering the file.

**Producer:** `bin/BootstrapMacros/MacroGenerator.cpp` (stage 1 of the bootstrap). To add a new schema element, edit there.

**Default expansions:** the file begins with `#include "DefineDefaultMacros.h"`, which expands every macro to nothing. Consumers redefine only the macros they care about and `#include "Generated.h"`; unhandled macros are silently dropped. This is why `Globals.cpp` can `#include "Generated.h"` four times in a row to populate four different tables from one source.

## File layout

1. `#include "DefineDefaultMacros.h"`
2. ~820 class blocks, each `PASTA_BEGIN_CLANG_WRAPPER(name, id) … PASTA_END_CLANG_WRAPPER(name, id)`. Alphabetically ordered.
3. After the class blocks, a series of free named enums: `PASTA_BEGIN_NAMED_ENUM(name, underlying) … PASTA_END_NAMED_ENUM(name)`.

There is no overall `BEGIN`/`END` wrapping the file.

## Class blocks

Every class block has exactly four sub-blocks, always in this order, even if empty:

```
PASTA_BEGIN_CLANG_WRAPPER(AttributedStmt, 607134768)
  PASTA_BEGIN_BASE_CLASSES(AttributedStmt, 607134768)
    PASTA_PUBLIC_BASE_CLASS(AttributedStmt, 607134768, ValueStmt, 1093492336)
  PASTA_END_BASE_CLASSES(AttributedStmt, 607134768)

  PASTA_BEGIN_METHODS(AttributedStmt, 607134768)
    PASTA_INSTANCE_METHOD_0(AttributedStmt, 607134768, 0, children, (llvm::iterator_range<clang::ConstStmtIterator>))
    PASTA_INSTANCE_METHOD_0(AttributedStmt, 607134768, 1, getAttrLoc, (clang::SourceLocation))
    PASTA_INSTANCE_METHOD_0(AttributedStmt, 607134768, 2, getAttrs, (llvm::ArrayRef<const clang::Attr *>))
    PASTA_INSTANCE_METHOD_0(AttributedStmt, 607134768, 3, getBeginLoc, (clang::SourceLocation))
    PASTA_INSTANCE_METHOD_0(AttributedStmt, 607134768, 4, getEndLoc, (clang::SourceLocation))
    PASTA_INSTANCE_METHOD_0(AttributedStmt, 607134768, 5, getSubStmt, (const clang::Stmt *))
  PASTA_END_METHODS(AttributedStmt, 607134768)

  PASTA_BEGIN_FIELDS(AttributedStmt, 607134768)
    PASTA_PRIVATE_INSTANCE_FIELD(AttributedStmt, 607134768, SubStmt, (clang::Stmt *))
  PASTA_END_FIELDS(AttributedStmt, 607134768)

  PASTA_BEGIN_CLASS_ENUMS(AttributedStmt, 607134768)
  PASTA_END_CLASS_ENUMS(AttributedStmt, 607134768)
PASTA_END_CLANG_WRAPPER(AttributedStmt, 607134768)
```

### Base classes (`PASTA_BEGIN_BASE_CLASSES` … `PASTA_END_BASE_CLASSES`)

```
PASTA_PUBLIC_BASE_CLASS(name, id, base_name, base_id)
```

One entry per public base. Non-public or non-AST bases are emitted as `// Skipped X` comments and ignored. A class with no public base (e.g. the four roots `Decl`, `Stmt`, `Type`, `Attr`) has an empty section.

### Methods (`PASTA_BEGIN_METHODS` … `PASTA_END_METHODS`)

Two macros, distinguished by arity (suffix `_N`):

```
PASTA_INSTANCE_METHOD_N(cls, id, meth_id, meth, (rt), (p0), (p1), …)
PASTA_OVERRIDE_METHOD_0(cls, id, meth_id, meth, (rt))
```

- `meth_id` is **per-class**, not global. It increments from 0 within each `PASTA_BEGIN_METHODS` block.
- `(rt)` and `(pN)` are parenthesized so their inner type strings can contain commas (`(std::optional<clang::NullabilityKind>)`, `(llvm::ArrayRef<const clang::Attr *>)`).
- `PASTA_OVERRIDE_METHOD_0` marks methods that override a virtual in a base; only the zero-arity form is emitted.

Distribution with LLVM 18.1.4:

| Macro | Count |
|---|---:|
| `PASTA_INSTANCE_METHOD_0` | 4,452 |
| `PASTA_INSTANCE_METHOD_1` | 633 |
| `PASTA_INSTANCE_METHOD_2` | 27 |
| `PASTA_INSTANCE_METHOD_3` | 5 |
| `PASTA_INSTANCE_METHOD_4` | 3 |
| `PASTA_INSTANCE_METHOD_5` | 3 |
| `PASTA_OVERRIDE_METHOD_0` | 52 |

`Globals.cpp:42` defines a `PASTA_INSTANCE_METHOD_6` macro but it is never emitted by stage 1. Either drop the definition or extend stage 1 to use it when a 6-argument Clang method appears.

### Fields (`PASTA_BEGIN_FIELDS` … `PASTA_END_FIELDS`)

Three visibility variants:

```
PASTA_INSTANCE_FIELD(cls, id, name, (type))            // public
PASTA_PROTECTED_INSTANCE_FIELD(cls, id, name, (type))
PASTA_PRIVATE_INSTANCE_FIELD(cls, id, name, (type))
```

Distribution: 5 / 34 / 1,095 — fields are overwhelmingly private. Type is parenthesized for the same comma-tolerance reason as method return types.

### Class-scoped enums (`PASTA_BEGIN_CLASS_ENUMS` … `PASTA_END_CLASS_ENUMS`)

```
PASTA_BEGIN_CLASS_NAMED_ENUM(cls, enum_name, (underlying))
  PASTA_CLASS_ENUMERATOR(value_name, (underlying), (numeric_value))
PASTA_END_CLASS_NAMED_ENUM(cls, enum_name)
```

Used for enums declared inside a Clang class (e.g. `AArch64SVEPcsAttr::Spelling`). Multiple `PASTA_BEGIN_CLASS_NAMED_ENUM` blocks may appear within a single `PASTA_BEGIN_CLASS_ENUMS` (e.g. `ARMInterruptAttr` declares both `InterruptType` and `Spelling`).

## Sibling artifact: `MethodMetadata.h`

Stage 1 (`bootstrap-macros`) emits a sibling X-macro file `bin/BootstrapTypes/MethodMetadata.h` parallel to `Generated.h`. It carries one entry per method already covered by `PASTA_INSTANCE_METHOD_*` / `PASTA_OVERRIDE_METHOD_*` and is consumed by the metadata-curation tooling (the planned `/pasta:curate-metadata` skill — Steps 13–15 of plan `snug-floating-finch`).

```c
PASTA_METHOD_METADATA(
    cls,                        // matches Generated.h's owning class
    meth_id,                    // matches Generated.h's per-class method id
    meth,                       // matches Generated.h's method name
    (return_type),              // canonical return type, parenthesized
    is_inline,                  // 0 or 1
    has_deprecated,             // 1 if [[deprecated]] / [[unavailable]]
    has_hidden_visibility,      // 1 if hidden-visibility attribute
    body_classification,        // SAFE | UNCONDITIONAL_ASSERT | CONDITIONAL_ASSERT | UNKNOWN
    "crash_predicate",          // for CONDITIONAL_ASSERT: guard expr text; "" otherwise
    "doxygen_text")             // raw doxygen comment, escaped as a C string literal
```

The `(meth_id, meth)` tuple is the join key into `Generated.h`. Consumers walk `Generated.h` and `MethodMetadata.h` in lockstep.

`body_classification` takes one of:

- `SAFE` — body present, no crash-equivalent calls reachable on any obvious path.
- `UNCONDITIONAL_ASSERT` — body's first reachable statement is a crash call (`assert`, `llvm_unreachable`, `report_fatal_error`, `__builtin_trap`, `__builtin_unreachable`, `abort`, or assert-macro post-expansion targets like `__assert_fail` / `__assert_rtn`). The wrapper should disable this method.
- `CONDITIONAL_ASSERT` — body crashes only when a guard predicate fails. `crash_predicate` is set to the textual condition under which it is **safe** to call (i.e., the wrapper should `return std::nullopt` when this predicate is false).
- `UNKNOWN` — no body available. Most non-trivial Clang methods are out-of-line (defined in `.cpp`, declared in headers); their bodies aren't visible to `bootstrap-macros`. Step 14 (`/pasta:curate-metadata` H7) treats `UNKNOWN` as "no signal" and falls back to other heuristics.

`MethodMetadata.h` follows the same default-macros pattern: a top-of-file `#include "DefineDefaultMacros.h"` (which provides a no-op default for `PASTA_METHOD_METADATA`) and a bottom `#include "UndefineDefaultMacros.h"`.

## Free named enums (file-level)

After the class blocks:

```
PASTA_BEGIN_NAMED_ENUM(name, (underlying))
  PASTA_NAMED_ENUMERATOR(value_name, (underlying), (numeric_value))
PASTA_END_NAMED_ENUM(name)
```

Same shape as class-scoped enums, but at file scope and using the `_NAMED_` (not `_CLASS_NAMED_`) variants.

## ID encoding

The numeric IDs (`id`, `base_id`, etc.) are 32-bit hashes of the class/method name, used at runtime for type dispatch. They're stable across regenerations as long as the name doesn't change. Two consequences:

- Renaming a Clang class changes its ID. PASTA's wrappers store IDs in generated tables (`gClassIDs`, the `kClassName_<id>` variables in `Globals.h`); consumers comparing IDs across LLVM versions must compare names too.
- Two different classes will not collide in practice (32-bit space, ~820 classes), but a future Clang version could in principle introduce a name that hashes to an existing ID. Stage 1 does not currently check for collisions.

## What is NOT in `Generated.h`

Three classes are referenced by other PASTA code but absent from `Generated.h`:

- `OMPDeclarativeDirectiveDecl`, `OMPDeclarativeDirectiveValueDecl` — synthesized intermediate templates used by `bin/BootstrapMacros/MacroGenerator.cpp`. Their existence in the inheritance graph is patched in via `kAdditionalExtends` in `Globals.cpp`.
- `ExceptionSpecification` — a PASTA-defined helper type (see `lib/AST/TypeManual.cpp`), not a Clang class. Hand-prepended to `kAllClassNames` and listed in `kCategorizationOptOut`.

`kAllClassNames` is therefore a superset of the names emitted by `Generated.h`.

## Consumer pattern

A typical consumer in `Globals.cpp`:

```cpp
const std::vector<llvm::StringRef> kAllClassNames{
  "OMPDeclarativeDirectiveDecl",
  "OMPDeclarativeDirectiveValueDecl",
  "ExceptionSpecification",
#define PASTA_BEGIN_CLANG_WRAPPER(name, id) PASTA_STR(name) ,
#include "Generated.h"
};
```

Only the macro of interest is overridden. Default expansions from `DefineDefaultMacros.h` make the rest a no-op. The consumer does not need to `#undef` afterward because each new `#include "Generated.h"` re-includes `DefineDefaultMacros.h`, which `#undef`s and redefines defaults.

## Maintainer checklist

When stage 1 (`bin/BootstrapMacros/`) is changed to emit a new schema element:

1. Update `DefineDefaultMacros.h` with a no-op default for the new macro.
2. Update this document with the macro's signature, semantics, and which sub-block it appears in.
3. Update consumers that should react (`Globals.cpp` tables, `Generate*.cpp` codegen).

When a Clang upgrade adds a new attribute kind, declaration, statement, etc., re-running stage 1 regenerates `Generated.h` automatically. No manual schema change is required for new instances of existing macro types.
