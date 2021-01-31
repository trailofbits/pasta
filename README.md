# PASTA

## Getting and Building the Code

First, update aptitude and get install the baseline dependencies such is for
example `git`, `cmake`, `ninja` and your compiler of choice (remember it needs to support
C++17). It is useful to use the same compiler at every subset to avoid some
name mangling problems. If you're using macOS then we recommend installing
Homebrew, and ensuring that you have Python 3.9 installed, along with an
up-to-date `cmake` and `ninja`.

### cxx-common

As for the dependencies, most of them are provided by [cxx-common](https://github.com/trailofbits/cxx-common). To get them you have two options:
  * Get the pre-built package for some available architectures
  * Build the yourself. (Can take around 40 minutes, since LLVM is being built)
For more depth on each option consult `README` of the project.

If you choose to build it manually first get the sources:

```shell
# Clone
git clone https://github.com/trailofbits/cxx-common.git
cd cxx-common
```

The repository uses [vcpkg](https://github.com/microsoft/vcpkg) which makes entire process rather easy.

```shell
./build_dependencies llvm-11   
```

If you do not plan to tinker with or work on PASTA, then we recommend adding in
`--release` so that you get a release build of LLVM.

It is important *do not forget the llvm-11* option, otherwise it will not build
and subsequently the projects built in next step will try to link system libraries
and that is highly unstable and not
tested (at least for now).


### PASTA

And finally to PASTA itself.
```
git clone https://github.com/trailofbits/pasta.git
cd pasta
mkdir build
cd build
cmake -DVCPKG_ROOT=/path/to/cxx-common/vcpkg ..
make install
```