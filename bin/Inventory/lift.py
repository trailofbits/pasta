# Copyright (c) 2023 Trail of Bits, Inc., all rights reserved.

from pypasta import *
from argparse import ArgumentParser
from schema import *
from typing import Callable, Dict, Iterable, List, Optional, Tuple, TypedDict

import os
import pathlib
import subprocess
import sys
import tempfile


def decls_in_dc_decl(dc: Decl) -> Iterable[Decl]:
  """Generate all declarations within a declaration context."""
  for decl in DeclContext.cast(dc).declarations:
    yield decl


def find_namespaces(dc: Decl, ns_name: str) -> Iterable[NamespaceDecl]:
  """Find all namespaces whose name matches `ns_name` within the declaration
  context `dc`."""
  for decl in decls_in_dc_decl(dc):
    if isinstance(decl, NamespaceDecl) and decl.name == ns_name:
      yield decl


def find_tags_in_dc_decl(dc: Decl) -> Iterable[TagDecl]:
  """Find all tags (enums, structures, unions, classes) inside of
  a declaration context."""
  for decl in decls_in_dc_decl(dc):
    if isinstance(decl, TagDecl):
      yield decl


def base_classes(tag: CXXRecordDecl) -> Iterable[CXXRecordDecl]:
  """Find the base classes of `cls`."""
  for base in tag.bases:
    base_type: Type = base.base_type.unqualified_desugared_type
    if isinstance(base_type, RecordType):
      base_tag = base_type.declaration
      assert isinstance(base_tag, CXXRecordDecl)
      yield base_tag


def indirect_base_classes(tag: RecordDecl) -> Iterable[RecordDecl]:
  """Find all base classes of `tag` that are also `RecordDecl`s. This will skip
  through template specializations."""
  if not isinstance(tag, CXXRecordDecl) or not tag.num_bases:
    return

  for base_tag in base_classes(tag):
    if isinstance(base_tag, ClassTemplateSpecializationDecl):
      yield from indirect_base_classes(base_tag)
    else:
      yield base_tag


def qualified_name(decl: NamedDecl) -> str:
  """Compute an approximation of the qualified name of `decl`."""
  path: List[str] = [decl.name]
  dc: Optional[DeclContext] = decl.declaration_context
  while dc:
    dc_decl: Optional[Decl] = Decl.cast(dc)
    if isinstance(dc_decl, NamespaceDecl):
      if dc_decl.is_anonymous_namespace:
        path.append("(anonymous namespace)")
      elif not dc_decl.is_inline:
        path.append(dc_decl.name)
    elif isinstance(dc_decl, TagDecl):
      path.append(dc_decl.name)
    else:
      break
    dc = dc_decl.declaration_context
  return "::".join(reversed(path))


def _relative_file_location(tok: FileToken) -> str:
  """Compute the relative location of some file token."""
  path: pathlib.Path = File.containing(tok).path
  parts: List[str] = []

  while len(path.name):
    if path.name == 'include':
      break
    parts.append(path.name)
    path = path.parent

  return str(os.path.join(*reversed(parts)))


def _relative_location(tok: Token) -> Optional[str]:
  """Compute the relative location of some token."""
  ft: Optional[FileToken] = tok.file_location
  return ft and _relative_file_location(ft) or None


def decl_location(decl: Decl) -> Optional[str]:
  """Find the relative path of the include file containing `decl`."""
  for tok in decl.tokens:
    if tok.role in (TokenRole.FILE_TOKEN, TokenRole.INITIAL_MACRO_USE_TOKEN):
      return _relative_location(tok)
    elif tok.role == TokenRole.FINAL_MACRO_EXPANSION_TOKEN:
      macro = tok.macro_location
      while macro.parent:
        macro = macro.parent
      return _relative_location(macro.first_use_token.parsed_location)

  return _relative_location(decl.token)


def nth_template_argument(tag: TagDecl, n: int) -> Optional[TemplateArgument]:
  """Return the `n`th template argument."""
  if not isinstance(tag, ClassTemplateSpecializationDecl):
    return None

  args: List[TemplateArgument] = list(tag.template_arguments)
  if n >= len(args):
    return None

  return args[n]


