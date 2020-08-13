/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#
#include <string>
#include <pasta/Python/Bindings.h>

namespace pasta {
namespace py {
namespace convert {

PyObject *FromI8(int8_t v) {
  return PyLong_FromSsize_t(v);
}

PyObject *FromI16(int16_t v) {
  return PyLong_FromSsize_t(v);
}

PyObject *FromI32(int32_t v) {
  return PyLong_FromSsize_t(v);
}

PyObject *FromI64(int64_t v) {
  return PyLong_FromSsize_t(v);
}

PyObject *FromU8(uint8_t v) {
  return PyLong_FromSize_t(v);
}

PyObject *FromU16(uint16_t v) {
  return PyLong_FromSize_t(v);
}

PyObject *FromU32(uint32_t v) {
  return PyLong_FromSize_t(v);
}

PyObject *FromU64(uint64_t v) {
  return PyLong_FromSize_t(v);
}

PyObject *FromStdStr(const std::string &s) {
  PyErr_Clear();
  auto ret = ::PyUnicode_DecodeUTF8(
      s.data(), static_cast<Py_ssize_t>(s.size()), nullptr);
  if (ret && !PyErr_Occurred()) {
    return ret;
  }

  PyErr_Clear();
  ret = PyUnicode_DecodeLocaleAndSize(
      s.data(), static_cast<Py_ssize_t>(s.size()), nullptr);

  if (ret && !PyErr_Occurred()) {
    auto new_ret = PyUnicode_AsUTF8String(ret);
    Py_DECREF(ret);
    return new_ret;
  }

  PyErr_Clear();
  ret = PyUnicode_DecodeLatin1(
      s.data(), static_cast<Py_ssize_t>(s.size()), nullptr);

  if (ret && !PyErr_Occurred()) {
    auto new_ret = PyUnicode_AsUTF8String(ret);
    Py_DECREF(ret);
    return new_ret;
  }

  return PyBytes_FromStringAndSize(s.data(), s.size());
}

PyObject *FromBool(bool b) {
  PyObject *ret = b ? Py_True : Py_False;
  Py_INCREF(ret);
  return ret;
}

bool ToBool(PyObject *v, void *storage) {
  const auto ret = PyObject_IsTrue(v);
  if (-1 == ret) {
    return false;
  } else {
    *reinterpret_cast<bool *>(storage) = !!ret;
    return true;
  }
}

bool ToI32(PyObject *v, void *storage) {
  if (!PyLong_Check(v)) {
    return false;
  }

  int did_overflow = 0;
  const auto ret = PyLong_AsLongAndOverflow(v, &did_overflow);
  const auto ret_i32 = static_cast<int32_t>(ret);
  if (ret != ret_i32 || did_overflow) {
    return false;
  }

  *reinterpret_cast<int32_t *>(storage) = ret_i32;
  return true;
}

bool ToI64(PyObject *v, void *storage) {
  if (!PyLong_Check(v)) {
    return false;
  }

  int did_overflow = 0;
  const auto ret = PyLong_AsLongLongAndOverflow(v, &did_overflow);
  if (did_overflow) {
    return false;
  }

  *reinterpret_cast<int64_t *>(storage) = ret;
  return true;
}

bool ToU32(PyObject *v, void *storage) {
  if (!PyLong_Check(v)) {
    return false;
  }
  const auto ret = PyLong_AsUnsignedLong(v);
  const auto ret_u32 = static_cast<uint32_t>(ret);

  if (ret == ret_u32) {
    *reinterpret_cast<uint32_t *>(storage) = ret_u32;
    return true;
  } else {
    return false;
  }
}

bool ToU64(PyObject *v, void *storage) {
  if (!PyLong_Check(v)) {
    return false;
  } else {
    const auto ret = PyLong_AsUnsignedLongLong(v);
    *reinterpret_cast<uint64_t *>(storage) = ret;
    return true;
  }
}

bool ToStdStr(PyObject *v, void *storage) {
  if (PyBytes_Check(v)) {
    const auto size = PyBytes_Size(v);
    const auto data = PyBytes_AsString(v);
    (void) new (storage) std::string(data, &(data[size]));
    return true;

  } else if (PyUnicode_Check(v)) {
    auto utf8 = PyUnicode_AsUTF8String(v);
    if (!utf8) {
      return false;
    }

    char *data = nullptr;
    Py_ssize_t size = 0;
    if (PyBytes_AsStringAndSize(utf8, &data, &size)) {
      Py_DECREF(utf8);
      return false;
    }

    (void) new (storage) std::string(data, &(data[size]));
    Py_DECREF(utf8);
    return true;

  } else {
    return false;
  }
}

}  // namespace convert

PythonErrorStreamer::~PythonErrorStreamer(void) {
  PyErr_Clear();
  PyErr_SetString(exc, ss.str().c_str());
}

}  // namespace py
}  // namespace pasta
