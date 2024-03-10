#include <iostream>
#include "user.h"

int main(){
    // Creating 3 tasks
    Taskptr task1 = std::make_shared<Task>(1, "Setup vcpkg", "Refer to documentation");
    Taskptr task2 = std::make_shared<Task>(2, "Test Task", "Testing Task Module");
    Taskptr task3 = std::make_shared<Task>(3, "Test User", "Testing User Module");

    std::cout << "Created 3 Tasks: \n";
    task1->displayTask();
    task2->displayTask();
    task3->displayTask();

    // Creating 2 users
    Userptr user1 = std::make_shared<User>(1, "Kushal", "password");
    Userptr user2 = std::make_shared<User>(2, "Suyash", "whybro");

    std::cout << "Created 2 users: \n"; 
    // Display User Test
    user1->displayUser();
    user2->displayUser();

    std::cout << "Assign 2 tasks to User1 and 1 task to user 2...\n";
    // Add Task Test
    user1->addTask(task1);
    user1->addTask(task2);
    user2->addTask(task3);

    // Login and Notification Test
    user1->login(1, "password");
    user1->displayAllUserTasks();
    user1->login(1, "password");
    user1->displayNewTasks();

    user2->login(2, "whybro");
    user2->displayAllUserTasks();
    user2->login(2, "whybro");
    user1->displayNewTasks();

    // Display Task by ID test
    user1->displayTaskById(1);
    user1->displayTaskById(2);
    user2->displayTaskById(2);
    user2->displayTaskById(3);

    //Task status Update
    user1->displayTaskById(1);
    user1->taskStatusUpdate(1, true);
    user1->displayTaskById(1);
    user2->displayTaskById(1);
    user2->taskStatusUpdate(1, true);
    user2->displayTaskById(1);

    // Delete Task by Id
    user1->displayAllUserTasks();
    user1->deleteTask(1);
    user1->displayAllUserTasks();

    user2->displayAllUserTasks();
    user2->deleteTask(2);
    user2->displayAllUserTasks();

    user2->displayAllUserTasks();
    user2->deleteTask(3);
    user2->displayAllUserTasks();

    // Get task by ID
    Taskptr task4 = user1->getTaskById(1);
    Taskptr task5 = user1->getTaskById(2);
    // task4->displayTask(); DO NOT USE IF NULL
    task5->displayTask();
    return 0;
}