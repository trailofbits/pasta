# Blowtorch

The purpose of this script is to use Python to invoke every method possible on
all of the AST objects, then catch exceptions thrown by the C++ side of the
code. PASTA's C++ API is value-based, but Clang's API is pointer-based. When
Clang returns a `nullptr`, or triggers an `assert`ion, then we want to capture
that optionality / fallability of the API via a `std::optional`-wrapped return
type. There is a manual list of these in the API bootstrapper.

Sometimes the manual list, as known by the API bootstrapper, isn't enough. The
blowtorch script exists to help us try to find more APIs that should be wrapped
in `std::optional` return types. The blowtorch takes a `compiled_commands.json`
and tries to reproduce each AST, then for each AST, it recursively traverses all
objects and invokes all methods until it reaches a fixpoint.

## Usage

```shell
PYTHONPATH=/path/to/build/pasta/bindings/python \
python blowtorch.py compile_commands.json
```

An optional command-line argument, `--sequential`, is provided to force the
blowtorch process to run one command at a time, rather than multiple in
parallel.

## Output

The exceptions triggered, which helps to document which methods need to be
inspected for `std::optional` wrapping.