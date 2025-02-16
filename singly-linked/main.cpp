#include <iostream>

#include "linked_list.cpp"

int main()
{
    SinglyLinkedList lst{0};

    for(int i = 1; i < 100; i++)
        lst.push(i);

    lst.traverse();

    std::cout << lst.search(99) << std::endl;

    lst.pop();

    lst.traverse();

    std::cout << lst.search(99) << std::endl;

    return 0;
}