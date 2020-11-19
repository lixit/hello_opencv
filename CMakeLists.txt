cmake_minimum_required(VERSION 3.5)

project(opencv LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

file( GLOB APP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp )
foreach( sourcefile ${APP_SOURCES} )
    file(RELATIVE_PATH filename ${CMAKE_CURRENT_SOURCE_DIR} ${sourcefile})
    string( REPLACE ".cpp" "" file ${filename} )
    add_executable( ${file} ${sourcefile} )
    target_link_libraries( ${file} ${OpenCV_LIBS} )
endforeach( sourcefile ${APP_SOURCES} )
