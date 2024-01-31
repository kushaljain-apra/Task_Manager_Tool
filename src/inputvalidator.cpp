#include <iostream>
#include <sstream>
#include "inputvalidator.h"

std::string InputValidator::validReadString(const std::string& message, const std::string err_message) {
    std::string user_input;
    while (true) {
        std::cout << message;
        std::getline(std::cin, user_input);
        if (!user_input.empty()) {
            break;
        } else {
            std::cout << err_message;
            std::cin.clear();
        }
    }
    return user_input;
}

int InputValidator::validReadInteger(const std::string& message, const std::string err_message) {
    int integer_value;
    std::string user_input;

    while (true) {
        std::cout << message;
        std::getline(std::cin, user_input);
        std::stringstream converter(user_input);
        if (converter >> integer_value && converter.eof()) {
            break;
        } else {
            std::cout << err_message;
            std::cin.clear();
        }
    }

    return integer_value;
}
