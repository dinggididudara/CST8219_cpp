# CMakeList.txt : CMake project for Final, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
  
project ("FinalProject-040899389")

# Add source to this project's executable.
add_executable (FinalProject-040899389 "FinalProject-040899389.cpp" "FinalProject-040899389.h")
 
target_include_directories(FinalProject-040899389 PUBLIC "./include")
target_link_directories(FinalProject-040899389 PUBLIC "./lib")
target_link_libraries(FinalProject-040899389 PUBLIC sfml-main sfml-graphics sfml-system sfml-window tgui)