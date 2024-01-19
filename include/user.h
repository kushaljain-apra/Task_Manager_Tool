#pragma once

#include <string>
#include <vector>
#include <memory>
#include "task.h"

class User{
    public:
        // Constructor
        User(int Userid, const std::string& Username, const std::string& Password);

        // getters
        int get_Userid() const;
        std::string get_Username() const;
        std::string get_Password() const;
        int getNewTasks() const;
        bool checkTask(int Taskid);
        Taskptr getTaskbyId(int Taskid);
        std::vector<int> getUsertaskIds();

        // setters
        void login(const std::string& Username ,const std::string& Password);
        void login(int Userid, const std::string& Password);
        void addTask(const Taskptr& userTask);
        void deleteTask(int Taskid);
        void taskStatusUpdate(int Taskid, bool Status);

        // Display Tasks
        void displayNotification();
        void displayNewTasks();
        void displayAllUserTasks();
        void displayTaskbyId(int Taskid);
        void displayUser();

    private:
        int Userid;
        std::string Username;
        std::string Password;
        std::vector <Taskptr> UserTasks;
};

using Userptr = std::shared_ptr<User>;