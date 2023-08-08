#include "DynamicArray_CXX.hpp"

#include <iostream>

DynamicArray_CXX::DynamicArray_CXX()
{
    m_pAddr = new int[20];

}

DynamicArray_CXX::~DynamicArray_CXX()
{
    delete m_pAddr;
}

void DynamicArray_CXX::pushBack(int ele)
{
    if(m_size < m_capacity) {
        m_pAddr[m_size] = ele;
        m_size++;
        return;
    }

    int* newAddr = new int[m_capacity*2];
    for(int i = 0; i < m_size; i++) {
        newAddr[i] = m_pAddr[i];
    }
    delete[] m_pAddr;
    m_pAddr = newAddr;
    m_pAddr[m_size] = ele;
    m_size++;
    m_capacity *= 2;
}

inline void DynamicArray_CXX::removeByPos(int pos)
{
    for(int i = pos; i < m_size - 1; i++) {
        m_pAddr[i] = m_pAddr[i+1];
    }
    m_size--;
}

inline void DynamicArray_CXX::removeByValue(int value)
{
    removeByPos(find(value));
}

inline int DynamicArray_CXX::find(int value)
{
    for(int i = 0; i < m_size; i++) {
        if(m_pAddr[i] == value) return i;
    }
    return -1;
}


inline void DynamicArray_CXX::clear()
{
    m_size = 0;
}

inline int DynamicArray_CXX::capacity()
{
    return capacity();
}

inline int DynamicArray_CXX::size()
{
    return m_size;
}

inline int DynamicArray_CXX::at(int pos)
{
    return m_pAddr[pos];
}

void DynamicArray_CXX::print()
{
    for(int i = 0; i < m_size; i++) {
        std::cout << m_pAddr[i] << " ";
    }
    std::cout << std::endl;
}

void DynamicArray_CXX::printInfo()
{
    std::cout << "capacity: " << m_capacity << std::endl;
    std::cout << "size: " << m_size << std::endl;
}
