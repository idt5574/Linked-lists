#ifndef _NODE_H_
#define _NODE_H_

class Node
{
    int data {-1};
    Node* next {nullptr};

public:

    // Constructors area

    Node() = default;
    Node(int data) : data(data)
    {}

    // Setters area

    void set_data(int data)
    { this->data = data; }

    void set_next(Node* next)
    { this->next = next; }

    // Getters area

    int get_data()
    { return data; }

    Node* get_next()
    { return next; }

};

#endif