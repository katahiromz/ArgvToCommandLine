# CMakeLists.txt --- CMake project settings
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 3.10)

# enable testing
enable_testing()

# project name, version, and languages
project(ArgvToCommandLine VERSION 1.0 LANGUAGES CXX)

# libArgvToCommandLine.a
add_library(ArgvToCommandLine STATIC ArgvToCommandLine.cpp)

# tests.exe
add_executable(tests WIN32 ArgvToCommandLine.cpp tests.cpp)
target_link_libraries(tests PRIVATE ArgvToCommandLine)

# add test
add_test(NAME tests COMMAND tests)
