## THIS IS THE MAIN CMAKELIST

## setup project
cmake_minimum_required(VERSION 3.10)
project(neuralanimals)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

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

## add source and test folders
add_subdirectory(src)
add_subdirectory(tests)






