cmake_minimum_required(VERSION 3.5)
project(xpyvm)

set(CMAKE_CXX_STANDARD 14)

add_executable(xpyvm main.cpp code/BinaryFileParser.cpp code/BinaryFileParser.hpp code/byteCode.hpp utils/bufferedInputStream.hpp utils/arrayList.cpp utils/arrayList.hpp object/XObject.cpp object/XObject.hpp object/XString.cpp object/XString.hpp code/codeObject.cpp code/codeObject.hpp object/XInteger.cpp object/XInteger.hpp runtime/Interpreter.cpp runtime/Interpreter.cpp runtime/Interpreter.hpp)
