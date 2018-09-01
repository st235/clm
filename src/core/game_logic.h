// Copyright (c) 2018 by Alexander Dadukin (st235@yandex.ru)
// All rights reserved.

#ifndef CORE_GAME_LOGIC_H
#define CORE_GAME_LOGIC_H

#include <memory>
#include <string>

namespace game {

struct Result {
  int cows = -1;
  int bulls = -1;
  bool is_win = false;
};

class GameEngine {
 public:
  GameEngine(int complexity);

  static std::unique_ptr<GameEngine> Create(int complexity);
  Result Compare(const std::string& word);

 private:
  int complexity_;
  std::string wished_word_;
};

} // namespace game

#endif // CORE_GAME_LOGIC_H
