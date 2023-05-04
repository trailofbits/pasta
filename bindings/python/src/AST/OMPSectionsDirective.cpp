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

void RegisterOMPSectionsDirective(py::module_ &m) {
  py::class_<OMPSectionsDirective, OMPExecutableDirective, Stmt>(m, "OMPSectionsDirective")
    .def("__hash__", [](const OMPSectionsDirective& stmt) { return (intptr_t)stmt.RawStmt(); })
    .def("__eq__", [](const OMPSectionsDirective& a, const OMPSectionsDirective& b) { return a.RawStmt() == b.RawStmt(); })
    .def_property_readonly("TaskReductionReferenceExpression", &OMPSectionsDirective::TaskReductionReferenceExpression)
    .def_property_readonly("HasCancel", &OMPSectionsDirective::HasCancel);
}
} // namespace pasta
