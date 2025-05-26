cmake_minimum_required(VERSION 3.10)

project(Exercises LANGUAGES CXX)

file(GLOB SOURCES "*.cpp")

add_executable(Exercises ${SOURCES})
