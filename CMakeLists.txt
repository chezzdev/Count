cmake_minimum_required(VERSION 3.3)
project(Count)

INCLUDE_DIRECTORIES($HOME/mongo-client-install/include)
LINK_DIRECTORIES($HOME/mongo-client-install/lib)
add_library(libmongoclient.a SHARED IMPORTED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/Count.cpp)

add_executable(Count ${SOURCE_FILES})

