#pragma once

#include <string>
#include <vector>
#include <memory>
#include "task.h"

class User{
    public:
        // Constructor
        User(int user_id, const std::string& username, const std::string& password);

        // User getters
        int getUserId() const;
        std::string getUsername() const;
        std::string getPassword() const;

        // Task getters
        int getNewTasks() const;
        bool checkTask(int task_id);
        Taskptr getTaskById(int task_id);
        std::vector<int> getUserAllTaskIds();

        // Login Validator
        bool login(int user_id, const std::string& password);

        // Task setters
        void addTask(const Taskptr& user_task);
        void deleteTask(int task_id);
        void taskStatusUpdate(int task_id, bool task_status);

        // Display Task Methods
        void displayNotifications();
        void displayNewTasks();
        void displayAllUserTasks();
        void displayTaskById(int task_id);

        // Display User Methods
        void displayUser();

    private:
        int user_id;
        std::string username;
        std::string password;
        std::vector <Taskptr> user_tasks;
};

using Userptr = std::shared_ptr<User>;