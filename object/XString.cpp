//
// Created by 徐东阳 on 2019-09-01.
//

#include <string.h>
#include <stdio.h>
#include "object/XString.hpp"

XString::XString(const char *value) {
    _length = strlen(value);
    _value = new char[_length];

    strcpy(_value, value);
}

XString::XString(const char *value, int length) {
    _length = length;
    _value = new char[length];

    for (int i = 0; i < _length; ++i) {
        _value[i] = value[i];
    }
}

void XString::print() { printf("%s", _value); }