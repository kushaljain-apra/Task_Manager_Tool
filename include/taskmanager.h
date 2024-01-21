#pragma once

#include "admin.h"
#include "user.h"
#include "task.h"
#include "inputvalidator.h"

class TaskManager {
    public:
        // Constructor
        TaskManager();

        //Getters
        int get_superAdminid();
        std::string get_superAdminUsername();
        std::string get_superAdminPassword();

        //Setters

        //Display Methods
        void Welcome();
        void HomePage();
        void RegisterationPage();
        void AdminLoginPage();
        void AdminPage();
        void UserLoginPage();
        void UserPage(Userptr& user);

    private:
        Adminptr superAdmin;
        InputValidatorptr validate;
};

using TaskManagerptr = std::shared_ptr<TaskManager>;
