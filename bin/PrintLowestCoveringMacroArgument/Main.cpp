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
    // NOTE(bpappas): Only print parsed tokens.
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

class StmtsPrintLowestCoveringMacroArgument final : public pasta::StmtVisitor {
public:
  std::ostream &os;

  virtual ~StmtsPrintLowestCoveringMacroArgument(void) = default;

  explicit StmtsPrintLowestCoveringMacroArgument(std::ostream &os_) : os(os_) {}

  void VisitStmt(const pasta::Stmt &stmt) {

    const auto covering_argument = stmt.LowestCoveringMacroArgument();
    if (covering_argument) {
      std::stringstream ss;
      PrintTokensTo(ss, stmt.Tokens());
      ss << " is covered by argument ";
      const auto parent = covering_argument->Parent();
      if (parent) {
        ss << "of parent macro ";
        const auto expansion = pasta::MacroExpansion::From(*parent);
        if (expansion) {
          ss << "expansion ";
          const auto definition = expansion->Definition();
          if (definition) {
            ss << "of macro definition ";
            const auto definition_name = definition->Name();
            if (definition_name) {
              ss << definition_name->Data() << ' ';
            }
            else {
              ss << "<unnamed> ";
            }
            ss << "argument number ";
            ss << covering_argument->Index() << ' ';
            const auto index = covering_argument->Index();
            const auto parameter = definition->Parameters().At(index);
            if (parameter and parameter->BeginToken()) {
              ss << parameter->BeginToken()->Data();
            }
            else {
              ss << "<unnamed>";
            }
          }
          else {
            ss << "that has no definition";
          }
        }
        else {
          ss << "that is not an expansion";
        }
      }
      else {
        ss << "that is an orphan";
      }
      std::cout << ss.str() << "\n";
    }

    for (const auto &child : stmt.Children()) {
      VisitStmt(child);
    }
  }
};

class DeclsPrintLowestCoveringMacroArgument final : public pasta::DeclVisitor {
public:
  std::ostream &os;

  virtual ~DeclsPrintLowestCoveringMacroArgument(void) = default;

  explicit DeclsPrintLowestCoveringMacroArgument(std::ostream &os_) : os(os_) {}

  void VisitDeclContext(const pasta::DeclContext &dc) {
    for (const auto &decl : dc.AlreadyLoadedDeclarations()) {
      Accept(decl);
    }
  }

  void VisitTranslationUnitDecl(const pasta::TranslationUnitDecl &decl) final {
    VisitDeclContext(decl);
  }

  void VisitVarDecl(const pasta::VarDecl &decl) final {
    // NOTE(bpappas): Only visit global variable declarations since we visit
    // local ones anyway inside function declaration contexts.
    if (!decl.IsLocalVariableDeclaration()) {
      if (auto initializer = decl.Initializer()) {
        StmtsPrintLowestCoveringMacroArgument finder(os);
        finder.Accept(*initializer);
      }
    }
  }

  void VisitFunctionDecl(const pasta::FunctionDecl &decl) final {
    if (auto body = decl.Body()) {
      StmtsPrintLowestCoveringMacroArgument finder(os);
      finder.Accept(*body);
    }
    VisitDeclContext(decl);
  }
};


static void PrintLowestCoveringMacroArgument(pasta::AST ast) {
  DeclsPrintLowestCoveringMacroArgument finder(std::cout);
  finder.Accept(ast.TranslationUnit());
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
      PrintLowestCoveringMacroArgument(maybe_ast.TakeValue());
      return EXIT_SUCCESS;
    }
  }

  return EXIT_SUCCESS;
}