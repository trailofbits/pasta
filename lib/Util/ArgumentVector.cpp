/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#include <pasta/Util/ArgumentVector.h>

#include <cstring>
#include <sstream>

namespace pasta {

// Initialize an argument vector from a string representing a command line. This
// will try to split the string into its associated parts.
ArgumentVector::ArgumentVector(const std::string &command) {
  Reset(command);
}

void ArgumentVector::Reset(void) {
  argv.clear();
  data.reset();
}

namespace {

// Try to strip a single level of quotes from some input data.
static char *StripSlashesAndQuotes(char *data) {
  size_t len = strlen(data);
  size_t read_i = 0;
  char quote_ch = '\0';

  size_t write_i = 0;
  for (; read_i < len; ++read_i) {
    const auto ch = data[read_i];
    if (ch == quote_ch) {
      quote_ch = '\0';
    } else if (ch == '"') {
      quote_ch = '"';
    } else if (ch == '\'') {
      quote_ch = '\'';
    } else if (ch == '\\') {
      ++read_i;
      if (read_i < len) {
        data[write_i++] = data[read_i];
      }
    } else {
      data[write_i++] = ch;
    }
  }
  data[write_i] = '\0';

  return data;
}

}  // namespace

// Initialize an argument vector from a string representing a command line. This
// will try to split the string into its associated parts.
void ArgumentVector::Reset(const std::string &command) {
  size_t data_size = (command.size() * 2) + 1;

  std::unique_ptr<char[]> backup(new char[data_size]);
  data.swap(backup);

  auto arg_data_ptr = &(data[0]);
  memset(arg_data_ptr, 0, data_size);

  char *last_token = nullptr;
  auto next = &(data[0]);
  next[0] = '\0';

  for (size_t i = 0; i < command.size();) {
    const auto ch = command[i];

    // Ignore spaces.
    if (' ' == ch || '\t' == ch) {
      *next++ = '\0';
      if (last_token) {
        argv.push_back(StripSlashesAndQuotes(last_token));
        last_token = nullptr;
      }
      ++i;

    // Accumulate everything until the next matching quote. Two separate
    // quoted strings can be side-by-side, so we can't commit this entry
    // here.
    } else if ('"' == ch || '\'' == ch) {
      if (!last_token) {
        last_token = next;
      }

      *next++ = ch;
      *next = '\0';

      auto j = (i + 1);

      for (; j < command.size();) {
        const auto inner_ch = command[j++];
        *next++ = inner_ch;
        *next = '\0';

        if (inner_ch == ch) {
          break;

        } else if (inner_ch == '\\') {
          if (j < command.size()) {
            *next++ = command[j++];
            *next = '\0';
          }
        }
      }

      i = j;
      *next = '\0';

    // Collect the slash and the escaped thing.
    } else if ('\\' == ch) {
      *next++ = ch;
      *next = '\0';

      i += 1;
      if (i < command.size()) {
        *next++ = command[i];
        *next = '\0';
        i += 1;
      }

    // Stop at new lines.
    } else if ('\n' == ch || '\r' == ch || '\0' == ch) {
      *next = '\0';
      break;

    // Add other stuff in.
    } else {
      if (!last_token) {
        last_token = next;
      }
      *next++ = ch;
      *next = '\0';
      i += 1;
    }
  }

  *next = '\0';
  if (last_token) {
    argv.push_back(StripSlashesAndQuotes(last_token));
  }

  argv.push_back(nullptr);
  argv.pop_back();
}

// Initialize an argument vector, given another argument vector where the
// vector entries are copied from a vector of strings.
ArgumentVector::ArgumentVector(const std::vector<std::string> &vec) {
  Reset(vec);
}

// Initialize an argument vector, given another argument vector where the
// vector entries are copied from a vector of strings.
void ArgumentVector::Reset(const std::vector<std::string> &vec) {
  size_t data_size = 0;
  for (const auto &entry : vec) {
    if (!entry.empty()) {
      data_size += entry.size() + 1;
    }
  }

  std::unique_ptr<char[]> backup(new char[data_size]);
  data.swap(backup);

  auto arg_data_ptr = &(data[0]);
  memset(arg_data_ptr, 0, data_size);

  for (const auto &entry : vec) {
    if (!entry.empty()) {
      memcpy(arg_data_ptr, entry.data(), entry.size());
      arg_data_ptr[entry.size()] = '\0';
      argv.push_back(arg_data_ptr);
      arg_data_ptr += entry.size() + 1;
    }
  }

  argv.push_back(nullptr);
  argv.pop_back();
}

// Initialize an argument vector, given the `argc` and `argv` from a
// command line.
ArgumentVector::ArgumentVector(int argc, char *argv[]) {
  Reset(argc, argv);
}

// Initialize an argument vector, given another argument vector where the
// vector entries are copied from a vector of C strings.
ArgumentVector::ArgumentVector(const std::vector<const char *> &vec) {
  Reset(vec);
}

// Initialize an argument vector, given another argument vector where the
// vector entries are copied from a vector of C strings.
void ArgumentVector::Reset(const std::vector<const char *> &vec) {
  size_t data_size = 0;
  for (auto str : vec) {
    auto str_size = strlen(str);
    if (str_size) {
      data_size += str_size + 1;
    }
  }

  std::unique_ptr<char[]> backup(new char[data_size]);
  data.swap(backup);

  auto arg_data_ptr = &(data[0]);
  memset(arg_data_ptr, 0, data_size);

  for (auto str : vec) {
    auto str_size = strlen(str);
    if (str_size) {
      memcpy(arg_data_ptr, str, str_size);
      arg_data_ptr[str_size] = '\0';
      argv.push_back(arg_data_ptr);
      arg_data_ptr += str_size + 1;
    }
  }

  argv.push_back(nullptr);
  argv.pop_back();
}

ArgumentVector::~ArgumentVector(void) {}

// Initialize one argument vector from another.
ArgumentVector::ArgumentVector(const ArgumentVector &vec)
    : ArgumentVector(vec.argv) {}

ArgumentVector::ArgumentVector(ArgumentVector &&vec) noexcept
    : argv(std::move(vec.argv)),
      data(std::move(vec.data)) {}

ArgumentVector &ArgumentVector::operator=(const ArgumentVector &that) {
  if (this != &that) {
    Reset(that);
  }
  return *this;
}

ArgumentVector &ArgumentVector::operator=(ArgumentVector &&that) noexcept {
  argv = std::move(that.argv);
  data = std::move(that.data);
  return *this;
}

// Initialize an argument vector, given the `argc` and `argv` from a
// command line.
void ArgumentVector::Reset(int argc, char *argv[]) {
  std::vector<const char *> vec;
  vec.reserve(static_cast<size_t>(argc));

  for (auto i = 0; i < argc; ++i) {
    vec.push_back(const_cast<const char *>(argv[i]));
  }

  Reset(vec);
}

// Initialize one argument vector from another.
void ArgumentVector::Reset(const ArgumentVector &vec) {
  if (this != &vec) {
    Reset(vec.argv);
  }
}

const std::vector<const char *> &ArgumentVector::Arguments(void) const {
  return argv;
}

size_t ArgumentVector::Size(void) const {
  return argv.size();
}

int ArgumentVector::Argc(void) const {
  return static_cast<int>(argv.size());
}

const char **ArgumentVector::Argv(void) const {
  return const_cast<const char **>(&(argv[0]));
}

std::string ArgumentVector::Join(const char *sep_) const {
  std::stringstream ss;
  auto sep = "";
  for (auto arg : argv) {
    ss << sep << arg;
    sep = sep_;
  }
  return ss.str();
}

const char *&ArgumentVector::operator[](size_t index) {
  return *&(argv[index]);
}

const char *ArgumentVector::operator[](size_t index) const {
  return *&(argv[index]);
}

}  // namespace pasta
