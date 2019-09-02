//
// Created by 徐东阳 on 2019-09-01.
//

#ifndef XPYVM_XINTEGER_HPP
#define XPYVM_XINTEGER_HPP


#include "XObject.hpp"

class XInteger : public XObject {
private:
    int _value;

public:
    XInteger(int value) {
        _value = value;
    }

    int value() { return _value; }
};


#endif //XPYVM_XINTEGER_HPP
