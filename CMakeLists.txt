cmake_minimum_required(VERSION 3.5)
project(xpyvm)

set(CMAKE_CXX_STANDARD 14)

add_executable(xpyvm main.cpp code/binaryFileParser.cpp code/binaryFileParser.hpp code/byteCode.hpp utils/bufferedInputStream.hpp utils/arrayList.cpp utils/arrayList.hpp)
