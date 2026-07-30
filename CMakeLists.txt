cmake_minimum_required(VERSION 4.2)
project(HTTPServer)

set(CMAKE_CXX_STANDARD 20)

add_executable(HTTPServer main.cpp
        src/server.cpp
        src/server.h
        src/HTTPhandler.cpp
        src/HTTPhandler.h)
