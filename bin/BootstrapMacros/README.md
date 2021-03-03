# Macro Bootstrap

This binary parses a file and prints out a massive "macro file." The indended
usage is as follows:

```shell
./bootstrap-macros clang -x c++ -c ~/Code/pasta/bin/BootstrapMacros/MacroGenerator.cpp -o /dev/null -isystem ~/Code/pasta/include -isystem ~/Code/cxx-common-11/vcpkg/installed/x64-osx/include/ -std=c++17 > ~/Code/pasta/bin/BootstrapTypes/Generated/Decl.h
```