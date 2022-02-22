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

#include <llvm/Support/JSON.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <optional>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unistd.h>
#include <variant>

static const std::hash<std::string_view> kStringViewHasher;
static const std::hash<std::string> kStringHasher;

using FileId = uint64_t;

// Visit all top-level declarations.
class TLDFinder final : public pasta::DeclVisitor {
 public:
  virtual ~TLDFinder(void) = default;

  std::unordered_map<const void *, pasta::Decl> &decls;

  TLDFinder(std::unordered_map<const void *, pasta::Decl> &decls_)
      : decls(decls_) {}

  void VisitDeclContext(const pasta::DeclContext &dc) {
    for (const auto &decl : dc.AlreadyLoadedDeclarations()) {
      Accept(decl);
    }
  }

  void VisitVarTemplateDecl(const pasta::VarTemplateDecl &tpl) final {
    for (pasta::VarTemplateSpecializationDecl decl : tpl.Specializations()) {
      VisitVarTemplateSpecializationDecl(decl);
    }
  }

  void VisitClassTemplateDecl(const pasta::ClassTemplateDecl &tpl) final {
    for (pasta::ClassTemplateSpecializationDecl decl : tpl.Specializations()) {
      VisitClassTemplateSpecializationDecl(decl);
    }
  }

  void VisitFunctionTemplateDecl(const pasta::FunctionTemplateDecl &tpl) final {
    for (pasta::FunctionDecl decl : tpl.Specializations()) {
      VisitFunctionDecl(decl);
    }
  }

  void VisitTranslationUnitDecl(const pasta::TranslationUnitDecl &decl) final {
    VisitDeclContext(decl);
  }

  void VisitNamespaceDecl(const pasta::NamespaceDecl &decl) final {
    VisitDeclContext(decl);
  }

  void VisitExternCContextDecl(const pasta::ExternCContextDecl &decl) final {
    VisitDeclContext(decl);
  }

  void VisitLinkageSpecDecl(const pasta::LinkageSpecDecl &decl) final {
    VisitDeclContext(decl);
  }

  void VisitDecl(const pasta::Decl &decl) final {
    decls.emplace(decl.RawDecl(), decl);
  }
};

using EntityVariant = std::variant<
    pasta::FileToken,
    pasta::Token,
    pasta::Decl,
    pasta::Stmt,
    pasta::Type>;

class Grammar {
 private:
  const EntityVariant entity;

  Grammar(void) = delete;

  std::vector<std::unique_ptr<Grammar>> tokens;
  const std::optional<FileId> file_id;

 public:
  inline explicit Grammar(pasta::Decl entity_)
      : entity(std::move(entity_)) {}

  inline explicit Grammar(pasta::Stmt entity_)
      : entity(std::move(entity_)) {}

  inline explicit Grammar(pasta::Type entity_)
      : entity(std::move(entity_)) {}

  inline explicit Grammar(pasta::Token entity_)
      : entity(std::move(entity_)) {}

  inline explicit Grammar(FileId file_id_, pasta::FileToken entity_)
      : entity(std::move(entity_)),
        file_id(file_id_) {}

  Grammar *LocateInsertPoint(pasta::Token tok);

  void AddFileToken(FileId file_id, pasta::FileToken file_tok,
                    pasta::Token tok);

  void AddExpansionToken(pasta::Token tok);

  // Convert this grammar into a JSON object. The file IDs are collected so that
  // the top-level JSON object will contain all of the files used.
  llvm::json::Object ToJSON(std::unordered_map<FileId, size_t> &files);
};

class Workspace {
 private:
  const std::filesystem::path workspace_dir;

  std::string file_data;
  std::unordered_map<pasta::File, FileId> source_file_ids;

  // Array of token contexts.
  llvm::json::Array contexts;
  std::unordered_map<uint32_t, size_t> context_to_offset;

  // Mapping of raw decl pointers to top-level declarations.
  std::unordered_map<const void *, pasta::Decl> top_level_decls;

  // Mapping of decls to files.
  std::unordered_map<pasta::Decl, pasta::File> file_containing_decl;

  // Maps top-level decls to "grammars," which are trees containing
  // tokens, declarations, statements, and types.
  std::unordered_map<pasta::Decl, Grammar> decl_to_grammar;

  // Mapping of source files to the top-level decls file that reference tokens
  // from those source files.
  //
  // Ordered so that we always process things in the same way.
  std::set<std::pair<FileId, FileId>> decls_by_file;

