#include "DynamicArray_C.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DynamicArray_C *init_Array()
{
    // malloc
    DynamicArray_C *myArray = (DynamicArray_C*)malloc(sizeof(DynamicArray_C));

    // give default
    myArray->size = 0;
    myArray->capacity = 20;

    // malloc according to the capacity of the array
    myArray->pAddr = (int*)malloc(sizeof(int) * myArray->capacity);

    return myArray;
}

void pushBack_Array(DynamicArray_C *array, int ele)
{
    if(!array) return;

    // if capacity enough
    if(array->size == array->capacity) {
        // policy: new capacity is as twice as original one

        // 1.malloc
        int *pNewSpace = (int*)malloc(sizeof(int) * array->capacity * 2);

        // 2.copy
        memcpy(pNewSpace, array->pAddr, array->size * sizeof(int));

        // 3.free
        free(array->pAddr);

        // 4. update capacity
        array->capacity *= 2;

        // 5. update pointer
        array->pAddr = pNewSpace;
    }

    // size is 1 bigger than index
    array->pAddr[array->size] = ele;
    array->size++;
}

void removeByPos_Array(DynamicArray_C *array, int pos)
{
    if(!array) return;

    // if valid position
    if(pos < 0 || pos >= array->size) {
        return;
    }

    // remove element : remove it and fill the empty pos with backword element
    // but actually just covering the element which is going to be removed with backword element is OK

    // you'd better not cover the last element with unknown element. So size - 1
    for(int i = pos; i < array->size - 1; i++) {
        array->pAddr[i] = array->pAddr[i+1];
    }
    array->size--;

}

void removeByValue_Array(DynamicArray_C *array, int value)
{
    if(!array) return;

    // find the value according value
    removeByPos_Array(array, find_Array(array, value));
}

int find_Array(DynamicArray_C *array, int value)
{
    for(int i = 0; i < array->size; i++) {
        if(array->pAddr[i] == value) return i;
    }
    return -1;
}

void free_Array(DynamicArray_C *array)
{
    if(array->pAddr) {
        free(array->pAddr);
    }
    free(array);
}

void clear_Array(DynamicArray_C *array)
{
    if(!array) return;
    array->size = 0;
    // if the size = 0, the following element will cover the origin element
}

void print_Array(DynamicArray_C *array)
{
    if(!array) return;

    for(int i = 0; i < array->size; i++) {
        printf("%d ", array->pAddr[i]);
    }
    printf("\n");
}

int get_capacity_Array(DynamicArray_C *array)
{
    if(!array) return -1;

    return array->capacity;
}

int get_size_Array(DynamicArray_C *array)
{
    if(!array) return -1;

    return array->size;
}


int at_Array(DynamicArray_C *array, int pos)
{
    if(!array) return -1;

    return array->pAddr[pos];
}
