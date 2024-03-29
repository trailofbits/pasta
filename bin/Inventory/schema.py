# Copyright (c) 2023 Trail of Bits, Inc., all rights reserved.

from abc import ABC, abstractmethod
from typing import Dict, List, Optional

import os

class Schema(ABC):
  """Abstract schema."""

  def __str__(self) -> str:
    return self.__class__.__name__[:-6]  # `-len("Schema")`.

  @property
  @abstractmethod
  def python_value_name(self):
    ...

  @property
  @abstractmethod
  def cxx_value_name(self):
    ...

  @property
  def cxx_name(self):
    return self.cxx_value_name
  


class NamedSchema(Schema, ABC):
  """Represents a schema for something with a name."""
  name: str

  def __init__(self, name: str):
    super().__init__()
    self.name = name

  def __str__(self) -> str:
    return self.name

  @property
  def python_value_name(self):
    return self.name

  @property
  def cxx_value_name(self):
    return self.name


class UnknownSchema(Schema):
  """Represents some unknown type."""

  @property
  def python_value_name(self):
    return "None"

  @property
  def cxx_value_name(self):
    return "void"


class VarSchema(NamedSchema):

  element_type: Schema

  def __init__(self, name: str, element_type: Schema):
    super().__init__(name)
    self.element_type = element_type

  def dump(self, indent: str):
    print(f"{indent}{self.name} :: {self.element_type}")


class MethodSchema(NamedSchema):

  # Return type of this method. Constructors will have a return type of
  # `UnknownSchema`. No other method should have a return type of
  # `UnknownSchema`.
  return_type: Schema

  # List of parameters to this method.
  parameters: List[VarSchema]

  # Is this method `const`-qualified?
  is_const: bool

  # Marks whether or not this method is actually inherited by something that
  # isn't representable in the schema format. For example, an
  # `clang::OMPThreadPrivateDecl` extends `clang::OMPDeclarativeDirective<Decl>`
  # which extends `Decl`. We don't represent class template specializations
  # in the schema format, so what we do is we say that `OMPThreadPrivateDecl`
  # extends `Decl`, and then we replicate the normally inherited methods from
  # `OMPDeclarativeDirective` into `OMPThreadPrivateDecl`, marking them as
  # `is_inherited`.
  is_inherited: bool

  # Marks whether or not this method is virtual.
  is_virtual: bool

  # Marks whether or not this method is a pure virtual interface method.
  is_interface: bool

  def __init__(self, name: str, return_type: Schema):
    super().__init__(name)
    self.return_type = return_type
    self.parameters = []
    self.is_const = False
    self.is_virtual = False
    self.is_inherited = False
    self.is_interface = False

  def dump(self, indent: str):
    params = ""
    if len(self.parameters):
      params = " -> ".join("({} {})".format(p.element_type, p.name) for p in self.parameters)
      params += " -> "
    const = self.is_const and " CONST" or ""
    virtual = self.is_virtual and " VIRTUAL" or ""
    inherited = self.is_inherited and " INHERITED" or ""
    iface = self.is_interface and " INTERFACE" or ""
    print(f"{indent}{self.name}{const}{virtual}{iface}{inherited} :: {params}{self.return_type}")

  @property
  def min_num_parameters(self) -> int:
    return len(self.parameters)

  @property
  def max_num_parameters(self) -> int:
    return len(self.parameters)


class OverloadSetSchema(NamedSchema):
  """Represents a set of method overloads, where the methods have the same
  name."""

  # Non-empty list of overloads. If there is only one method in here, then
  # it suggests that other methods do exist, but were not added (e.g. because
  # the lifter doesn't support them).
  overloads: List[MethodSchema]

  def __init__(self, name: str):
    super().__init__(name)
    self.overloads = []

  def dump(self, indent: str):
    print(f"{indent}OVERLOAD_SET {self.name}")
    next_indent = f"{indent}  "
    for method in self.overloads:
      method.dump(next_indent)

  @property
  def is_const(self) -> bool:
    return all(m.is_const for m in self.overloads)

  @property
  def is_virtual(self) -> bool:
    return all(m.is_virtual for m in self.overloads)

  @property
  def is_inherited(self) -> bool:
    return all(m.is_inherited for m in self.overloads)

  @property
  def is_interface(self) -> bool:
    return all(m.is_interface for m in self.overloads)

  @property
  def min_num_parameters(self) -> int:
    return min(m.min_num_parameters for m in self.overloads)

  @property
  def max_num_parameters(self) -> int:
    return max(m.max_num_parameters for m in self.overloads)


