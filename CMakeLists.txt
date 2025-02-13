
## setup project
cmake_minimum_required(VERSION 3.10)
project(neuralanimals)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## install dependencies 
include(FetchContent)

## sdl2
FetchContent_Declare(
    sdl2
    GIT_REPOSITORY "https://github.com/libsdl-org/SDL.git"
    GIT_TAG release-2.26.5
)

FetchContent_MakeAvailable(sdl2)


## gtest
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)

FetchContent_MakeAvailable(googletest)


## libnoise
FetchContent_Declare(
    libnoise
    GIT_REPOSITORY "https://github.com/eXpl0it3r/libnoise"
    GIT_TAG "master"
)
FetchContent_MakeAvailable(libnoise)



## add source files
file(GLOB_RECURSE SOURCES
    src/*.cpp
    src/render/*.cpp
    src/runtime/*.cpp
    src/world/*.cpp
    src/entity/*.cpp)

## create executable
add_executable(neuralanimals ${SOURCES})

## add test source files
file(GLOB_RECURSE TEST_SOURCES
    tests/*.cpp
    tests/render/*.cpp
    tests/runtime/*.cpp
    tests/world/*.cpp
    tests/entity/*.cpp)

## create test executable
add_executable(neuralanimals_tests ${TEST_SOURCES})

## include libraries
target_include_directories(neuralanimals PRIVATE 
                                                    ${CMAKE_SOURCE_DIR}/src
                                                    ${CMAKE_SOURCE_DIR}/src/entity
                                                    ${CMAKE_SOURCE_DIR}/src/render
                                                    ${CMAKE_SOURCE_DIR}/src/runtime
                                                    ${CMAKE_SOURCE_DIR}/src/world)
## link libraries
target_link_libraries(neuralanimals PRIVATE
    SDL2::SDL2main SDL2::SDL2
    noise
    gtest gtest_main)

## link libraries for tests
target_link_libraries(neuralanimals_tests PRIVATE
    gtest gtest_main)