  void SaveFile(const char *kind, FileId id);

  FileId FindFile(pasta::File file);

  // Find the top-level declaration containing a given token.
  std::optional<pasta::Decl> TopLevelDecl(pasta::Token token);

  void Index(pasta::Token token);

  void Index(pasta::Decl tld, Grammar *grammar);

 public:
  explicit Workspace(std::filesystem::path workspace_dir_)
      : workspace_dir(std::move(workspace_dir_)) {}

  void Index(const pasta::CompileCommand &command, const pasta::CompileJob &job,
             pasta::AST ast);
};

Grammar *Grammar::LocateInsertPoint(pasta::Token tok) {

  // Start by making a path into the most recently build grammar element.
  std::vector<Grammar *> path;
  path.push_back(this);
  while (!path.back()->tokens.empty()) {
    path.push_back(path.back()->tokens.back().get());
  }

  // Locate an entity somewhere in the path.
  auto find_in = [&path] (EntityVariant x) -> Grammar * {
    for (auto it = path.rbegin(); it != path.rend(); ++it) {
      Grammar *ent = *it;
      if (ent->entity == x) {
        return ent;
      }
    }
    return nullptr;
  };

  // Now, descend through the token contexts, and stop when we find one of the
  // context entities inside of our path.
  Grammar *parent{nullptr};
  std::vector<pasta::TokenContext> missed;
  for (auto context = tok.Context(); context; context = context->Parent()) {
    if (auto decl = pasta::Decl::From(*context)) {
      parent = find_in(*decl);
    } else if (auto stmt = pasta::Stmt::From(*context)) {
      parent = find_in(*stmt);
    } else if (auto type = pasta::Type::From(*context)) {
      parent = find_in(*type);
    }
    if (!parent) {
      missed.push_back(*context);
    } else {
      break;
    }
  }

  // If we didn't find anything, then we're adding to this node.
  if (!parent) {
    parent = this;
  }

  // We might need to invent several grammar elements for the `missed`
  // contexts.
  for (auto it = missed.rbegin(); it != missed.rend(); ++it) {
    pasta::TokenContext &context = *it;
    Grammar *missed_grammar = nullptr;
    if (auto decl = pasta::Decl::From(context)) {
      missed_grammar = new Grammar(*decl);
    } else if (auto stmt = pasta::Stmt::From(context)) {
      missed_grammar = new Grammar(*stmt);
    } else if (auto type = pasta::Type::From(context)) {
      missed_grammar = new Grammar(*type);
    } else {
      continue;  // Skip it.
    }
    parent->tokens.emplace_back(missed_grammar);
    parent = missed_grammar;
  }

  return parent;
}

void Grammar::AddFileToken(FileId file_id, pasta::FileToken file_tok,
                           pasta::Token tok) {
  auto grammar = LocateInsertPoint(tok);
  grammar->tokens.emplace_back(new Grammar(file_id, file_tok));
}

void Grammar::AddExpansionToken(pasta::Token tok) {
  auto grammar = LocateInsertPoint(tok);
  grammar->tokens.emplace_back(new Grammar(tok));
}

llvm::json::Object Grammar::ToJSON(std::unordered_map<FileId, size_t> &files) {
  llvm::json::Object o;
  if (std::holds_alternative<pasta::FileToken>(entity)) {
    assert(file_id.has_value());

    auto [it, added] = files.emplace(file_id.value(), files.size());
    o["type"] = "FileToken";
    o["file"] = it->second;
    o["offset"] = std::get<pasta::FileToken>(entity).Index();

  } else if (std::holds_alternative<pasta::Token>(entity)) {
    auto tok = std::get<pasta::Token>(entity);
    o["type"] = "Token";
    o["kind"] = llvm::json::fixUTF8(tok.KindName());
    o["data"] = llvm::json::fixUTF8(tok.Data());

  } else if (std::holds_alternative<pasta::Decl>(entity)) {
    auto ent = std::get<pasta::Decl>(entity);
    o["type"] = "Decl";
    o["sub_type"] = llvm::json::fixUTF8(ent.KindName());

  } else if (std::holds_alternative<pasta::Stmt>(entity)) {
    auto ent = std::get<pasta::Stmt>(entity);
    o["type"] = "Stmt";
    o["sub_type"] = llvm::json::fixUTF8(ent.KindName());

  } else if (std::holds_alternative<pasta::Type>(entity)) {
    auto ent = std::get<pasta::Type>(entity);
    o["type"] = "Type";
    o["sub_type"] = llvm::json::fixUTF8(ent.KindName());

  } else {
    assert(false);
  }

  if (!tokens.empty()) {
    llvm::json::Array children;
    for (auto &sub_grammar : tokens) {
      children.emplace_back(sub_grammar->ToJSON(files));
    }
    o["children"] = std::move(children);
  }

  return o;
}