class ClassSchema(NamedSchema, ABC):
  """Represents a schema for an arbitrary class in the Multiplier API. This
  is an abstract class."""

  # Relative path to the file where this alias is defined.
  location: Optional[str]

  # Path of namespaces containing this schema.
  namespaces: Optional[List[str]]

  # `struct` or `class`.
  elaborator: str

  # Bases classes, if any, of this class.
  bases: List['ClassSchema']

  # Public methods, and public static methods.
  constructor: Optional[Schema]
  methods: Dict[str, Schema]
  static_methods: Dict[str, Schema]

  # Does this class support `operator bool` in C++?
  has_boolean_conversion: bool

  # Does this class support `operator==` or `operator!=`?
  has_equivalence_relation: bool

  # Does this class support iteration? If so, this is the deduced value type
  # generated by the iterable.
  generated_type: Optional[Schema]

  # This this class support indexing? If so, this is the deduced value type
  # returned from `operator[]`.
  indexed_type: Optional[Schema]

  # Nested schemas, e.g. nested enums, classes, etc.
  nested_schemas: Dict[str, Schema]

  def __init__(self, name: str):
    super().__init__(name)
    self.location = None
    self.namespaces = None
    self.elaborator = "struct"
    self.bases = []
    self.constructor = None
    self.methods = {}
    self.static_methods = {}
    self.has_boolean_conversion = False
    self.has_equivalence_relation = False
    self.generated_type = None
    self.indexed_type = None
    self.nested_schemas = {}

  def _dump_section(self, indent: str, section_name: str, data: Dict[str, Schema]):
    if not len(data):
      return

    next_indent = indent + "    "
    print(f"{indent}  {section_name}")
    for member in data.values():
      member.dump(next_indent)

  def dump(self, indent: str):
    print(f"{indent}{self.elaborator.upper()} {self.name}")

    if self.location is not None:
      print(f"{indent}  LOCATION {self.location}")

    if self.namespaces is not None:
      print(f"{indent}  NAMESPACES {'::'.join(self.namespaces)}")

    if len(self.bases):
      print("{}  BASE_CLASSES {}".format(indent, ", ".join(str(base) for base in self.bases)))

    if self.has_boolean_conversion:
      print(f"{indent}  HAS_BOOLEAN_CONVERSION")

    if self.has_equivalence_relation:
      print(f"{indent}  EQUIVALENCE_RELATION")

    if self.generated_type is not None:
      print(f"{indent}  ITERATOR_PROTOCOL_GENERATES {self.generated_type}")

    if self.indexed_type is not None:
      print(f"{indent}  INDEXING_RETURNS {self.indexed_type}")

    self._dump_section(indent, "NESTED_SCHEMAS", self.nested_schemas)
    if self.constructor:
      print(f"{indent}  CONSTRUCTOR")
      self.constructor.dump(f"{indent}    ")
    self._dump_section(indent, "METHODS", self.methods)
    self._dump_section(indent, "STATIC_METHODS", self.static_methods)

  @property
  def python_value_name(self):
    ns_str = os.path.dirname(self.location).lower().replace("/", ".")
    return "{}{}".format(ns_str and f"{ns_str}." or "", self.name)

  @property
  def cxx_value_name(self) -> str:
    ns_str = self.namespaces and "::".join(self.namespaces) or ""
    return "{}{}{}".format(ns_str, ns_str and "::" or "", self.name)


class StringLikeSchema(Schema, ABC):

  @property
  def python_value_name(self):
    return "str"


class CStringSchema(StringLikeSchema):
  """Corresponds to a `const char *`."""

  @property
  def cxx_value_name(self):
    return "const char *"


class StdStringSchema(StringLikeSchema):
  """Corresponds to a `std::string`."""

  @property
  def cxx_value_name(self):
    return "std::string"


