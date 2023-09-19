# Copyright (c) 2023 Trail of Bits, Inc., all rights reserved.

from pypasta import *
from argparse import ArgumentParser
from schema import *
from typing import Callable, Dict, Iterable, List, Optional, TypedDict

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


def _relative_location(tok: Token) -> str:
  path: pathlib.Path = File.containing(tok.file_location).path
  parts: List[str] = []

  while len(path.name):
    if path.name == 'include':
      break
    parts.append(path.name)
    path = path.parent

  return str(os.path.join(*reversed(parts)))

def decl_location(decl: Decl) -> str:
  """Find the relative path of the include file containing `decl`."""
  for tok in decl.tokens:
    if tok.role in (TokenRole.FILE_TOKEN, TokenRole.INITIAL_MACRO_USE_TOKEN):
      return _relative_location(tok)
    elif tok.role == TokenRole.FINAL_MACRO_EXPANSION_TOKEN:
      macro = tok.macro_location
      while macro.parent:
        macro = macro.parent
      return _relative_location(macro.first_use_token.parsed_location)
  assert False
  return ""


def nth_template_argument(tag: TagDecl, n: int) -> Optional[TemplateArgument]:
  """Return the `n`th template argument."""
  if not isinstance(tag, ClassTemplateSpecializationDecl):
    return None

  args: List[TemplateArgument] = list(tag.template_arguments)
  if n >= len(args):
    return None

  return args[n]


