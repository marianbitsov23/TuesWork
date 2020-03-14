#ifndef OBJECT_H
#define OBJECT_H
#include <string>
#include <iostream>
using namespace std;

class Object{
    public:
        string name;

        Object();
        Object(string name);
};

class Weapon : public Object{
    public:
        double damage;

        Weapon();
        Weapon(string name, double damage);
};

class Armour : public Object, public Weapon{
    public:
        double armour;

        Armour();
        Armour(string name, double damage, double armour);
};

class Potion : public Object, public Weapon, public Armour{
    public:
        
};