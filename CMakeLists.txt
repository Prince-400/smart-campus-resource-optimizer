
cmake_minimum_required(VERSION 3.16)

project(SmartCampusOptimizer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SmartCampus
    backend/main.cpp
    backend/RoomManager.cpp
)

target_include_directories(SmartCampus PRIVATE backend)
