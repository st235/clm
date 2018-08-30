// Copyright (c) 2018 by Alexander Dadukin (st235@yandex.ru)
// All rights reserved.

#include "args_value.h"

#include <algorithm>

namespace args {

const std::string kSymbolTrue = "true";
const std::string kNumberTrue = "1";

Value::Value(std::string v): v_(v) {
}

bool Value::asBool() {
  std::string copy(v_);
  std::transform(copy.begin(), copy.end(), copy.begin(), ::tolower);
  return copy == kSymbolTrue || copy == kNumberTrue;
}

int Value::asInt() {
  return std::stoi(v_);
}

double Value::asDouble() {
  return std::stod(v_);
}

std::string Value::asString() {
  return v_;
}

}  // namespace args
