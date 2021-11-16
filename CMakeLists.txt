cmake_minimum_required(VERSION 3.17)
project(opengl)

include_directories(include)
link_directories(lib/x64)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

#add_executable(opengl jing.cpp)
#add_executable(opengl pin.cpp)
add_executable(opengl cut.cpp)
#add_executable(opengl bressenham.cpp)
target_link_libraries(opengl libopengl32.a  libfreeglut.a glu32.dll)