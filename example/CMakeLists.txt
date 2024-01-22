project(HelloWorld)

add_executable(helloworld helloworld.cpp)
add_executable(test_task test_task.cpp)
add_executable(test_user test_user.cpp)
add_executable(test_admin test_admin.cpp)
add_executable(test_taskmanager test_taskmanager.cpp)

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

