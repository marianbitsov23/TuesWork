#ifndef TRUCK_H
#define TRUCK_H
#include <iostream>
#include <string>
#include <vector>
#include "LiquidMaterial.h"
#include "HardMaterial.h"
using namespace std;

class Truck{
    public:
        vector<LiquidMaterial> liquids = {};
        vector<HardMaterial> hards = {};
        int capacity;
        bool used;

        Truck();
        Truck(vector<LiquidMaterial> liquids, vector<HardMaterial> hards, int capacity, bool used);
};

#endif