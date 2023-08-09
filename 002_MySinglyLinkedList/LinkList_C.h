#ifndef LINKLIST_C_H
#define LINKLIST_C_H

typedef struct LINKNODE_C {
    void* data;
    struct LINKNODE_C* next;

} LinkNode_C;

typedef struct LINKLIST_C {
    LinkNode_C* head;
    int size;
} LinkList_C;

// function pointer define
typedef void(*PrintLinkNodeFunc)(void*);

LinkList_C* init_LinkList();
LinkNode_C* at_LinkList(LinkList_C *list, int pos);
void  insert_LinkList(LinkList_C *list, int pos, void *data);
void  removeByPos_LinkList(LinkList_C *list, int pos);
int   find_LinkList(LinkList_C *list, void* data);
void  print_LinkList(LinkList_C *list, PrintLinkNodeFunc func);
void  printInfo_LinkList(LinkList_C *list);
void  free_LinkList(LinkList_C *list);

#endif // LINKLIST_C_H
