/*
 * Copyright (c) 2021 Trail of Bits, Inc.
 */

#include <pasta/AST/AST.h>
#include <pasta/AST/Macro.h>
#include <pasta/Compile/Command.h>
#include <pasta/Compile/Compiler.h>
#include <pasta/Compile/Job.h>
#include <pasta/Util/ArgumentVector.h>
#include <pasta/Util/File.h>
#include <pasta/Util/FileSystem.h>
#include <pasta/Util/Init.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_set>

#define PRINT_DEFINITIONS 1
#define PRINT_DERIVED 0

template <typename TokT>
static std::string TokData(const TokT &tok) {
  std::stringstream ss;
  for (auto ch : tok.Data()) {
    switch (ch) {
      case '<': ss << "&lt;"; break;
      case '>': ss << "&gt;"; break;
      case '"': ss << "&quot;"; break;
      case '\'': ss << "&apos;"; break;
      case '\n': ss << " "; break;
      case '&': ss << "&amp;"; break;
      default: ss << ch; break;
    }
  }
  return ss.str();
}

static void RecPrintMacroGraph(std::ostream &os, const pasta::Macro &node);

static void PrintMacroGraph(std::ostream &os,
                            const pasta::MacroToken &tok) {

  const auto a = reinterpret_cast<uintptr_t>(tok.RawMacro());
  os
      << "n" << a
      << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\"><TR>"
      << "<TD>" << TokData(tok) << "</TD></TR></TABLE>>];\n";

#if PRINT_DEFINITIONS
  if (auto def = tok.ParsedLocation().AssociatedMacro()) {
    os << "n" << a << " -> n" << reinterpret_cast<uintptr_t>(def->RawMacro())
       << " [style=dashed];\n";
  }
#endif

#if PRINT_DERIVED
  auto pt = tok.ParsedLocation();
  if (auto dt = pt.DerivedLocation()) {
    assert(tok.Data() == dt->Data());
    if (auto mt = dt->MacroLocation()) {
      assert(tok.Data() == mt->Data());
      os << "n" << a << " -> n" << reinterpret_cast<uintptr_t>(mt->RawMacro())
         << " [style=dotted];\n";
    }
  }
#endif
}

static void PrintMacroGraph(std::ostream &os,
                            const pasta::MacroParameter &param) {

  const auto a = reinterpret_cast<uintptr_t>(param.RawMacro());
  pasta::MacroRange nodes = param.Children();
  os
      << "n" << a
      << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\">"
      << "<TR><TD";
  if (nodes.Size()) {
    os << " colspan=\"" << nodes.Size() << "\"";
  }
  os << ">Parameter</TD></TR><TR>";

  auto i = 0u;
  for (const pasta::Macro &node : nodes) {
    (void) node;
    os << "<TD port=\"p" << (i++) << "\"> </TD>";
  }

  if (!i) {
    os << "<TD bgcolor=\"red\">?</TD>";
  }

  os
      << "</TR></TABLE>>];\n";

  i = 0u;
  for (const pasta::Macro &node : nodes) {
    RecPrintMacroGraph(os, node);
    os << "n" << a << ":p" << (i++) << " -> n"
       << reinterpret_cast<uintptr_t>(node.RawMacro()) << ";\n";
  }
}

static void PrintMacroGraph(std::ostream &os,
                            const pasta::MacroArgument &arg) {

  const auto a = reinterpret_cast<uintptr_t>(arg.RawMacro());
  auto nodes = arg.Children();
  os
      << "n" << a
      << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\">"
      << "<TR><TD";
  if (nodes.Size()) {
    os << " colspan=\"" << nodes.Size() << "\"";
  }
  os << ">Argument</TD></TR><TR>";

  auto i = 0u;
  for (const pasta::Macro &node : nodes) {
    (void) node;
    os << "<TD port=\"p" << (i++) << "\"> </TD>";
  }

  if (!i) {
    os << "<TD bgcolor=\"red\">?</TD>";
  }

  os
      << "</TR></TABLE>>];\n";

  i = 0u;
  for (const pasta::Macro &node : nodes) {
    RecPrintMacroGraph(os, node);
    os << "n" << a << ":p" << (i++) << " -> n"
       << reinterpret_cast<uintptr_t>(node.RawMacro()) << ";\n";
  }
}

