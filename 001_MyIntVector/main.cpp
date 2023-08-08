#include <iostream>

#include "DynamicArray_CXX.hpp"

extern "C" {
#include "DynamicArray_C.h"
}



void test_C() {
    DynamicArray_C* array = init_Array();

    for(int i = 0; i < 100; i++) {
        pushBack_Array(array, i);
    }

    print_Array(array);
    printInfo_Array(array);

    free_Array(array);

}

void test_CXX() {
    DynamicArray_CXX* array = new DynamicArray_CXX;
    for(int i = 0; i < 100; i++) {
        array->pushBack(i);
    }
    array->print();
    array->printInfo();
}

int main()
{
//    test_C();
    test_CXX();
    return 0;
}
