# Print the main source file of a compile command

This utility prints out the file contents of the main source file, one token
at a time, of a compile command (after building the AST). It doesn't really
do much else.

## Usage

```shell
./print-main-source-file clang test.c
```