void Workspace::SaveFile(const char *kind, FileId id) {
  std::stringstream ss;
  ss << kind << "." << id << ".json";
  std::filesystem::path path = workspace_dir / ss.str();

  ss << ".tmp." << static_cast<unsigned>(rand()) << '.'
     << static_cast<unsigned>(getpid());

  std::filesystem::path tmp_path = workspace_dir / ss.str();

  {
    std::ofstream fs(tmp_path);
    fs << file_data;
    file_data.clear();
  }

  std::filesystem::rename(tmp_path, path);
}

FileId Workspace::FindFile(pasta::File file) {
  auto it = source_file_ids.find(file);
  if (it != source_file_ids.end()) {
    return it->second;
  }

  llvm::json::Object o;

  // Path of the file.
  llvm::json::Array path;
  for (auto part : file.Path()) {
    auto part_str = part.generic_string();
    path.emplace_back(llvm::json::fixUTF8(part_str));
  }
  o["path"] = std::move(path);

  // Hash of the contents of the file, or failing that, the absolute path
  // of the file.
  std::stringstream file_hash_ss;
  if (auto data = file.Data(); data.Succeeded()) {
    file_hash_ss << std::hex << kStringViewHasher(data.TakeValue());
  } else {
    auto stat = file.Stat();
    std::stringstream ss;
    file_hash_ss << std::hex << kStringHasher(stat.real_path.generic_string());
  }
  o["hash"] = file_hash_ss.str();

  // Tokens in the file.
  llvm::json::Array tokens;
  for (pasta::FileToken tok : file.Tokens()) {
    llvm::json::Object t;
    t["data"] = llvm::json::fixUTF8(tok.Data());
    t["kind"] = llvm::json::fixUTF8(tok.KindName());
    t["line"] = tok.Line();
    t["column"] = tok.Column();
    tokens.emplace_back(std::move(t));
  }
  o["tokens"] = std::move(tokens);

  llvm::json::Value v(std::move(o));
  llvm::raw_string_ostream ss(file_data);
  ss << v;
  auto file_id = kStringHasher(file_data);
  auto [added_it, added] = source_file_ids.emplace(file, file_id);
  if (!added) {
    assert(false);
    return added_it->second;
  }

  SaveFile("source", file_id);
  return file_id;
}

// Find the top-level declaration containing a given token. This is the last
// decl in the token's context chain that we can associate with the prior
// computed set of top-level decls.
std::optional<pasta::Decl> Workspace::TopLevelDecl(pasta::Token tok) {
  auto context = tok.Context();
  if (!context.has_value()) {
    return std::nullopt;
  }
  std::optional<pasta::Decl> ret;
  for (; context; context = context->Parent()) {
    if (context->Kind() == pasta::TokenContextKind::kDecl) {
      if (auto it = top_level_decls.find(context->Data());
          it != top_level_decls.end()) {
        ret = it->second;
      }
    }
  }
  return ret;
}

void Workspace::Index(pasta::Token tok) {
  std::optional<std::pair<FileId, uint64_t>> file_offset;
  auto maybe_file_tok = tok.FileLocation();
  if (maybe_file_tok) {
    auto file_id = FindFile(pasta::File::Containing(*maybe_file_tok));
    file_offset.emplace(file_id, maybe_file_tok->Index());
  }

  // TODO(pag): Top level statements, e.g. `asm` statements, comments,
  //            semicolons, etc..
  auto tld = TopLevelDecl(tok);
  if (!tld.has_value()) {
    return;
  }

  auto [grammar, added] = decl_to_grammar.try_emplace(*tld, *tld);
  if (auto maybe_file_tok = tok.FileLocation()) {
    auto file_id = FindFile(pasta::File::Containing(*maybe_file_tok));
    grammar->second.AddFileToken(
        file_id, std::move(*maybe_file_tok), std::move(tok));
  } else {
    grammar->second.AddExpansionToken(std::move(tok));
  }
}

