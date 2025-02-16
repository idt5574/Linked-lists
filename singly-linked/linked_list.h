#ifndef _SINGLY_LINKED_LIST_
#define _SINGLY_LINKED_LIST_

#include "node.cpp"

class SinglyLinkedList
{
    Node* head {nullptr};

public:

    // Constructors area

    SinglyLinkedList(const SinglyLinkedList& other) = delete;

    SinglyLinkedList(int data)
    {
        head = new Node(data);
    }

    // other functions

    void push(int);
    Node* pop();

    void traverse();
    bool search(int target);
    size_t length();

};

#endif