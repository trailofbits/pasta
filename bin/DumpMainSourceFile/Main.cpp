/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <pasta/AST/AST.h>
#include <pasta/AST/Decl.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/FileSystem.h>
#include <pasta/Util/Init.h>

#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
const char *sysroot = R"AAA(Apple clang version 14.0.0 (clang-1400.0.29.202)
Target: x86_64-apple-darwin22.1.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
 "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang" -cc1 -triple x86_64-apple-macosx13.0.0 -Wundef-prefix=TARGET_OS_ -Wdeprecated-objc-isa-usage -Werror=deprecated-objc-isa-usage -Werror=implicit-function-declaration -emit-obj -mrelax-all --mrelax-relocations -disable-free -clear-ast-before-backend -disable-llvm-verifier -discard-value-names -main-file-name udf.c -mrelocation-model pic -pic-level 2 -mframe-pointer=all -fno-strict-return -fno-rounding-math -funwind-tables=2 -target-sdk-version=13.0 -fvisibility-inlines-hidden-static-local-var -target-cpu penryn -tune-cpu generic -debugger-tuning=lldb -target-linker-version 820.1 -v -P -resource-dir /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/14.0.0 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX13.0.sdk -include /trail/of/bits -D LIBUDF -D udf_EXPORTS -I /Users/pag/Code/MonetDB/common/stream -I /Users/pag/Code/MonetDB/common/utils -I /Users/pag/Code/MonetDB/gdk -I /Users/pag/Code/MonetDB/monetdb5/mal -I /Users/pag/Code/MonetDB/monetdb5/modules/mal -I /Users/pag/Code/MonetDB/monetdb5/modules/atoms -I /Users/pag/Code/MonetDB/sql/backends/monet5 -I /Users/pag/Code/MonetDB/clients/mapilib -I /Users/pag/Code/MonetDB/sql/include -I /Users/pag/Code/MonetDB/sql/server -I /Users/pag/Code/MonetDB/sql/common -I /Users/pag/Code/MonetDB/sql/storage -I /Users/pag/Code/MonetDB/sql/backends/monet5/UDF/udf -I /Users/pag/Code/MonetDB -internal-isystem /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX13.0.sdk/usr/local/include -internal-isystem /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/14.0.0/include -internal-externc-isystem /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX13.0.sdk/usr/include -internal-externc-isystem /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -Wno-format-nonliteral -Wno-cast-function-type -Wno-missing-braces -Wno-missing-field-initializers -Wno-char-subscripts -Wno-unreachable-code -Wno-everything -Wno-reorder-init-list -Wno-implicit-int-float-conversion -Wno-c99-designator -Wno-final-dtor-non-final-class -Wno-extra-semi-stmt -Wno-misleading-indentation -Wno-quoted-include-in-framework-header -Wno-implicit-fallthrough -Wno-enum-enum-conversion -Wno-enum-float-conversion -Wno-elaborated-enum-base -Wno-reserved-identifier -Wno-gnu-folding-constant -Wno-cast-function-type -Wno-bitwise-instead-of-logical -w -std=gnu99 -fdebug-compilation-dir=/Users/pag/Code/MonetDB/sql/backends/monet5/UDF/udf -ferror-limit 19 -stack-protector 3 -fstack-check -mdarwin-stkchk-strong-link -fblocks -fencode-extended-block-signature -fregister-global-dtors-with-atexit -fgnuc-version=4.2.1 -fmax-type-align=16 -fcommon -dD -clang-vendor-feature=+messageToSelfInClassMethodIdReturnType -clang-vendor-feature=+disableInferNewAvailabilityFromInit -clang-vendor-feature=+disableNonDependentMemberExprInCurrentInstantiation -fno-odr-hash-protocols -clang-vendor-feature=+enableAggressiveVLAFolding -clang-vendor-feature=+revert09abecef7bbf -clang-vendor-feature=+thisNoAlignAttr -clang-vendor-feature=+thisNoNullAttr -mllvm -disable-aligned-alloc-awareness=1 -D__GCC_HAVE_DWARF2_CFI_ASM=1 -o CMakeFiles/udf.dir/udf.c.o -x c /Users/pag/Code/MonetDB/sql/backends/monet5/UDF/udf/udf.c
