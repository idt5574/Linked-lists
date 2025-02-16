#include <iostream>

#include "linked_list.cpp"

int main()
{
    SinglyLinkedList lst{0};

    for(int i = 1; i < 3; i++)
        lst.push(i);

    lst.traverse();

    std::cout << lst.length() << std::endl;

    lst.remove(1);

    lst.traverse();

    return 0;
}