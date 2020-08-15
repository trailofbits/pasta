/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <cstdint>
#include <cstring>
#include <memory>
#include <new>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-register"
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#pragma clang diagnostic pop

#if PY_MAJOR_VERSION < 3
#  error "Minimum Python version is 3.0"
#endif

namespace pasta {
namespace py {

// The backing storage for a type `T` is usually `T` itself, but in the case of
// a `std::string_view`, we might need a view into a temporarily-allocated
// Python string, and so if that backing Python object disappears then the
// string view will access undefined memory, so we need to provide a mechanism
// to back the string view with proper storage for itself.
template <typename T>
struct StorageType {
 public:
  using Type = T;
};

struct StringView : public std::string_view {
  StringView(void) = default;

  template <typename T>
  StringView(T data_) : data(data_) {}

  std::string data;
};

template <>
struct StorageType<std::string_view> {
 public:
  using Type = StringView;
};

// A wrapper around an enumeration type that lets us convert to/from its
// underlying representation type.
template <typename T, typename ReprType>
class EnumWrapper {
 public:
  inline EnumWrapper(void) : val(static_cast<T>(ReprType{})) {}

  inline EnumWrapper(T val_) : val(val_) {}

  inline EnumWrapper(ReprType val_) : val(static_cast<T>(val_)) {}

  inline operator ReprType(void) const {
    return static_cast<ReprType>(val);
  }

  inline operator T(void) const {
    return static_cast<T>(val);
  }

  inline EnumWrapper<T, ReprType> &operator=(T val_) {
    val = val_;
    return *this;
  }

  inline EnumWrapper<T, ReprType> &operator=(ReprType val_) {
    val = static_cast<T>(val_);
    return *this;
  }

  T val;
};

namespace convert {

PyObject *FromI8(int8_t);
PyObject *FromI16(int16_t);
PyObject *FromI32(int32_t);
PyObject *FromI64(int64_t);

PyObject *FromU8(uint8_t);
PyObject *FromU16(uint16_t);
PyObject *FromU32(uint32_t);
PyObject *FromU64(uint64_t);

PyObject *FromStdStr(const std::string &);
PyObject *FromStdStrView(const std::string_view &);
PyObject *FromStringView(const StringView &);

PyObject *FromBool(bool);

bool ToBool(PyObject *, void *);

bool ToI32(PyObject *, void *);
bool ToI64(PyObject *, void *);

bool ToU32(PyObject *, void *);
bool ToU64(PyObject *, void *);

bool ToStdStr(PyObject *v, void *storage);
bool ToStdStrView(PyObject *v, void *storage);

}  // namespace convert

template <typename T>
class PythonObject;

template <typename T>
class NativeXPython;

template <>
class NativeXPython<void> {};

template <typename T>
class NativeXPython<const T &> : public NativeXPython<T> {};

template <>
class NativeXPython<bool> {
 public:
  static constexpr auto ToPython = convert::FromBool;
  static constexpr auto ToCxx = convert::ToBool;
};

template <>
class NativeXPython<int32_t> {
 public:
  static constexpr auto ToPython = convert::FromI32;
  static constexpr auto ToCxx = convert::ToI32;
};

template <>
class NativeXPython<int64_t> {
 public:
  static constexpr auto ToPython = convert::FromI64;
  static constexpr auto ToCxx = convert::ToI64;
};

template <>
class NativeXPython<uint32_t> {
 public:
  static constexpr auto ToPython = convert::FromU32;
  static constexpr auto ToCxx = convert::ToU32;
};

template <>
class NativeXPython<uint64_t> {
 public:
  static constexpr auto ToPython = convert::FromU64;
  static constexpr auto ToCxx = convert::ToU64;
};

template <>
class NativeXPython<std::string> {
 public:
  static constexpr auto ToPython = convert::FromStdStr;
  static constexpr auto ToCxx = convert::ToStdStr;
};

template <>
class NativeXPython<std::string_view> {
 public:
  static constexpr auto ToPython = convert::FromStdStrView;
  static constexpr auto ToCxx = convert::ToStdStrView;
};

template <>
class NativeXPython<StringView> {
 public:
  static constexpr auto ToPython = convert::FromStringView;
  static constexpr auto ToCxx = convert::ToStdStrView;
};

template <typename T, typename ReprType>
class NativeXPython<EnumWrapper<T, ReprType>> : public NativeXPython<ReprType> {
};

template <typename T>
class NativeXPython : public NativeXPython<typename std::conditional<
                          !std::is_same_v<typename StorageType<T>::Type, T>,
                          typename StorageType<T>::Type, void>::type> {};

class PythonErrorStreamer {
 public:
  explicit PythonErrorStreamer(PyObject *exc_) : exc(exc_) {}

