#include <iostream>
#include "task.h"
#include "user.h"

int main(){
    // Creating 3 tasks
    Taskptr task1 = std::make_shared<Task>(1, "Setup vcpkg", "Refer to documentation");
    Taskptr task2 = std::make_shared<Task>(2, "Test Task", "Testing Task Module");
    Taskptr task3 = std::make_shared<Task>(3, "Test User", "Testing User Module");

    std::cout << "Created 3 Tasks: \n";
    task1->printTask();
    task2->printTask();
    task3->printTask();

    // Creating 2 users
    Userptr user1 = std::make_shared<User>(1, "Kushal", "password");
    Userptr user2 = std::make_shared<User>(2, "Suyash", "whybro");

    std::cout << "Created 2 Users: \n"; 
    user1->displayUser();
    user2->displayUser();

    std::cout << "Assign 2 tasks to User1 and 1 task to user 2...\n";
    user1->addTask(task1);
    user1->addTask(task2);
    user2->addTask(task3);

    user1->Login("Kushal", "password");
    user1->displayNewTasks();
    user1->Login("Kushal", "password");
    user1->displayNewTasks();

    user2->Login(2, "whybro");
    user2->displayNewTasks();
    user2->Login(2, "whybro");
    user1->displayNewTasks();
    return 0;
}