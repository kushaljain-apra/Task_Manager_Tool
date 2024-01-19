#include <iostream>
#include "admin.h"

int main(){
    Adminptr admin = std::make_shared<Admin>(1, "admin", "password");

    // Display Methods Tests
    admin->displayAdmin();
    admin->displayNotification();
    admin->displayAllTasks();
    admin->displayUnapprovedUsers();

    // Login Method Tests
    admin->login("admin", "password");
    admin->login("admin", "pass");
    admin->login(1, "password");
    admin->login(2, "pass");

    // User Creation Methods
    admin->createUser(1, "kushal", "password");
    admin->displayNotification();
    admin->createUser(2, "suyash", "password");
    admin->displayNotification();
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
    admin->displayNotification();
    admin->displayAllTasks();
    admin->displayUnapprovedUsers();
    return 0;
}