  ~PythonErrorStreamer(void);

  template <typename T>
  inline PythonErrorStreamer &operator<<(const T &val) {
    ss << val;
    return *this;
  }

 private:
  PythonErrorStreamer(void) = delete;

  PyObject *const exc;
  std::stringstream ss;
};


template <typename T>
class BorrowedPythonPtr;

// Represents a held reference to a Python object.
template <typename T>
class SharedPythonPtr {
 public:
  friend class BorrowedPythonPtr<T>;

  template <typename D>
  friend class SharedPythonPtr;

  ~SharedPythonPtr(void) {
    Py_XDECREF(obj);
  }

  SharedPythonPtr(void) : obj(nullptr) {}

  SharedPythonPtr(std::nullptr_t) : obj(nullptr) {}

  SharedPythonPtr(T *that) : obj(that) {
    Py_XINCREF(obj);
  }

  template <typename D>
  SharedPythonPtr(D *that) : obj(reinterpret_cast<T *>(that)) {
    Py_XINCREF(obj);
    static_assert(std::is_convertible_v<D *, T *>);
  }

  SharedPythonPtr(const SharedPythonPtr<T> &that) : obj(that.obj) {
    Py_XINCREF(obj);
  }

  template <typename D>
  SharedPythonPtr(const SharedPythonPtr<D> &that)
      : obj(reinterpret_cast<T *>(that.obj)) {
    static_assert(std::is_convertible_v<D *, T *>);
    Py_XINCREF(obj);
  }

  SharedPythonPtr(SharedPythonPtr<T> &&that) noexcept : obj(that.obj) {
    that.obj = nullptr;
  }

  template <typename D>
  SharedPythonPtr(SharedPythonPtr<D> &&that) noexcept
      : obj(reinterpret_cast<T *>(that.obj)) {
    static_assert(std::is_convertible_v<D *, T *>);
    that.obj = nullptr;
  }

  SharedPythonPtr<T> &operator=(const SharedPythonPtr<T> &that) {
    Py_XINCREF(that.obj);
    Py_XDECREF(obj);
    obj = that.obj;
    return *this;
  }

  template <typename D>
  SharedPythonPtr<T> &operator=(const SharedPythonPtr<D> &that) {
    static_assert(std::is_convertible_v<D *, T *>);
    auto that_obj = reinterpret_cast<T *>(that.obj);
    Py_XINCREF(that_obj);
    Py_XDECREF(obj);
    obj = that_obj;
    return *this;
  }

  SharedPythonPtr<T> &operator=(SharedPythonPtr<T> &&that) noexcept {
    const auto that_obj = that.obj;
    Py_XINCREF(that_obj);
    Py_XDECREF(obj);
    that.obj = nullptr;
    obj = that_obj;
    return *this;
  }

  template <typename D>
  SharedPythonPtr<T> &operator=(SharedPythonPtr<D> &&that) noexcept {
    static_assert(std::is_convertible_v<D *, T *>);
    const auto that_obj = reinterpret_cast<T *>(that.obj);
    Py_XINCREF(that_obj);
    Py_XDECREF(obj);
    that.obj = nullptr;
    obj = that_obj;
    return *this;
  }

  SharedPythonPtr<T> &operator=(T *that) {
    Py_XINCREF(that);
    Py_XDECREF(obj);
    obj = that;
    return *this;
  }

  template <typename D>
  SharedPythonPtr<T> &operator=(D *that_) {
    static_assert(std::is_convertible_v<D *, T *>);
    auto that = reinterpret_cast<T *>(that_);
    Py_XINCREF(that);
    Py_XDECREF(obj);
    obj = that;
    return *this;
  }

