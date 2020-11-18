cmake_minimum_required(VERSION 3.5)

project(opencv LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(the_target "myopencv_sample")

add_executable(${the_target} main.cpp example2_5.cpp example2_6.cpp example2_7.cpp example2_9.cpp
	example2_10.cpp example2_11.cpp lkdemo.cpp ipcam.cpp chapter_3.cpp
	youtube_dft.cpp youtube_rtp.cpp ) # add other .cpp and .h files here

find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

target_link_libraries(${the_target} ${OpenCV_LIBS})


