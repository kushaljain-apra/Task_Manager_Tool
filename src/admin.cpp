#include <iostream>
#include "admin.h"

// Constructor
Admin::Admin(int admin_id, const std::string& username, const std::string& password){
    this->admin_id = admin_id;
    this->username = username;
    this->password = password;
}

// Admin Details getters
int Admin::getAdminId() const {
    return admin_id;
}

std::string Admin::getUsername() const {
    return username;
}

std::string Admin::getPassword() const {
    return password;
}

// User getter methods
bool Admin::checkUser(int user_id) {
    for(auto &user: this->users){
        if(user->getUserId() == user_id){
            return true;
        }
    }
    return false;
}

Userptr Admin::getUserById(int user_id) {
    std::cout << "\n";
    Userptr get_user = nullptr;
    int no_of_users = (int)this->users.size();
    for(int i = 0; i < no_of_users; i++){
        if(this->users[i]->getUserId() == user_id){
            get_user = this->users[i];
            break;
        }
    }

    if(get_user == nullptr){
        std::cout << "No User with Id:" << user_id << " was found, please enter correct User Id...\n";
    }
    std::cout << "\n";
    return get_user;
}

bool Admin::getApproveStatus(int user_id) {
    if(this->approved_users.find(user_id) != this->approved_users.end()){
        return true;
    }
    return false;
}

int Admin::getUnapprovedUsers() {
    int unapproved_users_count = 0;
    for(auto &user: this->users){
       if(!getApproveStatus(user->getUserId())){
            unapproved_users_count++;
       } 
    }
    return unapproved_users_count;
}

// Login Validator
bool Admin::login(int user_id, const std::string& password) {
    if(this->getAdminId() == admin_id && this->getPassword() == password){
        return true;
    }
    return false;
}

// User setter methods
void Admin::createUser(int user_id, const std::string& username, const std::string& password) {
    std::cout << "\n";
    if(!checkUser(user_id)){
        Userptr user = std::make_shared<User>(user_id, username, password);
        this->users.push_back(user);
        std::cout << "A new user has been created with User Id:" << user_id << " and username:" << username << " ...\n";
    }
    else{
        std::cout << "User with Id:" << user_id << " already exists, please enter a unique User Id ...\n";
    }
    std::cout << "\n";
}

void Admin::approveUser(int user_id) {
    std::cout << "\n";
    if(checkUser(user_id)){
        this->approved_users.insert(user_id);
        std::cout << "User with Id: " << user_id << " has been approved...\n";
    }
    else{
        std::cout << "User with given id does not exist...\n";
    }
    std::cout << "\n";
}

void Admin::deleteUser(int user_id) {
    std::cout << "\n";
    if(checkUser(user_id)){
        if(getApproveStatus(user_id)){
            this->approved_users.erase(user_id);
        }
        auto delete_user = this->users.begin();
        for(auto &user: this->users){
            if(user->getUserId() == user_id){
                break;
            }
            ++delete_user;
        }
        this->users.erase(delete_user);
        std::cout << "User with Id:" << user_id << " has been deleted along with tasks assigned...\n";
    }
    else{
        std::cout << "User with given id does not exist...\n";
    }
    std::cout << "\n";
}

// Task setter methods
void Admin::createTask(int task_id, const std::string& title, const std::string& description, int user_id) {
    std::cout << "\n";
    if(checkUser(user_id) && getApproveStatus(user_id)){
        for(auto &user: this->users){
            if(user->getUserId() == user_id){
                Taskptr task = std::make_shared<Task>(task_id, title, description);
                user->addTask(task);
                break;
            }
        }
    }
    else if(checkUser(user_id)){
        std::cout << "Cannot add task because User has not been approved ...\n";
    }
    else{
        std::cout << "User with given id does not exist...\n";
    }
    std::cout << "\n";
}

void Admin::deleteTask(int task_id) {
    std::cout << "\n";
    bool task_not_found = true;
    for(auto &user: this->users){
        if(user->checkTask(task_id)){
            task_not_found = false;
            user->deleteTask(task_id);
            break;
        }
    }
    if(task_not_found){
        std::cout << "Task does not exist, Please enter correct task Id" << "\n";
    }
    std::cout << "\n";
}

