#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

//001 动态数组框架搭建
//动态数组原理
//    当申请添加新的元素
//    如果容量不足
//    申请新内存
//    拷贝旧数据
//    释放旧数据
//    添加新元素

//动态数组容器里一般会有申请空间的策略，比如：先开始给你5个容量，如果不够用再加10个….而不是申请一个拷贝一次
//动态数组 重要成员
//    容量 capacity, 顾名思义能够容得下多少
//    大小 size，也就是具体有多少元素


/*
 * warning: didnt use namespace cause it's a
 * case. But in a pratical project, maybe you
 * should use namespace. And there are some
 * code styles dont meet the standard. such as
 * the usage between strcut and class
 */


typedef struct {
    // implementation for C++

    int *pAddr;
    int  size;
    int  capacity;
} DynamicArray_C;

// initalization
// implementation for C
DynamicArray_C* init_Array();
void pushBack_Array(DynamicArray_C* array, int ele);
void removeByPos_Array(DynamicArray_C* array, int pos);
void removeByValue_Array(DynamicArray_C* array, int value);
int  find_Array(DynamicArray_C* array, int value);
void free_Array(DynamicArray_C* array);
void clear_Array(DynamicArray_C* array);
void print_Array(DynamicArray_C* array);
int  get_capacity_Array(DynamicArray_C* array);
int  get_size_Array(DynamicArray_C* array);
int  at_Array(DynamicArray_C* array, int pos);
void printInfo_Array(DynamicArray_C* array);

#endif // DYNAMICARRAY_H
