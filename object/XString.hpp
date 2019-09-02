//
// Created by 徐东阳 on 2019-09-01.
//

#ifndef XPYVM_XSTRING_HPP
#define XPYVM_XSTRING_HPP


#include "XObject.hpp"

class XString : public XObject {
private:
    char *_value;
    int _length;
public:
    XString(const char *value);

    XString(const char *value, int length);

    const char *value() { return _value; }

    int length() { return _length; }
};


#endif //XPYVM_XSTRING_HPP
