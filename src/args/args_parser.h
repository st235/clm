// Copyright (c) 2018 by Alexander Dadukin (st235@yandex.ru)
// All rights reserved.

#ifndef ARGS_ARGS_PARSER_H
#define ARGS_ARGS_PARSER_H

#include <memory>
#include <string>
#include <vector>

namespace args {

class ArgsParser {
 public:
  explicit ArgsParser(std::vector<std::string> args_list);
  static std::unique_ptr<ArgsParser> Compile(int argc, char* argv[]);

 private:
  std::vector<std::string> args_list_;
};

} // namespace args

#endif // ARGS_ARGS_PARSER_H
