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

## debug
set(CMAKE_BUILD_TYPE Debug)

if(OpenMP_CXX_FOUND)
    target_compile_options(neuralanimals_lib PRIVATE ${OpenMP_CXX_FLAGS})
    target_link_libraries(neuralanimals_lib PRIVATE OpenMP::OpenMP_CXX)
endif()


include_directories(${SDL3_SOURCE_DIR}/include)



## add headers
target_include_directories(neuralanimals_lib PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/world
    ${CMAKE_CURRENT_SOURCE_DIR}/systems
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime
    ${CMAKE_CURRENT_SOURCE_DIR}/render
    ${CMAKE_CURRENT_SOURCE_DIR}/entity
    ${CMAKE_BINARY_DIR}/_deps/libnoise-src/include
    
    
    )

target_include_directories(neuralanimals PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/world
    ${CMAKE_CURRENT_SOURCE_DIR}/systems
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime
    ${CMAKE_CURRENT_SOURCE_DIR}/render
    ${CMAKE_CURRENT_SOURCE_DIR}/entity
    ${CMAKE_BINARY_DIR}/_deps/libnoise-src/include
  
    )

## this is required for libnoise
target_link_directories(neuralanimals PRIVATE ${CMAKE_BINARY_DIR}/_deps/libnoise-build)
target_link_directories(neuralanimals_lib PRIVATE ${CMAKE_BINARY_DIR}/_deps/libnoise-build)

# link libraries
target_link_libraries(neuralanimals_lib PRIVATE
    SDL3-static
    libnoise)

## link libraries
target_link_libraries(neuralanimals PRIVATE
    neuralanimals_lib
    SDL3-static
    libnoise)

