#include <iostream>
#include "taskmanager.h"

// Constructors
TaskManager::TaskManager() {
    Adminptr admin = std::make_shared<Admin>(1, "admin", "admin");
    this->super_admin = admin;
}

// Getters
int TaskManager::getSuperAdminId() {
    return super_admin->getAdminId();
}

std::string TaskManager::getSuperAdminUsername() {
    return super_admin->getUsername();
}

std::string TaskManager::getSuperAdminPassword() {
    return super_admin->getPassword();
}

// Display Methods
void TaskManager::welcome(){
    std::cout << "\t\t\t******************************************************************\n";
    std::cout << "\t\t\t                    welcome to Task Manager !!!\n";
    std::cout << "\t\t\t******************************************************************\n\n\n";
}

void TaskManager::homePage() {
    while(true){
        welcome();
        std::cout << "Note: Please use characters before the colon for typing using any commands\n\n";
        std::cout << "A: Admin Login\n";
        std::cout << "U: User Login\n";
        std::cout << "N: New User? Register here\n";
        std::cout << "exit: Exit Task Manager\n";

        std::string command = validator->validReadString("Enter a Command: ", "Please enter a command...\n");
        std::cout << "\n";

        if(command == "A"){
            adminLoginPage();
        }
        else if(command == "U"){
            userLoginPage();
        }
        else if(command == "N"){
            registerationPage();
        }
        else if(command == "exit"){
            break ;
        }
        else{
            std::cout << "Please enter a valid command...\n";
        }
    }
}

void TaskManager::registerationPage() {
    std::cout << "**************User Registration Page**************\n\n";
    int user_id = validator->validReadInteger("Enter User Id: ", "Please enter a valid integer...\n");
    std::string username = validator->validReadString("Enter username: ", "Please enter a username...\n");
    std::string password = validator->validReadString("Enter password: ", "Please enter a password...\n");

    std::cout << "\n";

    std::cout << "F: Finish Registeration\n";
    std::cout << "C: Cancel Registration\n";
    std::cout << "B: Go Back\n";

    while(true){
        std::string command = validator->validReadString("Enter a Command: ", "Please enter a command...\n");
        std::cout << "\n";

        if(command == "F"){
            if(!super_admin->checkUser(user_id)){
                std::cout << "User Registration Confirmed...\n";
                std::cout << "Redirecting to Home...\n";
            }
            super_admin->createUser(user_id, username, password);
            break;
        }
        else if(command == "C"){
            std::cout << "User Registration Canceled...\n";
            std::cout << "Redirecting to Home...\n";
            break;
        }
        else if(command == "B"){
            std::cout << "User Registration Failed...\n";
            std::cout << "Redirecting to Home...\n";
            break;
        }
        else{
            std::cout << "Please enter a valid command...\n";
        }
    }
}

void TaskManager::adminLoginPage() {
    while(true){
        std::cout << "**************Admin Login Page**************\n\n";
        int admin_id = validator->validReadInteger("Enter admin_id: ", "Please enter a valid integer...\n");
        std::string password = validator->validReadString("Enter password: ", "Please enter a password...\n");

        std::cout << "\n";

        if(super_admin->login(admin_id, password)){
            std::cout << "Access Granted...\n\n\n";
            std::cout << "**************Admin Page**************\n\n";
            super_admin->displayNotifications();
            adminPage();
            break;
        }
        else{
            std::cout << "Your username or password is incorrect, please login with correct username or password... \n";
        }
    }
}

