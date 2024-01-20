#pragma once
#include <string>

class InputValidator {
    public:
        std::string ValidreadString(const std::string& message, const std::string err_message);
        int ValidreadInteger(const std::string& message, const std::string err_message);
};