static void PrintMacroGraph(std::ostream &os,
                            const pasta::MacroDirective &dir) {
  if (!PRINT_DEFINITIONS &&
      dir.Kind() == pasta::MacroKind::kDefineDirective) {
    return;
  }

  if (PRINT_DEFINITIONS) {
    if (auto def = pasta::DefineMacroDirective::From(dir)) {
      for (auto use : def->Uses()) {
        goto has_uses;
      }
      return;
    }
  }

has_uses:
  const auto a = reinterpret_cast<uintptr_t>(dir.RawMacro());
  auto nodes = dir.Children();
  os
      << "n" << a
      << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\">"
      << "<TR><TD colspan=\"" << nodes.Size() << "\">";
  switch (dir.Kind()) {
    default:
      os << "Not a directive";
      break;
    case pasta::MacroKind::kOtherDirective:
      os << "Other Directive";
      break;
    case pasta::MacroKind::kIfDirective:
      os << "If";
      break;
    case pasta::MacroKind::kIfDefinedDirective:
      os << "IfDefined";
      break;
    case pasta::MacroKind::kIfNotDefinedDirective:
      os << "IfNotDefined";
      break;
    case pasta::MacroKind::kElseIfDirective:
      os << "ElseIf";
      break;
    case pasta::MacroKind::kElseIfDefinedDirective:
      os << "ElseIfDefined";
      break;
    case pasta::MacroKind::kElseIfNotDefinedDirective:
      os << "ElseIfNotDefined";
      break;
    case pasta::MacroKind::kElseDirective:
      os << "Else";
      break;
    case pasta::MacroKind::kEndIfDirective:
      os << "EndIf";
      break;
    case pasta::MacroKind::kDefineDirective:
      os << "Define";
      break;
    case pasta::MacroKind::kUndefineDirective:
      os << "Undefine";
      break;
    case pasta::MacroKind::kPragmaDirective:
      os << "Pragma";
      break;
    case pasta::MacroKind::kIncludeDirective:
      os << "Include";
      break;
    case pasta::MacroKind::kIncludeNextDirective:
      os << "IncludeNext";
      break;
    case pasta::MacroKind::kIncludeMacrosDirective:
      os << "IncludeMacros";
      break;
    case pasta::MacroKind::kImportDirective:
      os << "Import";
      break;
  }
  os << "</TD></TR><TR>";

  auto i = 0u;
  for (const pasta::Macro &node : nodes) {
    (void) node;
    os << "<TD port=\"p" << (i++) << "\"> </TD>";
  }

  if (!i) {
    os << "<TD bgcolor=\"red\">?</TD>";
  }

  os
      << "</TR></TABLE>>];\n";

  i = 0u;
  for (const pasta::Macro &node : nodes) {
    RecPrintMacroGraph(os, node);
    os << "n" << a << ":p" << (i++) << " -> n"
       << reinterpret_cast<uintptr_t>(node.RawMacro()) << ";\n";
  }
}


static void PrintMacroGraphSub(std::ostream &os,
                               const pasta::MacroSubstitution &sub) {

  const auto a = reinterpret_cast<uintptr_t>(sub.RawMacro());
  os << "n" << a << ":b -> b" << a << ";\n"
     << "n" << a << ":a -> a" << a << ";\n";

  auto before_nodes = sub.Children();
  auto after_nodes = sub.ReplacementChildren();

  os
      << "b" << a
      << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\"><TR>";

  auto i = 0u;
  for (const pasta::Macro &node : before_nodes) {
    (void) node;
    os << "<TD port=\"p" << (i++) << "\"> </TD>";
  }

  if (!i) {
    os << "<TD bgcolor=\"red\">?</TD>";
  }

  os
      << "</TR></TABLE>>];\n";

  i = 0u;
  for (const pasta::Macro &node : before_nodes) {
    RecPrintMacroGraph(os, node);
    os << "b" << a << ":p" << (i++) << " -> n"
       << reinterpret_cast<uintptr_t>(node.RawMacro()) << ";\n";
  }

  os
      << "a" << a
      << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\"><TR>";

  i = 0u;
  for (const pasta::Macro &node : after_nodes) {
    (void) node;
    os << "<TD port=\"p" << (i++) << "\"> </TD>";
  }

  if (!i) {
    os << "<TD bgcolor=\"red\">?</TD>";
  }

  os
      << "</TR></TABLE>>];\n";

  i = 0u;
  for (const pasta::Macro &node : after_nodes) {
    RecPrintMacroGraph(os, node);
    os << "a" << a << ":p" << (i++) << " -> n"
       << reinterpret_cast<uintptr_t>(node.RawMacro()) << ";\n";
  }
}

static void PrintMacroGraph(std::ostream &os,
                            const pasta::MacroExpansion &exp) {
  const auto a = reinterpret_cast<uintptr_t>(exp.RawMacro());
  os
      << "n" << a
      << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\">"
      << "<TR><TD colspan=\"2\" port=\"m\">Expansion</TD></TR><TR>"
      << "<TD port=\"b\">Before</TD><TD port=\"a\">After</TD></TR></TABLE>>];\n";

#if PRINT_DEFINITIONS
  if (auto def = exp.Definition()) {
    os
        << "n" << a << ":m -> n" << reinterpret_cast<uintptr_t>(def->RawMacro())
        << " [style=dashed];\n";
  }
#endif
  PrintMacroGraphSub(os, exp);
}

