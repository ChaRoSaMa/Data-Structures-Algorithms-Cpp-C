#include <iostream>
using namespace std;


extern "C" {
#include "DynamicArray_C.h"
}


void test_C() {
    DynamicArray_C* array = init_Array();
    for(int i = 0; i < 100; i++) {
        pushBack_Array(array, i);
    }
    print_Array(array);
}

void test_CXX() {

}

int main()
{
    test_C();

    return 0;
}
