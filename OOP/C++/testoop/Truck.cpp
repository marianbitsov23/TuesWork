#include "Truck.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Truck::Truck(){}

Truck::Truck(vector<LiquidMaterial> liquids, vector<HardMaterial> hards, int capacity, bool used){
    this->liquids = liquids;
    this->hards = hards;
    this->capacity = capacity;
    this->used = used;
}