static void PrintMacroGraph(std::ostream &os,
                            const pasta::MacroSubstitution &sub) {
  const auto a = reinterpret_cast<uintptr_t>(sub.RawMacro());
  os
      << "n" << a
      << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\">"
      << "<TR><TD colspan=\"2\" port=\"m\">Substitution</TD></TR><TR>"
      << "<TD port=\"b\">Before</TD><TD port=\"a\">After</TD></TR></TABLE>>];\n";

  PrintMacroGraphSub(os, sub);
}

void RecPrintMacroGraph(std::ostream &os, const pasta::Macro &node) {
  switch (node.Kind()) {
    case pasta::MacroKind::kToken:
      PrintMacroGraph(os, *pasta::MacroToken::From(node));
      break;
#define PASTA_IGNORE(...)
#define PASTA_MAKE_DIRECTIVE(kind) \
    case pasta::MacroKind::k ## kind ## Directive:

PASTA_FOR_EACH_MACRO_IMPL(PASTA_IGNORE,
                          PASTA_IGNORE,
                          PASTA_MAKE_DIRECTIVE,
                          PASTA_MAKE_DIRECTIVE,
                          PASTA_MAKE_DIRECTIVE,
                          PASTA_MAKE_DIRECTIVE,
                          PASTA_IGNORE)
#undef PASTA_IGNORE
#undef PASTA_MAKE_DIRECTIVE
      PrintMacroGraph(os, *pasta::MacroDirective::From(node));
      break;
    case pasta::MacroKind::kParameter:
      PrintMacroGraph(os, *pasta::MacroParameter::From(node));
      break;
    case pasta::MacroKind::kArgument:
      PrintMacroGraph(os, *pasta::MacroArgument::From(node));
      break;
    case pasta::MacroKind::kSubstitution:
      PrintMacroGraph(os, *pasta::MacroSubstitution::From(node));
      break;
    case pasta::MacroKind::kExpansion:
      PrintMacroGraph(os, *pasta::MacroExpansion::From(node));
      break;
  }
}

static void PrintMacroGraph(std::ostream &os, pasta::AST ast) {
  os
      << "digraph {\n"
      << "node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n";

  for (const pasta::Macro &node : ast.Macros()) {
    RecPrintMacroGraph(os, node);
  }

  os << "}\n";

  for (const pasta::Token &tok : ast.Tokens()) {
    std::cerr << std::setw(5) << std::setfill(' ') << tok.Index() << ' ';
    switch (tok.Role()) {
      case pasta::TokenRole::kInvalid:
        std::cerr << "    ";
        break;
      case pasta::TokenRole::kBeginOfFileMarker:
        std::cerr << "BOF ";
        break;
      case pasta::TokenRole::kEndOfFileMarker:
        std::cerr << "EOF ";
        break;
      case pasta::TokenRole::kFileToken:
        std::cerr << "FT  ";
        break;
      case pasta::TokenRole::kBeginOfMacroExpansionMarker:
        std::cerr << "BME ";
        break;
      case pasta::TokenRole::kEndOfMacroExpansionMarker:
        std::cerr << "EME ";
        break;
      case pasta::TokenRole::kInitialMacroUseToken:
        std::cerr << "IMU ";
        break;
      case pasta::TokenRole::kIntermediateMacroExpansionToken:
        std::cerr << "IME ";
        break;
      case pasta::TokenRole::kFinalMacroExpansionToken:
        std::cerr << "FME ";
        break;
      case pasta::TokenRole::kEndOfInternalMacroEventMarker:
        std::cerr << "IEM ";
        break;
    }
    std::cerr << tok.KindName() << ' ' << tok.Data();
    if (auto ft = tok.FileLocation()) {
      std::cerr << " PFI=" << ft->Index();

    }

    if (auto mt = tok.MacroLocation()) {
      if (auto mft = mt->FileLocation()) {
        std::cerr << " MFI=" << mft->Index();
      }
    }

    if (auto dl = tok.DerivedLocation()) {
      if (auto dft = dl->FileLocation()) {
        std::cerr << " DFI=" << dft->Index();
      }
    }
    std::cerr << '\n';
  }
}

int main(int argc, char *argv[]) {
  if (2 > argc) {
    std::cerr << "Usage: " << argv[0] << " COMPILE_COMMAND..."
              << std::endl;
    return EXIT_FAILURE;
  }

  pasta::InitPasta initializer;
  pasta::FileManager fm(pasta::FileSystem::CreateNative());
  auto maybe_compiler =
      pasta::Compiler::CreateHostCompiler(fm, pasta::TargetLanguage::kCXX);
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

  for (const auto &job : maybe_jobs.TakeValue()) {
    auto maybe_ast = job.Run();
    if (!maybe_ast.Succeeded()) {
      std::cerr << maybe_ast.TakeError() << std::endl;
      return EXIT_FAILURE;
    } else {
      PrintMacroGraph(std::cout, maybe_ast.TakeValue());
    }
  }

  return EXIT_SUCCESS;
}
