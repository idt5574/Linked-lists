#include "linked_list.h"

#include <iostream>

void DoublyLinkedList::push(int data)
{
    Node* new_node = new Node(data);

    new_node->set_next(head);

    if(head != nullptr) 
        head->set_prev(new_node);

    head = new_node;
}

void DoublyLinkedList::push(int data, bool inEnd)
{
    if(!inEnd) return push(data);

    Node* new_node = new Node(data);

    new_node->set_prev(tail);

    if(tail != nullptr)
        tail->set_next(new_node);
    
    tail = new_node;
}

void DoublyLinkedList::insert(int data, int pos)
{
    if(pos < 0)
    {
        std::cout << "ERROR! Invalid insertion position\n";
        return;
    }

    if(pos == 0) return push(data);

    Node* curr = head;
    int count {0};

    while (count < pos - 1 && curr != nullptr)
    {
        curr = curr->get_next();
        count++;
    }
    
    if(curr == nullptr)
    {
        std::cout << "ERROR! Invalid insertion position\n";
        return;
    }

    Node* temp = new Node(data);
    temp->set_next(curr->get_next());
    temp->set_prev(curr);

    curr->get_next()->set_prev(temp);
    curr->set_next(temp);
}

Node* DoublyLinkedList::pop()
{
    if(head == nullptr)
        return nullptr;
    
    if(head->get_next() == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node* curr = tail->get_prev();
    tail = curr;
    delete tail->get_next();
    tail->set_next(nullptr);

    return head;
}

Node* DoublyLinkedList::pop(bool inStart)
{
    if(!inStart) return pop();
    
    if(head == nullptr)
        return nullptr;

    Node* temp = head;
    head = head->get_next();

    if(head != nullptr)
        head->set_prev(nullptr);
    
    delete temp;
    return head;
}

// Node* DoublyLinkedList::remove(int pos)
// {
//     if(!head) return head;

//     Node* curr = head;

//     for(int i = 0; curr && i < pos; ++i)
//         curr = curr->get_next();

//     if(!curr) return
// }

void DoublyLinkedList::traverse()
{
    Node* curr = head;

    std::cout << "START" << std::endl;

    while (curr != nullptr)
    {
        std::cout << curr->get_data() << std::endl;
        curr = curr->get_next();
    }

    std::cout << "END" << std::endl;
}

void DoublyLinkedList::traverse(bool isBackward)
{
    if(!isBackward) return traverse();

    Node* curr = tail;

    std::cout << "START" << std::endl;

    while (curr != nullptr)
    {
        std::cout << curr->get_data() << std::endl;
        curr = curr->get_prev();
    }

    std::cout << "END" << std::endl;
}

int DoublyLinkedList::length()
{
    int len {0};

    for(Node* cur = head; cur != nullptr; cur = cur->get_next())
        len++;
    
    return len;
}
