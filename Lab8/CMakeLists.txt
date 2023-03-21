
cmake_minimum_required(VERSION 2.8.9)

project (Lab8)

set(CMAKE_CXX_STANDARD 11)           
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Lab8Lib SHARED Lab8cpp.cpp)

target_include_directories(Lab8Lib PRIVATE
	"C:\\Program Files\\Eclipse Foundation\\jdk-11.0.12.7-hotspot\\include"
	"C:\\Program Files\\Eclipse Foundation\\jdk-11.0.12.7-hotspot\\include\\win32"
)