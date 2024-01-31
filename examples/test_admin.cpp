#include <iostream>
#include "admin.h"

int main(){
    Adminptr admin = std::make_shared<Admin>(1, "admin", "password");

    // Display Methods Tests
    admin->displayAdmin();
    admin->displayNotifications();
    admin->displayAllTasks();
    admin->displayUnapprovedUsers();

    // Login Method Tests
    admin->login(1, "password");
    admin->login(1, "pass");
    admin->login(1, "password");
    admin->login(2, "pass");

    // User Creation Methods
    admin->createUser(1, "kushal", "password");
    admin->displayNotifications();
    admin->createUser(2, "suyash", "password");
    admin->displayNotifications();
    admin->displayAllTasks();
    admin->displayUnapprovedUsers();

    // Task Creation Methods
    admin->createTask(1, "test admin module", "testing admin module", 1);
    admin->approveUser(1);
    admin->createTask(1, "test admin module", "testing admin module", 1);
    admin->createTask(2, "test user module", "testing user module", 1);
    admin->approveUser(2);
    admin->createTask(1, "test admin module", "testing admin module", 2);
    admin->createTask(2, "test user module", "testing user module", 2);
    admin->displayNotifications();
    admin->displayAllTasks();
    admin->displayUnapprovedUsers();
    return 0;
}