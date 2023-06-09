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

class StmtPrintAlignedParameterSubstitutions final : public pasta::StmtVisitor {
public:
  std::ostream &os;

  virtual ~StmtPrintAlignedParameterSubstitutions(void) = default;

  explicit StmtPrintAlignedParameterSubstitutions(std::ostream &os_) : os(os_) {}

  void VisitStmt(const pasta::Stmt &stmt) {
    // NOTE(bpappas): Don't visit implicit expressions to avoid printing their
    // tokens twice. Implicit expressions comprise the same tokens as their
    // immediate children, so if we were to visit them, we would first print
    // their tokens, and then their immediate childrens' tokens.
    if (stmt.Kind() != pasta::StmtKind::kImplicitCastExpr
        && stmt.Kind() != pasta::StmtKind::kImplicitValueInitExpr) {
      auto covering_macros = stmt.CoveringMacros();
      std::vector<pasta::MacroExpansion> covering_expansions;
      for (auto macro : covering_macros) {
        if (auto exp = pasta::MacroExpansion::From(macro)) {
          // NOTE(bpappas): To avoid visiting function-like macro expansions
          // twice, we only consider expansions that do not have arguments, or
          // are the pre-expanded versions of their arguments
          auto should_visit = (exp->Arguments().empty() ||
                               exp->IsArgumentPreExpansion());
          if (should_visit) {
            covering_expansions.push_back(*exp);
          }
        }
      }
      if (!covering_expansions.empty()) {
        std::stringstream ss;
        PrintTokensTo(ss, stmt.Tokens());
        ss << " is covered by the following expansions:\n";
        for (auto &exp : covering_expansions) {
          if (auto name = exp.NameOrOperator()) {
            ss << name->Data();
          } else {
            ss << "<a nameless macro>";
          }
          ss << "\nAligned parameters:\n";
          auto aligned_parameters = exp.AlignedParameterSubstitutions(stmt);
          auto parameter_use_counts = exp.ParameterUseCounts();
          for (auto &[param, param_stmts] : aligned_parameters) {
            unsigned expected = parameter_use_counts.at(param);
            auto param_name  = param.Name();
            std::size_t actual = param_stmts.size();
            ss << "  " << (param_name ? param_name->Data() : "<a nameless parameter>")
              << " (expected " << std::to_string(expected)
              << ", actual " << std::to_string(actual)
              << "):\n";
            for (auto param_stmt : param_stmts) {
              ss << "    ";
              PrintTokensTo(ss, param_stmt.Tokens());
              ss << '\n';
            }
          }
        }
        std::cout << ss.str();
      }
    }
    for (const auto &child : stmt.Children()) {
      Accept(child);
    }
  }
};

class DeclPrintStmtsCoveredByArguments final : public pasta::DeclVisitor {
public:
  std::ostream &os;

  virtual ~DeclPrintStmtsCoveredByArguments(void) = default;

  explicit DeclPrintStmtsCoveredByArguments(std::ostream &os_) : os(os_) {}

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
        StmtPrintAlignedParameterSubstitutions finder(os);
        finder.Accept(*initializer);
      }
    }
  }

  void VisitFunctionDecl(const pasta::FunctionDecl &decl) final {
    if (auto body = decl.Body()) {
      StmtPrintAlignedParameterSubstitutions finder(os);
      finder.Accept(*body);
    }
    VisitDeclContext(decl);
  }
};


static void PrintAlignedParameterSubstitutions(pasta::AST ast) {
  DeclPrintStmtsCoveredByArguments finder(std::cout);
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
    } else {
      PrintAlignedParameterSubstitutions(maybe_ast.TakeValue());
    }
  }

  return EXIT_SUCCESS;
}