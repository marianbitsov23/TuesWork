#include "clothes.h"
#include <iostream>
#include <string>
using namespace std;

Clothes::Clothes(){}

Clothes::Clothes(string type, string material, int used){
    this->type = type;
    this->material = material;
    this->used = used;
}

void Clothes::set_type(string type){
    this->type = type;
}

string Clothes::get_type(){
    return type;
}

void Clothes::set_material(string material){
    this->material = material;
}

string Clothes::get_material(){
    return material;
}

void Clothes::set_used(int used){
    this->used = used;
}

int Clothes::get_used(){
    return used;
}