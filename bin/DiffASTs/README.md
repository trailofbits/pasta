# Diff Clang ASTs Using Pasta + Graphtage

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