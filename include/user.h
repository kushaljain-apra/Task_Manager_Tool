#pragma once

#include <string>
#include <vector>
#include <memory>
#include "task.h"

class User{
    public:

    private:
        std::string username;
        std::string password;
        std::vector <Taskptr> userTasks;

};

using Userptr = std::shared_ptr<User>;