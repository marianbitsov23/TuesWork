#ifndef CONSTRUCTION_H
#define CONSTRUCTION_H
#include <iostream>
#include <string>
#include <vector>
#include "LiquidMaterial.h"
#include "HardMaterial.h"
using namespace std;

class Construction{
    public:
        vector<LiquidMaterial> ordered_liquid_materials;
        vector<HardMaterial> ordered_hard_materials;
        vector<LiquidMaterial> storage_liquid_materials;
        vector<HardMaterial> storage_hard_materials;

        Construction();
        Construction(vector<LiquidMaterial> ordered_liquid_materials, vector<HardMaterial> ordered_hard_materials, vector<LiquidMaterial> storage_liquid_materials, vector<HardMaterial> storage_hard_materials);
};

#endif