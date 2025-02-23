## THIS CMAKELIST CREATES THE APPLICATION EXECUTABLE


## add source files
file(GLOB_RECURSE SRC_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
list(REMOVE_ITEM SRC_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)




## create library for app logic
add_library(neuralanimals_lib ${SRC_SOURCES})
## create executable
add_executable(neuralanimals main.cpp)

## enable OpenMP
find_package(OpenMP REQUIRED)

if(OpenMP_CXX_FOUND)
    target_compile_options(neuralanimals_lib PRIVATE ${OpenMP_CXX_FLAGS})
    target_link_libraries(neuralanimals_lib PRIVATE OpenMP::OpenMP_CXX)
endif()



## add headers
target_include_directories(neuralanimals_lib PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}/_deps/libnoise-src/include
    )

target_include_directories(neuralanimals PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}/_deps/libnoise-src/include
    )

## this is required for libnoise
target_link_directories(neuralanimals PRIVATE ${CMAKE_BINARY_DIR}/_deps/libnoise-build)
target_link_directories(neuralanimals_lib PRIVATE ${CMAKE_BINARY_DIR}/_deps/libnoise-build)

# link libraries
target_link_libraries(neuralanimals_lib PRIVATE
    SDL2::SDL2main SDL2::SDL2
    libnoise)

## link libraries
target_link_libraries(neuralanimals PRIVATE
    neuralanimals_lib
    SDL2::SDL2main SDL2::SDL2
    libnoise)

