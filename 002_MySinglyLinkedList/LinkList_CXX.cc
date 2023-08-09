#include "LinkList_CXX.hpp"

#include <iostream>

LinkList_CXX::LinkList_CXX()
{
    m_size = 1;
    m_head = new LinkNode_CXX;
    m_head->data = nullptr;
    m_head->next = nullptr;

}

LinkList_CXX::~LinkList_CXX()
{
    LinkNode_CXX *tempNode = m_head;
    LinkNode_CXX *nextNode = m_head->next;
    while(nextNode->next) {
        delete tempNode;
        tempNode = nextNode;
        nextNode = nextNode->next;
    }
    delete nextNode;
}

void LinkList_CXX::insert(int pos, void *data)
{
    if((pos - 1) < 0 || pos > m_size ) {
        // in this case we just insert it in the end
        pos = m_size;
    }

    LinkNode_CXX *lastNode = at(pos - 1);
    LinkNode_CXX *newNode = new LinkNode_CXX;
    newNode->next = lastNode->next;
    lastNode->next = newNode;
    newNode->data = data;
    m_size++;
}

void LinkList_CXX::removeByPos(int pos)
{
    if((pos - 1) < 0 || pos > m_size ) return;

    LinkNode_CXX *lastNode = at(pos - 1);
    LinkNode_CXX *thePosNode = lastNode->next;
    LinkNode_CXX *nextNode = thePosNode->next;

    delete thePosNode;
    lastNode->next = nextNode;

    m_size--;
}

void LinkList_CXX::print(PrintLinkNodeFunc func)
{
    LinkNode_CXX *tempNode = m_head;
    for(int i = 0; i < m_size; i++) {
        func(tempNode->data);
        tempNode = tempNode->next;
    }
}

void LinkList_CXX::printInfo()
{
    std::cout << "size: " << m_size << std::endl;
}

LinkNode_CXX *LinkList_CXX::at(int pos)
{
    LinkNode_CXX *tempNode = m_head;
    for(int i = 0; i < pos; i++) {
        tempNode = tempNode->next;
    }
    return tempNode;
}

LinkNode_CXX *LinkList_CXX::head() const
{
    return m_head;
}
