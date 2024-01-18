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

int User::getNewTasks() const {
    int newTaskcount = 0;
    for(auto &task: this->UserTasks){
        if(!(task->getTaskReadStatus())){
            newTaskcount++;
        }
    }
    return newTaskcount;
}

// Setters
void User::Login(const std::string& Username, const std::string& Password){
    std::cout << "\n";
    if(this->Username == Username && this->Password == Password){
        displayNotification();
    }
    else{
        std::cout << "Your username or password is incorrect, please login with correct username or password... \n";
    }
    std::cout << "\n";
}

void User::Login(int Userid, const std::string& Password){
    std::cout << "\n";
    if(this->Userid == Userid && this->Password == Password){
        displayNotification();
    }
    else{
        std::cout << "Your username or password is incorrect, please login with correct username or password... \n";
    }
    std::cout << "\n";
}

void User::addTask(const Taskptr& userTask) {
    std::cout << "\n";
    std::cout << "Task with Id: " << userTask->get_id() << " was added with User Id: " << this->get_Userid() << " ...\n";
    this->UserTasks.push_back(userTask);
    std::cout << "\n";
}

void User::deleteTask(int Taskid) {
    std::cout << "\n";
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
    std::cout << "\n";
}

void User::TaskStatusUpdate(int Taskid, bool Status){
    std::cout << "\n";
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
    std::cout << "\n";
}

// Display Methods
void User::displayNotification(){
    std::cout << "\n";
    std::cout << "Collecting if any new tasks are assigned...\n";
    int newTaskcount = getNewTasks();
    if(newTaskcount == 0){
        std::cout << "No new tasks are assigned...\n";
    }
    else{
        std::cout << "You have " << newTaskcount << " tasks assigned to you...\n";
    }
    std::cout << "\n";
}

void User::displayNewTasks(){
    std::cout << "\n";
    int newTaskcount = getNewTasks();
    if(newTaskcount > 0){
        for(auto &task: this->UserTasks){
            if(!(task->getTaskReadStatus())){
                task->setTaskReadStatus(true);
                task->printTask();
            }
        }
    }else{
        std::cout << "No new tasks were found...\n";
    }
    std::cout << "\n";
}

void User::displayAllUserTasks(){
    std::cout << "\n";
    for(auto &task: this->UserTasks){
        task->setTaskReadStatus(true);
        task->printTask();
    }
    std::cout << "\n";
}

void User::displayTaskbyId(int Taskid){
    std::cout << "\n";
    for(auto &task: this->UserTasks){
        if(task->get_id() == Taskid){
            task->setTaskReadStatus(true);
            task->printTask();
            break;
        }
    }
    std::cout << "\n";
}

void User::displayUser(){
    std::cout << "\n";
    std::cout << "User Id: " << this->get_Userid() << "\n";
    std::cout << "Username: " << this->get_Username() << "\n";
    std::cout << "\n";
}