def public_decls_in_tag(tag: TagDecl) -> Iterable[Decl]:
  """Generate the publicly visible `Decl`s inside of a `TagDecl`."""

  # If this is a `class`, as opposed to a `struct` or `union`, then start
  # by treating the access as private, and so skip anything we come across
  # by default.
  skip = tag.tag_kind == TagTypeKind.CLASS
  for decl in decls_in_dc_decl(tag):
    
    # Turn on skipping if the access specifier hasn't changed to `public`.
    if isinstance(decl, AccessSpecDecl):
      skip = decl.access_specifier_token.data != "public"
      continue

    # Don't inventory stuff with `private` or `protected` visibility.
    if not skip:
      yield decl


def public_decls_in_tag_and_template_bases(tag: TagDecl) -> Iterable[Decl]:
  """Generate the public `Decl`s from `tag`. If tag extends any class template
  specializations, then go and generate the public decls from those too, because
  we can't represent them."""
  if isinstance(tag, CXXRecordDecl) and tag.num_bases:
    for base_tag in base_classes(tag):
      if isinstance(base_tag, ClassTemplateSpecializationDecl):
        for decl in public_decls_in_tag_and_template_bases(base_tag):

          # Filter out constructors/destructors; they're on the wrong types.
          if not isinstance(decl, (CXXConstructorDecl, CXXDestructorDecl)):
            yield decl

  for decl in public_decls_in_tag(tag):
    yield decl


