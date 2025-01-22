
## setup project
cmake_minimum_required(VERSION 3.10)
project(neuralanimals)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## find SDL
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

## add source files
set(SOURCES src/main.cpp)

## create executable
add_executable(neuralanimals ${SOURCES})

## include libraries
target_include_directories(neuralanimals PRIVATE  ${SDL2_INCLUDE_DIRS})

## link libraries
target_link_libraries(neuralanimals PRIVATE ${SDL2_LIBRARIES})