  T *Get(void) const {
    return obj;
  }

  // Steal a reference.
  void Take(T *that) {
    Py_XDECREF(obj);
    obj = that;
  }

  operator bool(void) const {
    return obj != nullptr;
  }

  T *operator->(void) const {
    return obj;
  }

  T &operator*(void) const {
    return *obj;
  }

  // Get a copy of the pointer. The reference count is incremented.
  BorrowedPythonPtr<T> Borrow(void) const;

  // Release ownership of this owned pointer. The reference count is not
  // decremented.
  BorrowedPythonPtr<T> Release(void);

 private:
  T *obj;
};

// Wraps a pointer to a Python object. No reference counting operations are
// performed by the constructors or destructor. The implied meaning is that
// any Python object that is addressable via this object has a reference count
// of at least one.
template <typename T>
class BorrowedPythonPtr {
 public:
  friend class SharedPythonPtr<T>;

  template <typename D>
  friend class BorrowedPythonPtr;

  using Type = T;

  ~BorrowedPythonPtr(void) {}

  BorrowedPythonPtr(void) : obj(nullptr) {}

  BorrowedPythonPtr(std::nullptr_t) : obj(nullptr) {}

  BorrowedPythonPtr(T *that) : obj(that) {}

  template <typename D>
  BorrowedPythonPtr(D *that) : obj(reinterpret_cast<T *>(that)) {
    static_assert(std::is_convertible_v<D *, T *>);
  }

  BorrowedPythonPtr(BorrowedPythonPtr<T> &&that) noexcept : obj(that.obj) {}

  BorrowedPythonPtr(const BorrowedPythonPtr<T> &that) : obj(that.obj) {}

  template <typename D>
  BorrowedPythonPtr(BorrowedPythonPtr<D> &&that) noexcept
      : obj(reinterpret_cast<T *>(that.obj)) {
    static_assert(std::is_convertible_v<D *, T *>);
  }

  template <typename D>
  BorrowedPythonPtr(const BorrowedPythonPtr<D> &that) noexcept
      : obj(reinterpret_cast<T *>(that.obj)) {
    static_assert(std::is_convertible_v<D *, T *>);
  }

  T *Get(void) const {
    return obj;
  }

  operator bool(void) const {
    return obj != nullptr;
  }

  T *operator->(void) const {
    return obj;
  }

  T &operator*(void) const {
    return *obj;
  }

  SharedPythonPtr<T> Acquire(void) const {
    return obj;
  }

  SharedPythonPtr<T> Give(void) {
    SharedPythonPtr<T> p;
    p.Take(obj);
    obj = nullptr;
    return p;
  }

 private:
  BorrowedPythonPtr<T> &operator=(BorrowedPythonPtr<T> &&) noexcept = delete;
  BorrowedPythonPtr<T> &operator=(const BorrowedPythonPtr<T> &) = delete;

  T *obj;
};

template <typename T>
BorrowedPythonPtr<T> SharedPythonPtr<T>::Borrow(void) const {
  Py_XINCREF(obj);
  return obj;
}

template <typename T>
BorrowedPythonPtr<T> SharedPythonPtr<T>::Release(void) {
  auto ret = obj;
  obj = nullptr;
  return ret;
}

template <typename T>
static constexpr bool kIsBorrowedPythonPtr = false;

template <typename T>
static constexpr bool kIsBorrowedPythonPtr<BorrowedPythonPtr<T>> = true;

template <typename T>
static constexpr bool kIsBorrowedPythonPtr<BorrowedPythonPtr<T> &> = true;

template <typename T>
static constexpr bool kIsBorrowedPythonPtr<const BorrowedPythonPtr<T> &> = true;

template <typename T>
static constexpr bool kIsBorrowedPythonPtr<BorrowedPythonPtr<T> &&> = true;

template <typename T>
static constexpr bool kIsBorrowedPythonPtr<T *> =
    std::is_convertible_v<T *, PyObject *>;

inline static PyObject *ReleaseBorrowedPythonPtr(PyObject *ptr) {
  return ptr;
}

template <typename T>
inline static PyObject *ReleaseBorrowedPythonPtr(BorrowedPythonPtr<T> ptr) {
  return ptr.Get();
}

// Base type of a python object.
class PythonObjectBase : public PyObject {
 public:
  inline PyObject *BorrowSelf(void) {
    return this;
  }

