//
// Created by 徐东阳 on 2019-09-01.
//

#ifndef XPYVM_ARRAYLIST_HPP
#define XPYVM_ARRAYLIST_HPP


template<typename T>
class ArrayList {
private:
    int _length;
    T *_array;
    int _size;

    void expand();
    void shrink();

public:
    ArrayList(int n=8);
    void add(T t);
    void insert(int index, T t);
    T get(int index);
    void set(int index, T t);
    int size();
    int length();
    T pop();
};


#endif //XPYVM_ARRAYLIST_HPP
