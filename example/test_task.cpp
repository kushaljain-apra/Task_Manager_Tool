#include <iostream>
#include "task.h"

int main(){
    Taskptr mytask = std::make_shared<Task>(1, "Setup vcpkg", "Refer to documentation");
    std::cout << mytask->get_id() << " " << mytask->get_title() << " " << mytask->get_description() << " " << mytask->isCompleted() << "\n";
    std::cout << "Changing task status to completed...\n";
    mytask->setAsCompleted(true);
    std::cout << mytask->get_id() << " " << mytask->get_title() << " " << mytask->get_description() << " " << mytask->isCompleted() << "\n";
    
    return 0;
}