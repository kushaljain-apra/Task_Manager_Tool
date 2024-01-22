#include <iostream>
#include "taskmanager.h"

int main(){
    TaskManagerptr taskmanager = std::make_shared<TaskManager>();
    taskmanager->HomePage();
    return 0;
}