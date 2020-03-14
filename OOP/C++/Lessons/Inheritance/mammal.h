#ifndef MAMMAL_H
#define MAMMLA_H
#include "animal.h"

class Mammal : Animal{
    int children;
public:
    Mammal(int age);
    int getChildren const ();
    void setChildren(int children);
    void giveBirth(int children);
}