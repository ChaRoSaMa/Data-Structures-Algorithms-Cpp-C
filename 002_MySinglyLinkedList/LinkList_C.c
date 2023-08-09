#include "LinkList_C.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkList_C *init_LinkList()
{
    LinkList_C *list = (LinkList_C*)malloc(sizeof(LinkList_C));
    list->size = 1;
    list->head = (LinkNode_C*)malloc(sizeof(LinkNode_C));
    list->head->data = NULL;
    list->head->next = NULL;

    return list;
}

LinkNode_C *at_LinkList(LinkList_C *list, int pos)
{
    LinkNode_C *tempNode = list->head;
    for(int i = 0; i < pos; i++) {
        tempNode = tempNode->next;
    }
    return tempNode;
}


void insert_LinkList(LinkList_C *list, int pos, void *data)
{
    if(!list || data == NULL) return;

    if(pos < 0 || pos > list->size ) {
        // in this case we just insert it in the end
        pos = list->size;
    }

    LinkNode_C *tempNode = at_LinkList(list, pos - 1);
    // tempNode is the node in the pos

    LinkNode_C *newNode = (LinkNode_C*)malloc(sizeof(LinkNode_C));
    
    newNode->data = data;
    newNode->next = tempNode->next;
    tempNode->next = newNode;

    list->size++;
}

void removeByPos_LinkList(LinkList_C *list, int pos)
{
    if(!list || pos < 1) return;

    LinkNode_C *lastNode = at_LinkList(list, pos - 1);
    LinkNode_C *posNode = lastNode->next;
    LinkNode_C *nextNode = posNode->next;
    free(posNode);
    lastNode->next = nextNode;
    list->size--;
}

int find_LinkList(LinkList_C *list, void *data)
{
    if(!list) return;

    LinkNode_C *tempNode = list->head;
    for(int i = 0; i < list->size; i++) {
        if(tempNode->data == data) return i;
        tempNode = tempNode->next;
    }

    return -1;
}

void print_LinkList(LinkList_C *list, PrintLinkNodeFunc func)
{
    if(!list) return;

    LinkNode_C *node = list->head;
    for(int i = 0; i < list->size; i++) {
        func(node->data);
        node = node->next;
    }
}

void printInfo_LinkList(LinkList_C *list)
{
    printf("size: %d \n", list->size);
}

void free_LinkList(LinkList_C *list)
{
    LinkNode_C *pNextNode = list->head->next;
    LinkNode_C *tempNode = list->head;
    free(tempNode);

    while(pNextNode != NULL) {
        tempNode = pNextNode;
        pNextNode = tempNode->next;
        free(tempNode);
    }

    free(list);
}
