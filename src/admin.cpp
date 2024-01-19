#include <iostream>
#include "task.h"
#include "admin.h"

// Constructor
Admin::Admin(int Adminid, const std::string& Username, const std::string& Password){
    this->Adminid = Adminid;
    this->Username = Username;
    this->Password = Password;
}

// Getters
int Admin::get_Adminid() const {
    return Adminid;
}

std::string Admin::get_Username() const {
    return Username;
}

std::string Admin::get_Password() const {
    return Password;
}

bool Admin::checkUser(int Userid) {
    for(auto &user: this->Users){
        if(user->get_Userid() == Userid){
            return true;
        }
    }
    return false;
}

Userptr Admin::getUserbyId(int Userid) {
    std::cout << "\n";
    Userptr getUser = nullptr;
    int numUsers = (int)this->Users.size();
    for(int i = 0; i < numUsers; i++){
        if(this->Users[i]->get_Userid() == Userid){
            getUser = this->Users[i];
            break;
        }
    }

    if(getUser == nullptr){
        std::cout << "No User with Id:" << Userid << " was found, please enter correct User Id...\n";
    }
    std::cout << "\n";
    return getUser;
}

bool Admin::getApproveStatus(int Userid) {
    if(this->approvedUsers.find(Userid) != this->approvedUsers.end()){
        return true;
    }
    return false;
}

int Admin::getUnapprovedUsers() {
    int UnapprovedUsercount = 0;
    for(auto &user: this->Users){
       if(!getApproveStatus(user->get_Userid())){
            UnapprovedUsercount++;
       } 
    }
    return UnapprovedUsercount;
}

// Setters
void Admin::login(const std::string& Username, const std::string& Password) {
    std::cout << "\n";
    if(this->get_Username() == Username && this->get_Password() == Password){
        displayNotification();
    }
    else{
        std::cout << "Your username or password is incorrect, please login with correct username or password... \n";
    }
    std::cout << "\n";
}

void Admin::login(int Userid, const std::string& Password) {
    std::cout << "\n";
    if(this->get_Adminid() == Adminid && this->get_Password() == Password){
        displayNotification();
    }
    else{
        std::cout << "Your username or password is incorrect, please login with correct username or password... \n";
    }
    std::cout << "\n";
}

void Admin::createUser(int Userid, const std::string& Username, const std::string& Password) {
    std::cout << "\n";
    if(!checkUser(Userid)){
        Userptr user = std::make_shared<User>(Userid, Username, Password);
        this->Users.push_back(user);
        std::cout << "A new user has been created with User Id:" << Userid << " and Username:" << Username << " ...\n";
    }
    else{
        std::cout << "User with Id:" << Userid << " already exists, please enter a unique User Id ...\n";
    }
    std::cout << "\n";
}

void Admin::approveUser(int Userid) {
    std::cout << "\n";
    if(checkUser(Userid)){
        this->approvedUsers.insert(Userid);
        std::cout << "User with Id: " << Userid << " has been approved...\n";
    }
    else{
        std::cout << "User with given id does not exist...\n";
    }
    std::cout << "\n";
}

void Admin::deleteUser(int Userid) {
    std::cout << "\n";
    if(checkUser(Userid)){
        if(getApproveStatus(Userid)){
            this->approvedUsers.erase(Userid);
        }
        auto deleteUser = this->Users.begin();
        for(auto &user: this->Users){
            if(user->get_Userid() == Userid){
                break;
            }
            ++deleteUser;
        }
        this->Users.erase(deleteUser);
        std::cout << "User with Id:" << Userid << " has been deleted along with tasks assigned...\n";
    }
    else{
        std::cout << "User with given id does not exist...\n";
    }
    std::cout << "\n";
}

void Admin::createTask(int Taskid, const std::string& title, const std::string& description, int Userid) {
    std::cout << "\n";
    if(checkUser(Userid) && getApproveStatus(Userid)){
        for(auto &user: this->Users){
            if(user->get_Userid() == Userid){
                Taskptr task = std::make_shared<Task>(Taskid, title, description);
                user->addTask(task);
                break;
            }
        }
    }
    else if(checkUser(Userid)){
        std::cout << "Cannot add task because User has not been approved ...\n";
    }
    else{
        std::cout << "User with given id does not exist...\n";
    }
    std::cout << "\n";
}

