#include <iostream>
#include "task.h"

int main(){
    Taskptr mytask = std::make_shared<Task>(1, "Setup vcpkg", "Refer to documentation");
    mytask->displayTask();
    std::cout << "Changing task status and read status to completed...\n";
    mytask->getTaskReadStatus();
    mytask->setTaskReadStatus(true);
    mytask->displayTask();
    
    return 0;
}