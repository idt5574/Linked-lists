#include "linked_list.h"

#include <iostream>

void SinglyLinkedList::push(int data)
{
    Node* newNode = new Node(data); // Создаём указатель на новую ноду

    if(head == nullptr) // Если вершина списка - нулевой указатель, приравниваем её к новой ноде
    {
        head = newNode;
        return;
    }

    Node* curr = head; // Указатель для перебора односвязного спика
    while (curr->get_next() != nullptr) // Пока следующий элемент не равен нулевому указателю
        curr = curr->get_next(); // Приравниваем текущий указатель к следующему
    
    curr->set_next(newNode); // Создаём для текущей ноды - следующую
}

void SinglyLinkedList::push(int data, bool inBegining)
{
    if(!inBegining) return push(data);

    Node* newNode = new Node(data);

    newNode->set_next(head);

    head = newNode;
}

void SinglyLinkedList::insert(int data, int pos)
{
    if(pos < 0 || pos > length())
    {
        std::cout << "ERROR! Invalid insertion position!\n";
        return;
    }

    if(pos == 0) return push(data, true);

    Node* prev = head;
    int count {0};
    while (count < pos - 1 && prev != nullptr)
    {
        prev = prev->get_next();
        count++;
    }

    if(prev == nullptr)
    {
        std::cout << "ERROR! Invalid insertion position!\n";
        return;
    }
    
    Node* temp = new Node(data);
    temp->set_next(prev->get_next());
    prev->set_next(temp);
}

Node* SinglyLinkedList::pop()
{
    if(head == nullptr) return nullptr;

    if(head->get_next() == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node* second_last = head;
    while (second_last->get_next()->get_next() != nullptr)
        second_last = second_last->get_next();
    
    delete (second_last->get_next());

    second_last->set_next(nullptr);

    return head;
}


void SinglyLinkedList::traverse() // вывод списка в консоль
{
    Node* current = head;
    int count = 0;
    
    std::cout << "START" << std::endl;

    while (current != nullptr)
    {
        std::cout << count++ << ") " << current->get_data() << std::endl; 
        
        current = current->get_next();
    }

    std::cout << "END" << std::endl;
}


bool SinglyLinkedList::search(int target)
{
    Node* current = head;

    while (current != nullptr)
    {
        if(current->get_data() == target)
            return true;
        
        current = current->get_next();
    }

    return false;
}


size_t SinglyLinkedList::length()
{
    size_t len {0};
    Node* current = head;

    while (current != nullptr)
    {
        len++;
        current = current->get_next();
    }

    return len;
}