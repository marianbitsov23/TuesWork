#include <iostream>
#include "bird.h"

Bird::Bird(int age) : Animal(age){}
void Bird::layEggs const () { std::cout << "Lay eggs" << endl; }