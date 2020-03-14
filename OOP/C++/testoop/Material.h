#ifndef MATERIAL_H
#define MATERIAL_H
#include <iostream>
#include <string>
using namespace std;

class Material{
    public:
        string name;
        double price;

        Material();
        Material(string name, double price);



};

ostream& operator<<(ostream& out, Material& m);

#endif