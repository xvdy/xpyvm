#include <iostream>
#include "utils/BufferedInputStream.hpp"
#include "utils/ArrayList.hpp"
#include "utils/ArrayList.cpp"
#include "runtime/Interpreter.hpp"
#include "code/BinaryFileParser.hpp"

int main(int argc, char **argv) {
    if (argc <= 1) {
        puts("vm need a file\n");
        return 0;
    }
    BufferedInputStream stream = BufferedInputStream(argv[1]);

    BinaryFileParser parser(&stream);
    CodeObject *codeObject = parser.parse();

    Interpreter interpreter;
    interpreter.run(codeObject);

    return 0;
}