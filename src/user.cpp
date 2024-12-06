#include <iostream>
#include "user.h"

// Constructor
User::User(int user_id, const std::string& username, const std::string& password){
    this->user_id = user_id;
    this->username = username;
    this->password = password;
}

// User getters
int User::getUserId() const {
    return user_id;
}

std::string User::getUsername() const {
    return username;
}

std::string User::getPassword() const {
    return password;
}

// Task getters
int User::getNewTasks() const {
    int new_task_count = 0;
    for(auto &task: this->user_tasks){
        if(!(task->getTaskReadStatus())){
            new_task_count++;
        }
    }
    return new_task_count;
}

bool User::checkTask(int task_id) {
    for(auto &task: this->user_tasks){
        if(task->getTaskId() == task_id){
            return true;
        }
    }
    return false;
}

Taskptr User::getTaskById(int task_id) {
    std::cout << "\n";
    Taskptr get_task = nullptr;
    int no_of_user_tasks = (int)this->user_tasks.size();
    for(int i = 0; i < no_of_user_tasks; i++){
        if(this->user_tasks[i]->getTaskId() == task_id){
            get_task = this->user_tasks[i];
            break;
        }
    }

    if(get_task == nullptr){
        std::cout << "No Task with Id:" << task_id << " was found, please enter correct Task Id...\n";
    }
    std::cout << "\n";
    return get_task;
}

std::vector<int> User::getUserAllTaskIds() {
    std::vector<int> user_task_ids;
    for(auto &task: this->user_tasks){
        user_task_ids.push_back(task->getTaskId());
    }
    return user_task_ids;
}

// Login Validator
bool User::login(int user_id, const std::string& password){
    if(this->getUserId() == user_id && this->getPassword() == password){
        return true;
    }
    return false;
}

// Task setters
void User::addTask(const Taskptr& user_task) {
    std::cout << "\n";
    if(!checkTask(user_task->getTaskId())){
        std::cout << "Task with Id:" << user_task->getTaskId() << " was added with User Id:" << this->getUserId() << " ...\n";
        this->user_tasks.push_back(user_task);
    }
    else{
        std::cout << "Task with Id:" << user_task->getTaskId() << " already exists, please enter a unique Task Id" << " ...\n";
    }
    std::cout << "\n";
}

void User::deleteTask(int task_id) {
    std::cout << "\n";
    if(checkTask(task_id)){
        auto deleteTask = this->user_tasks.begin();
        for(auto &task: this->user_tasks){
            if(task->getTaskId() == task_id){
                break;
            }
            ++deleteTask;
        }
        std::cout << "Task exists, deleting Task with Id:" << task_id << "\n";
        this->user_tasks.erase(deleteTask);
    }
    else{
        std::cout << "Task does not exist, Please enter correct task Id" << "\n";
    }
    std::cout << "\n";
}

void User::taskStatusUpdate(int task_id, bool task_status){
    std::cout << "\n";
    if(checkTask(task_id)){
        for(auto &task: this->user_tasks){
            if(task->getTaskId() == task_id){
                std::cout << "Task exists, updating the Task status with Id:" << task->getTaskId() << " from " << task->getTaskStatus() << " to " << task_status << "\n";
                task->setTaskStatus(task_status);
                break;
            }
        }
    }
    else{
        std::cout << "Task does not exist, Please enter correct task Id" << "\n";
    }
    std::cout << "\n";
}

// Display Task Methods
void User::displayNotifications(){
    std::cout << "\n";
    std::cout << "Collecting if any new tasks are assigned...\n";
    int new_task_count = getNewTasks();
    if(new_task_count == 0){
        std::cout << "No new tasks are assigned...\n";
    }
    else{
        std::cout << "You have " << new_task_count << " tasks assigned to you...\n";
    }
    std::cout << "\n";
}

void User::displayNewTasks(){
    std::cout << "\n";
    int new_task_count = getNewTasks();
    if(new_task_count > 0){
        for(auto &task: this->user_tasks){
            if(!(task->getTaskReadStatus())){
                task->setTaskReadStatus(true);
                task->displayTask();
            }
        }
    }else{
        std::cout << "No new tasks were found...\n";
    }
    std::cout << "\n";
}

void User::displayAllUserTasks(){
    std::cout << "\n";
    bool task_not_found = true;
    for(auto &task: this->user_tasks){
        task_not_found = false;
        task->setTaskReadStatus(true);
        task->displayTask();
    }
    
    if(task_not_found){
        std::cout << "No Tasks are assigned right now...\n";
    }
    std::cout << "\n";
}

void User::displayTaskById(int task_id){
    std::cout << "\n";
    if(checkTask(task_id)){
        for(auto &task: this->user_tasks){
            if(task->getTaskId() == task_id){
                task->setTaskReadStatus(true);
                task->displayTask();
                break;
            }
        }
    }
    else{
        std::cout << "Task does not exist, Please enter correct task Id" << "\n";
    }
    std::cout << "\n";
}

// Display User Methods
void User::displayUser(){
    std::cout << "\n";
    std::cout << "User Id: " << this->getUserId() << "\n";
    std::cout << "username: " << this->getUsername() << "\n";
    std::cout << "\n";
}

