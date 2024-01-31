#include <iostream>
#include "taskmanager.h"

int main(){
    TaskManagerptr taskmanager = std::make_shared<TaskManager>();
    taskmanager->homePage();
    return 0;
}