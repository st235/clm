// Copyright (c) 2018 by Alexander Dadukin (st235@yandex.ru)
// All rights reserved.

#include <memory>
#include <utility>
#include <string>
#include <iostream>

#include "args/args_parser.h"
#include "core/game_logic.h"

void CreateGame(std::unique_ptr<args::Value> value) {
  auto game_engine = game::GameEngine::Create(value->asInt());

  std::string try_word;
  game::Result game_result;

  while (!game_result.is_win) {
    std::cout << "type your try: ";
    std::getline(std::cin, try_word);

    game_result = game_engine->Compare(try_word);
    std::cout << "b: " << game_result.bulls << " c: " << game_result.cows << std::endl;
  }

    std::cout << "you win!" << std::endl;
}

void PrintHelp(std::unique_ptr<args::Value> value) {
}

int main(int argc, char *argv[]){
   auto args = args::ArgsParser::Create();

   args->Add("-c", CreateGame);
   args->Add("-h", PrintHelp);

   args->Compile(argc, argv);
   return 0;
}