void Workspace::Index(pasta::Decl tld, Grammar *grammar) {
  std::unordered_map<FileId, size_t> files;
  auto o = grammar->ToJSON(files);

  llvm::json::Array files_array;
  files_array.reserve(files.size());
  for (auto [file_id, file_offset] : files) {
    files_array.emplace_back(nullptr);
    (void) file_id;
    (void) file_offset;
  }
  for (auto [file_id, file_offset] : files) {
    files_array[file_offset] = std::to_string(file_id);
  }

  o["files"] = std::move(files_array);

  llvm::raw_string_ostream ss(file_data);

  llvm::json::Value v(std::move(o));
  ss << v;
  auto tld_file_id = kStringHasher(file_data);
  SaveFile("tld", tld_file_id);

  // Map between the just-saved file, and each of the files referenced by the
  // tokens in the just-saved file.
  for (auto [file_id, file_offset] : files) {
    decls_by_file.emplace(file_id, tld_file_id);
  }
}

// Index the AST produced by a specific command and job.
void Workspace::Index(const pasta::CompileCommand &command,
                      const pasta::CompileJob &job, pasta::AST ast) {
  context_to_offset.clear();
  top_level_decls.clear();
  file_containing_decl.clear();
  decl_to_grammar.clear();
  decls_by_file.clear();

  TLDFinder finder(top_level_decls);
  finder.VisitTranslationUnitDecl(ast.TranslationUnit());

  for (pasta::Token tok : ast.Tokens()) {
    Index(std::move(tok));
  }

  for (auto &[tld, grammar] : decl_to_grammar) {
    Index(tld, &grammar);
  }

  llvm::json::Object o;
  llvm::json::Array args;
  for (auto arg : job.SourceFile().Path()) {
    args.emplace_back(llvm::json::fixUTF8(arg.generic_string()));
  }
  o["path"] = std::move(args);

  for (auto arg : command.Arguments()) {
    args.emplace_back(llvm::json::fixUTF8(arg));
  }
  o["command"] = std::move(args);

  for (auto arg : job.Arguments()) {
    args.emplace_back(llvm::json::fixUTF8(arg));
  }
  o["job"] = std::move(args);

  for (auto part : job.WorkingDirectory()) {
    args.emplace_back(llvm::json::fixUTF8(part.generic_string()));
  }
  o["working_dir"] = std::move(args);

  for (auto part : job.ResourceDirectory()) {
    args.emplace_back(llvm::json::fixUTF8(part.generic_string()));
  }
  o["resource_dir"] = std::move(args);

  for (auto part : job.SystemRootDirectory()) {
    args.emplace_back(llvm::json::fixUTF8(part.generic_string()));
  }
  o["sysroot_dir"] = std::move(args);

  o["triple"] = llvm::json::fixUTF8(job.TargetTriple());
  o["aux_triple"] = llvm::json::fixUTF8(job.AuxiliaryTargetTriple());
  o["file"] = std::to_string(FindFile(job.SourceFile()));

  for (auto file : ast.ParsedFiles()) {
    args.emplace_back(std::to_string(FindFile(job.SourceFile())));
  }
  llvm::json::Object files;

  for (auto [file_id, tld_file_id] : decls_by_file) {
    std::string file_id_str = std::to_string(file_id);
    std::string tld_file_id_str = std::to_string(tld_file_id);
    llvm::json::Array *tld_file_list = files.getArray(file_id_str);
    if (!tld_file_list) {
      auto [it, added] = files.try_emplace(
          llvm::json::ObjectKey{file_id_str}, llvm::json::Array());
      tld_file_list = it->second.getAsArray();
    }
    tld_file_list->emplace_back(tld_file_id_str);
  }

  o["file_decls"] = std::move(files);

  llvm::raw_string_ostream ss(file_data);
  llvm::json::Value v(std::move(o));
  ss << v;
  auto tu_file_id = kStringHasher(file_data);
  SaveFile("tu", tu_file_id);
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

  auto maybe_cwd = maybe_compiler->FileSystem()->CurrentWorkingDirectory();
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

  Workspace ws("/tmp/ws");

  for (const pasta::CompileJob &job : maybe_jobs.TakeValue()) {
    auto maybe_ast = job.Run();
    if (!maybe_ast.Succeeded()) {
      std::cerr << maybe_ast.TakeError() << std::endl;
      return EXIT_FAILURE;
    } else {
      ws.Index(command, job, maybe_ast.TakeValue());
    }
  }

  return EXIT_SUCCESS;
}
