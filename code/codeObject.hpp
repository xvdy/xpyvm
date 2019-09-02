//
// Created by 徐东阳 on 2019-09-01.
//

#ifndef XPYVM_COCDOBJECT_HPP
#define XPYVM_COCDOBJECT_HPP

#include "../object/XString.hpp"
#include "../utils/arrayList.hpp"

class CodeObject: public XObject {
public:
    CodeObject(int argCount, int nLocals, int stackSize, int flag, XString *byteCodes, ArrayList<XObject *> *consts,
               ArrayList<XObject *> *names, ArrayList<XObject *> *varNames, ArrayList<XObject *> *freeVars,
               ArrayList<XObject *> *cellVars, XString *fileName, XString *coName, int lineNo, XString *noTable
    );
    XString* byteCodes;

};


#endif //XPYVM_COCDOBJECT_HPP
