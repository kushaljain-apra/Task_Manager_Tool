cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

# set(CMAKE_TOOLCHAIN_FILE "C:/Users/developer/Task_Manager_Tool/vcpkg/scripts/buildsystems/vcpkg.cmake")
# find_package(fmt CONFIG REQUIRED)
# add_executable(HelloWorld printhello.cpp)
# target_link_libraries(HelloWorld PRIVATE fmt::fmt)

add_library(printhello src/printhello.cpp)
add_library(task src/task.cpp)
add_library(user src/user.cpp)
add_library(admin src/admin.cpp)
add_library(taskmanager src/taskmanager.cpp)
add_library(inputvalidator src/inputvalidator.cpp)

target_include_directories(printhello
    PUBLIC
    include 
)

target_include_directories(task
    PUBLIC
    include 
)

target_include_directories(user
    PUBLIC
    include 
)

target_include_directories(admin
    PUBLIC
    include 
)

target_include_directories(taskmanager
    PUBLIC
    include 
)

target_include_directories(inputvalidator
    PUBLIC
    include 
)

option(BUILD_EXAMPLES "Whether to build examples or not..." ON)

if(BUILD_EXAMPLES)
    message(STATUS "Buidling Examples...")
    add_executable(helloworld examples/helloworld.cpp)
    add_executable(test_task examples/test_task.cpp)
    add_executable(test_user examples/test_user.cpp)
    add_executable(test_admin examples/test_admin.cpp)
    add_executable(test_taskmanager examples/test_taskmanager.cpp)

    target_link_libraries(helloworld
        PRIVATE 
        printhello)

    target_link_libraries(test_task
        PRIVATE 
        task)

    target_link_libraries(test_user
        PRIVATE 
        user task)

    target_link_libraries(test_admin
        PRIVATE 
        admin task user)

    target_link_libraries(test_taskmanager
        PRIVATE 
        taskmanager admin task user inputvalidator)
endif()

add_executable(main main/main.cpp)
target_link_libraries(main
    PRIVATE 
    taskmanager admin task user inputvalidator)