void TaskManager::adminPage() {
    while(true){
        if(super_admin->getUnapprovedUsers() > 0){
            std::cout << "S: Show Unapproved users\n";
            std::cout << "D: Dismiss\n";

            std::string command = validator->validReadString("Enter a Command: ", "Please enter a command...\n");
            std::cout << "\n";

            if(command == "S"){
                super_admin->displayUnapprovedUsers();
                break;
            }
            else if(command == "D"){
                break;
            }
            else{
                std::cout << "Please enter a valid command...\n";
            }
        }
        else{
            break;
        }
    }

    while(true){
        std::cout << "1: Create Task\n";
        std::cout << "2: Delete Task\n";
        std::cout << "3: Update Task status\n";
        std::cout << "4: Reassign Task\n";
        std::cout << "5: Create User\n";
        std::cout << "6: Approve User\n";
        std::cout << "7: Delete User\n";
        std::cout << "8: Display All Tasks\n";
        std::cout << "9: Display Task by Id\n";
        std::cout << "10: Display Task by User\n";
        std::cout << "11: Display users\n";
        std::cout << "12: Display Unapproved users\n";
        std::cout << "13: Display Admin Details\n";
        std::cout << "L: Logout\n";

        std::cout << "\n";

        std::string command = validator->validReadString("Enter a command: ", "Please enter a command...\n");
        std::cout << "\n";

        if(command == "1"){
            int task_id = validator->validReadInteger("Enter Task Id: ", "Please enter a valid Task Id...\n");
            std::string title = validator->validReadString("Enter title: ", "Please enter a title...\n");
            std::string description = validator->validReadString("Enter description: ", "Please enter a description...\n");
            int user_id = validator->validReadInteger("Enter User Id: ", "Please enter a valid User Id...\n");
            super_admin->createTask(task_id, title, description, user_id);
        }
        else if(command == "2"){
            int task_id = validator->validReadInteger("Enter Task Id: ", "Please enter a valid Task Id...\n");
            super_admin->deleteTask(task_id);
        }
        else if(command == "3"){
            int task_id = validator->validReadInteger("Enter Task Id: ", "Please enter a valid Task Id...\n");
            int task_status = validator->validReadInteger("Enter status (1 for complete OR 0 for incomplete): ", "Please enter a valid status...\n");
            bool updated_task_status;
            if(task_status == 0){
                updated_task_status = false;
            }
            else{
                updated_task_status = true;
            }
            super_admin->taskAdminStatusUpdate(task_id, updated_task_status);
        }
        else if(command == "4"){
            int task_id = validator->validReadInteger("Enter Task Id: ", "Please enter a valid Task Id...\n");
            int user_id = validator->validReadInteger("Enter User Id: ", "Please enter a valid User Id...\n");
            super_admin->reassignTask(task_id, user_id);
        }
        else if(command == "5"){
            int user_id = validator->validReadInteger("Enter User Id: ", "Please enter a valid integer...\n");
            std::string username = validator->validReadString("Enter username: ", "Please enter a username...\n");
            std::string password = validator->validReadString("Enter password: ", "Please enter a password...\n");
            super_admin->createUser(user_id, username, password);
        }
        else if(command == "6"){
            int user_id = validator->validReadInteger("Enter User Id: ", "Please enter a valid integer...\n");
            super_admin->approveUser(user_id);
        }
        else if(command == "7"){
            int user_id = validator->validReadInteger("Enter User Id: ", "Please enter a valid integer...\n");
            super_admin->deleteUser(user_id);
        }
        else if(command == "8"){
            super_admin->displayAllTasks();
        }
        else if(command == "9"){
            int task_id = validator->validReadInteger("Enter Task Id: ", "Please enter a valid Task Id...\n");
            super_admin->displayTaskById(task_id);
        }
        else if(command == "10"){
            int user_id = validator->validReadInteger("Enter User Id: ", "Please enter a valid integer...\n");
            super_admin->displayUserTasks(user_id);
        }
        else if(command == "11"){
            super_admin->displayUsers();
        }
        else if(command == "12"){
            super_admin->displayUnapprovedUsers();
        }
        else if(command == "13"){
            super_admin->displayAdmin();
        }
        else if(command == "L"){
            std::cout << "Logged out Successfully...\n";
            break;
        }
        else{
            std::cout << "Please enter a valid command...\n";
        }
    }
}

void TaskManager::userLoginPage() {
    while(true){
        std::cout << "**************User Login Page**************\n\n";
        int user_id = validator->validReadInteger("Enter user_id: ", "Please enter a valid integer...\n");
        std::string password = validator->validReadString("Enter password: ", "Please enter a password...\n");

        std::cout << "\n";

        if(super_admin->checkUser(user_id)){
            Userptr& user = super_admin->getUserById(user_id);
            if(user->login(user_id, password) && super_admin->getApproveStatus(user_id)){
                std::cout << "Access Granted...\n\n\n";
                std::cout << "**************User Page**************\n\n";
                user->displayNotifications();
                userPage(user);
                break;
            }
            else if(user->login(user_id, password) && !super_admin->getApproveStatus(user_id)){
                std::cout << "You cannot login, check with admin if your Id is approved or not...\n";
                break;
            }
            else{
                std::cout << "Your username or password is incorrect, please login with correct username or password... \n";
            }
        }
        else{
            std::cout << "Your username or password is incorrect, please login with correct username or password... \n";
        }
    }
}

void TaskManager::userPage(Userptr& user) {
    while(true){
        if(user->getNewTasks() > 0){
            std::cout << "S: Show New Tasks\n";
            std::cout << "D: Dismiss\n";

            std::string command = validator->validReadString("Enter a Command: ", "Please enter a command...\n");
            std::cout << "\n";

            if(command == "S"){
                user->displayNewTasks();
                break;
            }
            else if(command == "D"){
                break;
            }
            else{
                std::cout << "Please enter a valid command...\n";
            }
        }
        else{
            break;
        }
    }

    while(true){
        std::cout << "1: Update Task status\n";
        std::cout << "2: Display All Tasks\n";
        std::cout << "3: Display New Tasks\n";
        std::cout << "4: Display Task by Id\n";
        std::cout << "5: Display User Details\n";
        std::cout << "L: Logout\n";

        std::cout << "\n";

        std::string command = validator->validReadString("Enter a command: ", "Please enter a command...\n");
        std::cout << "\n";

        if(command == "1"){
            int task_id = validator->validReadInteger("Enter Task Id: ", "Please enter a valid Task Id...\n");
            int task_status = validator->validReadInteger("Enter status (1 for complete OR 0 for incomplete): ", "Please enter a valid status...\n");
            bool updated_task_status;
            if(task_status == 0){
                updated_task_status = false;
            }
            else{
                updated_task_status = true;
            }
            user->taskStatusUpdate(task_id, updated_task_status);
        }
        else if(command == "2"){
            user->displayAllUserTasks();
        }
        else if(command == "3"){
            user->displayNewTasks();
        }
        else if(command == "4"){
            int task_id = validator->validReadInteger("Enter Task Id: ", "Please enter a valid Task Id...\n");
            user->displayTaskById(task_id);
        }
        else if(command == "5"){
            user->displayUser();
        }
        else if(command == "L"){
            std::cout << "Logged out Successfully...\n";
            break;
        }
        else{
            std::cout << "Please enter a valid command...\n";
        }
    }
}
