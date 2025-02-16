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
    void push(int, bool);

    void insert(int, int);

    Node* pop();
    Node* pop(bool);

    Node* remove(int);

    void traverse();
    bool search(int);
    size_t length();

};

#endif