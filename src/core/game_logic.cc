// Copyright (c) 2018 by Alexander Dadukin (st235@yandex.ru)
// All rights reserved.

#include "game_logic.h"
#include <iostream>

#include "../utils/string_utils.h"

namespace game {

GameEngine::GameEngine(int complexity): complexity_(complexity) {
  wished_word_ = utils::GenerateString(complexity);
  std::cout << wished_word_ << std::endl;
}

std::unique_ptr<GameEngine> GameEngine::Create(int complexity) {
  return std::make_unique<GameEngine>(complexity);
}

Result GameEngine::Compare(const std::string& word) {
  Result res;

  if (complexity_ != word.length()) return res;
  int bulls = 0;
  int cows = 0;

  for (int i = 0; i < complexity_; i++) {
    if (wished_word_[i] == word[i]) {
      bulls++;
      continue;
    }

    if (wished_word_.find(word[i]) != std::string::npos) {
      cows++;
    }
  }

  res.bulls = bulls;
  res.cows = cows;
  res.is_win = (complexity_ == bulls);
  return res;
}

}  // namespace game
