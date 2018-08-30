// Copyright (c) 2018 by Alexander Dadukin (st235@yandex.ru)
// All rights reserved.

#include "args_parser.h"

#include <iostream>
#include <utility>

namespace args {

ArgsParser::ArgsParser(std::vector<std::string> args_list) :
                      args_list_(std::move(args_list)) {
}

std::unique_ptr<ArgsParser> ArgsParser::Compile(int argc, char* argv[]) {
  std::vector<std::string> args_list;

  for (int i = 0; i < argc; i++) {
    args_list.emplace_back(std::string(argv[i]));
  }

  return std::make_unique<ArgsParser>(std::move(args_list));
}

}  // namespace args
