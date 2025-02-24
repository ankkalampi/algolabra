## THIS CMAKELIST CREATES THE TEST EXECUTABLE

## enable testing for ctest
enable_testing()

## add source files
file(GLOB_RECURSE TEST_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/behavior/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/entity/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/render/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/world/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/systems/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/components/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/entities/*.cpp)

## create executable
add_executable(neuralanimals_tests ${TEST_SOURCES})

target_include_directories(neuralanimals_tests PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}/_deps/libnoise-src/include
    ${CMAKE_SOURCE_DIR}/src
    )



## link libraries
target_link_libraries(neuralanimals_tests PRIVATE
    neuralanimals_lib
    gtest
    gtest_main)

## enable automatic test discovery for googletest
include(GoogleTest)
gtest_discover_tests(neuralanimals_tests)
