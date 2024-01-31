#pragma once

#include <string>
#include <memory>

class Task{
    public:
        // Constructors
        Task(int task_id, const std::string& title, const std::string& description);

        // Getters
        int getTaskId() const;
        std::string getTitle() const;
        std::string getDescription() const;
        bool getTaskStatus() const;
        bool getTaskReadStatus() const;

        // Setters
        void setTaskStatus(bool task_status);
        void setTaskReadStatus(bool task_read_status);

        // Display Method
        void displayTask() const;
    
    private:
        int task_id;
        std::string title;
        std::string description;
        bool task_status;
        bool task_read_status;

};

using Taskptr = std::shared_ptr<Task>;