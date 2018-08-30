// Copyright (c) 2018 by Alexander Dadukin (st235@yandex.ru)
// All rights reserved.

#include "args/args_parser.h"

int main(int argc, char *argv[]){
   args::ArgsParser::Compile(argc, argv);
   return 0;
}

