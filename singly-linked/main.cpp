#include <iostream>

#include "linked_list.cpp"

int main()
{
    SinglyLinkedList lst{0};

    for(int i = 1; i < 100; i++)
        lst.push(i);

    lst.traverse();

    lst.pop();

    lst.traverse();

    return 0;
}