class StdStringViewSchema(StringLikeSchema):
  """Corresponds to a `std::string_view`."""

  @property
  def cxx_value_name(self):
    return "std::string_view"


class StdFilesystemPathSchema(StringLikeSchema):
  """Corresponds to a `std::filesystem::path`."""

  @property
  def python_value_name(self):
    return "pathlib.PurePath"

  @property
  def cxx_value_name(self):
    return "std::filesystem::path"


class LLVMStringRefSchema(StringLikeSchema):
  """Corresponds to an `llvm::StringRef`."""

  @property
  def cxx_value_name(self):
    return "llvm::StringRef"


class LLVMTwineSchema(StringLikeSchema):
  """Corresponds to an `llvm::Twine`."""

  @property
  def cxx_value_name(self):
    return "llvm::Twine"


class LLVMTriple(StringLikeSchema):
  """Corresponds to an `llvm::Triple`."""

  @property
  def cxx_value_name(self):
    return "llvm::Triple"


class MutiplyParameterizedSchema(Schema, ABC):
  """Corresponds to a schema with an unknown number of type parameters."""

  element_types: List[Schema]

  def __init__(self, element_types: List[Schema]):
    super().__init__()
    self.element_types = element_types

  def __str__(self) -> str:
    class_prefix = self.__class__.__name__[:-6]  # `-len("Schema")`.
    element_types = ", ".join(f"{e}" for e in self.element_types)
    return f"{class_prefix}[{element_types}]"


class TupleLikeSchema(MutiplyParameterizedSchema, ABC):

  @property
  def python_value_name(self):
    return "Tuple[{}]".format(
        ", ".join(p.python_value_name for p in self.element_types))


class StdPairSchema(TupleLikeSchema):
  """Corresponds to `std::pair<A, B>`."""

  @property
  def cxx_value_name(self):
    return "std::pair<{}, {}>".format(
        self.element_types[0].cxx_name, self.element_types[1].cxx_name)


class StdTupleSchema(TupleLikeSchema):
  """Corresponds to `std::tuple<A, B, ..., X>`."""

  @property
  def cxx_value_name(self):
    return "std::tuple<{}>".format(
        ", ".join(et.cxx_name for et in self.element_types))


class StdMonostateSchema(UnknownSchema):

  @property
  def python_value_name(self):
    return "None"

  @property
  def cxx_value_name(self):
    return "std::monostate"


class StdVariantSchema(MutiplyParameterizedSchema):
  """Corresponds to `std::variant<A, B, ..., X>`."""

  @property
  def python_value_name(self):
    ret = " | ".join(p.python_value_name \
                     for p in self.element_types \
                     if not isinstance(p, StdMonostateSchema))

    if sum(1 for p in self.element_types if isinstance(p, StdMonostateSchema)):
      ret = f"Optional[{ret}]"
    return ret

  @property
  def cxx_value_name(self):
    return "std::variant<{}>".format(
        ", ".join(et.cxx_name for et in self.element_types))


class ParameterizedSchema(Schema, ABC):
  """Corresponds to a parameterized schema, e.g. `type<T>` in C++."""
  element_type: Schema

  def __init__(self, element_type: Schema):
    super().__init__()
    self.element_type = element_type

  def __str__(self) -> str:
    class_prefix = self.__class__.__name__[:-6]  # `-len("Schema")`.
    return f"{class_prefix}[{self.element_type}]"


class IteratorRangeSchema(ParameterizedSchema):
  """Represents a type having both a `begin` and `end` methods, and where we're
  able to infer the iterated type. This is also a class with no other meaningful
  accessors/state."""

  @property
  def python_value_name(self):
    return "Iterable[{}]".format(self.element_type.python_value_name)

  @property
  def cxx_value_name(self):
    return "void"


class StdOptionalSchema(ParameterizedSchema):
  """Corresponds to a `std::optional<T>`."""

  @property
  def python_value_name(self):
    return "Optional[{}]".format(self.element_type.python_value_name)

  @property
  def cxx_value_name(self):
    return "std::optional<{}>".format(self.element_type.cxx_name)


class ContainerLikeSchema(ParameterizedSchema, ABC):
  """Represents containers of things."""
  pass


