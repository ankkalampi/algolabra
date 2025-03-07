## THIS IS THE MAIN CMAKELIST

## setup project
cmake_minimum_required(VERSION 3.10)
project(neuralanimals)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

## install dependencies 
include(FetchContent)

## set root directory for file i/o etc
## use in code: PROJECT_ROOT_DIR
add_definitions(-DPROJECT_ROOT_DIR="${CMAKE_SOURCE_DIR}")

set(SDL3_DISABLE_INSTALL ON CACHE BOOL "" FORCE) # Ei asenneta järjestelmään
set(SDL_TEST OFF CACHE BOOL "" FORCE) # Ei testejä
set(SDL_SHARED OFF CACHE BOOL "" FORCE) # Käytä vain staattista versiota
set(SDL_STATIC ON CACHE BOOL "" FORCE) # Pakota staattinen käännös

## sdl2
FetchContent_Declare(
    sdl3
    GIT_REPOSITORY "https://github.com/libsdl-org/SDL.git"
    GIT_TAG release-3.2.4
)

FetchContent_MakeAvailable(sdl3)


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

FetchContent_Declare(
    Eigen
    GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
    GIT_TAG 3.4.0
)

FetchContent_MakeAvailable(Eigen)



## add source and test folders
add_subdirectory(src)
add_subdirectory(tests)






