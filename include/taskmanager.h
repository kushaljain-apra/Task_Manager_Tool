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
        int getSuperAdminId();
        std::string getSuperAdminUsername();
        std::string getSuperAdminPassword();

        //Display Methods
        void welcome();
        void homePage();
        void registerationPage();
        void adminLoginPage();
        void adminPage();
        void userLoginPage();
        void userPage(Userptr& user);

    private:
        Adminptr super_admin;
        InputValidatorptr validator;
};

using TaskManagerptr = std::shared_ptr<TaskManager>;
