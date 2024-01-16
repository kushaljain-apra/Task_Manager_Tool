project(HelloWorld)

add_library(hello printhello.cpp)

target_include_directories(hello 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include 
)