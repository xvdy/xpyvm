//
// Created by 徐东阳 on 2019-09-02.
//

#include "stdio.h"
#include "runtime/Interpreter.hpp"
#include "code/CodeObject.hpp"
#include "code/ByteCode.hpp"

#include "utils/ArrayList.hpp"
#include "code/CodeObject.hpp"
#include "object/XObject.hpp"
#include "object/XInteger.hpp"
#include "object/XString.hpp"

Interpreter::Interpreter() {}

void Interpreter::run(CodeObject *codes) {
    int pc = 0;
    int codeLength = codes->byteCodes->length();

    stack = new ArrayList<XObject *>(codes->stackSize);
    consts = codes->consts;
    printf("pc %d codeLength: %d \n", pc, codeLength);
    puts("run..");

    while (pc < codeLength) {
        printf("pc is : %d", pc);
        unsigned char opCode = codes->byteCodes->value()[pc++];
        bool hasArg = (opCode & 0xFF) >= ByteCode::HAVE_ARGUMENT;

        int opArg = -1;
        if (hasArg) {
            int b = codes->byteCodes->value()[pc++] & 0xFF;
            opArg = ((codes->byteCodes->value()[pc++] & 0xFF) << 8) | b;
        }

        XObject *v;

        printf("opCode %d", opCode);

        switch (opCode) {
            case ByteCode::LOAD_CONST:
                stack->add(consts->get(opArg));
                break;
            case ByteCode::PRINT_ITEM:
                v = stack->pop();
                v->print();
                break;
            case ByteCode::PRINT_NEWLINE:
                printf("\n");
                break;
            case ByteCode::RETURN_VALUE:
                stack->pop();
                break;
            default:
                printf("error: unknow byte code %d\n", opCode);
        }
    }
}