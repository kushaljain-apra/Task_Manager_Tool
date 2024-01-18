#include <iostream>
#include "task.h"

int main(){
    Taskptr mytask = std::make_shared<Task>(1, "Setup vcpkg", "Refer to documentation");
    mytask->printTask();
    std::cout << "Changing task status and read status to completed...\n";
    mytask->setTaskstatus(true);
    mytask->setTaskReadStatus(true);
    mytask->printTask();
    
    return 0;
}