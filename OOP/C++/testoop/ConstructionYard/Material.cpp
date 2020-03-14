#include "Material.h"
#include <iostream>
#include <string>
using namespace std;

Material::Material(){}

Material::Material(string name, double price){
    this->name = name;
    this->price = price;
}

ostream& operator<<(ostream& out, Material& m){
    out << "name" << m.name << "price" << m.price << endl;
}