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
        Admin(int Userid, const std::string& Username, const std::string& Password);

        // getters
        int get_Adminid() const;
        std::string get_Username() const;
        std::string get_Password() const;
        bool checkUser(int Userid);
        Userptr getUserbyId(int Userid);
        bool getApproveStatus(int Userid);
        int getUnapprovedUsers();

        // setters
        void login(const std::string& Username ,const std::string& Password);
        void login(int Adminid, const std::string& Password);
        void createUser(int Userid, const std::string& Username, const std::string& Password);
        void approveUser(int Userid);
        void deleteUser(int Userid);
        void createTask(int Taskid, const std::string& title, const std::string& description, int Userid);
        void deleteTask(int Taskid);
        void taskAdminStatusUpdate(int Taskid, bool Status);
        void reassignTask(int Taskid, int toUser);

        // Display Methods
        void displayNotification();
        void displayUnapprovedUsers();
        void displayUsers();
        void displayAllTasks();
        void displayUserTasks(int Userid);        
        void displayTaskbyId(int Taskid);
        void displayAdmin();
        
    // Data Members
    private:
        int Adminid;
        std::string Username;
        std::string Password;
        std::set<int> approvedUsers; 
        std::vector<Userptr> Users;
};

using Adminptr = std::shared_ptr<Admin>;