cmake_minimum_required(VERSION 3.10)
project(DSA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE SRC_FILES
    ${CMAKE_SOURCE_DIR}/fundamentals/*.cpp
    ${CMAKE_SOURCE_DIR}/nc/*.cpp
    ${CMAKE_SOURCE_DIR}/main.cpp
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_compile_options(${PROJECT_NAME} PRIVATE -O3)

set(DEBUG_EXECUTABLE ${PROJECT_NAME}_debug)
add_executable(${DEBUG_EXECUTABLE} ${SRC_FILES})
target_include_directories(${DEBUG_EXECUTABLE} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_compile_options(${DEBUG_EXECUTABLE} PRIVATE -g)

option(USE_DEBUG "Enable debug mode" OFF)
if(USE_DEBUG)
    set(CMAKE_BUILD_TYPE Debug)
else()
    set(CMAKE_BUILD_TYPE Release)
endif()
