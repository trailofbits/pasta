# Target-specific Builtin Bootstrapper

This is an optional phase of PASTA's bootstrapping process, usually done in
response to issues compiling GCC-based compile commands. Clang can sometimes
struggle to reproduce ASTs produced from GCC-based compile commands. This can
sometimes be the default case if PASTA (which uses and wraps Clang) is compiled
with the GCC. One source of problems is that the GCC supports a different set
of target architecture-specific builtins. In order to handle these, PASTA tries
to declare and augment Clang's set of builtins. To do so, PASTA must actually
specify these builtins according to the proper format. This format is described
in [`clang/Basic/Builtins.def`](https://github.com/llvm/llvm-project/blob/main/clang/include/clang/Basic/Builtins.def#L17).

Assuming we have a C file with a bunch of function declarations, e.g.:

```c
__gcc_v32qi __builtin_ia32_paddb256(__gcc_v32qi, __gcc_v32qi);
// ...
```

Or possibly some conditional declarations:

```c
#if !__has_builtin(__builtin_ia32_paddb256)
__gcc_v32qi __builtin_ia32_paddb256(__gcc_v32qi, __gcc_v32qi);
#endif
```

[CBMC](https://github.com/diepbp/SlicingCBMC/tree/master/ansi-c) turns out to be
a really good source for finding such declarations. We arrange, through the
`-include`d file [GCC.h](GCC.h) in `bootstrap.py` for the CBMC-relevant typedefs
to be defined.

## Usage

```shell
PYTHONPATH=/path/to/build/pasta/bindings/python \
python bootstrap.py path_to_file_with_declarations.c
```

## Output

The output of bootstrap script will be the requisit uses of Clang's
`TARGET_BUILTIN` macro, which must be manually embedded in one of the
`lib/Compile/Builtins*.h` files:

```c
TARGET_BUILTIN(__builtin_ia32_paddb, "V8cV8cV8c", "ncV:64:", "")
```