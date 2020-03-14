#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H
#include <string>
#include <iostream>
using namespace std;

class MainCharacter{
    public:
        string name;
        double damage;
        double armour;

        MainCharacter();
        MainCharacter(string name, double damage, double armour);

};

class Human : public MainCharacter{
    public:
        Human();
        Human(string name, double damage, double armour);
};

class Orc : public MainCharacter{
    public:
        Orc();
        Orc(string name, double damage, double armour);
};

class Elf : public MainCharacter{
    public:
        Elf();
        Elf(string name, double damage, double armour);
};

#endif