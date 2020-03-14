#ifndef HARDMATERIAL_H
#define HARDMATERIAL_H
#include <iostream>
#include <string>
#include "Material.h"
using namespace std;

class HardMaterial : public Material{
    public:
        string type = "hard";
        int volume;

        HardMaterial();
        HardMaterial(int volume);
};

#endif