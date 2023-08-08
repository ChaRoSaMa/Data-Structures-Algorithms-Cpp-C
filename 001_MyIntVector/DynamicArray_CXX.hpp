#ifndef DYNAMICARRAY_CXX_H
#define DYNAMICARRAY_CXX_H

class DynamicArray_CXX {
    // implementation for C++
public: // to a
    DynamicArray_CXX();
    ~DynamicArray_CXX();
    void pushBack(int ele);
    void removeByPos(int pos);
    void removeByValue(int value);
    int  find(int value);
    void clear();
    int  capacity();
    int  size();
    int  at(int pos);
    void print();
    void printInfo();

private:
    int *m_pAddr = nullptr;
    int  m_size = 0;
    int  m_capacity = 20;
};



#endif // DYNAMICARRAY_CXX_H
