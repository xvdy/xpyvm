//
// Created by 徐东阳 on 2019-09-01.
//

#ifndef XPYVM_COCDOBJECT_HPP
#define XPYVM_COCDOBJECT_HPP

#include "object/XObject.hpp"
#include "object/XString.hpp"
#include "utils/ArrayList.hpp"

class CodeObject : public XObject {

public:
    int argCount;
    int nLocals;
    int stackSize;
    int flag;
    XString *byteCodes;
    ArrayList<XObject *> *consts;

    ArrayList<XObject *> *names;
    ArrayList<XObject *> *varNames;
    ArrayList<XObject *> *freeVars;
    ArrayList<XObject *> *cellVars;
    XString *fileName;
    XString *coName;
    int lineNo;
    XString *noTable;

    CodeObject(int argCount, int nLocals, int stackSize, int flag, XString *byteCodes, ArrayList<XObject *> *consts,
               ArrayList<XObject *> *names, ArrayList<XObject *> *varNames, ArrayList<XObject *> *freeVars,
               ArrayList<XObject *> *cellVars, XString *fileName, XString *coName, int lineNo, XString *noTable
    );

};


#endif //XPYVM_COCDOBJECT_HPP
