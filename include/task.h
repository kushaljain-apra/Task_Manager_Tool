#pragma once

#include <string>
#include <memory>

class Task{
    public:
        // Constructors
        Task(int id, const std::string& title, const std::string& description);

        // Getters
        int get_id() const;
        std::string get_title() const;
        std::string get_description() const;
        bool getTaskstatus() const;
        bool getTaskReadStatus() const;
        void printTask() const;

        // Setters
        void setTaskstatus(bool TaskStatus);
        void setTaskReadStatus(bool TaskReadStatus);
    
    private:
        int id;
        std::string title;
        std::string description;
        bool TaskStatus;
        bool TaskReadStatus;

};

using Taskptr = std::shared_ptr<Task>;