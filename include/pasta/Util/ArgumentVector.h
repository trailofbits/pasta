/*
 * Copyright (c) 2020 Trail of Bits, Inc.
 */

#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

namespace pasta {

// Packages an argument vector and the backing storage of the arguments
// themselves.
class ArgumentVector {
 public:
  ~ArgumentVector(void);

  ArgumentVector(void) = default;
  ArgumentVector(const ArgumentVector &vec);
  ArgumentVector(ArgumentVector &&vec) noexcept;

  explicit ArgumentVector(int argc, char *argv[]);

  // Implicit.
  ArgumentVector(const std::string &command);
  ArgumentVector(std::string_view command);
  ArgumentVector(const std::vector<std::string> &vec);
  ArgumentVector(const std::vector<const char *> &vec);

  ArgumentVector &operator=(const ArgumentVector &that);
  ArgumentVector &operator=(ArgumentVector &&that) noexcept;

  void Reset(void);
  void Reset(std::string_view command);
  void Reset(const std::vector<std::string> &vec);
  void Reset(const std::vector<const char *> &vec);
  void Reset(int argc, char *argv[]);

  const std::vector<const char *> &Arguments(void) const;
  size_t Size(void) const;
  std::string Join(const char *sep = " ") const;

  const char *&operator[](size_t index);
  const char *operator[](size_t index) const;

  int Argc(void) const;
  const char **Argv(void) const;

  inline auto begin(void) const -> decltype(Arguments().begin()) {
    return Arguments().begin();
  }

  inline auto end(void) const -> decltype(Arguments().end()) {
    return Arguments().end();
  }

 private:
  std::vector<const char *> argv;
  std::unique_ptr<char[]> data;
};

}  // namespace pasta
