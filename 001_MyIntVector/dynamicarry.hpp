#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray_CXX {
    // implementation for C++
    DynamicArray();
    void pushBack(int ele);
    void removeByPos(int pos);
    void removeByValue(int value);
    int  find(int value);
    void free();

    int *pAddr;
    int  size;
    int  capacity;
};


#endif // DYNAMICARRAY_H
