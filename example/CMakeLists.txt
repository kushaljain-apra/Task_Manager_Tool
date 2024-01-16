project(HelloWorld)

add_executable(helloworld helloworld.cpp)

add_executable(testtask test_task.cpp)

target_link_libraries(helloworld
    PRIVATE 
    hello)

target_link_libraries(testtask
    PRIVATE 
    task)