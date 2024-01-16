project(HelloWorld)

add_library(hello printhello.cpp)
add_library(task task.cpp)

target_include_directories(hello
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include 
)

target_include_directories(task
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include 
)