clang -cc1 version 14.0.0 (clang-1400.0.29.202) default target x86_64-apple-darwin22.1.0
ignoring nonexistent directory "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX13.0.sdk/usr/local/include"
ignoring nonexistent directory "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX13.0.sdk/Library/Frameworks"
#include "..." search starts here:
#include <...> search starts here:
 /Users/pag/Code/MonetDB/common/stream
 /Users/pag/Code/MonetDB/common/utils
 /Users/pag/Code/MonetDB/gdk
 /Users/pag/Code/MonetDB/monetdb5/mal
 /Users/pag/Code/MonetDB/monetdb5/modules/mal
 /Users/pag/Code/MonetDB/monetdb5/modules/atoms
 /Users/pag/Code/MonetDB/sql/backends/monet5
 /Users/pag/Code/MonetDB/clients/mapilib
 /Users/pag/Code/MonetDB/sql/include
 /Users/pag/Code/MonetDB/sql/server
 /Users/pag/Code/MonetDB/sql/common
 /Users/pag/Code/MonetDB/sql/storage
 /Users/pag/Code/MonetDB/sql/backends/monet5/UDF/udf
 /Users/pag/Code/MonetDB
 /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/14.0.0/include
 /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX13.0.sdk/usr/include
 /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include
 /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX13.0.sdk/System/Library/Frameworks (framework directory)
End of search list.
<built-in>:1:10: fatal error: '/trail/of/bits' file not found
#include "/trail/of/bits"
         ^~~~~~~~~~~~~~~~
1 error generated.)AAA";


const char *no_sysroot = R"AAA(Apple clang version 14.0.0 (clang-1400.0.29.202)
Target: x86_64-apple-darwin22.1.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
 "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang" -cc1 -triple x86_64-apple-macosx13.0.0 -Wundef-prefix=TARGET_OS_ -Wdeprecated-objc-isa-usage -Werror=deprecated-objc-isa-usage -Werror=implicit-function-declaration -emit-obj -mrelax-all --mrelax-relocations -disable-free -clear-ast-before-backend -disable-llvm-verifier -discard-value-names -main-file-name udf.c -mrelocation-model pic -pic-level 2 -mframe-pointer=all -fno-strict-return -fno-rounding-math -funwind-tables=2 -fcompatibility-qualified-id-block-type-checking -fvisibility-inlines-hidden-static-local-var -target-cpu penryn -tune-cpu generic -debugger-tuning=lldb -target-linker-version 820.1 -v -P -resource-dir /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/14.0.0 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX13.0.sdk -include /trail/of/bits -isysroot /Users/pag/Code/MonetDB/sql/backends/monet5/UDF/udf/trail_of_bits -D LIBUDF -D udf_EXPORTS -I /Users/pag/Code/MonetDB/common/stream -I /Users/pag/Code/MonetDB/common/utils -I /Users/pag/Code/MonetDB/gdk -I /Users/pag/Code/MonetDB/monetdb5/mal -I /Users/pag/Code/MonetDB/monetdb5/modules/mal -I /Users/pag/Code/MonetDB/monetdb5/modules/atoms -I /Users/pag/Code/MonetDB/sql/backends/monet5 -I /Users/pag/Code/MonetDB/clients/mapilib -I /Users/pag/Code/MonetDB/sql/include -I /Users/pag/Code/MonetDB/sql/server -I /Users/pag/Code/MonetDB/sql/common -I /Users/pag/Code/MonetDB/sql/storage -I /Users/pag/Code/MonetDB/sql/backends/monet5/UDF/udf -I /Users/pag/Code/MonetDB -internal-isystem /Users/pag/Code/MonetDB/sql/backends/monet5/UDF/udf/trail_of_bits/usr/local/include -internal-isystem /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/14.0.0/include -internal-externc-isystem /Users/pag/Code/MonetDB/sql/backends/monet5/UDF/udf/trail_of_bits/usr/include -internal-externc-isystem /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -Wno-format-nonliteral -Wno-cast-function-type -Wno-missing-braces -Wno-missing-field-initializers -Wno-char-subscripts -Wno-unreachable-code -Wno-everything -Wno-reorder-init-list -Wno-implicit-int-float-conversion -Wno-c99-designator -Wno-final-dtor-non-final-class -Wno-extra-semi-stmt -Wno-misleading-indentation -Wno-quoted-include-in-framework-header -Wno-implicit-fallthrough -Wno-enum-enum-conversion -Wno-enum-float-conversion -Wno-elaborated-enum-base -Wno-reserved-identifier -Wno-gnu-folding-constant -Wno-cast-function-type -Wno-bitwise-instead-of-logical -w -std=gnu99 -fdebug-compilation-dir=/Users/pag/Code/MonetDB/sql/backends/monet5/UDF/udf -ferror-limit 19 -stack-protector 3 -fstack-check -mdarwin-stkchk-strong-link -fblocks -fencode-extended-block-signature -fregister-global-dtors-with-atexit -fgnuc-version=4.2.1 -fmax-type-align=16 -fcommon -dD -clang-vendor-feature=+messageToSelfInClassMethodIdReturnType -clang-vendor-feature=+disableInferNewAvailabilityFromInit -clang-vendor-feature=+disableNonDependentMemberExprInCurrentInstantiation -fno-odr-hash-protocols -clang-vendor-feature=+enableAggressiveVLAFolding -clang-vendor-feature=+revert09abecef7bbf -clang-vendor-feature=+thisNoAlignAttr -clang-vendor-feature=+thisNoNullAttr -mllvm -disable-aligned-alloc-awareness=1 -D__GCC_HAVE_DWARF2_CFI_ASM=1 -o CMakeFiles/udf.dir/udf.c.o -x c /Users/pag/Code/MonetDB/sql/backends/monet5/UDF/udf/udf.c