  inline PyObject *ReferenceSelf(void) {
    Py_INCREF(this);
    return this;
  }
};

// A simple Python wrapper around a class of type `T`. Derived classes can
// access the `self` pointer via the `Self()` method, and they can also throw
// errors via streaming into `Error()`.
template <typename T>
class PythonObject : public PythonObjectBase {
 public:
  PythonObject(void) = default;

  // Used to heap allocate a Python object.
  template <typename... Args>
  static BorrowedPythonPtr<T> New(Args &&... args);

  void operator delete(void *self);

  static PyTypeObject gType;

 protected:
  // Implements the `__init__` method. This calls `T`s constructor.
  static int PyInit(PyObject *self_, PyObject *args, PyObject *kargs);
  static PyObject *PyAlloc(PyTypeObject *type, Py_ssize_t num_items);
  static PyObject *PyNew(PyTypeObject *type, PyObject *args, PyObject *kwargs);
  static void PyDealloc(PyObject *self_);
};

template <typename T>
PyTypeObject PythonObject<T>::gType = {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc99-extensions"
    .tp_basicsize = sizeof(T),
    .tp_init = PyInit,
    .tp_alloc = PyAlloc,
    .tp_new = PyNew,
    .tp_dealloc = PyDealloc,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    .tp_base = &PyBaseObject_Type
#pragma clang diagnostic pop
};

// Try to marshal values of type `T` to a python object.
template <typename T>
inline static PyObject *ConvertToPythonObject(T val) {
  if constexpr (kIsBorrowedPythonPtr<T>) {
    const auto ptr = ReleaseBorrowedPythonPtr(val);
    if (PyErr_Occurred()) {
      Py_XDECREF(ptr);
      return nullptr;
    } else if (!ptr) {
      Py_RETURN_NONE;
    } else {
      return ptr;
    }

  } else if (PyErr_Occurred()) {
    return nullptr;

  } else {
    return NativeXPython<T>::ToPython(val);
  }
}

template <typename T>
inline static T *ConvertFromPythonObject(PyObject *obj, void *storage) {
  if constexpr (std::is_same_v<T, PyObject *>) {
    return new (storage) T(reinterpret_cast<T>(obj));

  } else if constexpr (std::is_convertible_v<T, PythonObjectBase *>) {
    using BaseType = typename std::remove_pointer<T>::type;
    if (PyObject_TypeCheck(obj, &(BaseType::gType))) {
      return new (storage) T(reinterpret_cast<T>(obj));
    } else {
      return nullptr;
    }

  } else if constexpr (kIsBorrowedPythonPtr<T>) {
    using BaseType = typename T::Type;
    if (PyObject_TypeCheck(obj, &(BaseType::gType))) {
      return new (storage) T(reinterpret_cast<BaseType *>(obj));
    } else {
      return nullptr;
    }

  } else if (NativeXPython<T>::ToCxx(obj, storage)) {
    return reinterpret_cast<T *>(storage);

  } else {
    return nullptr;
  }
}

// A positional argument to a Python-exposed function.
template <typename T>
class PythonArg {
 public:
  using SelfType = PythonArg<T>;
  using StoreT = typename StorageType<T>::Type;

  PythonArg(void) = default;

  ~PythonArg(void) {
    Reset();
  }

  PythonArg(const SelfType &that) : owned_pimpl(nullptr), pimpl(that.pimpl) {}

  PythonArg(SelfType &&that) noexcept
      : owned_pimpl(that.owned_pimpl
                        ? new (impl) StoreT(std::move(*(that.owned_pimpl)))
                        : nullptr),
        pimpl(that.owned_pimpl ? owned_pimpl : that.pimpl) {
    that.Reset();
  }

  PythonArg(T &val) : owned_pimpl(nullptr), pimpl(&val) {}

  PythonArg(const T &val) : owned_pimpl(nullptr), pimpl(&val) {}

  PythonArg(T &&val) noexcept
      : owned_pimpl(new (impl) StoreT(std::forward<T>(val))),
        pimpl(owned_pimpl) {}

