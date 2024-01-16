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
        bool isCompleted() const;

        // Setters
        void setAsCompleted(bool completed);
    
    private:
        int id;
        std::string title;
        std::string description;
        bool completed;
};

using Taskptr = std::shared_ptr<Task>;