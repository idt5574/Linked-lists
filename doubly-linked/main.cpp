#include <iostream>

#include "linked_list.cpp"

int main()
{
    DoublyLinkedList lst {1, 2};

    lst.traverse();

    lst.push(3);

    lst.traverse();

    lst.push(4, true);

    lst.traverse();

    lst.insert(5, 2);

    lst.traverse();

    lst.pop();

    lst.traverse();

    lst.pop(true);

    lst.traverse();

    std::cout << lst.length() << std::endl;

    return 0;
}