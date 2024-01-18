#include <iostream>
#include "user.h"

// Constructor
User::User(int Userid, const std::string& Username, const std::string& Password){
    this->Userid = Userid;
    this->Username = Username;
    this->Password = Password;
}

// Getters
int User::get_Userid() const {
    return Userid;
}

std::string User::get_Username() const {
    return Username;
}

std::string User::get_Password() const {
    return Password;
}

// Setters
void User::addTask(const Taskptr& userTask) {
    std::cout << "Task with Id: " << userTask->get_id() << "was added" << "\n";
    this->UserTasks.push_back(userTask);
}

void User::deleteTask(int Taskid) {
    auto deleteTask = this->UserTasks.begin();
    for(auto &task: this->UserTasks){
        if(task->get_id() == Taskid){
            std::cout << "Task exists, deleting the Task with Id: " << task->get_id() << "\n";
            this->UserTasks.erase(deleteTask);
            break;
        }
        ++deleteTask;
    }
    
    if(deleteTask == this->UserTasks.end()){
        std::cout << "Task does not exist, Please enter correct task Id" << "\n";
    }
}

void User::TaskStatusUpdate(int Taskid, bool Status){
    bool updatedTask = false;
    for(auto &task: this->UserTasks){
        if(task->get_id() == Taskid){
            std::cout << "Task exists, updating the Task status with Id: " << task->get_id() << " from " << task->getTaskstatus() << " to " << Status << "\n";
            task->setTaskstatus(Status);
            updatedTask = true;
            break;
        }
    }

    if(!updatedTask){
        std::cout << "Task does not exist, Please enter correct task Id" << "\n";
    }
}

// Display Methods
void User::displayAllUserTasks(){

}

void User::displayTaskbyId(int Taskid){

}

void User::displayUser(){
    std::cout << "\n";
    std::cout << "User Id: " << this->get_Userid() << "\n";
    std::cout << "Username: " << this->get_Username() << "\n";
    std::cout << "\n";
}