  template <typename... Args>
  PythonArg(Args &&... args)
      : owned_pimpl(new (impl) StoreT(std::forward<Args>(args)...)),
        pimpl(owned_pimpl) {}

  PythonArg &operator=(const SelfType &that) {
    if (this != &that) {
      Reset();
      pimpl = that.pimpl;
    }
    return *this;
  }

  PythonArg &operator=(SelfType &&that) noexcept {
    if (this != &that) {
      Reset();
      if (that.owned_pimpl) {
        owned_pimpl = new (impl) StoreT(std::move(*(that.owned_pimpl)));
        pimpl = owned_pimpl;
        that.Reset();
      } else {
        pimpl = that.pimpl;
      }
    }
    return *this;
  }

  inline operator bool(void) const {
    return pimpl != &kDefaultVal;
  }

  inline const StoreT &operator*(void) const {
    return *pimpl;
  }

  inline const T *operator->(void) const {
    return pimpl;
  }

  inline bool Parse(PyObject *py_obj) {
    Reset();
    if (auto new_owned_pimpl = ConvertFromPythonObject<T>(py_obj, impl);
        new_owned_pimpl) {
      owned_pimpl = reinterpret_cast<StoreT *>(new_owned_pimpl);
      pimpl = owned_pimpl;
      return true;
    } else {
      pimpl = &kDefaultVal;
      return false;
    }
  }

  static const char *Name(void) {
    return "<unnamed>";
  }

  static const char *Keyword(void) {
    return nullptr;
  }

 private:
  void Reset(void) {
    if (owned_pimpl) {
      if constexpr (std::is_destructible_v<StoreT> &&
                    !std::is_trivially_destructible_v<StoreT>) {
        owned_pimpl->~StoreT();
      }
      owned_pimpl = nullptr;
    }
    pimpl = &kDefaultVal;
  }

  alignas(StoreT) uint8_t impl[sizeof(StoreT)];
  StoreT *owned_pimpl{nullptr};
  const StoreT *pimpl{&kDefaultVal};

