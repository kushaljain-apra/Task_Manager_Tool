#pragma once

#include <string>
#include <vector>
#include <memory>
#include "user.h"
#include "task.h"

class Admin{
    public:
        Admin(const std::string& username, const std::string& password);

        // CRUD Operations methods
        void CreateTask(int id, const std::string& title, std::string& description, const Userptr& AssignedUser);

    
    private:
        std::string username;
        std::string password;
        std::vector<Taskptr> tasks;

        Taskptr findTaskbyId(int id) const;

};

using Adminptr = std::shared_ptr<Admin>;