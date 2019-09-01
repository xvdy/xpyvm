#include <iostream>
#include "utils/bufferedInputStream.hpp"
#include "utils/arrayList.hpp"
#include "utils/arrayList.cpp"

int main(int argc, char **argv) {
    if (argc <= 1) {
        puts("vm need a file\n");
        return 0;
    }
//    BufferedInputStream b = BufferedInputStream(argv[1]);
//    printf("magic number is: 0x%x\n", b.read_int());

    ArrayList<int> *a = new(ArrayList<int>);
    a->add(1);
    a->add(2);
    a->add(3);
    a->add(4);
    a->add(5);
    a->add(6);
    a->add(7);
    a->add(8);
    a->add(9);
    printf("%d \n", a->length());
    printf("%d \n", a->pop());
    printf("%d \n", a->pop());
    printf("%d \n", a->pop());
    printf("%d \n", a->size());
    a->set(5, 55);
    printf("%d \n", a->get(5));
    printf("%d \n", a->length());

}