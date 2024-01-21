#include <iostream>
#include "taskmanager.h"

// Constructors
TaskManager::TaskManager() {
    Adminptr admin = std::make_shared<Admin>(1, "admin", "admin");
    this->superAdmin = admin;
}

// Getters
int TaskManager::get_superAdminid() {
    return superAdmin->get_Adminid();
}

std::string TaskManager::get_superAdminUsername() {
    return superAdmin->get_Username();
}

std::string TaskManager::get_superAdminPassword() {
    return superAdmin->get_Password();
}

// Setters

// Display Methods
void TaskManager::Welcome(){
    std::cout << "\t\t\t******************************************************************\n";
    std::cout << "\t\t\t                Welcome to Task Manager !!!\n";
    std::cout << "\t\t\t******************************************************************\n\n\n";
}
void TaskManager::HomePage() {
    while(true){
        Welcome();
        std::cout << "Note: Please use characters before the colon for typing using any commands";
        std::cout << "A: Admin Login\n";
        std::cout << "U: User Login\n";
        std::cout << "N: New User? Register here\n";
        std::cout << "exit: Exit Task Manager\n";

        std::string command = validate->ValidreadString("Enter a Command: ", "Please enter a command...\n");
        std::cout << "\n";

        if(command == "A"){
            AdminLoginPage();
        }
        else if(command == "U"){
            UserLoginPage();
        }
        else if(command == "N"){
            RegisterationPage();
        }
        else if(command == "exit"){
            break ;
        }
        else{
            std::cout << "Please enter a valid command...\n";
        }
    }
}

