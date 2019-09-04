#include <iostream>
#include "utils/bufferedInputStream.hpp"
#include "utils/arrayList.hpp"
#include "utils/arrayList.cpp"
#include "runtime/interpreter.hpp"
#include "code/binaryFileParser.hpp"

int main(int argc, char **argv) {
    if (argc <= 1) {
        puts("vm need a file\n");
        return 0;
    }
    BufferedInputStream stream = BufferedInputStream(argv[1]);
    printf("magic number is: 0x%x\n", stream.read_int());

    BinaryFileParser parser(&stream);
    CodeObject *codeObject = parser.parse();

    Interpreter interpreter;
    interpreter.run(codeObject);

    return 0;
}