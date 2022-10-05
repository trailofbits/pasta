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

static void RecPrintMacroGraph(std::ostream &os, const pasta::MacroNode &node);

static void PrintMacroGraph(std::ostream &os,
                            const pasta::MacroToken &tok) {

  const auto a = reinterpret_cast<uintptr_t>(tok.RawNode());
  os
      << "n" << a
      << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\"><TR>"
      << "<TD>" << TokData(tok) << "</TD></TR></TABLE>>];\n";

  if (auto pt = tok.ParsedLocation()) {
    if (auto dt = pt->DerivedLocation()) {
      assert(tok.Data() == dt->Data());
      if (auto mt = dt->MacroLocation()) {
        assert(tok.Data() == mt->Data());
        os << "n" << a << " -> n" << reinterpret_cast<uintptr_t>(mt->RawNode())
           << " [style=dotted];\n";
      }
    }
  }
}

static void PrintMacroGraph(std::ostream &os,
                            const pasta::MacroArgument &arg) {

  const auto a = reinterpret_cast<uintptr_t>(arg.RawNode());
  auto nodes = arg.Nodes();
  os
      << "n" << a
      << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\">"
      << "<TR><TD";
  if (nodes.Size()) {
    os << " colspan=\"" << nodes.Size() << "\"";
  }
  os << ">Argument</TD></TR><TR>";

  auto i = 0u;
  for (const pasta::MacroNode &node : nodes) {
    (void) node;
    os << "<TD port=\"p" << (i++) << "\"> </TD>";
  }

  if (!i) {
    os << "<TD bgcolor=\"red\">?</TD>";
  }

  os
      << "</TR></TABLE>>];\n";

  i = 0u;
  for (const pasta::MacroNode &node : nodes) {
    RecPrintMacroGraph(os, node);
    os << "n" << a << ":p" << (i++) << " -> n"
       << reinterpret_cast<uintptr_t>(node.RawNode()) << ";\n";
  }
}

static void PrintMacroGraph(std::ostream &os,
                            const pasta::MacroDirective &dir) {
  const auto a = reinterpret_cast<uintptr_t>(dir.RawNode());
  auto nodes = dir.Nodes();
  os
      << "n" << a
      << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\">"
      << "<TR><TD colspan=\"" << nodes.Size() << "\">";
  switch (dir.DirectiveKind()) {
    case pasta::MacroDirectiveKind::kOther:
      os << "Other Directive";
      break;
    case pasta::MacroDirectiveKind::kIf:
      os << "If";
      break;
    case pasta::MacroDirectiveKind::kIfDefined:
      os << "IfDefined";
      break;
    case pasta::MacroDirectiveKind::kIfNotDefined:
      os << "IfNotDefined";
      break;
    case pasta::MacroDirectiveKind::kElseIf:
      os << "ElseIf";
      break;
    case pasta::MacroDirectiveKind::kElse:
      os << "Else";
      break;
    case pasta::MacroDirectiveKind::kEndIf:
      os << "EndIf";
      break;
    case pasta::MacroDirectiveKind::kDefine:
      os << "Define";
      break;
    case pasta::MacroDirectiveKind::kUndefine:
      os << "Undefine";
      break;
    case pasta::MacroDirectiveKind::kHashPragma:
      os << "HashPragma";
      break;
    case pasta::MacroDirectiveKind::kC99Pragma:
      os << "C99Pragma";
      break;
    case pasta::MacroDirectiveKind::kMicrosoftPragma:
      os << "MicrosoftPragma";
      break;
    case pasta::MacroDirectiveKind::kInclude:
      os << "Include";
      break;
    case pasta::MacroDirectiveKind::kIncludeNext:
      os << "IncludeNext";
      break;
    case pasta::MacroDirectiveKind::kIncludeMacros:
      os << "IncludeMacros";
      break;
    case pasta::MacroDirectiveKind::kImport:
      os << "Import";
      break;
  }
  os << "</TD></TR><TR>";

  auto i = 0u;
  for (const pasta::MacroNode &node : nodes) {
    (void) node;
    os << "<TD port=\"p" << (i++) << "\"> </TD>";
  }

  if (!i) {
    os << "<TD bgcolor=\"red\">?</TD>";
  }

  os
      << "</TR></TABLE>>];\n";

  i = 0u;
  for (const pasta::MacroNode &node : nodes) {
    RecPrintMacroGraph(os, node);
    os << "n" << a << ":p" << (i++) << " -> n"
       << reinterpret_cast<uintptr_t>(node.RawNode()) << ";\n";
  }
}


