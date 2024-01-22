project(HelloWorld)

add_executable(main main.cpp)

target_link_libraries(main
    PRIVATE 
    taskmanager admin task user inputvalidator)