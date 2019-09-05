//
// Created by 徐东阳 on 2019-09-01.
//

#ifndef XPYVM_BINARYFILEPARSER_H
#define XPYVM_BINARYFILEPARSER_H


#include "utils/bufferedInputStream.hpp"
#include "utils/arrayList.hpp"
#include "object/XObject.hpp"
#include "object/XInteger.hpp"
#include "object/XString.hpp"
#include "code/codeObject.hpp"

class BinaryFileParser {
private:
    BufferedInputStream *_buffer;
    int cur;
    ArrayList<XString *> _stringTable;
public:
    BinaryFileParser(BufferedInputStream *buffer);

    CodeObject *parse();

    CodeObject *getCodeObject();

    XString *getByteCodes();

    XString *getNoTable();

    int getInt();

    XString *getString();

    XString *getName();

    XString *getFileName();

    ArrayList<XObject *> *getConsts();

    ArrayList<XObject *> *getNames();

    ArrayList<XObject *> *getVarNames();

    ArrayList<XObject *> *getFreeVars();

    ArrayList<XObject *> *getCellVars();

    ArrayList<XObject *> *getTuple();
};


#endif //XPYVM_BINARYFILEPARSER_H
