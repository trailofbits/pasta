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

void
PrintCovering(const pasta::Stmt &stmt, const pasta::MacroArgument &arg) {
  std::stringstream ss;
  PrintTokensTo(ss, stmt.Tokens());
  ss << " is covered by argument ";
  const auto parent = arg.Parent();
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
        ss << arg.Index() << ' ';
        const auto index = arg.Index();
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

class StmtPrintCoveringMacros final : public pasta::StmtVisitor {
public:
  std::ostream &os;

  virtual ~StmtPrintCoveringMacros(void) = default;

  explicit StmtPrintCoveringMacros(std::ostream &os_) : os(os_) {}

  void VisitStmt(const pasta::Stmt &stmt) {
    // NOTE(bpappas): Don't visit these kinds of expressions to avoid printing
    // their tokens twice. These kinds of expressions comprise the same tokens
    // as their immediate children, so if we were to visit them, we would first
    // print their tokens, and then their immediate childrens' tokens.
    if (stmt.Kind() != pasta::StmtKind::kImplicitCastExpr
        && stmt.Kind() != pasta::StmtKind::kImplicitValueInitExpr) {
      auto covering_macros = stmt.CoveringMacros();
      if (!covering_macros.empty()) {
        std::stringstream ss;
        PrintTokensTo(ss, stmt.Tokens());
        ss << " is covered by ";
        int i = 0;
        for (auto macro : covering_macros) {
          if (i > 0) {
            ss << ' ';
          }
          ss << macro.BeginToken()->Data();
          ss << ' ' << '(' << macro.KindName() << ')';
          i++;
        }
        ss << "\n";
        std::cout << ss.str();
      }
    }
    for (const auto &child : stmt.Children()) {
      Accept(child);
    }
  }
};

class DeclPrintCoveringMacros final : public pasta::DeclVisitor {
public:
  std::ostream &os;

  virtual ~DeclPrintCoveringMacros(void) = default;

  explicit DeclPrintCoveringMacros(std::ostream &os_) : os(os_) {}

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
        StmtPrintCoveringMacros finder(os);
        finder.Accept(*initializer);
      }
    }
  }

  void VisitFunctionDecl(const pasta::FunctionDecl &decl) final {
    if (auto body = decl.Body()) {
      StmtPrintCoveringMacros finder(os);
      finder.Accept(*body);
    }
    VisitDeclContext(decl);
  }
};


static void PrintCoveringMacros(pasta::AST ast) {
  DeclPrintCoveringMacros finder(std::cout);
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
      PrintCoveringMacros(maybe_ast.TakeValue());
    }
  }

  return EXIT_SUCCESS;
}