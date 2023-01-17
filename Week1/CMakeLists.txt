# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.2)

project ("Week1")

# Include sub-projects.
add_subdirectory ("Week1")

add_executable(Soomin_Lab1 "Week1/Week1.cpp" "Week1/Week1.h")
