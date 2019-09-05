//
// Created by 徐东阳 on 2019-09-01.
//

#include "code/CodeObject.hpp"

CodeObject::CodeObject(int argCount, int nLocals, int stackSize, int flag, XString *byteCodes,
                       ArrayList<XObject *> *consts,
                       ArrayList<XObject *> *names, ArrayList<XObject *> *varNames, ArrayList<XObject *> *freeVars,
                       ArrayList<XObject *> *cellVars, XString *fileName, XString *coName, int lineNo, XString *noTable
) :
        argCount(argCount),
        nLocals(nLocals),
        stackSize(stackSize),
        flag(flag),
        byteCodes(byteCodes),
        consts(consts),
        names(names),
        varNames(varNames),
        freeVars(freeVars),
        cellVars(cellVars),
        fileName(fileName),

        coName(coName),
        lineNo(lineNo),
        noTable(noTable) {
}
