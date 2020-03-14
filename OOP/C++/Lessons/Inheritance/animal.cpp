#include "animal.h"

Animal::Animal(int age) : age(age){}
int getAge() { return age; }
void Animal::setAge(int age) { this->age = age; } 