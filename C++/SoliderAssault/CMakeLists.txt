cmake_minimum_required(VERSION 3.0)
project(SoliderAssault)
set(CMAEK_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_BUILD_TYPE Debug)
include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(SoliderAssault.exe main.cpp src/Gun.cpp src/Solider.cpp)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}) #将可执行文件存储在当前目录下