static void PrintMacroGraphSub(std::ostream &os,
                               const pasta::MacroSubstitution &sub) {

  const auto a = reinterpret_cast<uintptr_t>(sub.RawNode());
  os << "n" << a << ":b -> b" << a << ";\n"
     << "n" << a << ":a -> a" << a << ";\n";

  auto before_nodes = sub.UsageNodes();
  auto after_nodes = sub.SubstitutionNodes();

  os
      << "b" << a
      << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\"><TR>";

  auto i = 0u;
  for (const pasta::MacroNode &node : before_nodes) {
    (void) node;
    os << "<TD port=\"p" << (i++) << "\"> </TD>";
  }

  if (!i) {
    os << "<TD bgcolor=\"red\">?</TD>";
  }

  os
      << "</TR></TABLE>>];\n";

  i = 0u;
  for (const pasta::MacroNode &node : before_nodes) {
    RecPrintMacroGraph(os, node);
    os << "b" << a << ":p" << (i++) << " -> n"
       << reinterpret_cast<uintptr_t>(node.RawNode()) << ";\n";
  }

  os
      << "a" << a
      << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\"><TR>";

  i = 0u;
  for (const pasta::MacroNode &node : after_nodes) {
    (void) node;
    os << "<TD port=\"p" << (i++) << "\"> </TD>";
  }

  if (!i) {
    os << "<TD bgcolor=\"red\">?</TD>";
  }

  os
      << "</TR></TABLE>>];\n";

  i = 0u;
  for (const pasta::MacroNode &node : after_nodes) {
    RecPrintMacroGraph(os, node);
    os << "a" << a << ":p" << (i++) << " -> n"
       << reinterpret_cast<uintptr_t>(node.RawNode()) << ";\n";
  }
}

static void PrintMacroGraph(std::ostream &os,
                            const pasta::MacroExpansion &exp) {
  const auto a = reinterpret_cast<uintptr_t>(exp.RawNode());
  os
      << "n" << a
      << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\">"
      << "<TR><TD colspan=\"2\" port=\"m\">Expansion</TD></TR><TR>"
      << "<TD port=\"b\">Before</TD><TD port=\"a\">After</TD></TR></TABLE>>];\n";

  if (auto def = exp.Definition()) {
    os
        << "n" << a << ":m -> n" << reinterpret_cast<uintptr_t>(def->RawNode())
        << " [style=dashed];\n";
  }

  PrintMacroGraphSub(os, exp);
}

static void PrintMacroGraph(std::ostream &os,
                            const pasta::MacroSubstitution &sub) {
  const auto a = reinterpret_cast<uintptr_t>(sub.RawNode());
  os
      << "n" << a
      << " [label=<<TABLE cellpadding=\"2\" cellspacing=\"0\" border=\"1\">"
      << "<TR><TD colspan=\"2\" port=\"m\">Substitution</TD></TR><TR>"
      << "<TD port=\"b\">Before</TD><TD port=\"a\">After</TD></TR></TABLE>>];\n";

  PrintMacroGraphSub(os, sub);
}

void RecPrintMacroGraph(std::ostream &os, const pasta::MacroNode &node) {
  switch (node.Kind()) {
    case pasta::MacroNodeKind::kInvalid:
      break;
    case pasta::MacroNodeKind::kToken:
      PrintMacroGraph(os, *pasta::MacroToken::From(node));
      break;
    case pasta::MacroNodeKind::kDirective:
    case pasta::MacroNodeKind::kDefine:
    case pasta::MacroNodeKind::kInclude:
      PrintMacroGraph(os, *pasta::MacroDirective::From(node));
      break;
    case pasta::MacroNodeKind::kArgument:
      PrintMacroGraph(os, *pasta::MacroArgument::From(node));
      break;
    case pasta::MacroNodeKind::kSubstitution:
      PrintMacroGraph(os, *pasta::MacroSubstitution::From(node));
      break;
    case pasta::MacroNodeKind::kExpansion:
      PrintMacroGraph(os, *pasta::MacroExpansion::From(node));
      break;
  }
}

static void PrintMacroGraph(std::ostream &os, pasta::AST ast) {
  os
      << "digraph {\n"
      << "node [shape=none margin=0 nojustify=false labeljust=l font=courier];\n";

  for (const pasta::MacroNode &node : ast.Macros()) {
    RecPrintMacroGraph(os, node);
  }

  os << "}\n";

  for (const pasta::Token &tok : ast.Tokens()) {
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
      case pasta::TokenRole::kIntermediateMacroExpansionToken:
        std::cerr << "IME ";
        break;
      case pasta::TokenRole::kFinalMacroExpansionToken:
        std::cerr << "FME ";
        break;
    }
    std::cerr << tok.KindName() << ' ' << tok.Data();
    if (auto ft = tok.FileLocation()) {
      std::cerr << ' ' << ft->KindName() << ' ' << ft->Data();
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
