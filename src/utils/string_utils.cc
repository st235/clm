// Copyright (c) 2018 by Alexander Dadukin (st235@yandex.ru)
// All rights reserved.

#include "string_utils.h"

#include <cstdlib>
#include <ctime>
#include <math.h>

namespace utils {

std::string GenerateString(const int length) {
    std::srand(std::time(0));

    int limmit = pow(10, length) - 1;
    int current = 0;

    int number = std::rand() % 10;
    while(current * 10 + number < limmit) {
        current = current * 10 + number;
        number = rand() % 10;
    }

    return std::to_string(current);
}

}  // namspace utils
