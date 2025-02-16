#include <iostream>

#include "linked_list.cpp"

int main()
{
    SinglyLinkedList lst{0};

    for(int i = 1; i < 10; i++)
        lst.push(i);

    lst.traverse();

    std::cout << lst.search(99) << ' ' << lst.length() << std::endl;

    lst.push(14, true);
    lst.insert(42, 5);
    lst.push(88, false);

    lst.traverse();

    std::cout << lst.search(99) << ' ' << lst.length() << std::endl;

    return 0;
}