clang -cc1 version 14.0.0 (clang-1400.0.29.202) default target x86_64-apple-darwin22.1.0
ignoring nonexistent directory "/Users/pag/Code/MonetDB/sql/backends/monet5/UDF/udf/trail_of_bits/usr/local/include"
ignoring nonexistent directory "/Users/pag/Code/MonetDB/sql/backends/monet5/UDF/udf/trail_of_bits/usr/include"
ignoring nonexistent directory "/Users/pag/Code/MonetDB/sql/backends/monet5/UDF/udf/trail_of_bits/System/Library/Frameworks"
ignoring nonexistent directory "/Users/pag/Code/MonetDB/sql/backends/monet5/UDF/udf/trail_of_bits/Library/Frameworks"
#include "..." search starts here:
#include <...> search starts here:
 /Users/pag/Code/MonetDB/common/stream
 /Users/pag/Code/MonetDB/common/utils
 /Users/pag/Code/MonetDB/gdk
 /Users/pag/Code/MonetDB/monetdb5/mal
 /Users/pag/Code/MonetDB/monetdb5/modules/mal
 /Users/pag/Code/MonetDB/monetdb5/modules/atoms
 /Users/pag/Code/MonetDB/sql/backends/monet5
 /Users/pag/Code/MonetDB/clients/mapilib
 /Users/pag/Code/MonetDB/sql/include
 /Users/pag/Code/MonetDB/sql/server
 /Users/pag/Code/MonetDB/sql/common
 /Users/pag/Code/MonetDB/sql/storage
 /Users/pag/Code/MonetDB/sql/backends/monet5/UDF/udf
 /Users/pag/Code/MonetDB
 /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/14.0.0/include
 /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include
End of search list.
<built-in>:1:10: fatal error: '/trail/of/bits' file not found
#include "/trail/of/bits"
         ^~~~~~~~~~~~~~~~
1 error generated.
)AAA";

int main(int argc, char *argv[]) {
  if (2 > argc) {
    std::cerr << "Usage: " << argv[0] << " COMPILE_COMMAND..."
              << std::endl;
    return EXIT_FAILURE;
  }

  pasta::InitPasta initializer;
  pasta::FileManager fm(pasta::FileSystem::CreateNative());
  auto maybe_compiler = pasta::Compiler::Create(
      fm, "/usr/bin/clang",
      "/Users/pag/Code/MonetDB/sql/backends/monet5/UDF/udf",
      pasta::CompilerName::kAppleClang,
      pasta::TargetLanguage::kC, sysroot, no_sysroot);

  if (!maybe_compiler.Succeeded()) {
    std::cerr << maybe_compiler.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  auto maybe_cwd = pasta::FileSystem::From(maybe_compiler.Value())->CurrentWorkingDirectory();
  if (!maybe_cwd.Succeeded()) {
    std::cerr << maybe_compiler.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  const pasta::ArgumentVector args(argc - 1, &argv[1]);
  auto maybe_command = pasta::CompileCommand::CreateFromArguments(
      args, maybe_cwd.TakeValue());
  if (!maybe_command.Succeeded()) {
    std::cerr << maybe_command.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  const auto command = maybe_command.TakeValue();
  auto maybe_jobs = maybe_compiler->CreateJobsForCommand(command);
  if (!maybe_jobs.Succeeded()) {
    std::cerr << maybe_jobs.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  for (const pasta::CompileJob &job : maybe_jobs.TakeValue()) {
    std::cerr << job.Arguments().Join() << "\n\n";
    auto maybe_ast = job.Run();
    if (!maybe_ast.Succeeded()) {
      std::cerr << maybe_ast.TakeError() << std::endl;
      return EXIT_FAILURE;
    } else {
      for (auto tok : maybe_ast.TakeValue().MainFile().Tokens()) {
        std::cerr << tok.Data();
      }
    }
  }

  return EXIT_SUCCESS;
}
