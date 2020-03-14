#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

template <class T>
class Node{
    public:
        T value;
        Node* left;
        Node* right;

        Node();
        Node(T value);
};

#endif