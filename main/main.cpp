#include <iostream>
#include <crtdbg.h>
#include "taskmanager.h"

int main(){
    TaskManagerptr taskmanager = std::make_shared<TaskManager>();
    taskmanager->HomePage();
    _CrtDumpMemoryLeaks();
    return 0;
}