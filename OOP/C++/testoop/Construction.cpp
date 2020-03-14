#include <iostream>
#include <string>
#include "Construction.h"
#include <vector>
using namespace std;

Construction::Construction(){}

Construction::Construction(vector<LiquidMaterial> ordered_liquid_materials, vector<HardMaterial> ordered_hard_materials, vector<LiquidMaterial> storage_liquid_materials, vector<HardMaterial> storage_hard_materials){
    this->ordered_hard_materials = ordered_hard_materials;
    this->ordered_liquid_materials = ordered_liquid_materials;
    this->storage_hard_materials = storage_hard_materials;
    this->storage_liquid_materials = storage_liquid_materials;
}