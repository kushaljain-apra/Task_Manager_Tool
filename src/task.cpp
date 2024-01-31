#include <iostream>
#include "task.h"

// Constructor
Task::Task(int task_id, const std::string& title, const std::string& description){
    this->task_id = task_id;
    this->title = title;
    this->description = description;
    this->task_status = false;
    this->task_read_status = false;
}

// Getters
int Task::getTaskId() const{
    return task_id;
}

std::string Task::getTitle() const {
    return title;
}

std::string Task::getDescription() const {
    return description;
}

bool Task::getTaskStatus() const{
    return task_status;
}

bool Task::getTaskReadStatus() const {
    return task_read_status;
}

// Setters
void Task::setTaskStatus(bool task_status){
    this->task_status = task_status;
}

void Task::setTaskReadStatus(bool task_read_status){
    this->task_read_status = task_read_status;
}

// Display Method
void Task::displayTask() const{
    std::cout << "\n";
    std::cout << "Task Id: " << getTaskId() << "\n";
    std::cout << "title: " << getTitle() << "\n";
    std::cout << "description: " << getDescription() << "\n";
    std::cout << "Task status: " << getTaskStatus() << "\n";
    std::cout << "\n";
}