class SequenceLikeSchema(ContainerLikeSchema, ABC):
  """Represents list-like things."""

  @property
  def python_value_name(self):
    return "Sequence[{}]".format(self.element_type.python_value_name)


class SetLikeSchema(ContainerLikeSchema, ABC):
  """Represents list-like things."""

  @property
  def python_value_name(self):
    return "Set[{}]".format(self.element_type.python_value_name)


class DictionaryLikeSchema(ContainerLikeSchema):
  """Corresponds to a map/dictionary-like type."""
  key_type: Schema

  def __init__(self, key_type: Schema, value_type: Schema):
    super().__init__(value_type)
    self.key_type = key_type

  def __str__(self) -> str:
    class_prefix = self.__class__.__name__[:-6]  # `-len("Schema")`.
    return f"{class_prefix}[{self.key_type}, {self.element_type}]"

  @property
  def python_value_name(self):
    return "Mapping[{}, {}]".format(
        self.key_type.python_value_name, self.element_type.python_value_name)


class StdSpanSchema(SequenceLikeSchema):
  """Corresponds to a `std::span<T>`."""

  @property
  def cxx_value_name(self):
    return "std::span<{}>".format(self.element_type.cxx_name)


class StdVectorSchema(SequenceLikeSchema):
  """Corresponds to a `std::vector<T>`."""

  @property
  def cxx_value_name(self):
    return "std::vector<{}>".format(self.element_type.cxx_name)


class StdSetSchema(SetLikeSchema):
  """Corresponds to a `std::set<T>`."""

  @property
  def cxx_value_name(self):
    return "std::set<{}>".format(self.element_type.cxx_name)


class StdUnorderedSetSchema(SetLikeSchema):
  """Corresponds to a `std::unordered_set<T>`."""

  @property
  def cxx_value_name(self):
    return "std::unordered_set<{}>".format(self.element_type.cxx_name)


class StdMapSchema(DictionaryLikeSchema):
  """Corresponds to a `std::map<K, V>`."""

  @property
  def cxx_value_name(self):
    return "std::map<{}, {}>".format(
        self.key_type.cxx_name, self.element_type.cxx_name)


class StdUnorderedMapSchema(DictionaryLikeSchema):
  """Corresponds to a `std::unordered_map<K, V>`."""

  @property
  def cxx_value_name(self):
    return "std::unordered_map<{}, {}>".format(
        self.key_type.cxx_name, self.element_type.cxx_name)


class GapGeneratorSchema(ParameterizedSchema):
  """Corresponds to a `gap::generator<T>`."""

  @property
  def python_value_name(self):
    return "Iterable[{}]".format(self.element_type.python_value_name)

  @property
  def cxx_value_name(self):
    return "gap::generator<{}>".format(self.element_type.cxx_name)


class LLVMArrayRefSchema(SequenceLikeSchema):
  """Corresponds to an `llvm::ArrayRef<T>`."""

  @property
  def cxx_value_name(self):
    return "llvm::ArrayRef<{}>".format(self.element_type.cxx_name)


class LLVMSmallVectorSchema(SequenceLikeSchema):
  """Corresponds to an `llvm::SmallVector<T>`."""

  @property
  def cxx_value_name(self):
    return "llvm::SmallVector<{}>".format(self.element_type.cxx_name)


class LLVMNumericSchema(Schema, ABC):
  pass


class LLVMAPIntSchema(LLVMNumericSchema):
  """Corresponds to an `llvm::APInt`."""

  @property
  def python_value_name(self):
    return "int"

  @property
  def cxx_value_name(self):
    return "llvm::APInt"


class LLVMAPSIntSchema(LLVMNumericSchema):
  """Corresponds to an `llvm::APSInt`."""

  @property
  def python_value_name(self):
    return "int"

  @property
  def cxx_value_name(self):
    return "llvm::APSInt"


class LLVMAPFloatSchema(LLVMNumericSchema):
  """Corresponds to an `llvm::APFloat`."""

  @property
  def python_value_name(self):
    return "float"

  @property
  def cxx_value_name(self):
    return "llvm::APFloat"


class LLVMAPFixedPointSchema(LLVMNumericSchema):
  """Corresponds to an `llvm::APFixedPoint`."""

  @property
  def python_value_name(self):
    return "float"

  @property
  def cxx_value_name(self):
    return "llvm::APFixedPoint"


