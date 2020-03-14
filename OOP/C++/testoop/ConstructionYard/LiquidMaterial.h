#ifndef LIQUIDMATERIAL_H
#define LIQUIDMATERIAL_H
#include <iostream>
#include <string>
#include "Material.h"
using namespace std;

class LiquidMaterial : public Material{
    public:
        string type = "liquid";
        int count;

        LiquidMaterial();
        LiquidMaterial(int count);
        
};

#endif