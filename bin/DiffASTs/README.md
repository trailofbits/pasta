# Diff Clang ASTs Using Pasta + Graphtage

Producing a diff of two Clang ASTs using Pasta and [Graphtage](https://github.com/trailofbits/graphtage) to highlight semantic differences in source code.

## Dependencies

Install `trailofbits/graphtage` using the following command.

```shell
pip install graphtage
```

## Usage
```shell
PYTHONPATH=/path/to/build/pasta/bindings/python \
python diff.py \
  --system-include-dir /path/to/system/usr/include \
  test_before.c test_after.c
```

## Output

```
"#include <stdio.h>                                                                                                                           

int main() {
  printf(\"G̟H̶e̶l̶l̶o ̶W̶or̶l̶db̟y̟e̟!\");
  return 0;
}"
```