class ClangASTContextSchema(Schema):
  """Corresponds to a `clang::ASTContext`."""

  @property
  def python_value_name(self):
    assert False

  @property
  def cxx_value_name(self):
    return "clang::ASTContext"


class BuiltinTypeSchema(Schema, ABC):
  """Corresponds to a builtin type in C/C++."""
  pass


class BooleanSchema(BuiltinTypeSchema):
  """Corresponds to a `bool` type in C++ and a `_Bool` type in C."""

  @property
  def python_value_name(self):
    return "bool"

  @property
  def cxx_value_name(self):
    return "bool"


class IntegerSchema(BuiltinTypeSchema, ABC):
  """Any integral type in C/C++."""
  size_in_bits: int
  is_signed: bool

  def __init__(self, size_in_bits: int, is_signed: bool):
    super().__init__()
    self.size_in_bits = size_in_bits
    self.is_signed = is_signed

  @property
  def python_value_name(self):
    return "int"


class Int8Schema(IntegerSchema):
  """Corresponds to a `char`, `signed char`, or `int8_t` in C/C++."""
  def __init__(self):
    super().__init__(8, True)

  @property
  def cxx_value_name(self) -> str:
    return "int8_t"


class CharSchema(Int8Schema):
  """Corresponds to the `char` type in C/C++."""

  @property
  def cxx_value_name(self) -> str:
    return "char"


class Int16Schema(IntegerSchema):
  """Corresponds to a `short`, `signed short`, or `int16_t` in C/C++."""
  def __init__(self):
    super().__init__(16, True)

  @property
  def cxx_value_name(self) -> str:
    return "int16_t"


class Int32Schema(IntegerSchema):
  """Corresponds to a `int`, `signed int`, or `int32_t` in C/C++."""
  def __init__(self):
    super().__init__(32, True)

  @property
  def cxx_value_name(self) -> str:
    return "int32_t"


class Int64Schema(IntegerSchema):
  """Corresponds to a `long`, `signed long`, or `long long`, `signed long long`,
  or an `int64_t` in C/C++."""
  def __init__(self):
    super().__init__(64, True)

  @property
  def cxx_value_name(self) -> str:
    return "int64_t"


class UInt8Schema(IntegerSchema):
  """Corresponds to a `unsigned char` or `uint8_t` in C/C++."""
  def __init__(self):
    super().__init__(8, False)

  @property
  def cxx_value_name(self) -> str:
    return "uint8_t"


class UInt16Schema(IntegerSchema):
  """Corresponds to a `unsigned short` or `uint16_t` in C/C++."""
  def __init__(self):
    super().__init__(16, False)

  @property
  def cxx_value_name(self) -> str:
    return "uint16_t"


class UInt32Schema(IntegerSchema):
  """Corresponds to a `unsinged`, `unsigned int`, or `uint32_t` in C/C++."""
  def __init__(self):
    super().__init__(32, False)

  @property
  def cxx_value_name(self) -> str:
    return "uint32_t"


class UInt64Schema(IntegerSchema):
  """Corresponds to a `unsigned long`, `unsigned long long`, or an `uint64_t`
  in C/C++."""

  def __init__(self):
    super().__init__(64, False)

  @property
  def cxx_value_name(self) -> str:
    return "uint64_t"


class FloatingPointSchema(BuiltinTypeSchema, ABC):
  """Corresponds to any floating point type in C/C++."""
  size_in_bits: int

  def __init__(self, size_in_bits: int):
    super().__init__()
    self.size_in_bits = size_in_bits

  @property
  def python_value_name(self):
    return "float"


class FloatSchema(FloatingPointSchema):
  """Corresponds to a `float` in C/C++."""

  def __init__(self):
    super().__init__(32)

  @property
  def cxx_value_name(self):
    return "float"


class DoubleSchema(FloatingPointSchema):
  """Corresponds to a `double` in C/C++."""

  def __init__(self):
    super().__init__(64)

  @property
  def cxx_value_name(self):
    return "double"


