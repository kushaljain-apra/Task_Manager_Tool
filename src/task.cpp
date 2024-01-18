#include <iostream>
#include "task.h"

// Constructor
Task::Task(int Taskid, const std::string& Title, const std::string& Description){
    this->Taskid = Taskid;
    this->Title = Title;
    this->Description = Description;
    this->TaskStatus = false;
    this->TaskReadStatus = false;
}

// Getters
int Task::get_id() const{
    return Taskid;
}

std::string Task::get_title() const {
    return Title;
}

std::string Task::get_description() const {
    return Description;
}

bool Task::getTaskstatus() const{
    return TaskStatus;
}

bool Task::getTaskReadStatus() const {
    return TaskReadStatus;
}

// Setters
void Task::setTaskstatus(bool Status){
    this->TaskStatus = Status;
}

void Task::setTaskReadStatus(bool ReadStatus){
    this->TaskReadStatus = ReadStatus;
}

// Display Methods
void Task::printTask() const{
    std::cout << "\n";
    std::cout << "Task Id: " << get_id() << "\n";
    std::cout << "Title: " << get_title() << "\n";
    std::cout << "Description: " << get_description() << "\n";
    std::cout << "Task Status: " << getTaskstatus() << "\n";
    std::cout << "\n";
}