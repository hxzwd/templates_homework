cmake_minimum_required(VERSION 2.8)
if(UNIX)
	set(CMAKE_CXX_COMPILER "g++-4.9")
	add_definitions("-std=c++11")
else()
	#nothing 
endif()

set(SRC main.cpp)

add_executable(main ${SRC})