class EnumSchema(NamedSchema):
  """Corresponds to an `enum` type in C/C++."""

  # Relative path to the file where this enum is defined.
  location: Optional[str]

  # Path of namespaces containing this schema.
  namespaces: Optional[List[str]]

  # Underlying integer type of this enum
  base_type: 'IntegerSchema'

  # Named list of enumerators.
  enumerators: [str]

  # Is this an `enum class` in C++?
  is_scoped: bool

  # Is the underlying type explicitly specified?
  is_explicitly_typed: bool

  # Is this enum enumerable? This will be `False` if any of the enumerators
  # has an initializer.
  is_enumerable: bool

  def __init__(self, name: str, is_scoped: bool, base_type: 'IntegerSchema'):
    super().__init__(name)
    self.location = None
    self.namespaces = None
    self.base_type = base_type
    self.enumerators = []
    self.is_scoped = is_scoped
    self.is_explicitly_typed = False
    self.is_enumerable = True

  def dump(self, indent: str):
    scoped = self.is_scoped and "_CLASS" or ""
    explicit = self.is_explicitly_typed and "EXPLICIT_" or ""
    print(f"{indent}ENUM{scoped} {self.name}")

    if self.location is not None:
      print(f"{indent}  LOCATION {self.location}")
    if self.namespaces is not None:
      print(f"{indent}  NAMESPACES {'::'.join(self.namespaces)}")
    print(f"{indent}  {explicit}BASE_TYPE {self.base_type}")
    if self.is_enumerable:
      print(f"{indent}  ENUMERABLE")
    print(f"{indent}  ENUMERATORS")
    for enumerator in self.enumerators:
      print(f"{indent}    {enumerator}")

  @property
  def python_value_name(self):
    ns_str = os.path.dirname(self.location).lower().replace("/", ".")
    return "{}{}".format(ns_str and f"{ns_str}." or "", self.name)

  @property
  def cxx_value_name(self) -> str:
    ns_str = self.namespaces and "::".join(self.namespaces) or ""
    return "{}{}{}".format(ns_str, ns_str and "::" or "", self.name)


class AliasSchema(NamedSchema):
  """Corresponds to a `using` or `typedef` type in C/C++."""

  # Relative path to the file where this alias is defined.
  location: str

  base_type: Schema

  def __init__(self, name: str, base_type: Schema):
    super().__init__(name)
    self.base_type = base_type

  def __str__(self) -> str:
    return f"Alias[{self.name}, {self.base_type}]"

  def dump(self, indent: str):
    print(f"{indent}ALIAS {self.name}")
    print(f"{indent}  LOCATION {self.location}")
    print(f"{indent}  BASE_TYPE {self.base_type}")


class PointerLikeSchema(ParameterizedSchema, ABC):
  """Corresponds to something pointer-like."""

  @property
  def python_value_name(self):
    return self.element_type.python_value_name


class ReferenceSchema(PointerLikeSchema):
  """Corresponds to an `T &` reference type."""

  @property
  def cxx_value_name(self):
    return self.element_type.cxx_value_name

  @property
  def cxx_name(self):
    return "{} &".format(self.element_type.cxx_value_name)


class ConstReferenceSchema(ReferenceSchema):
  """Corresponds to an `const T &` reference type."""

  @property
  def cxx_value_name(self):
    return self.element_type.cxx_value_name

  @property
  def cxx_name(self):
    return "const {} &".format(self.element_type.cxx_value_name)


class RawPointerSchema(PointerLikeSchema):
  """Corresponds to a `T *` in C/C++."""

  @property
  def cxx_value_name(self):
    return "{} *".format(self.element_type.cxx_value_name)


class ConstRawPointerSchema(RawPointerSchema):
  """Corresponds to a `const T *` in C/C++."""

  @property
  def cxx_value_name(self):
    return "const {} *".format(self.element_type.cxx_value_name)


class StdUniquePtrSchema(PointerLikeSchema):
  """Corresponds to a `std::unique_ptr<T>` in C/C++."""

  @property
  def cxx_value_name(self):
    return "std::unique_ptr<{}>".format(self.element_type.cxx_name)


class StdSharedPtrSchema(PointerLikeSchema):
  """Corresponds to a `std::shared_ptr<T>` in C/C++."""

  @property
  def cxx_value_name(self):
    return "std::shared_ptr<{}>".format(self.element_type.cxx_name)
