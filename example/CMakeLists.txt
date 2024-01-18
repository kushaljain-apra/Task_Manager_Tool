project(HelloWorld)

add_executable(helloworld helloworld.cpp)
add_executable(test_task test_task.cpp)
add_executable(test_user test_user.cpp)

target_link_libraries(helloworld
    PRIVATE 
    printhello)

target_link_libraries(test_task
    PRIVATE 
    task)

target_link_libraries(test_user
    PRIVATE 
    user)

target_link_libraries(test_user
    PRIVATE 
    task)