  static const StoreT kDefaultVal;
};

template <typename T>
const typename StorageType<T>::Type PythonArg<T>::kDefaultVal = {};

namespace detail {

template <size_t N>
struct num {
  static const constexpr auto value = N;
};

template <class F, size_t... Is>
inline void for_(F func, std::index_sequence<Is...>) {
  using expander = int[];
  (void) expander{0, ((void) func(num<Is>{}), 0)...};
}

template <size_t N, typename F>
inline void for_(F func) {
  for_(func, std::make_index_sequence<N>());
}

}  // namespace detail

// Extract the Python arguments into individual `PyObject *` pointers
// corresponding with function's arguments.
template <typename Details, typename... Args>
static bool TryParsePythonArguments(PyObject *args, PyObject *kargs,
                                    std::tuple<Args...> &parsed_args) {

  PyObject *py_args[sizeof...(Args)] = {};

  int num_positionals = 0;
  int num_kwargs = 0;
  int max_num_kwargs = 0;
  int min_num_positionals = 0;
  const auto max_num_positionals = static_cast<int>(sizeof...(Args));

  // Figure out the minimum number of positional arguments needed.
  detail::for_<sizeof...(Args)>([&](auto i) {
    auto &arg_spec = std::get<i.value>(parsed_args);
    if (!arg_spec.Keyword()) {
      ++min_num_positionals;
    } else {
      ++max_num_kwargs;
    }
  });

  // Extract the keyword arguments.
  if (kargs && PyDict_Check(kargs)) {
    Py_ssize_t i = 0;
    PyObject *karg_key = nullptr;
    PyObject *karg_value = nullptr;

    num_kwargs = static_cast<int>(PyDict_Size(kargs));
    if (num_kwargs > max_num_kwargs) {
      PyErr_Format(
          PyExc_TypeError,
          "Too many keyword arguments passed to %s.%s(); got %d, expected at most %d",
          Details::kClassName, Details::kMethodName, num_kwargs,
          max_num_kwargs);
      return false;
    }

    while (PyDict_Next(kargs, &i, &karg_key, &karg_value)) {
      if (!PyUnicode_Check(karg_key)) {
        PyErr_Format(PyExc_TypeError,
                     "%s.%s() passed non-string keyword argument key",
                     Details::kClassName, Details::kMethodName);
        return false;
      }

      auto utf8 = PyUnicode_AsUTF8String(karg_key);
      if (!utf8) {
        PyErr_Format(PyExc_TypeError,
                     "%s.%s() passed non-utf8 keyword argument key",
                     Details::kClassName, Details::kMethodName);
        return false;
      }

      char *karg_key_data = nullptr;
      Py_ssize_t karg_key_size = 0;
      if (PyBytes_AsStringAndSize(utf8, &karg_key_data, &karg_key_size)) {
        Py_DECREF(utf8);
        return false;
      }

      // Go see if we can find this keyword argument in our argument list.
      auto found = false;
      detail::for_<sizeof...(Args)>([&](auto i) {
        if (!py_args[i.value]) {
          auto &arg_spec = std::get<i.value>(parsed_args);
          if (const char *kw = arg_spec.Keyword()) {
            if (!strncmp(kw, karg_key_data,
                         static_cast<size_t>(karg_key_size))) {
              py_args[i.value] = karg_value;
              found = true;
            }
          }
        }
      });

      if (max_num_kwargs && !found) {
        PyErr_Format(PyExc_TypeError,
                     "'%s' is an invalid keyword argument for %s.%s()",
                     karg_key_data, Details::kClassName, Details::kMethodName);
        Py_DECREF(utf8);
        return false;
      }

      Py_DECREF(utf8);
    }
  }

  // Then collect the positional and keyword arguments in the order
  // that they appear.
  ssize_t j = 0;
  if (args && PyTuple_Check(args)) {
    if (auto num_args = PyTuple_Size(args)) {

      // Make sure we don't get too many positionals.
      if (num_args > (max_num_positionals - num_kwargs)) {
        PythonErrorStreamer(PyExc_TypeError)
            << Details::kClassName << "." << Details::kMethodName << "()"
            << " expected at most " << max_num_positionals
            << " positional arguments; got " << num_args << " positionals"
            << " and " << num_kwargs << " keyword arguments";
        return false;
      }

      detail::for_<sizeof...(Args)>([&](auto i) {
        if (!py_args[i.value]) {
          if (auto arg_val = PyTuple_GetItem(args, j++)) {
            py_args[i.value] = arg_val;
            num_positionals++;
          }
        }
      });
    }
  }

  PyErr_Clear();

  // Next, make sure that all positionals are covered.
  if (num_positionals < min_num_positionals) {
    PyErr_Format(PyExc_TypeError,
                 "%s.%s() expected at least %d positional arguments; got %d",
                 Details::kClassName, Details::kMethodName, min_num_positionals,
                 num_positionals);
    return false;
  }

  // Now try to parse each argument, and error out on the first issue.
  auto error = false;
  detail::for_<sizeof...(Args)>([&](auto i) {
    auto &arg_parser = std::get<i.value>(parsed_args);
    if (!error && py_args[i.value] && !arg_parser.Parse(py_args[i.value])) {
      PyErr_Clear();
      PyErr_Format(PyExc_TypeError,
                   "Invalid type '%s' passed to argument %s of method %s.%s()",
                   _PyType_Name(py_args[i.value]->ob_type), arg_parser.Name(),
                   Details::kClassName, Details::kMethodName);
      error = true;
    }
  });

  return !error;
}

// A wrapper for a specific method.
template <typename Details, typename Ret, typename T, typename... Args>
class PythonMethodWrapper {
 public:
  static PyObject *StaticMethod(PyObject *self_, PyObject *args,
                                PyObject *kwargs) {
    if (!PyObject_TypeCheck(self_, &T::gType)) {
      PyErr_Format(
          PyExc_TypeError, "Cannot call method %s.%s() with object of type %s",
          Details::kClassName, Details::kMethodName, self_->ob_type->tp_name);
    }

    auto self = reinterpret_cast<T *>(self_);
    auto ret = Py_None;

    auto callable = [self](Args... args) -> Ret {
      const auto method_ptr = Details::MethodPointer();
      return (self->*method_ptr)(std::forward<Args>(args)...);
    };

    // If the method takes any arguments, then parse them.
    if constexpr (0 < sizeof...(Args)) {
      std::tuple<Args...> native_args;
      if (!TryParsePythonArguments<Details>(args, kwargs, native_args)) {
        return nullptr;
      }

      if constexpr (std::is_same_v<Ret, void>) {
        std::apply(callable, native_args);
        Py_INCREF(ret);
      } else {
        ret = ConvertToPythonObject(std::apply(callable, native_args));
      }

    // If the method doesn't take any arguments, then call the method.
    } else {
      auto num_args = args && PyTuple_Check(args) ? PyTuple_Size(args) : 0;
      auto num_kwargs = args && PyDict_Check(args) ? PyDict_Size(args) : 0;
      if (num_args + num_kwargs) {
        PyErr_Format(
            PyExc_TypeError,
            "method %s.%s() does not take any arguments, but %d positional and "
            "%d keyword arguments were given",
            Details::kClassName, Details::kMethodName,
            static_cast<int>(num_args), static_cast<int>(num_kwargs));
        return nullptr;
      }

      if constexpr (std::is_same_v<Ret, void>) {
        callable();
        Py_INCREF(ret);
      } else {
        ret = ConvertToPythonObject(callable());
      }
    }

    if (!PyErr_Occurred()) {
      return ret;
    }

    if (ret) {
      Py_DECREF(ret);
    }

    return nullptr;
  }
};

// Type of a method object: takes in a `self` pointer, an argument tuple, and
// a keyword argument list.
typedef PyObject *(PythonMethodType)(PyObject * /* self */,
                                     PyObject * /* args */,
                                     PyObject * /* kwargs */);

// Return the pointer to the static dispatcher, and ensure that the dispatcher's
// `gMethod` static field is initialized.
template <typename Details, typename T, typename Ret, typename... Args>
static constexpr PythonMethodType *PythonMethod(Ret (T::*)(Args...)) {
  static_assert(
      std::is_convertible_v<T *, PythonObjectBase *>,
      "Invalid use of PythonMethod on a non-PythonObjectBase method name");

  using Wrapper = PythonMethodWrapper<Details, Ret, T, Args...>;
  return &Wrapper::StaticMethod;
}

// Wrapper around an exposed `__init__` method. The main thing this does
// is check if the exposed `__init__` returned an error, and if so, converts
// it to an integer.
template <typename T>
int PythonObject<T>::PyInit(PyObject *self, PyObject *args, PyObject *kargs) {
  uint8_t stashed_head[sizeof(PythonObjectBase)];
  memcpy(&(stashed_head), self, sizeof(stashed_head));
  T::__init__(self, args, kargs);
  memcpy(self, &(stashed_head[0]), sizeof(stashed_head));
  return PyErr_Occurred() ? -1 : 0;
}

// Allocates the object.
template <typename T>
PyObject *PythonObject<T>::PyAlloc(PyTypeObject *type, Py_ssize_t num_items) {
  auto size = _PyObject_VAR_SIZE(type, num_items + 1);
  auto self = reinterpret_cast<PyObject *>(PyObject_MALLOC(size));
  if (!self) {
    return PyErr_NoMemory();
  }
  memset(self, 0, size);
  (void) PyObject_INIT(self, type);
  return self;
}

template <typename T>
PyObject *PythonObject<T>::PyNew(PyTypeObject *type, PyObject *args,
                                 PyObject *kwargs) {
  return type->tp_alloc(type, 0);
}

// Destroys the object.
template <typename T>
void PythonObject<T>::PyDealloc(PyObject *self_) {
  auto self = reinterpret_cast<T *>(self_);
  self->~T();
  PyObject_Free(self);
}

template <typename T>
void PythonObject<T>::operator delete(void *self) {
  Py_DECREF(reinterpret_cast<T *>(self));
}

// Used to heap allocate a Python object.
template <typename T>
template <typename... Args>
BorrowedPythonPtr<T> PythonObject<T>::New(Args &&... args) {
  auto self = PyAlloc(&T::gType, 0);
  uint8_t stashed_head[sizeof(PythonObjectBase)];
  memcpy(&(stashed_head), self, sizeof(stashed_head));
  auto ret = new (self) T(std::forward<Args>(args)...);
  memcpy(self, &(stashed_head[0]), sizeof(stashed_head));
  if (PyErr_Occurred()) {
    Py_DECREF(self);
    return nullptr;
  } else {
    return ret;
  }
}

// Wrap an instance method in a static static dispatcher that can downcast
// the `self` pointer to the correct type then invoke the method. We create
// tag type in place to make sure each method is given its own dispatcher.
#define DEFINE_PYTHON_METHOD(class, method, py_method) \
  struct py_method##_details { \
    static constexpr char kClassName[] = #class; \
    static constexpr char kMethodName[] = #py_method; \
    static auto MethodPointer(void) -> decltype(&class ::method) { \
      return &class ::method; \
    } \
  }; \
  static constexpr auto py_method = \
      PythonMethod<py_method##_details>(&class ::method)

#define PYTHON_METHOD(py_method, doc) \
  { \
#    py_method, reinterpret_cast < PyCFunction>(py_method), \
        (METH_VARARGS | METH_KEYWORDS), doc \
  }

#define PYTHON_METHOD_SENTINEL \
  { nullptr, nullptr, 0, nullptr }

#define DEFINE_PYTHON_ARG(name, ...) \
  struct name##_arg : public PythonArg<__VA_ARGS__> { \
    using PythonArg<__VA_ARGS__>::PythonArg; \
    static const char *Name(void) { \
      return #name; \
    } \
    static const char *Keyword(void) { \
      return nullptr; \
    } \
  }

