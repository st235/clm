// Copyright (c) 2018 by Alexander Dadukin (st235@yandex.ru)
// All rights reserved.

#include <memory>
#include <utility>
#include <iostream>

#include "args/args_parser.h"

void Version(std::unique_ptr<args::Value> value) {
    std::cout << "0.0.1" << std::endl;
}

void CommandExtractor(std::unique_ptr<args::Value> v) {
    std::cout << v->asString() << std::endl;
}

int main(int argc, char *argv[]){
   auto args = args::ArgsParser::Create();
   args->Add("-v", Version);
   args->Add("-h", CommandExtractor);

   args->Compile(argc, argv);
   return 0;
}

