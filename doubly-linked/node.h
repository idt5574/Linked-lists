#ifndef _NODE_H_
#define _NODE_H_

class Node
{
    int data {0};

    Node* prev {nullptr};
    Node* next {nullptr};

public:

    Node(int d) : data{d}
    {}

    void set_data(int d) { data = d; }
    void set_prev(Node* p) { prev = p; }
    void set_next(Node* n) { next = n; }

    int get_data() { return data; }
    Node* get_prev() { return prev; }
    Node* get_next() { return next; }
    
};

#endif