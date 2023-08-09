#include <iostream>

#include "LinkList_CXX.hpp"

extern "C" {
#include "LinkList_C.h"
}


void printFunc(void* data) {
    std::string *str = (std::string*)data;
    std::cout << *str << " ";
}

void test_C() {
    LinkList_C *list = init_LinkList();

    std::string *str  = new std::string("I");
    std::string *str1 = new std::string("love");
    std::string *str2 = new std::string("programming");
    list->head->data = (void*)str;

    insert_LinkList(list, 1, (void*)str1);
    insert_LinkList(list, 2, (void*)str2);

//    removeByPos_LinkList(list, 1);
    std::cout << find_LinkList(list, str) << std::endl;

    print_LinkList(list, printFunc);
    std::cout << std::endl;
    printInfo_LinkList(list);

    free_LinkList(list);

}

void test_CXX() {
    LinkList_CXX *list = new LinkList_CXX;
    std::string *str  = new std::string("I");
    std::string *str1 = new std::string("love");
    std::string *str2 = new std::string("programming");
    list->head()->data = (void*)str;
    list->insert(1, (void*)str1);
    list->insert(2, (void*)str2);

//    list->removeByPos(1);

    list->print(printFunc);
    std::cout << std::endl;
    list->printInfo();

    delete list;
}

int main()
{

    test_CXX();

    return 0;
}