#define DEFINE_PYTHON_KWARG(name, ...) \
  struct name##_kwarg : public PythonArg<__VA_ARGS__> { \
    using PythonArg<__VA_ARGS__>::PythonArg; \
    static const char *Name(void) { \
      return #name; \
    } \
    static const char *Keyword(void) { \
      return #name; \
    } \
  }

template <typename Constructor, typename TypeToConstruct,
          typename... ConstructorArgs>
class ConstructorInvoker {
 public:
  // Super sketchy ;-)
  void Invoke(ConstructorArgs &&... args) {
    new (this) TypeToConstruct(std::forward<ConstructorArgs>(args)...);
  }
};

template <typename Details, typename BaseType, typename... ConstructorArgs>
class PythonConstructorWrapper
    : public PythonMethodWrapper<Details, void, BaseType, ConstructorArgs...> {
};

// Return the pointer to the static dispatcher, and ensure that the dispatcher's
// `gMethod` static field is initialized.
template <typename Details, typename BaseType, typename... Args>
static constexpr PythonMethodType *PythonConstructor(void (*)(Args...)) {
  using Wrapper = PythonConstructorWrapper<Details, BaseType, Args...>;
  return &Wrapper::StaticMethod;
}

template <typename Constructor, typename TypeToConstruct,
          typename... ConstructorArgs>
