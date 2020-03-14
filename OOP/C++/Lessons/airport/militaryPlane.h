#ifndef MILITARYPLANE_H
#define MILITARYPLANE_H
#include "plane.h"
#include <iostream>
#include <string>
using namespace std;

class MilitaryPlane : public Plane{
    public:
        int military_power;

        MilitaryPlane();
        MilitaryPlane(int military_power);
        MilitaryPlane(MilitaryPlane& p);

};

#endif