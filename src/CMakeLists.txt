project(HelloWorld)

add_library(printhello printhello.cpp)
add_library(task task.cpp)
add_library(user user.cpp)
add_library(admin admin.cpp)
add_library(taskmanager taskmanager.cpp)
add_library(inputvalidator inputvalidator.cpp)

target_include_directories(printhello
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include 
)

target_include_directories(task
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include 
)

target_include_directories(user
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include 
)

target_include_directories(admin
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include 
)

target_include_directories(taskmanager
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include 
)

target_include_directories(inputvalidator
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include 
)
