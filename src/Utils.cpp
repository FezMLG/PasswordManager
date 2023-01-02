//
// Created by Konrad on 02.01.2023.
//

#include "Utils.h"

std::string Utils::userInput() {
    std::string input;
    std::cin.sync();
    std::getline(std::cin, input);
    return input;
}
