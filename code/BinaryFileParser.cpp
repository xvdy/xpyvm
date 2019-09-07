//
// Created by 徐东阳 on 2019-09-01.
//

#include <assert.h>
#include "stdio.h"
#include "code/BinaryFileParser.hpp"

BinaryFileParser::BinaryFileParser(BufferedInputStream *buffer) {
    _buffer = buffer;
}

CodeObject *BinaryFileParser::parse() {
    int magicNumber = _buffer->read_int();
    printf("magic number is:0x%x\n", magicNumber);
    int modifyTime = _buffer->read_int();
    printf("modify time is:0x%x\n", modifyTime);

    char objectType = _buffer->read();

    if (objectType == 'c') {
        CodeObject *c = getCodeObject();
        puts("parse ok");
        return c;
    }

    return NULL;
}

CodeObject *BinaryFileParser::getCodeObject() {
    int argCount = _buffer->read_int();
    int nLocals = _buffer->read_int();
    int stackSize = _buffer->read_int();
    int flags = _buffer->read_int();
    printf("flags is:0x%x\n", flags);

    XString *byteCodes = getByteCodes();
    ArrayList<XObject *> *consts = getConsts();
    ArrayList<XObject *> *names = getNames();
    ArrayList<XObject *> *varNames = getVarNames();
    ArrayList<XObject *> *freeVars = getFreeVars();
    ArrayList<XObject *> *cellVars = getCellVars();


    XString *fileName = getFileName();
    XString *moduleName = getName();
    int beginLineNo = _buffer->read_int();
    XString *lineNoTable = getNoTable();


    return new CodeObject(
            argCount, nLocals, stackSize, flags, byteCodes, consts, names, varNames, freeVars, cellVars, fileName,
            moduleName, beginLineNo, lineNoTable
    );
}

XString *BinaryFileParser::getString() {
    int length = _buffer->read_int();
    char *value = new char[length];

    for (int i = 0; i < length; ++i) {
        value[i] = _buffer->read();
    }

    XString *s = new XString(value, length);

    delete[]value;
    return s;
}

XString *BinaryFileParser::getName() {
    int c = _buffer->read();
    if (c == 's') {
        return getString();
    } else if (c == 't') {
        XString *s = getString();
        _stringTable.add(s);
        return s;
    } else if (c == 'R') {
        return _stringTable.get(_buffer->read_int());
    }

    return NULL;
}

XString *BinaryFileParser::getFileName() {
    return getName();
}

XString *BinaryFileParser::getByteCodes() {
    assert(_buffer->read() == 's');

    return getString();
}

XString *BinaryFileParser::getNoTable() {
    char c = _buffer->read();
    if (c != 's' && c != 't') {
        _buffer->unread();
        return NULL;
    }
    return getString();
}

ArrayList<XObject *> *BinaryFileParser::getConsts() {
    char c = _buffer->read();
    if (c == '(') {
        return getTuple();
    }
    _buffer->unread();
    return NULL;
}

ArrayList<XObject *> *BinaryFileParser::getNames() {
    char c = _buffer->read();
    if (c != '(') {
        return getTuple();
    }
    _buffer->unread();
    return NULL;
}

ArrayList<XObject *> *BinaryFileParser::getVarNames() {
    char c = _buffer->read();
    if (c != '(') {
        return getTuple();
    }
    _buffer->unread();
    return NULL;
}

ArrayList<XObject *> *BinaryFileParser::getFreeVars() {
    char c = _buffer->read();
    if (c != '(') {
        return getTuple();
    }
    _buffer->unread();
    return NULL;
}

ArrayList<XObject *> *BinaryFileParser::getCellVars() {
    char c = _buffer->read();
    if (c != '(') {
        return getTuple();
    }
    _buffer->unread();
    return NULL;
}

ArrayList<XObject *> *BinaryFileParser::getTuple() {
    int length = _buffer->read_int();
    XString *str;

    ArrayList<XObject *> *list = new ArrayList<XObject *>(length);
    for (int i = 0; i < length; i++) {
        char obj_type = _buffer->read();

        switch (obj_type) {
            case 'c':
                printf("got a code object\n");
                list->add(getCodeObject());
                break;
            case 'i':
                list->add(new XInteger(_buffer->read_int()));
                break;
            case 'N':
                list->add(new XInteger(0));
                break;
            case 't':
                str = getString();
                list->add(str);
                _stringTable.add(str);
                break;
            case 's':
                list->add(getString());
                break;
            case 'R':
                list->add(_stringTable.get(_buffer->read_int()));
                break;
            default:
                printf("parser, unrecognized type : %c\n", obj_type);
        }
    }

    return list;
}


