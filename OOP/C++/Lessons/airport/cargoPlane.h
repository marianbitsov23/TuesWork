#ifndef CARGOPLANE_H
#define CARGOPLANE_H
#include "plane.h"
#include <iostream>
#include <string>
using namespace std;

class CargoPlane : public Plane{
    public:
        int current_load;
        int max_load;

        CargoPlane();
        CargoPlane(int current_load, int max_load);
        CargoPlane(CargoPlane& p);

};

#endif