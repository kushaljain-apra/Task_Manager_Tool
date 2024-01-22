cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

#set(CMAKE_TOOLCHAIN_FILE "C:/Users/developer/Task_Manager_Tool/vcpkg/scripts/buildsystems/vcpkg.cmake")
# find_package(fmt CONFIG REQUIRED)
# add_executable(HelloWorld helloworld.cpp)
# target_link_libraries(HelloWorld PRIVATE fmt::fmt)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(main)

option(BUILD_EXAMPLES "Whether to build example or not" OFF)

if (BUILD_EXAMPLES)
    message(STATUS "Building Examples...")
    add_subdirectory(example)
endif()

