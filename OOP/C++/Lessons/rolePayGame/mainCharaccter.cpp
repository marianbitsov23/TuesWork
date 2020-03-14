#include "mainCharacter.h"

MainCharacter::MainCharacter(){}

MainCharacter::MainCharacter(string name, double damage, double armour){
    this->name = name;
    this->damage = damage;
    this->armour = armour;
}

Human::Human(){}

Human::Human(string name, double damage, double armour){
    this->name = name;
    this->damage = damage;
    this->armour = armour;
}

Orc::Orc(){}

Orc::Orc(string name, double damage, double armour){
    this->name = name;
    this->damage = damage;
    this->armour = armour;
}

Elf::Elf(){}

Elf::Elf(string name, double damage, double armour){
    this->name = name;
    this->damage = damage;
    this->armour = armour;
}
