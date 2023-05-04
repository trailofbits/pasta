/*
 * Copyright (c) 2023 Trail of Bits, Inc.
 */

// This file is auto-generated.

#include <pasta/AST/AST.h>
#include <pasta/AST/Attr.h>
#include <pasta/AST/Decl.h>
#include <pasta/AST/Stmt.h>
#include <pasta/AST/Type.h>

#include <pybind11/pybind11.h>

namespace pasta {
namespace py = pybind11;

void RegisterOMPParallelSectionsDirective(py::module_ &m) {
  py::class_<OMPParallelSectionsDirective, OMPExecutableDirective, Stmt>(m, "OMPParallelSectionsDirective")
    .def("__hash__", [](const OMPParallelSectionsDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPParallelSectionsDirective& a, const OMPParallelSectionsDirective& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("TaskReductionReferenceExpression", &OMPParallelSectionsDirective::TaskReductionReferenceExpression)
    .def_property_readonly("HasCancel", &OMPParallelSectionsDirective::HasCancel);
}
} // namespace pasta
