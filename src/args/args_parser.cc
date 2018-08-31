// Copyright (c) 2018 by Alexander Dadukin (st235@yandex.ru)
// All rights reserved.

#include "args_parser.h"

#include <utility>

namespace args {

ArgsParser::ArgsParser() = default;

std::unique_ptr<ArgsParser> ArgsParser::Create() {
  return std::make_unique<ArgsParser>();
}

void ArgsParser::Add(const std::string& key, Callback callback) {
  commands_.emplace(std::make_pair(key, callback));
}

void ArgsParser::Compile(int argc, char* argv[]) {
  for (int i = 0; i < argc; i++) {
    std::string current_argument(argv[i]);

    if (!Contains(current_argument)) {
      continue;
    }

    const auto& callback = commands_[current_argument];

    std::string next_argument(i + 1 < argc ? argv[i + 1] : "");
    bool is_key = Contains(next_argument);

    auto value = std::make_unique<Value>(is_key ? "" : next_argument);
    callback(std::move(value));
  }
}

bool ArgsParser::Contains(const std::string& key) {
  return commands_.find(key) != commands_.end();
}

}  // namespace args
