# Type Bootstrap

This is "stage 2" of the PASTA bootstrap process. It uses the generated macros
file to emit PASTA's wrapper API. Running this phase will overwrite multiple
files, including `include/pasta/AST/Forward.h`, `include/pasta/AST/Decl.h`,
`lib/AST/Decl.cpp`, etc.

# Usage

```shell
./bootstrap-types
```