cmake_minimum_required(VERSION 3.10)

project(HeaderFiles LANGUAGES CXX)

file(GLOB SOURCES "*.cpp")

add_executable(HeaderFiles ${SOURCES})
