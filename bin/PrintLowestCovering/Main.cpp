#include <fcntl.h>
#include <pasta/AST/AST.h>
#include <pasta/AST/Macro.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/File.h>
#include <pasta/Util/FileSystem.h>
#include <pasta/Util/Init.h>
#include <unistd.h>

#include <csignal>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_set>

void PrintTokensTo(std::iostream &s, const pasta::TokenRange &tokens) {
  int i = 0;
  for (auto &&token : tokens) {
    if (token.Role() == pasta::TokenRole::kFinalMacroExpansionToken ||
        token.Role() == pasta::TokenRole::kFileToken) {
      if (i > 0) {
        s << ' ';
      }
      s << token.Data();
      i++;
    }
  }
}

void PrintLowestCovering(const pasta::MacroExpansion &expansion) {
  assert(expansion.BeginToken());

  const auto stmt = expansion.CoveredStmt();
  const auto decl = expansion.CoveredDecl();
  const auto name = expansion.BeginToken()->Data();
  std::stringstream ss;

  ss << name << " covers ";
  if (stmt && decl) {
    ss << "a Stmt and a Decl";
  }
  else if (stmt) {
    PrintTokensTo(ss, stmt->Tokens());
  }
  else if (decl) {
    PrintTokensTo(ss, decl->Tokens());
  }
  else {
    ss << "nothing";
  }
  std::cout << ss.str() << "\n";

  auto children = expansion.ReplacementChildren();
  auto definition = expansion.Definition();
  if (definition && definition->IsFunctionLike()) {
    children = children.begin()->Children();
  }

  for (const auto &child : children) {
    const auto child_expansion = pasta::MacroExpansion::From(child);
    if (child_expansion &&
        child_expansion != expansion &&
        child.Kind() != pasta::MacroKind::kParameterSubstitution) {
      PrintLowestCovering(*child_expansion);
    }
  }
}

void PrintLowestCovering(pasta::AST ast) {
  for (const auto &node : ast.Macros()) {
    if (auto expansion = pasta::MacroExpansion::From(node)) {
      PrintLowestCovering(*expansion);
    }
  }
}

static void OnSigsegv(int) {
  std::cerr << "Process ID: " << getpid() << "\nPress enter: \n";
  std::cerr.flush();
  char x;
  (void) read(0, &x, 1);
}

int main(int argc, char *argv[]) {
  if (2 > argc) {
    std::cerr << "Usage: " << argv[0] << " COMPILE_COMMAND..." << std::endl;
    return EXIT_FAILURE;
  }

  signal(SIGSEGV, OnSigsegv);

  pasta::InitPasta initializer;
  pasta::FileManager fm(pasta::FileSystem::CreateNative());
  auto maybe_compiler =
    pasta::Compiler::CreateHostCompiler(fm, pasta::TargetLanguage::kCXX);
  if (!maybe_compiler.Succeeded()) {
    std::cerr << maybe_compiler.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  auto maybe_cwd = pasta::FileSystem::From(maybe_compiler.Value())
    ->CurrentWorkingDirectory();
  if (!maybe_cwd.Succeeded()) {
    std::cerr << maybe_compiler.TakeError() << std::endl;
    return EXIT_FAILURE;
  }

  const pasta::ArgumentVector args(argc - 1, &argv[1]);
  auto maybe_command =
    pasta::CompileCommand::CreateFromArguments(args, maybe_cwd.TakeValue());
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

  for (const auto &job : maybe_jobs.TakeValue()) {
    auto maybe_ast = job.Run();
    if (!maybe_ast.Succeeded()) {
      std::cerr << maybe_ast.TakeError() << std::endl;
      return EXIT_FAILURE;
    }
    else {
      PrintLowestCovering(maybe_ast.TakeValue());
    }
  }

  return EXIT_SUCCESS;
}