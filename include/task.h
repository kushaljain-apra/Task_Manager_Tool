#pragma once

#include <string>
#include <memory>

class Task{
    public:
        // Constructors
        Task(int Taskid, const std::string& Title, const std::string& Description);

        // Getters
        int get_id() const;
        std::string get_title() const;
        std::string get_description() const;
        bool getTaskstatus() const;
        bool getTaskReadStatus() const;

        // Setters
        void setTaskstatus(bool TaskStatus);
        void setTaskReadStatus(bool TaskReadStatus);

        // Display Methods
        void printTask() const;
    
    private:
        int Taskid;
        std::string Title;
        std::string Description;
        bool TaskStatus;
        bool TaskReadStatus;

};

using Taskptr = std::shared_ptr<Task>;