class SchemaLifter:
  """Lift declarations into schemas."""
  decl_schemas: Dict[Decl, Schema]
  type_schemas: Dict[Type, Schema]
  unknown_schema: UnknownSchema
  std_path_schema: StdFilesystemPathSchema
  std_string_schema: StdStringSchema
  std_string_view_schema: StdStringViewSchema
  char_schema: CharSchema

  qual_name_type_schemas: Dict[str, Callable[[TagDecl], Schema]]
  type_handlers: Dict[type[Type], Callable[[Type], Schema]]
  builtin_type_schemas: Dict[BuiltinTypeKind, BuiltinTypeSchema]

  def __init__(self):
    self.decl_schemas = {}
    self.type_schemas = {}
    self.unknown_schema = UnknownSchema()
    self.std_path_schema = StdFilesystemPathSchema()
    self.std_string_schema = StdStringSchema()
    self.std_string_view_schema = StdStringViewSchema()

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
      TemplateTypeParmType: self._lift_template_param_type,
      AutoType: self._lift_auto_type,
      RValueReferenceType: self._lift_unsupported,
      ConstantArrayType: self._lift_unsupported,
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
      "std::filesystem::path": self._lift_std_filesystem_path,
      "std::string": self._lift_std_string,
      "std::basic_string": self._lift_std_string,
      "std::string_view": self._lift_std_string_view,
      "std::basic_string_view": self._lift_std_string_view,
      "std::optional": self._lift_std_optional,
      "std::vector": self._lift_std_vector,
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
      "std::map": self._lift_std_map,
      "std::unordered_map": self._lift_std_unordered_map,
      "std::set": self._lift_std_set,
      "std::unordered_set": self._lift_std_unordered_set,
      "std::variant": self._lift_unsupported,
      "std::__wrap_iter": self._lift_std_wrap_iter,
      "std::reverse_iterator": self._lift_unsupported,
      "std::tuple": self._lift_unsupported,
      "std::pair": self._lift_unsupported,
      "std::function": self._lift_unsupported,
      "std::__optional_destruct_base::": self._lift_unsupported,
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

  def _lift_member(self, member: ValueDecl) -> Optional[VarSchema]:
    """Lift a method parameter, static member, or field into a schema."""

    type_schema = self.lift_type(member.type)
    if isinstance(type_schema, UnknownSchema):
      return None

    return VarSchema(member.name, type_schema)

  def _lift_method(self, method: CXXMethodDecl) -> Optional[MethodSchema]:
    """Lift a `CXXMethodDecl` into a `MethodSchema`. If this fails, then
    `None` is returned."""

    if not len(method.name):
      return None

    type_schema = self.lift_type(method.return_type)
    if isinstance(type_schema, UnknownSchema):
      return None

    schema = MethodSchema(method.name, type_schema)

    for i, decl in enumerate(method.parameters):
      type_schema = self.lift_type(decl.type)
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


  def _lift_iterated_type_from_iterator(self, tag: RecordDecl) -> Schema:
    """Try to go and drill into `tag`, find `operator*` and then lift its
    return type."""

    for decl in decls_in_dc_decl(tag):
      if isinstance(decl, CXXMethodDecl) and \
         decl.is_overloaded_operator and \
         decl.access == AccessSpecifier.PUBLIC and \
         decl.overloaded_operator == OverloadedOperatorKind.STAR and \
         not len(decl.parameters):
        return self.lift_type(decl.return_type)

    return self.unknown_schema

  def _unwrap_std_wrap_iter(self, tag: ClassTemplateSpecializationDecl) -> Schema:
    """Assuming `tag` represents `std::__wrap_iter`, try to find the iterator
    inside its template argument and extract a schema for the iterated type."""
    arg: Optional[TemplateArgument] = nth_template_argument(tag, 0)
    if not arg:
      return self.unknown_schema

    tp: Optional[Type] = arg.as_type
    decl: Optiona[Decl] = arg.as_declaration
    if tp:
      return self._lift_iterator(tp)

    if decl:
      if isinstance(decl, RecordType):
        return self._lift_iterated_type_from_iterator(decl)

    assert False, f"Unrecognized tag type {tag.__class__} with name {tag.name}"
    return self.unknown_schema

  def _lift_iterator(self, tp: Type) -> Schema:
    """Recover the iterator type, and lift out the iterated type."""
    
    # Unwrap the method's return type.
    while isinstance(tp, (QualifiedType, TypedefType, ReferenceType,
                          TemplateSpecializationType, DecltypeType,
                          ElaboratedType, SubstTemplateTypeParmType,
                          AdjustedType, AutoType)):
      tp = tp.unqualified_type.desugar

    # Pointers are the easiest form of iterator to support; the iterated type
    # is the pointer element type.
    if isinstance(tp, PointerType):
      schema = self.lift_type(tp)
      if isinstance(schema, RawPointerSchema):
        return schema.element_type
      if isinstance(schema, CStringSchema):
        return self.char_schema
      return self.unknown_schema

    if not isinstance(tp, RecordType):
      assert False, f"Unrecognied iterator type class {tp.__class__}"
    
    tag: RecordDecl = tp.declaration

    # Check if we're wrapping another iterator.
    if isinstance(tag, ClassTemplateSpecializationDecl):
      if qualified_name(tag) == "std::__wrap_iter":
        return self._unwrap_std_wrap_iter(tag)

    return self._lift_iterated_type_from_iterator(tag)

  def _lift_iterated_method(self, meth: CXXMethodDecl) -> Schema:
    """Assuming `meth` is the `begin` method on a class that follows C++'s
    range/iterator protocol, then try to figure out the generated type from
    inspecting the overloaded operator(s) of the return iterator type."""

    return self._lift_iterator(meth.return_type)

  def _lift_class(self, tag: CXXRecordDecl) -> Schema:
    """Lift a `CXXRecordDecl` into a `Schema`."""
    if tag in self.decl_schemas:
      return self.decl_schemas[tag]

    # We do not allow binding of `union`s, they are not friendly to binidng.
    if tag.tag_kind == TagTypeKind.UNION:
      self.decl_schemas[tag] = self.unknown_schema
      return self.unknown_schema

    # Cache it early on, so that we can handle self-referential types.
    schema: ClassSchema = ClassSchema(tag.name)
    self.decl_schemas[tag] = schema

    # Capture base classes. If we can't lift a base class then we ignore it.
    if tag.num_bases:
      for base_tag in base_classes(tag):
        base_schema = self.lift_decl(base_tag)
        if isinstance(base_schema, ClassSchema):
          schema.bases.append(base_schema)

    # If this is a `class`, as opposed to a `struct` or `union`, then start
    # by treating the access as private, and so skip anything we come across
    # by default.
    skip = tag.tag_kind == TagTypeKind.CLASS

    num_accessors = 0

    begin_decl: Optional[CXXMethodDecl] = None
    end_decl: Optional[CXXMethodDecl] = None

    for decl in decls_in_dc_decl(tag):
      
      # Turn on skipping if the access specifier hasn't changed to `public`.
      if isinstance(decl, AccessSpecDecl):
        skip = decl.access_specifier_token.data != "public"
        continue

      # Don't inventory stuff with `private` or `protected` visibility.
      if skip:
        continue

      # E.g. `FriendDecl`.
      if not isinstance(decl, NamedDecl):
        continue

      # Instance members.
      if isinstance(decl, FieldDecl):
        member_schema: Optional[VarSchema] = self._lift_member(decl)
        if member_schema:
          schema.members[decl.name] = member_schema
          num_accessors += 1
        continue

      # Static members.
      if isinstance(decl, VarDecl):
        member_schema: Optional[VarSchema] = self._lift_member(decl)
        if member_schema:
          schema.static_members[decl.name] = member_schema
        continue

      # Nested enums/classes
      if isinstance(decl, (TypedefNameDecl, TagDecl)):
        nested_decl = self.lift_decl(decl)
        if isinstance(nested_decl, NamedSchema):
          schema.nested_schemas[decl.name] = nested_decl
        continue

      if isinstance(decl, CXXDestructorDecl):
        continue

      # Detect presence of `operator bool()` overloaded operator.
      if isinstance(decl, CXXConversionDecl):
        if isinstance(self.lift_type(decl.return_type), BooleanSchema):
          schema.has_boolean_conversion = True
        continue

      if isinstance(decl, CXXMethodDecl):
        if decl.is_implicit or decl.is_overloaded_operator:
          continue

        section: Dict[str, MethodSchema] = None
        if decl.is_instance:
          if isinstance(decl, CXXConstructorDecl):
            section = schema.constructors
          else:

            # Try to detect an iterator protocol.
            if decl.name == "begin":
              begin_decl = decl
              continue
            elif decl.name == "end":
              end_decl = decl
              continue

            section = schema.methods
            num_accessors += 1
        else:
          section = schema.static_methods

        # Prefer overloads that are `const`-qualified.
        if decl.name in section:
          prev_method_schema = section[decl.name]
          if prev_method_schema.is_const:
            continue

        # Lift the method.
        method_schema: Optional[MethodSchema] = self._lift_method(decl)
        if not method_schema or isinstance(method_schema, UnknownSchema):
          continue

        method_schema.is_const = decl.is_const
        section[decl.name] = method_schema

    # It looks like this follows an iterator protocol.
    if begin_decl and end_decl:
      iterated_schema = self._lift_iterated_method(begin_decl)
      if not isinstance(iterated_schema, UnknownSchema):
        num_accessors += 1
        schema.generated_type = iterated_schema

    # This class doesn't expose any stateful accessors, so we'll drop it.
    if not num_accessors:
      self.decl_schemas[tag] = self.unknown_schema
      return self.unknown_schema

    schema.location = decl_location(tag)

    return schema

  def _lift_enum(self, tag: EnumDecl) -> Schema:
    """Lift an `EnumDecl` into an `EnumSchema`."""
    if tag in self.decl_schemas:
      return self.decl_schemas[tag]

    # Get the schema for the underlying integer type.
    int_type: Schema = self.lift_type(tag.integer_type)
    if not isinstance(int_type, IntegerSchema):
      self.decl_schemas[tag] = self.unknown_schema
      return self.unknown_schema

    schema: EnumSchema = EnumSchema(tag.name, tag.is_scoped_using_class_tag,
                                    int_type)

    if len(tag.integer_type_range):
      schema.is_explicitly_typed = True

    for decl in decls_in_dc_decl(tag):
      assert isinstance(decl, EnumConstantDecl)
      schema.enumerators.append(decl.name)

    # If there are no enumerators, then we can't guarantee that this can be
    # usefully wrapped.
    if not len(schema.enumerators):
      self.decl_schemas[tag] = self.unknown_schema
      return self.unknown_schema

    schema.location = decl_location(tag)

    self.decl_schemas[tag] = schema
    return schema

  def _lift_typedef(self, typedef: TypedefNameDecl) -> Schema:
    """Lift a `TypedefNameDecl`, i.e. a `typedef` or a `using`, into an
    `AliasSchema`."""
    if typedef in self.decl_schemas:
      return self.decl_schemas[typedef]

    nested_schema: Schema = self.lift_type(typedef.underlying_type)
    if isinstance(nested_schema, UnknownSchema):
      self.decl_schemas[typedef] = nested_schema
      return nested_schema

    # Drill down through the aliases.
    while isinstance(nested_schema, AliasSchema):
      nested_schema = nested_schema.base_type

    schema: Schema = AliasSchema(typedef.name, nested_schema)
    schema.location = decl_location(typedef)

    # Handle an alias, e.g. `using string_view = std::basic_string_view<...>;`.
    qual_name = qualified_name(typedef)
    if qual_name in self.qual_name_type_schemas:
      schema = nested_schema

    # Handle things like `size_t`.    
    if isinstance(nested_schema, BuiltinTypeSchema):
      schema = nested_schema

    self.decl_schemas[typedef] = schema
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
    
    # Don't lift anything that can't be named, and whose parent's can't be
    # lifted, or that is a template or partially specialized template.
    if not isinstance(decl, NamedDecl) or \
       not len(decl.name) or \
       isinstance(self, (ClassTemplatePartialSpecializationDecl,
                         VarTemplatePartialSpecializationDecl,
                         TemplateDecl)) or \
       not self._lift_parent(decl):

      self.decl_schemas[decl] = self.unknown_schema
      return self.unknown_schema

    if isinstance(decl, CXXRecordDecl):
      return self._lift_class(decl)
      
    elif isinstance(decl, EnumDecl):
      return self._lift_enum(decl)

    elif isinstance(decl, TypedefNameDecl):
      return self._lift_typedef(decl)

    assert False
    self.decl_schemas[decl] = self.unknown_schema
    return self.unknown_schema

  def _lift_qualified_type(self, tp: QualifiedType) -> Schema:
    return self.unknown_schema

    # # We don't like `restrict` or `volatile` things.
    # if not tp.is_const_qualified or tp.is_restrict_qualified or \
    #    tp.is_volatile_qualified:
    #    return self.unknown_schema

    # ut: Type = tp.unqualified_type

    # # Detect a `T * const`... Doesn't really affect us
    # if isinstance(ut, PointerType):
    #   return self.lift_type(ut)

    # tp_str = " ".join(str(tok) for tok in PrintedTokenRange.create(tp))
    # print(f"Ignoring {ut.__class__.__name__}: {tp_str}")
    # return self.unknown_schema

  def _lift_reference_type(self, tp: ReferenceType) -> Schema:
    pt: Type = tp.pointee_type
    is_const = False
    if isinstance(pt, QualifiedType):
      is_const = pt.is_const_qualified

      # Reject `const`- and `restrict`-qualified reference element types.
      if pt.is_restrict_qualified or pt.is_volatile_qualified:
        return self.unknown_schema

      pt = pt.unqualified_type  # Unwrap the qualification

    # Don't allow pointers-to-unknowns, or pointers-to-pointers.
    ps: Schema = self.lift_type(pt)
    if isinstance(ps, (UnknownSchema, PointerLikeSchema, CStringSchema)):
      return self.unknown_schema

    if isinstance(ps, Int8Schema) and is_const:
        return CStringSchema()

    return is_const and ConstReferenceSchema(ps) or ReferenceSchema(ps)

    return self.lift_type(tp.pointee_type)

  def _lift_builtin_type(self, tp: BuiltinType) -> Schema:
    return self.builtin_type_schemas.get(tp.builtin_kind, self.unknown_schema)

  def _lift_typedef_type(self, tp: TypedefType) -> Schema:
    return self._lift_typedef(tp.declaration)

  def _lift_elaborated_type(self, tp: ElaboratedType) -> Schema:
    return self.lift_type(tp.desugar)

  def _lift_spec_type(self, tp: TemplateSpecializationType) -> Schema:
    return self.lift_type(tp.desugar)

  def _lift_substituted_type(self, tp: SubstTemplateTypeParmType) -> Schema:
    return self.lift_type(tp.replacement_type)

  def _lift_using_type(self, tp: UsingType) -> Schema:
    return self.lift_decl(tp.found_declaration.target_declaration)

  def _lift_pointer_type(self, tp: PointerType) -> Schema:
    pt: Type = tp.pointee_type
    is_const = False
    if isinstance(pt, QualifiedType):
      is_const = pt.is_const_qualified

      # Reject `const`- and `restrict`-qualified pointer element types.
      if pt.is_restrict_qualified or pt.is_volatile_qualified:
        return self.unknown_schema

      pt = pt.unqualified_type  # Unwrap the qualification

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
    if tp.is_parameter_pack:
      return self.unknown_schema
    if tp.is_sugared:
      return self.lift_type(tp.desugar)
    return self.unknown_schema

  def _lift_auto_type(self, tp: AutoType) -> Schema:
    return self.lift_type(tp.desugar)

  def _lift_unsupported(self, *args) -> Schema:
    return self.unknown_schema

  def _lift_std_filesystem_path(self, tag: TagDecl) -> Schema:
    return self.std_path_schema

  def _lift_std_string(self, tag: TagDecl) -> Schema:
    arg = self._lift_nth_template_argument(tag, 0)
    if not isinstance(arg, Int8Schema):
      return self.unknown_schema
    return self.std_string_schema

  def _lift_std_string_view(self, tag: TagDecl) -> Schema:
    arg = self._lift_nth_template_argument(tag, 0)
    if not isinstance(arg, Int8Schema):
      return self.unknown_schema
    return self.std_string_view_schema

  def _lift_1_parameter(self, tag: TagDecl, container: type[Schema]) -> Schema:
    arg = self._lift_nth_template_argument(tag, 0)
    if not isinstance(arg, Int8Schema):
      return self.unknown_schema
    return container(arg)

  def _lift_std_optional(self, tag: TagDecl) -> Schema:
    return self._lift_1_parameter(tag, StdOptionalSchema)

  def _lift_std_vector(self, tag: TagDecl) -> Schema:
    return self._lift_1_parameter(tag, StdVectorSchema)

  def _lift_std_set(self, tag: TagDecl) -> Schema:
    return self._lift_1_parameter(tag, StdSetSchema)

  def _lift_std_unordered_set(self, tag: TagDecl) -> Schema:
    return self._lift_1_parameter(tag, StdUnorderedSetSchema)

  def _lift_2_parameter(self, tag: TagDecl, container: type[Schema]) -> Schema:
    key = self._lift_nth_template_argument(tag, 0)
    val = self._lift_nth_template_argument(tag, 1)
    if isinstance(key, UnknownSchema) or isinstance(val, UnknownSchema):
      return self.unknown_schema
    return container(key, val)

  def _lift_std_map(self, tag: TagDecl) -> Schema:
    return self._lift_2_parameter(tag, StdMapSchema)

  def _lift_std_unordered_map(self, tag: TagDecl) -> Schema:
    return self._lift_2_parameter(tag, StdUnorderedMapSchema)

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

  def _lift_std_wrap_iter(self, tag: TagDecl) -> Schema:
    return self._lift_nth_template_argument(tag, 0)

  def _lift_gap_generator(self, tag: TagDecl) -> Schema:
    arg = self._lift_nth_template_argument(tag, 0)
    if isinstance(arg, UnknownSchema):
      return self.unknown_schema
    return GapGeneratorSchema(arg)

  def _make_lifter(self, constructor: type[Schema]) -> Callable[[TagDecl], Schema]:
    def do_lift(tag: TagDecl):
      return constructor()
    return do_lift

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

    if "llvm::" in qual_name:
      print(f"!!! {qual_name}")

    return self.lift_decl(tag)

  def lift_type(self, tp: Type) -> Schema:
    """Lift a `Type` into a `Schema`. Returns `UnknownSchema` when the type
    isn't supported."""
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

