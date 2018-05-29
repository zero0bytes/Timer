
cmake_minimum_required(VERSION 3.0)
project(timer-test)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=armv6 -mfpu=vfp -mfloat-abi=hard")
add_executable(timer-test timer-test.cpp Timer.cpp pstream.h)
target_link_libraries(timer-test )



