//
// Created by 徐东阳 on 2019-09-02.
//

#ifndef XPYVM_INTERPRETER_HPP
#define XPYVM_INTERPRETER_HPP

#include "../code/codeObject.hpp"

class Interpreter {
private:
    ArrayList<XObject *> *stack;
    ArrayList<XObject *> *consts;
public:
    Interpreter();

    void run(CodeObject *code);
};


#endif //XPYVM_INTERPRETER_HPP
