#pragma once

#include <string>
#include <vector>
#include <set>
#include <memory>
#include "user.h"
#include "task.h"

class Admin{
    public:
        // Constructor
        Admin(int user_id, const std::string& username, const std::string& password);

        // Admin Details getters
        int getAdminId() const;
        std::string getUsername() const;
        std::string getPassword() const;

        // User getter methods
        bool checkUser(int user_id);
        Userptr getUserById(int user_id);
        bool getApproveStatus(int user_id);
        int getUnapprovedUsers();

        // Login Validator
        bool login(int admin_id, const std::string& password);

        // User setter methods
        void createUser(int user_id, const std::string& username, const std::string& password);
        void approveUser(int user_id);
        void deleteUser(int user_id);

        // Task setter methods
        void createTask(int task_id, const std::string& title, const std::string& description, int user_id);
        void deleteTask(int task_id);
        void taskAdminStatusUpdate(int task_id, bool task_status);
        void reassignTask(int task_id, int reassign_to_user_id);

        // Display user methods 
        void displayNotifications();
        void displayUnapprovedUsers();
        void displayUsers();

        // Display task methods
        void displayAllTasks();
        void displayUserTasks(int user_id);        
        void displayTaskById(int task_id);

        // Display Admin Methods
        void displayAdmin();
        
    // Data Members
    private:
        int admin_id;
        std::string username;
        std::string password;
        std::set<int> approved_users; 
        std::vector<Userptr> users;
};

using Adminptr = std::shared_ptr<Admin>;