#include <iostream>
#include "task.h"

// Constructor
Task::Task(int id, const std::string& title, const std::string& description){
    this->id = id;
    this->title = title;
    this->description = description;
    this->TaskStatus = false;
    this->TaskReadStatus = false;
}

// Getters
int Task::get_id() const{
    return id;
}

std::string Task::get_title() const {
    return title;
}

std::string Task::get_description() const {
    return description;
}

bool Task::getTaskstatus() const{
    return TaskStatus;
}

bool Task::getTaskReadStatus() const {
    return TaskReadStatus;
}

void Task::printTask() const{
    std::cout << "\n";
    std::cout << "Task Id: " << get_id() << "\n";
    std::cout << "Title: " << get_title() << "\n";
    std::cout << "Description: " << get_description() << "\n";
    std::cout << "Task Status: " << getTaskstatus() << "\n";
    std::cout << "\n";
}


// Setters
void Task::setTaskstatus(bool Status){
    this->TaskStatus = Status;
}

void Task::setTaskReadStatus(bool ReadStatus){
    this->TaskReadStatus = ReadStatus;
}