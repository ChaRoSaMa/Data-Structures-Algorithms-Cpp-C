#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray_CXX {
    // implementation for C++
    DynamicArray_CXX();
    void pushBack(int ele);
    void removeByPos(int pos);
    void removeByValue(int value);
    int  find(int value);
    void free();
    void clear();
    int  get_capacity();
    int  get_size();
    int  at(int pos);

    int *pAddr;
    int  size;
    int  capacity;
};



#endif // DYNAMICARRAY_H
