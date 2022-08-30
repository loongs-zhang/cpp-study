cmake_minimum_required(VERSION 3.19)
project(cpp_study)

set(CMAKE_CXX_STANDARD 20)

#设置动态链接库名
set(LIB_NAME libhook)
add_library(libhook SHARED hook.cpp)

add_executable(01HelloWorld 01HelloWorld.cpp)
add_executable(02Cin 02Cin.cpp)
add_executable(03Loop 03Loop.cpp)
add_executable(04If 04If.cpp)
add_executable(05Hook 05Hookd.cpp)

target_link_libraries(05Hook libhook)
