//
// Created by 徐东阳 on 2019-09-01.
//

#include "arrayList.hpp"
#include "stdio.h"

template<typename T>
ArrayList<T>::ArrayList(int n) {
    _length = n;
    _size = 0;
    _array = new T[n];
}

template<typename T>
void ArrayList<T>::expand() {
    T *_newArray = new(T[_length * 2]);

    for (int i = 0; i < _length; i++) {
        _newArray[i] = _array[i];
    }

    _array = _newArray;
    _length = _length * 2;
}

template<typename T>
void ArrayList<T>::shrink() {
    if (_size < _length / 2) {
        T *_newArray = new(T[_length / 2]);

        for (int i = 0; i < _length; i++) {
            _newArray[i] = _array[i];
        }

        _array = _newArray;
        _length = _length / 2;
    }
}

template<typename T>
void ArrayList<T>::add(T t) {
    if (_size >= _length) {
        expand();
    }
    _array[_size++] = t;
}

template<typename T>
T ArrayList<T>::get(int index) {
    return _array[index];
}

template<typename T>
void ArrayList<T>::set(int index, T t) {
    _array[index] = t;
}

template<typename T>
int ArrayList<T>::size() {
    return _size;
}

template<typename T>
int ArrayList<T>::length() {
    return _length;
}

template<typename T>
T ArrayList<T>::pop() {
    if (_size - 1 < 0) {
        puts("error: array index < 0");
    }
    shrink();
    return _array[--_size];
}
