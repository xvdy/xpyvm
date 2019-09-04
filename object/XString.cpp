//
// Created by 徐东阳 on 2019-09-01.
//

#include <string>
#include "XString.hpp"

XString::XString(const char *value) {
    _length = strlen(value);
    _value = new char[_length];

    strcpy(_value, value);
}

XString::XString(const char *value, int length) {
    _length = strlen(value);
    _value = new char[_length];

    for (int i = 0; i < _length; ++i) {
        _value[i] = value[i];
    }
}

void XString::print() { printf("%d", _value); }
