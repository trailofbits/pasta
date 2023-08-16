# Print the macro graph

This utility / example outputs a DOT digraph of the macro graph.

The level of verbosity can be configured by editing the following macros within
the source code:

 - `PRINT_DEFINITIONS`: Should nodes for macro definitions be printed?
 - `PRINT_DERIVED`: Should back-edges between tokens be shown? This generally
   shows how tokens in an expansion relate back to a usage.
 - `PRINT_DIRECTIVES`: Should directives, e.g. `#if` directives, be shown?
 - `PRINT_ROLE_COLORS`: Should different background colors be used on nodes
   and cells to distinguish the stages at which a token appeared (e.g. in a
   file, in a macro use, in an expansion, or one that finally reaches the
   parser). 

## Usage

```shell
./print-macro-graph clang test.c
```

## Output

A GraphViz DOT digraph will be printed to `stdout` upon success, and error
messages and debug messages may be printed to `stderr`.

For example, the macro graph for the following C code is as follows:

```c
#define HELLO_WORLD 1
#define CAT3(a, b, c) CAT2(CAT2(a, b), c)
#define CAT2(a, b) CAT2_(a, b)
#define CAT2_(a, b) a ## b

int main() {
  return CAT3(HELLO, _, WORLD);
}
```

![](example.png)
