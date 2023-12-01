# Copyright (c) 2023 Trail of Bits, Inc., all rights reserved.

from lift import *
from wrap import wrap, Renamer

def run_on_ast(ast: AST, ns_name: str):
  schemas: List[Schema] = []
  lifter = SchemaLifter()

  # Filter out all tag decls that aren't private `*Impl` classes, and also
  # only look at the definitions.
  for tag in find_tags_in_namespace(ast.translation_unit, ns_name):
    if not tag.name.endswith("Impl") and tag.is_this_declaration_a_definition:
      schema: Schema = lifter.lift_decl(tag)
      if isinstance(schema, NamedSchema):
        yield schema


class BasicRenamer(Renamer):
  METHOD_RENAMES = {
    "from": "cast",
    "in": "contained_in",
  }
  def rename_method(self, class_schema: ClassSchema,
                    method_schema: MethodSchema | OverloadSetSchema) -> str:
    return self.METHOD_RENAMES.get(method_schema.name, method_schema.name)


if __name__ == "__main__":
  parser = ArgumentParser(description='Create an inventory of the API surface area of the classes / enumerator within a namespace')
  parser.add_argument('--namespace', default="pasta")
  parser.add_argument('--local_include_dir', required=True)
  parser.add_argument('--system_include_dir', required=True)
  parser.add_argument('--working_dir', default=os.path.dirname(__file__))
  parser.add_argument('--source_file', default="PASTA.cpp")
  args = parser.parse_args()
  fs: FileSystem = FileSystem.create_native()
  fm: FileManager = FileManager(fs)
  cxx: Compiler = Compiler.create_host_compiler(fm, TargetLanguage.CXX)
  argv = ArgumentVector([
      str(cxx.executable_path),
      "-x", "c++",
      "-std=c++20",
      "-isystem", str(args.local_include_dir),
      "-isystem", str(args.system_include_dir),
      "-DGAP_ENABLE_COROUTINES",
      str(args.source_file)])

  cmd = CompileCommand.create_from_arguments(argv, args.working_dir)
  maybe_jobs = cxx.create_jobs_for_command(cmd)
  renamer = BasicRenamer()
  
  if isinstance(maybe_jobs, str):
    print(maybe_jobs)
    sys.exit(1)

  for job in maybe_jobs:
    maybe_ast = job.run()
    if isinstance(maybe_ast, str):
      print(maybe_ast)
      sys.exit(1)

    elif isinstance(maybe_ast, AST):
      wrap(run_on_ast(maybe_ast, args.namespace), renamer)
        

