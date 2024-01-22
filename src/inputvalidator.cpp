#include <iostream>
#include <sstream>
#include "inputvalidator.h"

std::string InputValidator::ValidreadString(const std::string& message, const std::string err_message) {
    std::string userInput;
    while (true) {
        std::cout << message;
        std::getline(std::cin, userInput);
        if (!userInput.empty()) {
            break;
        } else {
            std::cout << err_message;
            std::cin.clear();
        }
    }
    return userInput;
}

int InputValidator::ValidreadInteger(const std::string& message, const std::string err_message) {
    int integerValue;
    std::string userInput;

    while (true) {
        std::cout << message;
        std::getline(std::cin, userInput);
        std::stringstream converter(userInput);
        if (converter >> integerValue && converter.eof()) {
            break;
        } else {
            std::cout << err_message;
            std::cin.clear();
        }
    }

    return integerValue;
}
