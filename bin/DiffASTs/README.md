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
python diff.py test_before.cpp test_after.cpp
```

## Output

```
"#include <iostream>

int main() {
  std::cout << \"++G++~~Hell~~o~~ W~~o~~rl~~d++bye++!\" << std::endl;
  return 0;
}"
```