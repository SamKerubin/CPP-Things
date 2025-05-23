# Some of the statements usually used to create a CMakeLists.txt file are:

# cmake_minimum_required(V) <- minimum version thats supported (usually VERSION 3.10)

# project(name LANG) <- project name and language used (C for C and CXX for C++)

# file() <- allows to manipulate files in a directory
#   WRITE <- writes content to a file
#   APPEND <- appends content to a file
#   READ <- read the content of a file
#   GLOB <- generates a list of files that matches the expression

# target_include_directories(name ACCESS include) <- access the headers from a directory
# Access can be:
#   PRIVATE: only the target can see it
#   PUBLIC: everyone  can see it
#   INTERFACE: only those who use it can see it

cmake_minimum_required(VERSION 3.10)

project(HeaderFiles LANGUAGES CXX)

file(GLOB SOURCES "*.cpp")

add_executable(HeaderFiles ${SOURCES})
