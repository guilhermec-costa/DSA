cmake_minimum_required(VERSION 3.10)
project(DSA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SRC_FILES src/*.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Cria o executável principal
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_compile_options(${PROJECT_NAME} PRIVATE -O3)

# Cria o executável de debug
set(DEBUG_EXECUTABLE ${PROJECT_NAME}_debug)
add_executable(${DEBUG_EXECUTABLE} ${SRC_FILES})
target_include_directories(${DEBUG_EXECUTABLE} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_compile_options(${DEBUG_EXECUTABLE} PRIVATE -g)

# Define build type
option(USE_DEBUG "Enable debug mode" OFF)
if(USE_DEBUG)
    set(CMAKE_BUILD_TYPE Debug)
else()
    set(CMAKE_BUILD_TYPE Release)
endif()
