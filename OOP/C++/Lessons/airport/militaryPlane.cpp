#include "militaryPlane.h"
#include <iostream>
#include <string>
using namespace std;

MilitaryPlane::MilitaryPlane(){}

MilitaryPlane::MilitaryPlane(int military_power){
    this->military_power = military_power;
}

MilitaryPlane::MilitaryPlane(MilitaryPlane& p){
    this->military_power = p.military_power;  
}
