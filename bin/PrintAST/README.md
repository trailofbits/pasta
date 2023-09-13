# Pretty print the parsed code

This utility parses the code, builds an AST, then pretty prints it back to
C/C++ code. You shouldn't expect the output to be identical to what is parsed.
The output will not include comments, and hopefully the whitespace will be
correct.

## Usage


```shell
./print-ast clang test.c
```
