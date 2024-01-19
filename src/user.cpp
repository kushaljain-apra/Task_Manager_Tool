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

bool User::checkTask(int Taskid) {
    for(auto &task: this->UserTasks){
        if(task->get_id() == Taskid){
            return true;
        }
    }
    return false;
}

Taskptr User::getTaskbyId(int Taskid) {
    std::cout << "\n";
    Taskptr getTask = nullptr;
    int numUserTasks = (int)this->UserTasks.size();
    for(int i = 0; i < numUserTasks; i++){
        if(this->UserTasks[i]->get_id() == Taskid){
            getTask = this->UserTasks[i];
            break;
        }
    }

    if(getTask == nullptr){
        std::cout << "No Task with Id:" << Taskid << " was found, please enter correct Task Id...\n";
    }
    std::cout << "\n";
    return getTask;
}

std::vector<int> User::getUsertaskIds() {
    std::vector<int> UserTaskids;
    for(auto &task: this->UserTasks){
        UserTaskids.push_back(task->get_id());
    }
    return UserTaskids;
}

// Setters
void User::login(const std::string& Username, const std::string& Password){
    std::cout << "\n";
    if(this->get_Username() == Username && this->get_Password() == Password){
        displayNotification();
    }
    else{
        std::cout << "Your username or password is incorrect, please login with correct username or password... \n";
    }
    std::cout << "\n";
}

void User::login(int Userid, const std::string& Password){
    std::cout << "\n";
    if(this->get_Userid() == Userid && this->get_Password() == Password){
        displayNotification();
    }
    else{
        std::cout << "Your username or password is incorrect, please login with correct username or password... \n";
    }
    std::cout << "\n";
}

void User::addTask(const Taskptr& userTask) {
    std::cout << "\n";
    if(!checkTask(userTask->get_id())){
        std::cout << "Task with Id:" << userTask->get_id() << " was added with User Id:" << this->get_Userid() << " ...\n";
        this->UserTasks.push_back(userTask);
    }
    else{
        std::cout << "Task with Id:" << userTask->get_id() << " already exists, please enter a unique Task Id" << " ...\n";
    }
    std::cout << "\n";
}

void User::deleteTask(int Taskid) {
    std::cout << "\n";
    if(checkTask(Taskid)){
        auto deleteTask = this->UserTasks.begin();
        for(auto &task: this->UserTasks){
            if(task->get_id() == Taskid){
                break;
            }
            ++deleteTask;
        }
        std::cout << "Task exists, deleting Task with Id:" << Taskid << "\n";
        this->UserTasks.erase(deleteTask);
    }
    else{
        std::cout << "Task does not exist, Please enter correct task Id" << "\n";
    }
    std::cout << "\n";
}

void User::taskStatusUpdate(int Taskid, bool Status){
    std::cout << "\n";
    if(checkTask(Taskid)){
        for(auto &task: this->UserTasks){
            if(task->get_id() == Taskid){
                std::cout << "Task exists, updating the Task status with Id:" << task->get_id() << " from " << task->getTaskstatus() << " to " << Status << "\n";
                task->setTaskstatus(Status);
                break;
            }
        }
    }
    else{
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
    bool taskNotFound = true;
    for(auto &task: this->UserTasks){
        taskNotFound = false;
        task->setTaskReadStatus(true);
        task->printTask();
    }
    
    if(taskNotFound){
        std::cout << "No Tasks are assigned right now...\n";
    }
    std::cout << "\n";
}

void User::displayTaskbyId(int Taskid){
    std::cout << "\n";
    if(checkTask(Taskid)){
        for(auto &task: this->UserTasks){
            if(task->get_id() == Taskid){
                task->setTaskReadStatus(true);
                task->printTask();
                break;
            }
        }
    }
    else{
        std::cout << "Task does not exist, Please enter correct task Id" << "\n";
    }
    std::cout << "\n";
}

void User::displayUser(){
    std::cout << "\n";
    std::cout << "User Id: " << this->get_Userid() << "\n";
    std::cout << "Username: " << this->get_Username() << "\n";
    std::cout << "\n";
}

