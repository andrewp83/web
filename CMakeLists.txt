cmake_minimum_required(VERSION 3.2)

project(web)

set(CMAKE_CXX_STANDARD 17)

set(HEADERS include/web/query_handler.hpp
            include/server.hpp)

set(SOURCES main.cpp
            src/server.cpp
            src/web/query_handler.cpp)

include_directories(include)

add_executable(webd ${SOURCES} ${HEADERS})