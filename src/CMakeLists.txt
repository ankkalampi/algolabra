## THIS CMAKELIST CREATES THE APPLICATION EXECUTABLE


## add source files
file(GLOB_RECURSE SRC_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
list(REMOVE_ITEM SRC_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)




## create library for app logic
add_library(neuralanimals_lib ${SRC_SOURCES})
## create executable
add_executable(neuralanimals main.cpp)



## add headers
target_include_directories(neuralanimals_lib PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    )

## this is required for libnoise
target_include_directories(neuralanimals PRIVATE ${CMAKE_BINARY_DIR}/_deps/noise-src/include)


# link libraries
target_link_libraries(neuralanimals_lib PRIVATE
    SDL2::SDL2main SDL2::SDL2
    noise)

## link libraries
target_link_libraries(neuralanimals PRIVATE
    neuralanimals_lib
    SDL2::SDL2main SDL2::SDL2
    noise)

