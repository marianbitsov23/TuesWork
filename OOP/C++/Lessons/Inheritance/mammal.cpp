#include <iostream>
#include "mammal.h"

Mammal::Mammal(int age, int children) : Animal(age), children(children){}
int Mammal::getChildren const() { return children; }
void Mammal::setChildren(int children){ this->children = children; }
void Mammal::giveBirth(int children){
    this->children += children;
    std::cout << "Give birth" << endl;
}