void Admin::deleteTask(int Taskid) {
    std::cout << "\n";
    bool taskNotFound = true;
    for(auto &user: this->Users){
        if(user->checkTask(Taskid)){
            taskNotFound = false;
            user->deleteTask(Taskid);
            break;
        }
    }
    if(taskNotFound){
        std::cout << "Task does not exist, Please enter correct task Id" << "\n";
    }
    std::cout << "\n";
}

void Admin::taskAdminStatusUpdate(int Taskid, bool Status) {
    std::cout << "\n";
    bool taskNotFound = true;
    for(auto &user: this->Users){
        if(user->checkTask(Taskid)){
            taskNotFound = false;
            user->taskStatusUpdate(Taskid, Status);
            break;
        }
    }
    if(taskNotFound){
        std::cout << "Task does not exist, Please enter correct task Id" << "\n";
    }
    std::cout << "\n";
}

void Admin::reassignTask(int Taskid, int toUserid) {
    std::cout << "\n";
    if(checkUser(toUserid) && getApproveStatus(toUserid)){
        bool taskNotFound = true;
        Taskptr task;
        for(auto &user: this->Users){
            if(user->checkTask(Taskid)){
                taskNotFound = false;
                task = user->getTaskbyId(Taskid);
                user->deleteTask(Taskid);
                break;
            }
        }
        if(!taskNotFound){
            for(auto &user: this->Users){
                if(user->get_Userid() == toUserid){
                    user->addTask(task);
                    break;
                }
            }
        }
        else{
            std::cout << "Task does not exist, Please enter correct task Id" << "\n";
        }
    }
    else if(checkUser(toUserid)){
        std::cout << "Cannot reassign task because User has not been approved ...\n";
    }
    else{
        std::cout << "User with given id does not exist...\n";
    }
    std::cout << "\n";
}

// Display Methods
void Admin::displayNotification() {
    std::cout << "\n";
    std::cout << "Collecting if any users are yet to be approved...\n";
    int UnapprovedUsercount = getUnapprovedUsers();
    if(UnapprovedUsercount == 0){
        std::cout << "No users are yet to be approved...\n";
    }
    else{
        std::cout << "You have " << UnapprovedUsercount << " users who are yet to be approved...\n";
    }
    std::cout << "\n";
}

void Admin::displayUnapprovedUsers(){
    std::cout << "\n";
    int UnapprovedUsercount = getUnapprovedUsers();
    if(UnapprovedUsercount > 0){
        for(auto &user: this->Users){
            if(!getApproveStatus(user->get_Userid())){
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
    for(auto &user: this->Users){
        user->displayUser();
    }
    std::cout << "\n";
}

void Admin::displayAllTasks(){
    std::cout << "\n";
    bool taskNotFound = true;
    for(auto &user: this->Users){
        std::vector<int> Taskids = user->getUsertaskIds();
        for(auto &id: Taskids){
            taskNotFound = false;
            Taskptr task = user->getTaskbyId(id);
            task->printTask();
        }
    }

    if(taskNotFound){
        std::cout << "No Tasks are assigned right now...\n";
    }
    std::cout << "\n";
}

void Admin::displayUserTasks(int Userid){
    std::cout << "\n";
    bool taskNotFound = true;
    for(auto &user: this->Users){
        if(user->get_Userid() == Userid){
            std::vector<int> Taskids = user->getUsertaskIds();
            for(auto &id: Taskids){
                taskNotFound = false;
                Taskptr task = user->getTaskbyId(id);
                task->printTask();
            }
            break;
        }
    }

    if(taskNotFound){
        std::cout << "No Tasks are assigned right now...\n";
    }
    std::cout << "\n";
}

void Admin::displayTaskbyId(int Taskid){
    std::cout << "\n";
    bool taskNotFound = true;
    for(auto &user: this->Users){
        if(user->checkTask(Taskid)){
            taskNotFound = false;
            Taskptr task = user->getTaskbyId(Taskid);
            task->printTask();
            break;
        }
    }

    if(taskNotFound){
        std::cout << "Task does not exist, Please enter correct task Id\n";
    }
    std::cout << "\n";
}

void Admin::displayAdmin(){
    std::cout << "\n";
    std::cout << "Admin Id: " << this->get_Adminid() << "\n";
    std::cout << "Username: " << this->get_Username() << "\n";
    std::cout << "\n";
}