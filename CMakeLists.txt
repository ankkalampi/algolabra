
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
set(SOURCES     src/main.cpp
                src/render/render.cpp
                src/runtime/runtime.cpp
                src/world/world.cpp
                src/world/world_utils.cpp
                src/world/terrain.cpp
                src/entity/animal.cpp
                src/entity/plant.cpp
                src/population.cpp
                src/entity/entity.cpp)

## create executable
add_executable(neuralanimals ${SOURCES})

## include libraries
target_include_directories(neuralanimals PRIVATE  ${SDL2_INCLUDE_DIRS})
target_include_directories(neuralanimals PRIVATE /usr/include/glm)
target_include_directories(neuralanimals PRIVATE /usr/include/libnoise)
target_include_directories(neuralanimals PRIVATE 
                                                    ${CMAKE_SOURCE_DIR}/src
                                                    ${CMAKE_SOURCE_DIR}/src/entity
                                                    ${CMAKE_SOURCE_DIR}/src/render
                                                    ${CMAKE_SOURCE_DIR}/src/runtime
                                                    ${CMAKE_SOURCE_DIR}/src/world)
## link libraries
target_link_libraries(neuralanimals PRIVATE ${SDL2_LIBRARIES})
target_link_libraries(neuralanimals PRIVATE noise)


