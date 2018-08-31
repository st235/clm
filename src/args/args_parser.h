// Copyright (c) 2018 by Alexander Dadukin (st235@yandex.ru)
// All rights reserved.

#ifndef ARGS_ARGS_PARSER_H
#define ARGS_ARGS_PARSER_H

#include <functional>
#include <map>
#include <memory>
#include <string>

#include "args_value.h"

namespace args {

using Callback = std::function<void(std::unique_ptr<Value>)>;

class ArgsParser {
 public:
  explicit ArgsParser();

  static std::unique_ptr<ArgsParser> Create();

  void Add(const std::string& key, Callback callback);
  void Compile(int argc, char* argv[]);

 private:
  std::map<std::string, Callback> commands_;

  bool Contains(const std::string& key);
};

} // namespace args

#endif // ARGS_ARGS_PARSER_H
