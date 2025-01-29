
## setup project
cmake_minimum_required(VERSION 3.10)
project(neuralanimals)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


## find SDL
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

## Noise library
include_directories(/usr/include/libnoise)


## add source files
set(SOURCES src/main.cpp src/render/render.cpp)

## create executable
add_executable(neuralanimals ${SOURCES})

## include libraries
target_include_directories(neuralanimals PRIVATE  ${SDL2_INCLUDE_DIRS})
target_include_directories(neuralanimals PRIVATE /usr/include/glm)
target_include_directories(neuralanimals PRIVATE /usr/include/libnoise)
target_include_directories(neuralanimals PRIVATE ${CMAKE_SOURCE_DIR}/src)
## link libraries
target_link_libraries(neuralanimals PRIVATE ${SDL2_LIBRARIES})
target_link_libraries(neuralanimals PRIVATE noise)


