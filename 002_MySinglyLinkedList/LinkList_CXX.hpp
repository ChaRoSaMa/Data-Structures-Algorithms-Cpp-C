#ifndef LINKLIST_CXX_HPP
#define LINKLIST_CXX_HPP

typedef void(*PrintLinkNodeFunc)(void*);

class LinkNode_CXX {
public:
    void *data = nullptr;
    LinkNode_CXX *next = nullptr;
};

class LinkList_CXX
{
public:
    LinkList_CXX();
    ~LinkList_CXX();

    void insert(int pos, void *data);
    void removeByPos(int pos);
    void print(PrintLinkNodeFunc func);
    void printInfo();

    LinkNode_CXX *at(int pos);


public: // getter
    LinkNode_CXX *head() const;

private:
    int m_size;
    LinkNode_CXX *m_head;
};


//LinkList_C* init_LinkList();
//LinkNode_C* at_LinkList(LinkList_C *list, int pos);
//void  insert_LinkList(LinkList_C *list, int pos, void *data);
//void  removeByPos_LinkList(LinkList_C *list, int pos);
//int   find_LinkList(LinkList_C *list, void* data);
//void  print_LinkList(LinkList_C *list, PrintLinkNodeFunc func);
//void  printInfo_LinkList(LinkList_C *list);
//void  free_LinkList(LinkList_C *list);









#endif // LINKLIST_CXX_HPP