void Admin::taskAdminStatusUpdate(int task_id, bool status) {
    std::cout << "\n";
    bool task_not_found = true;
    for(auto &user: this->users){
        if(user->checkTask(task_id)){
            task_not_found = false;
            user->taskStatusUpdate(task_id, status);
            break;
        }
    }
    if(task_not_found){
        std::cout << "Task does not exist, Please enter correct task Id" << "\n";
    }
    std::cout << "\n";
}

void Admin::reassignTask(int task_id, int reassign_to_user_id) {
    std::cout << "\n";
    if(checkUser(reassign_to_user_id) && getApproveStatus(reassign_to_user_id)){
        bool task_not_found = true;
        Taskptr task;
        for(auto &user: this->users){
            if(user->checkTask(task_id)){
                task_not_found = false;
                task = user->getTaskById(task_id);
                user->deleteTask(task_id);
                break;
            }
        }

        if(!task_not_found){
            for(auto &user: this->users){
                if(user->getUserId() == reassign_to_user_id){
                    user->addTask(task);
                    break;
                }
            }
        }
        else{
            std::cout << "Task does not exist, Please enter correct task Id" << "\n";
        }
    }
    else if(checkUser(reassign_to_user_id)){
        std::cout << "Cannot reassign task because User has not been approved ...\n";
    }
    else{
        std::cout << "User with given id does not exist...\n";
    }
    std::cout << "\n";
}

// Display user methods 
void Admin::displayNotifications() {
    std::cout << "\n";
    std::cout << "Collecting if any users are yet to be approved...\n";
    int unapproved_users_count = getUnapprovedUsers();
    if(unapproved_users_count == 0){
        std::cout << "No users are yet to be approved...\n";
    }
    else{
        std::cout << "You have " << unapproved_users_count << " users who are yet to be approved...\n";
    }
    std::cout << "\n";
}

void Admin::displayUnapprovedUsers(){
    std::cout << "\n";
    int unapproved_users_count = getUnapprovedUsers();
    if(unapproved_users_count > 0){
        for(auto &user: this->users){
            if(!getApproveStatus(user->getUserId())){
                user->displayUser();
            }
        }
    }else{
        std::cout << "No users are yet to be approved...\n";
    }
    std::cout << "\n";
}

void Admin::displayUsers(){
    std::cout << "\n";
    int no_of_users = (int)this->users.size();
    if(no_of_users > 0){
        for(auto &user: this->users){
            user->displayUser();
        }
    }
    else{
        std::cout << "No Users are currently present...\n";
    }
    std::cout << "\n";
}

// Display task methods
void Admin::displayAllTasks(){
    std::cout << "\n";
    bool task_not_found = true;
    for(auto &user: this->users){
        std::vector<int> task_ids = user->getUserAllTaskIds();
        for(auto &id: task_ids){
            task_not_found = false;
            Taskptr task = user->getTaskById(id);
            std::cout << "User Id: " << user->getUserId() << "\n";
            task->displayTask();
        }
    }

    if(task_not_found){
        std::cout << "No Tasks are assigned right now...\n";
    }
    std::cout << "\n";
}

void Admin::displayUserTasks(int user_id){
    std::cout << "\n";
    bool task_not_found = true;
    for(auto &user: this->users){
        if(user->getUserId() == user_id){
            std::vector<int> task_ids = user->getUserAllTaskIds();
            for(auto &id: task_ids){
                task_not_found = false;
                Taskptr task = user->getTaskById(id);
                std::cout << "User Id: " << user->getUserId() << "\n";
                task->displayTask();
            }
            break;
        }
    }

    if(task_not_found){
        std::cout << "No Tasks are assigned right now...\n";
    }
    std::cout << "\n";
}

void Admin::displayTaskById(int task_id){
    std::cout << "\n";
    bool task_not_found = true;
    for(auto &user: this->users){
        if(user->checkTask(task_id)){
            task_not_found = false;
            Taskptr task = user->getTaskById(task_id);
            std::cout << "User Id: " << user->getUserId() << "\n";
            task->displayTask();
            break;
        }
    }

    if(task_not_found){
        std::cout << "Task does not exist, Please enter correct task Id\n";
    }
    std::cout << "\n";
}

// Display Admin Methods
void Admin::displayAdmin(){
    std::cout << "\n";
    std::cout << "Admin Id: " << this->getAdminId() << "\n";
    std::cout << "username: " << this->getUsername() << "\n";
    std::cout << "\n";
}