class SchemaLifter:
  """Lift declarations into schemas. This acts as one big recursive visitor.
  It primarily focuses on classes, methods, and enumerators. It tries to
  recognize certain things like C++ standard library containers and represent
  those in a specific way."""

  decl_schemas: Dict[Decl, Schema]
  type_schemas: Dict[Type, Schema]
  unknown_schema: UnknownSchema
  char_schema: CharSchema

  qual_name_type_schemas: Dict[str, Callable[[TagDecl], Schema]]
  type_handlers: Dict[type[Type], Callable[[Type], Schema]]
  builtin_type_schemas: Dict[BuiltinTypeKind, BuiltinTypeSchema]

  def __init__(self):
    self.unknown_schema = UnknownSchema()

    self.decl_schemas = {
      None: self.unknown_schema,
    }
    self.type_schemas = {
      None: self.unknown_schema,
    }

    self.type_handlers = {
      QualifiedType: self._lift_qualified_type,
      ReferenceType: self._lift_reference_type,
      LValueReferenceType: self._lift_reference_type,
      BuiltinType: self._lift_builtin_type,
      TypedefType: self._lift_typedef_type,
      ElaboratedType: self._lift_elaborated_type,
      RecordType: self._lift_tag_type,
      EnumType: self._lift_tag_type,
      TemplateSpecializationType: self._lift_spec_type,
      PointerType: self._lift_pointer_type,
      DecltypeType: self._lift_decltype_type,
      SubstTemplateTypeParmType: self._lift_substituted_type,
      UsingType: self._lift_using_type,
      AdjustedType: self._lift_adjusted_type,
      DecayedType: self._lift_adjusted_type,
      TemplateTypeParmType: self._lift_template_param_type,
      AutoType: self._lift_auto_type,
      RValueReferenceType: self._lift_unsupported,
      ConstantArrayType: self._lift_unsupported,
      IncompleteArrayType: self._lift_unsupported,
      ParenType: self._lift_unsupported,
      FunctionType: self._lift_unsupported,
      FunctionProtoType: self._lift_unsupported,
      InjectedClassNameType: self._lift_injected_class_name_type,
    }

    self.char_schema = CharSchema() 

    int8_s = Int8Schema()
    int16_s = Int16Schema()
    int32_s = Int32Schema()
    int64_s = Int64Schema()

    uint8_s = UInt8Schema()
    uint16_s = UInt16Schema()
    uint32_s = UInt32Schema()
    uint64_s = UInt64Schema()

    self.builtin_type_schemas = {
      BuiltinTypeKind.BOOLEAN: BooleanSchema(),
      BuiltinTypeKind.CHARACTER_S: self.char_schema,
      BuiltinTypeKind.S_CHAR: int8_s,
      BuiltinTypeKind.U_CHAR: uint8_s,
      BuiltinTypeKind.SHORT: int16_s,
      BuiltinTypeKind.U_SHORT: uint16_s,
      BuiltinTypeKind.INT: int32_s,
      BuiltinTypeKind.U_INT: uint32_s,
      BuiltinTypeKind.FLOAT: FloatSchema(),
      BuiltinTypeKind.DOUBLE: DoubleSchema(),
      BuiltinTypeKind.LONG: int64_s,
      BuiltinTypeKind.U_LONG: uint64_s,
      BuiltinTypeKind.LONG_LONG: int64_s,
      BuiltinTypeKind.U_LONG_LONG: uint64_s,
    }

    self.qual_name_type_schemas = {
      "std::filesystem::path":self._make_lifter(StdFilesystemPathSchema),
      "std::string": self._make_lifter(StdStringSchema),
      "std::basic_string": self._make_lifter(StdStringSchema),
      "std::string_view": self._make_lifter(StdStringViewSchema),
      "std::basic_string_view": self._make_lifter(StdStringViewSchema),
      "std::optional": self._make_1_parameter_lifter(StdOptionalSchema),
      "std::vector": self._make_1_parameter_lifter(StdVectorSchema),
      "std::shared_ptr": self._lift_std_shared_ptr,
      "std::unique_ptr": self._lift_std_unique_ptr,
      "std::input_iterator_tag": self._lift_unsupported,
      "std::forward_iterator_tag": self._lift_unsupported,
      "std::bidirectional_iterator_tag": self._lift_unsupported,
      "std::random_access_iterator_tag": self._lift_unsupported,
      "std::error_code": self._lift_unsupported,
      "std::error_category": self._lift_unsupported,
      "std::error_condition": self._lift_unsupported,
      "std::filesystem::file_type": self._lift_unsupported,
      "std::filesystem::perms": self._lift_unsupported,
      "std::map": self._make_2_parameter_lifter(StdMapSchema),
      "std::unordered_map": self._make_2_parameter_lifter(StdUnorderedMapSchema),
      "std::set": self._make_1_parameter_lifter(StdSetSchema),
      "std::unordered_set": self._make_1_parameter_lifter(StdUnorderedSetSchema),
      "std::initializer_list": self._lift_unsupported,
      "std::variant": self._lift_unsupported,
      "std::nullopt_t": self._lift_unsupported,
      "std::reverse_iterator": self._lift_unsupported,
      "std::tuple": self._lift_unsupported,
      "std::pair": self._lift_unsupported,
      "std::function": self._lift_unsupported,
      "std::__optional_destruct_base::": self._lift_unsupported,
      "std::aligned_storage::type": self._lift_unsupported,
      "gap::generator": self._make_lifter(GapGeneratorSchema),
      "llvm::hash_code": self._lift_unsupported,
      "llvm::PointerUnion": self._lift_unsupported,  # TODO(pag): Adapt to variant.
      "llvm::function_ref": self._lift_unsupported,
      "llvm::Twine": self._make_lifter(LLVMTwineSchema),
      "llvm::StringRef": self._make_lifter(LLVMStringRefSchema),
      "llvm::Triple": self._make_lifter(LLVMTriple),
      "clang::ASTContext": self._make_lifter(ClangASTContextSchema),
      "clang::APInt": self._make_lifter(LLVMAPIntSchema),
      "clang::APSInt": self._make_lifter(LLVMAPSIntSchema),
      "clang::APFloat": self._make_lifter(LLVMAPFloatSchema),
      "clang::APFixedPoint": self._make_lifter(LLVMAPFixedPointSchema),
      "llvm::APInt": self._make_lifter(LLVMAPIntSchema),
      "llvm::APSInt": self._make_lifter(LLVMAPSIntSchema),
      "llvm::APFloat": self._make_lifter(LLVMAPFloatSchema),
      "llvm::APFixedPoint": self._make_lifter(LLVMAPFixedPointSchema),
      "llvm::ArrayRef": self._make_1_parameter_lifter(LLVMArrayRefSchema),
      "llvm::MutableArrayRef": self._lift_unsupported,
      "llvm::SmallVector": self._make_1_parameter_lifter(LLVMSmallVectorSchema),
      "llvm::SmallVectorImpl": self._make_1_parameter_lifter(LLVMSmallVectorSchema),
    }

  def _lift_nth_template_argument(self, tag: TagDecl, n: int) -> Schema:
    """Lift the `n`th template argument to a schema."""
    arg: Optional[TemplateArgument] = nth_template_argument(tag, n)
    if not arg:
      return self.unknown_schema

    decl: Optional[Decl] = arg.as_declaration
    tp: Optional[Type] = arg.as_type
    schema: Schema = self.unknown_schema

    if decl:
      schema = self.lift_decl(decl)
    
    elif tp:

      # Only let us find basic things in the template arguments. This is a
      # simple way to prevent things like pointers-to-pointers.
      if not isinstance(tp, (RecordType, ElaboratedType, BuiltinType, \
                             TemplateSpecializationType)):
        return self.unknown_schema

      schema = self.lift_type(tp)

    return schema

  def _lift_method(self, method: CXXMethodDecl) -> Optional[MethodSchema]:
    """Lift a `CXXMethodDecl` into a `MethodSchema`. If this fails, then
    `None` is returned."""

    if not len(method.name):
      return None

    # Lift the return type. Things like `void` are mapped to `UnknownSchema`,
    # and we disallow `UnknownSchema` as return types (except for constructors),
    # largely to avoid lifting setters methods.
    type_schema = self.lift_type(method.return_type.unqualified_type)
    if isinstance(type_schema, UnknownSchema):
      if not isinstance(method, CXXConstructorDecl):
        return None

    schema = MethodSchema(method.name, type_schema)

    for i, decl in enumerate(method.parameters):
      type_schema = self.lift_type(decl.type.unqualified_type)
      if isinstance(type_schema, UnknownSchema):
        return None

      # Find the parameter name.
      name = decl.name
      if not len(name):
        for method_redecl in method.redeclarations:
          name = list(method_redecl.parameters)[i].name
          if len(name):
            break

      schema.parameters.append(VarSchema(name, type_schema))

    return schema

  def _merge_method(self, method: MethodSchema, existing: Optional[Schema],
                    num_with_name: int) -> Schema:
    """Combine multiple same-named methods into an overload set. If two methods
    have the same parameter lists, then choose the `const`-qualified method."""

    if isinstance(existing, MethodSchema):
      overloads = OverloadSetSchema(method.name)
      overloads.overloads.append(existing)
      existing = overloads

    # We have at least one other method with this name, though we may not have
    # lifted it. We want to communicate that we're dealing with an overload set
    # because event if only one overload makes it out, if we tried to pass that
    # to something like nanobind then it wouldn't know which overload to select.
    elif num_with_name:
      overloads = OverloadSetSchema(method.name)
      existing = overloads

    else:
      assert existing is None
      return method

    assert isinstance(existing, OverloadSetSchema)

    found = False
    method_params = " ".join(str(p) for p in method.parameters)

    for i, overload in enumerate(existing.overloads):
      assert overload.name == method.name

      if method_params != " ".join(str(p) for p in overload.parameters):
        continue

      found = True
      if method.is_const:
        existing.overloads[i] = method
      break

    if not found:
      existing.overloads.append(method)

    return existing

  def _lift_iterated_type(self, tp: Type) -> Schema:
    """Lift the iterated type of an iterator to a `Schema`."""

    # Allow ourselves to handle pointer-to-pointer-like constructs here, e.g.
    # `clang::Stmt *&` as returned by a `clang::StmtIterator`.
    while tp.is_sugared:
      tp = tp.desugar

    # Treat iterators returning `T *&` as though they return `T *`.
    if isinstance(tp, ReferenceType):
      is_const, pt = self._desugar_pointee_type(tp.pointee_type)
      referenced_schema = self.lift_type(pt)
      if isinstance(referenced_schema, PointerLikeSchema):
        return referenced_schema

    return self.lift_type(tp)

  def _lift_iterated_type_from_decl(self, tag: RecordDecl) -> Schema:
    """Try to go and drill into `tag`, find `operator*` and then lift its
    return type."""

    for decl in decls_in_dc_decl(tag):
      if isinstance(decl, CXXMethodDecl) and \
         decl.is_overloaded_operator and \
         decl.access == AccessSpecifier.PUBLIC and \
         decl.overloaded_operator == OverloadedOperatorKind.STAR and \
         not len(decl.parameters):

        iterated_schema = self._lift_iterated_type(
            decl.return_type.unqualified_type)

        # NOTE(pag): There might be an `operator *(void)` that we fail on, but
        #            an `operator *(void) const` that we can succeed on.
        if not isinstance(iterated_schema, UnknownSchema):
          return iterated_schema

    # We failed to find an `operator*` in `tag`. Try to see if we can find it in
    # a base class.
    if not isinstance(tag, CXXRecordDecl) or not tag.num_bases:
      return self.unknown_schema

    # Capture base classes. If we can't lift a base class then we ignore it.
    for base_tag in base_classes(tag):
      iterated_schema = self._lift_iterated_type_from_decl(base_tag)
      if not isinstance(iterated_schema, UnknownSchema):
        return iterated_schema

    return self.unknown_schema

  def _lift_iterated_type_from_type(self, tp: Type) -> Schema:
    """Recover the iterator type, and lift out the iterated type."""
    
    # Unwrap the method's return type.
    while tp.is_sugared:
      tp = tp.unqualified_type.desugar

    # Pointers are the easiest form of iterator to support; the iterated type
    # is the pointer element type.
    if isinstance(tp, PointerType):
      is_const, pt = self._desugar_pointee_type(tp.pointee_type)
      return self.lift_type(pt)

    if not isinstance(tp, RecordType):
      assert False, f"Unrecognized iterator type class {tp.__class__}"
      return self.unknown_schema

    return self._lift_iterated_type_from_decl(tp.declaration)

  def _lift_record(self, tag: RecordDecl) -> Schema:
    """Lift a `RecordDecl` into a `Schema`."""

    # We do not allow binding of `union`s, they are not friendly to binidng.
    if tag.tag_kind == TagTypeKind.UNION:
      return self.unknown_schema

    schema: ClassSchema = ClassSchema(tag.name)
    schema.location = decl_location(tag)

    # Cache it early on, so that we can handle self-referential types.
    self.decl_schemas[tag] = schema

    # Capture base classes. If we can't lift a base class then we ignore it.
    for base_tag in indirect_base_classes(tag):
      base_schema = self.lift_decl(base_tag)
      if isinstance(base_schema, ClassSchema):
        schema.bases.append(base_schema)

    # If this is a `class`, as opposed to a `struct` or `union`, then start
    # by treating the access as private, and so skip anything we come across
    # by default.
    if tag.tag_kind == TagTypeKind.CLASS:
      schema.elaborator = "class"

    num_accessors = 0

    # `begin` and `end` methods of an iterator protocol.
    begin_decl: Optional[CXXMethodDecl] = None
    end_decl: Optional[CXXMethodDecl] = None

    # Number of methods seen with a given name.
    overload_count: Dict[str, int] = {}

    # Get the public decls in `tag`, as well as any public decls in any base
    # classes that are actually class template specializations.
    for decl in public_decls_in_tag_and_template_bases(tag):

      # E.g. `FriendDecl`.
      if not isinstance(decl, NamedDecl):
        continue

      # Nested enums/classes/aliases.
      if isinstance(decl, (TypedefNameDecl, TagDecl)):
        nested_decl = self.lift_decl(decl)
        if isinstance(nested_decl, NamedSchema):
          schema.nested_schemas[decl.name] = nested_decl
        continue

      # No point in describing the destructor.
      if isinstance(decl, CXXDestructorDecl):
        continue

      if not isinstance(decl, CXXMethodDecl):
        continue

      # Detect presence of `operator bool()` overloaded operator.
      if isinstance(decl, CXXConversionDecl):
        rs = self.lift_type(decl.return_type.unqualified_type)
        if isinstance(rs, BooleanSchema):
          schema.has_boolean_conversion = True
        continue

      # Detect presence of `operator==` or `operator!=`, so that we can know if
      # this object induces an equivalence relation. 
      if decl.is_overloaded_operator and \
         (decl.overloaded_operator == OverloadedOperatorKind.EQUAL_EQUAL or
          decl.overloaded_operator == OverloadedOperatorKind.EXCLAIM_EQUAL):
        schema.has_equivalence_relation = True

      # Skip these.
      if decl.is_implicit or decl.is_overloaded_operator:
        continue

      section: Optional[Dict[str, MethodSchema]] = None
      accessor_increment = 0

      num_with_name = overload_count.get(decl.name, 0)
      overload_count[decl.name] = num_with_name + 1

      if not isinstance(decl, CXXConstructorDecl):
        if decl.is_instance:

          # Try to detect an iterator protocol.
          if decl.name == "begin":
            begin_decl = decl
            continue
          elif decl.name == "end":
            end_decl = decl
            continue

          section = schema.methods
          accessor_increment = 1
        else:
          section = schema.static_methods

      # Lift the method.
      method_schema: Optional[MethodSchema] = self._lift_method(decl)
      if not method_schema or isinstance(method_schema, UnknownSchema):
        continue

      num_accessors += accessor_increment
      method_schema.is_const = decl.is_const
      method_schema.is_inherited = decl.parent != tag

      if section is not None:
        section[decl.name] = self._merge_method(
            method_schema, section.get(decl.name), num_with_name)
      else:
        schema.constructor = self._merge_method(
            method_schema, schema.constructor, num_with_name)

    # It looks like this follows an iterator protocol.
    iterated_schema = None
    if begin_decl and end_decl:
      iterated_schema = self._lift_iterated_type_from_type(
          begin_decl.return_type.unqualified_type)
      if not isinstance(iterated_schema, UnknownSchema):
        schema.generated_type = iterated_schema

    # This class is a template specialization, or has no stateful accessors,
    # so try to convert it into an iterator range or outright drop it.
    if isinstance(tag, ClassTemplateSpecializationDecl) or not num_accessors:
      new_schema: Schema = self.unknown_schema
      if schema.generated_type:
        new_schema = IteratorRangeSchema(schema.generated_type)
      return new_schema

    return schema

  def _lift_enum(self, tag: EnumDecl) -> Schema:
    """Lift an `EnumDecl` into an `EnumSchema`."""

    # Get the schema for the underlying integer type.
    int_type: Schema = self.lift_type(tag.integer_type)
    if not isinstance(int_type, IntegerSchema):
      return self.unknown_schema

    schema = EnumSchema(tag.name, tag.is_scoped_using_class_tag, int_type)
    schema.location = decl_location(tag)

    # Cache it, just in case an enumerator initializer somehow references it.
    self.decl_schemas[tag] = schema

    if len(tag.integer_type_range):
      schema.is_explicitly_typed = True

    for decl in decls_in_dc_decl(tag):
      assert isinstance(decl, EnumConstantDecl)
      schema.enumerators.append(decl.name)

      # If any of the enumerators has an initializer expression, then assume
      # that the enumerators are not totally ordered and/or that this value
      # doesn't match the would-be default value.
      if decl.initializer_expression is not None:
        schema.is_enumerable = False

    # If there are no enumerators, then we can't guarantee that this can be
    # usefully wrapped.
    if not len(schema.enumerators):
      return self.unknown_schema

    return schema

  def _lift_typedef(self, typedef: TypedefNameDecl) -> Schema:
    """Lift a `TypedefNameDecl`, i.e. a `typedef` or a `using`, into an
    `AliasSchema`."""

    nested_schema: Schema = self.lift_type(typedef.underlying_type)
    if isinstance(nested_schema, UnknownSchema):
      return nested_schema

    # Drill down through the aliases.
    while isinstance(nested_schema, AliasSchema):
      nested_schema = nested_schema.base_type

    schema: Schema = AliasSchema(typedef.name, nested_schema)
    schema.location = decl_location(typedef)

    # Cache it, just in we end up going into some kind of struct body that then
    # re-refereces this typedef.
    self.decl_schemas[typedef] = schema

    # Handle things like `size_t`.    
    if isinstance(nested_schema, (BuiltinTypeSchema, IteratorRangeSchema, 
                                  PointerLikeSchema, NamedSchema)):
      schema = nested_schema

    # Handle an alias, e.g. `using string_view = std::basic_string_view<...>;`.
    elif qualified_name(typedef) in self.qual_name_type_schemas:
      schema = nested_schema

    return schema

  def _lift_parent(self, decl: NamedDecl) -> bool:
    """Returns `True` if `decl` isn't nested inside of a `TagDecl`, or if
    if that parent tag can be successfully lifted."""

    dc: Optional[DeclContext] = decl.declaration_context
    if not dc:
      return True

    dc_decl: Optional[Decl] = Decl.cast(dc)
    if not isinstance(dc_decl, TagDecl):
      return isinstance(dc_decl, (TranslationUnitDecl, NamespaceDecl,
                                  LinkageSpecDecl))

    if dc_decl in self.decl_schemas:
      dc_schema = self.decl_schemas[dc_decl]
    else:
      dc_schema = self.lift_decl(dc_decl)

    return not isinstance(dc_schema, UnknownSchema)

  def lift_decl(self, decl: Decl) -> Schema:
    """Lift a `Decl` into a `Schema`. Returns `UnknownSchema` when the
    decl isn't supported."""
    assert isinstance(decl, Decl)

    if decl in self.decl_schemas:
      return self.decl_schemas[decl]

    schema: Schema = self.unknown_schema
    
    # Don't lift anything that can't be named, and whose parent's can't be
    # lifted, or that is a template or partially specialized template.
    if not isinstance(decl, NamedDecl) or \
       not len(decl.name) or \
       isinstance(self, (ClassTemplatePartialSpecializationDecl,
                         VarTemplatePartialSpecializationDecl,
                         TemplateDecl)) or \
       not self._lift_parent(decl):

      self.decl_schemas[decl] = self.unknown_schema
      schema = self.unknown_schema

    elif isinstance(decl, RecordDecl):
      decl_def = decl.definition
      if decl_def:
        decl = decl_def
        schema = self._lift_record(decl_def)
      
    elif isinstance(decl, EnumDecl):
      decl_def = decl.definition
      if decl_def:
        decl = decl_def
        schema = self._lift_enum(decl_def)

    elif isinstance(decl, TypedefNameDecl):
      schema = self._lift_typedef(decl)

    elif isinstance(decl, VarDecl):
      pass

    else:
      assert False

    self.decl_schemas[decl] = schema
    return schema

  def _lift_qualified_type(self, tp: QualifiedType) -> Schema:
    tp_str = " ".join(str(tok) for tok in PrintedTokenRange.create(tp))
    assert False, f"Ignoring {tp_str}"
    return self.unknown_schema

  def _lift_reference_type(self, tp: ReferenceType) -> Schema:
    is_const, pt = self._desugar_pointee_type(tp.pointee_type)

    # Don't allow pointers-to-unknowns, or pointers-to-pointers.
    ps: Schema = self.lift_type(pt)
    if isinstance(ps, UnknownSchema):
      return self.unknown_schema

    return is_const and ConstReferenceSchema(ps) or ReferenceSchema(ps)

    return self.lift_type(tp.pointee_type)

  def _lift_builtin_type(self, tp: BuiltinType) -> Schema:
    return self.builtin_type_schemas.get(tp.builtin_kind, self.unknown_schema)

  def _lift_typedef_type(self, tp: TypedefType) -> Schema:
    return self.lift_decl(tp.declaration)

  def _lift_elaborated_type(self, tp: ElaboratedType) -> Schema:
    return self.lift_type(tp.desugar)

  def _lift_spec_type(self, tp: TemplateSpecializationType) -> Schema:
    if not tp.is_sugared:
      return self.unknown_schema
    return self.lift_type(tp.desugar)

  def _lift_substituted_type(self, tp: SubstTemplateTypeParmType) -> Schema:
    if not tp.is_sugared:
      return self.unknown_schema
    
    return self.lift_type(tp.desugar)

  def _lift_using_type(self, tp: UsingType) -> Schema:
    return self.lift_decl(tp.found_declaration.target_declaration)

  def _desugar_pointee_type(self, pt: Type) -> Tuple[bool, Type]:
    is_const = False
    # Desugar the type, but keep track of whether or not we encountered
    # `const`-qualification.
    changed = True
    while changed:
      changed = False
      if isinstance(pt, QualifiedType):
        is_const = pt.is_const_qualified

        # Reject `const`- and `restrict`-qualified reference element types.
        if pt.is_restrict_qualified or pt.is_volatile_qualified:
          return self.unknown_schema

        pt = pt.unqualified_type  # Unwrap the qualification
        changed = True

      if pt.is_sugared:
        pt = pt.desugar
        changed = True
    return is_const, pt

  def _lift_pointer_type(self, tp: PointerType) -> Schema:
    is_const, pt = self._desugar_pointee_type(tp.pointee_type)

    # Don't allow pointers-to-unknowns, or pointers-to-pointers.
    ps: Schema = self.lift_type(pt)
    if isinstance(ps, (UnknownSchema, PointerLikeSchema, CStringSchema)):
      return self.unknown_schema

    if isinstance(ps, Int8Schema) and is_const:
      return CStringSchema()
    
    return is_const and ConstRawPointerSchema(ps) or RawPointerSchema(ps)

  def _lift_decltype_type(self, tp: DecltypeType) -> Schema:
    return self.lift_type(tp.desugar)

  def _lift_adjusted_type(self, tp: AdjustedType) -> Schema:
    return self.lift_type(tp.desugar)

  def _lift_template_param_type(self, tp: TemplateTypeParmType) -> Schema:
    if tp.is_parameter_pack or not tp.is_sugared:
      return self.unknown_schema
    return self.lift_type(tp.desugar)

  def _lift_injected_class_name_type(self, tp: InjectedClassNameType) -> Schema:
    return self.lift_decl(tp.declaration)

  def _lift_auto_type(self, tp: AutoType) -> Schema:
    return self.lift_type(tp.desugar)

  def _lift_unsupported(self, *args) -> Schema:
    return self.unknown_schema

  def _lift_1_parameter(self, tag: TagDecl, container: type[Schema]) -> Schema:
    arg = self._lift_nth_template_argument(tag, 0)
    if isinstance(arg, UnknownSchema):
      return self.unknown_schema
    return container(arg)

  def _lift_2_parameter(self, tag: TagDecl, container: type[Schema]) -> Schema:
    key = self._lift_nth_template_argument(tag, 0)
    val = self._lift_nth_template_argument(tag, 1)
    if isinstance(key, UnknownSchema) or isinstance(val, UnknownSchema):
      return self.unknown_schema
    return container(key, val)

  def _make_lifter(self, constructor: type[Schema]) -> Callable[[TagDecl], Schema]:
    def do_lift(tag: TagDecl):
      return constructor()
    return do_lift

  def _make_1_parameter_lifter(self, constructor: type[Schema]) -> Callable[[TagDecl], Schema]:
    def do_lift(tag: TagDecl):
      return self._lift_1_parameter(tag, constructor)
    return do_lift

  def _make_2_parameter_lifter(self, constructor: type[Schema]) -> Callable[[TagDecl], Schema]:
    def do_lift(tag: TagDecl):
      return self._lift_2_parameter(tag, constructor)
    return do_lift

  def _lift_std_shared_ptr(self, tag: TagDecl) -> Schema:
    arg = self._lift_nth_template_argument(tag, 0)
    if isinstance(arg, (UnknownSchema, PointerLikeSchema, CStringSchema)):
      return self.unknown_schema
    return StdSharedPtrSchema(arg)

  def _lift_std_unique_ptr(self, tag: TagDecl) -> Schema:
    arg = self._lift_nth_template_argument(tag, 0)
    if isinstance(arg, (UnknownSchema, PointerLikeSchema, CStringSchema)):
      return self.unknown_schema
    return StdUniquePtrSchema(arg)

  def _lift_tag_type(self, tp: TagType) -> Schema:
    """Lift a `TagType` into a `Schema`. This tries to
    identify some standard library types and ignore or specialize them."""
    tag: TagDecl = tp.declaration
    if tag in self.decl_schemas:
      return self.decl_schemas[tag]
    
    # Compute an approximation of the qualified path of the tag.
    qual_name: str = qualified_name(tag)
    if qual_name in self.qual_name_type_schemas:
      schema = self.qual_name_type_schemas[qual_name](tag)
      self.decl_schemas[tag] = schema
      return schema
    
    if "std::" in qual_name:
      assert False, f"Missing support for standard library type {qual_name}"
      return self.unknown_schema

    return self.lift_decl(tag)

  def lift_type(self, tp: Type) -> Schema:
    """Lift a `Type` into a `Schema`. Returns `UnknownSchema` when the type
    isn't supported."""
    assert isinstance(tp, Type)

    schema: Optional[Schema] = self.type_schemas.get(tp)
    if schema:
      return schema

    if tp.__class__ in self.type_handlers:
      schema = self.type_handlers[tp.__class__](tp)
    else:
      tp_str = " ".join(str(tok) for tok in PrintedTokenRange.create(tp))
      assert False, f"Unhandled type {tp.__class__.__name__} failed: {tp_str}"
      schema = self.unknown_schema

    self.type_schemas[tp] = schema

    return schema

