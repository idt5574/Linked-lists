#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "node.cpp"

class DoublyLinkedList
{
    Node* head {nullptr};
    Node* tail {nullptr};

public:

    DoublyLinkedList(const DoublyLinkedList& other) = delete;

    DoublyLinkedList(int data = 0)
    {
        head = new Node(data);
        tail = head;
    }

    DoublyLinkedList(int d1, int d2)
    {
        head = new Node(d1);
        tail = new Node(d2);

        head->set_next(tail);
        tail->set_prev(head);
    }

    void push(int);
    void push(int, bool);

    void insert(int, int);

    Node* pop();
    Node* pop(bool);

    Node* remove(int);

    void traverse();
    void traverse(bool);

    int length();

};

#endif