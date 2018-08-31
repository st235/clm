// Copyright (c) 2018 by Alexander Dadukin (st235@yandex.ru)
// All rights reserved.

#ifndef ARGS_ARGS_VALUE_H
#define ARGS_ARGS_VALUE_H

#include <string>
#include <memory>

namespace args {

class Value {
 public:
  Value(std::string v);

  bool asBool();
  int asInt();
  double asDouble();
  std::string asString();

 private:
  std::string v_;
};

} // namespace args

#endif // ARGS_ARGS_VALUE_H
