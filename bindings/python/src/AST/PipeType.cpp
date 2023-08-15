/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include "../Bindings.h"

namespace pasta {
namespace nb = nanobind;

void RegisterPipeType(nb::module_ &m) {
  nb::class_<PipeType, Type>(m, "PipeType")
    .def("__hash__", [](const PipeType &type) { return (intptr_t)type.RawType(); })
    .def("__eq__", [](const Type &a, const Type &b) { return a.RawType() == b.RawType(); })
    .def_prop_ro("desugar", &PipeType::Desugar)
    .def_prop_ro("element_type", &PipeType::ElementType)
    .def_prop_ro("is_read_only", &PipeType::IsReadOnly)
    .def_prop_ro("is_sugared", &PipeType::IsSugared);
}
} // namespace pasta