inline static ConstructorInvoker<Constructor, TypeToConstruct,
                                 ConstructorArgs...>
ConstructorInvokerType(void (*)(ConstructorArgs...));

template <typename BaseType, typename T, typename... Args>
auto RebasePythonConstructorMethodPointer(void (T::*method_ptr)(Args...))
    -> void (BaseType::*)(Args...) {
  return reinterpret_cast<void (BaseType::*)(Args...)>(method_ptr);
}

#define DEFINE_PYTHON_CONSTRUCTOR(type, ...) \
  struct Constructor { \
    static void Prototype(__VA_ARGS__) {} \
  }; \
  using CIT = decltype( \
      ConstructorInvokerType<Constructor, type>(Constructor::Prototype)); \
  struct ConstructorDetails { \
    static constexpr char kClassName[] = #type; \
    static constexpr char kMethodName[] = "__init__"; \
    static constexpr auto kMethodPtr = &CIT::Invoke; \
    static auto MethodPointer(void) -> decltype( \
        RebasePythonConstructorMethodPointer<type>(&CIT::Invoke)) { \
      return RebasePythonConstructorMethodPointer<type>(&CIT::Invoke); \
    } \
  }; \
  static constexpr auto __init__ = \
      PythonConstructor<ConstructorDetails, type>(&Constructor::Prototype); \
  type(__VA_ARGS__)

}  // namespace py
}  // namespace pasta
