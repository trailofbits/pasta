# Normalize `compile_commands.json`

`compile_commands.json` aren't as reliable as they seem. The compiler that
invokes your command is likely implicitly using built-in include directories
that are not explicitly represented in each of your commands. This makes it
challenging for independent tools to get consistent/coherent results given the
same set of commands.

This tool tries to solve this problem by emitting normalized `-cc1` commands
that make implicit things (e.g. include paths, compiler resource directory,
etc.) explicit.

## Usage

```shell
PYTHONPATH=/path/to/build/pasta/bindings/python \
python normalize.py \
    --c_compiler `which clang-15` \
    --cxx_compiler `which clang++-15` \
    ./compile_commands.json
```

## Output

This command will output a new JSON compilation database to `stdout`.