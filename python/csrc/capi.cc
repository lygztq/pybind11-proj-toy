#include "pybind11/pybind11.h"
#include "toy.h"

namespace py = pybind11;

PYBIND11_MODULE(pytoy_capi, m) {
  m.doc() = R"pbdoc(
    Toy: example project
    -----------------------------------------

    .. currentmodule:: toy

    .. autosummary::
      :toctree: __generate
  )pbdoc";

  m.def("sigmoid", &sigmoid);
}