void TaskManager::RegisterationPage() {
    std::cout << "**************User Registration Page**************\n\n";
    int Userid = validate->ValidreadInteger("Enter User Id: ", "Please enter a valid integer...\n");
    std::string Username = validate->ValidreadString("Enter Username: ", "Please enter a username...\n");
    std::string Password = validate->ValidreadString("Enter Password: ", "Please enter a password...\n");

    std::cout << "\n";

    std::cout << "F: Finish Registeration\n";
    std::cout << "C: Cancel Registration\n";
    std::cout << "B: Go Back\n";

    while(true){
        std::string command = validate->ValidreadString("Enter a Command: ", "Please enter a command...\n");
        std::cout << "\n";

        if(command == "F"){
            if(!superAdmin->checkUser(Userid)){
                std::cout << "User Registration Confirmed...\n";
                std::cout << "Redirecting to Home...\n";
            }
            superAdmin->createUser(Userid, Username, Password);
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

void TaskManager::AdminLoginPage() {
    while(true){
        std::cout << "**************Admin Login Page**************\n\n";
        int Adminid = validate->ValidreadInteger("Enter Adminid: ", "Please enter a valid integer...\n");
        std::string Password = validate->ValidreadString("Enter Password: ", "Please enter a password...\n");

        std::cout << "\n";

        if(superAdmin->get_Adminid() == Adminid && superAdmin->get_Password() == Password){
            std::cout << "Access Granted...\n";
            std::cout << "**************Admin Page**************\n\n";
            superAdmin->login(Adminid, Password);
            AdminPage();
            break;
        }
        else{
            std::cout << "Your username or password is incorrect, please login with correct username or password... \n";
        }
    }
}

void TaskManager::AdminPage() {
    while(true){
        if(superAdmin->getUnapprovedUsers() > 0){
            std::cout << "S: Show Unapproved Users\n";
            std::cout << "D: Dismiss\n";

            std::string command = validate->ValidreadString("Enter a Command: ", "Please enter a command...\n");
            std::cout << "\n";

            if(command == "S"){
                superAdmin->displayUnapprovedUsers();
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
        std::cout << "3: Update Task Status\n";
        std::cout << "4: Reassign Task\n";
        std::cout << "5: Create User\n";
        std::cout << "6: Approve User\n";
        std::cout << "7: Delete User\n";
        std::cout << "8: Display All Tasks\n";
        std::cout << "9: Display Task by Id\n";
        std::cout << "10: Display Task by User\n";
        std::cout << "11: Display Users\n";
        std::cout << "12: Display Unapproved Users\n";
        std::cout << "13: Display Admin Details\n";
        std::cout << "L: Logout\n";

        std::cout << "\n";

        std::string command = validate->ValidreadString("Enter a command: ", "Please enter a command...\n");
        std::cout << "\n";

        if(command == "1"){
            int Taskid = validate->ValidreadInteger("Enter Task Id: ", "Please enter a valid Task Id...\n");
            std::string Title = validate->ValidreadString("Enter Title: ", "Please enter a title...\n");
            std::string Description = validate->ValidreadString("Enter Description: ", "Please enter a description...\n");
            int Userid = validate->ValidreadInteger("Enter User Id: ", "Please enter a valid User Id...\n");
            superAdmin->createTask(Taskid, Title, Description, Userid);
        }
        else if(command == "2"){
            int Taskid = validate->ValidreadInteger("Enter Task Id: ", "Please enter a valid Task Id...\n");
            superAdmin->deleteTask(Taskid);
        }
        else if(command == "3"){
            int Taskid = validate->ValidreadInteger("Enter Task Id: ", "Please enter a valid Task Id...\n");
            int Status = validate->ValidreadInteger("Enter Status (1 for complete OR 0 for incomplete): ", "Please enter a valid status...\n");
            bool update;
            if(Status == 0){
                update = false;
            }
            else{
                update = true;
            }
            superAdmin->taskAdminStatusUpdate(Taskid, update);
        }
        else if(command == "4"){
            int Taskid = validate->ValidreadInteger("Enter Task Id: ", "Please enter a valid Task Id...\n");
            int Userid = validate->ValidreadInteger("Enter User Id: ", "Please enter a valid User Id...\n");
            superAdmin->reassignTask(Taskid, Userid);
        }
        else if(command == "5"){
            int Userid = validate->ValidreadInteger("Enter User Id: ", "Please enter a valid integer...\n");
            std::string Username = validate->ValidreadString("Enter Username: ", "Please enter a username...\n");
            std::string Password = validate->ValidreadString("Enter Password: ", "Please enter a password...\n");
            superAdmin->createUser(Userid, Username, Password);
        }
        else if(command == "6"){
            int Userid = validate->ValidreadInteger("Enter User Id: ", "Please enter a valid integer...\n");
            superAdmin->approveUser(Userid);
        }
        else if(command == "7"){
            int Userid = validate->ValidreadInteger("Enter User Id: ", "Please enter a valid integer...\n");
            superAdmin->deleteUser(Userid);
        }
        else if(command == "8"){
            superAdmin->displayAllTasks();
        }
        else if(command == "9"){
            int Taskid = validate->ValidreadInteger("Enter Task Id: ", "Please enter a valid Task Id...\n");
            superAdmin->displayTaskbyId(Taskid);
        }
        else if(command == "10"){
            int Userid = validate->ValidreadInteger("Enter User Id: ", "Please enter a valid integer...\n");
            superAdmin->displayUserTasks(Userid);
        }
        else if(command == "11"){
            superAdmin->displayUsers();
        }
        else if(command == "12"){
            superAdmin->displayUnapprovedUsers();
        }
        else if(command == "13"){
            superAdmin->displayAdmin();
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

void TaskManager::UserLoginPage() {
    while(true){
        std::cout << "**************User Login Page**************\n\n";
        int Userid = validate->ValidreadInteger("Enter Userid: ", "Please enter a valid integer...\n");
        std::string Password = validate->ValidreadString("Enter Password: ", "Please enter a password...\n");

        std::cout << "\n";

        if(superAdmin->checkUser(Userid)){
            Userptr& user = superAdmin->getUserbyId(Userid);
            if(user->get_Password() == Password){
                std::cout << "Access Granted...\n";
                std::cout << "**************User Page**************\n\n";
                user->login(Userid, Password);
                UserPage(user);
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

void TaskManager::UserPage(Userptr& user) {
    while(true){
        if(user->getNewTasks() > 0){
            std::cout << "S: Show New Tasks\n";
            std::cout << "D: Dismiss\n";

            std::string command = validate->ValidreadString("Enter a Command: ", "Please enter a command...\n");
            std::cout << "\n";

            if(command == "S"){
                user->displayNewTasks();
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
        std::cout << "1: Update Task Status\n";
        std::cout << "2: Display All Tasks\n";
        std::cout << "3: Display New Tasks\n";
        std::cout << "4: Display Task by Id\n";
        std::cout << "5: Display User Details\n";
        std::cout << "L: Logout\n";

        std::cout << "\n";

        std::string command = validate->ValidreadString("Enter a command: ", "Please enter a command...\n");
        std::cout << "\n";

        if(command == "1"){
            int Taskid = validate->ValidreadInteger("Enter Task Id: ", "Please enter a valid Task Id...\n");
            int Status = validate->ValidreadInteger("Enter Status (1 for complete OR 0 for incomplete): ", "Please enter a valid status...\n");
            bool update;
            if(Status == 0){
                update = false;
            }
            else{
                update = true;
            }
            user->taskStatusUpdate(Taskid, update);
        }
        else if(command == "2"){
            user->displayAllUserTasks();
        }
        else if(command == "3"){
            user->displayNewTasks();
        }
        else if(command == "4"){
            int Taskid = validate->ValidreadInteger("Enter Task Id: ", "Please enter a valid Task Id...\n");
            user->displayTaskbyId(Taskid);
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
