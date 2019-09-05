cmake_minimum_required(VERSION 2.8)
project(xpyvm)

SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -Wall -g -ggdb ")
SET(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall")

add_executable(xpyvm main.cpp
        utils/bufferedInputStream.hpp utils/arrayList.cpp utils/arrayList.hpp
        object/XInteger.cpp object/XInteger.hpp object/XObject.hpp object/XObject.cpp object/XString.cpp object/XString.hpp
        code/byteCode.hpp code/codeObject.cpp code/codeObject.hpp code/BinaryFileParser.cpp code/BinaryFileParser.hpp
        runtime/Interpreter.cpp runtime/Interpreter.hpp
        )

INCLUDE_DIRECTORIES(./)
