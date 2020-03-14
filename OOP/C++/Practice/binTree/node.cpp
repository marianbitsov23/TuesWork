#include "node.h"

template <class T>
Node<T>::Node(){}

template <class T>
Node<T>::Node(T value){
    this->value = value;
    left = NULL;
    right = NULL;
}