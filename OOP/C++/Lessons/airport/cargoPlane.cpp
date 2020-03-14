#include "cargoPlane.h"
#include <iostream>
#include <string>
using namespace std;

CargoPlane::CargoPlane(){}

CargoPlane::CargoPlane(int current_load, int max_load){
    this->current_load = current_load;
    this->max_load = max_load;
}

CargoPlane::CargoPlane(CargoPlane& p){
    this->current_load = p.current_load;
    this->max_load = p.max_load; 
}
