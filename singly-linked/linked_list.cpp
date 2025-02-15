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
    
    std::cout << "START" << std::endl;

    while (current != nullptr)
    {
        std::cout << current->get_data() << std::endl; 
        
        current = current->get_next();
    }

    std::cout << "END" << std::endl;
}