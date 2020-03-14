#include "plane.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

Plane::Plane(){}

Plane::Plane(int size, string model, bool is_allowed, int velocity, int fuel, int fuel_per_kilometer, float x){
    this->size = size;
    this->model = model;
    this->is_allowed = is_allowed;
    this->velocity = velocity;
    this->fuel = fuel;
    this->fuel_per_kilometer = fuel_per_kilometer;
    this->x = x;
}

Plane::Plane(Plane& p){
    this->size = p.size;
    this->model = p.model;
    this->is_allowed = p.is_allowed;
    this->velocity = p.velocity;
    this->fuel = p.fuel;
    this->fuel_per_kilometer = p.fuel_per_kilometer;
    this->x = p.x;
}

double Plane::distance_to_airport(Airport& airport){
    return abs(x - airport.ax);
}

int Plane::can_reach(Airport& airport){
    if(fuel >= fuel_per_kilometer * distance_to_airport(airport)){
        return 1;
    }
    return 0;
}

ostream& operator<<(ostream& out, Plane& p){
    out << p.size << p.model << p.is_allowed << p.velocity << p.fuel << p.fuel_per_kilometer << p.x << endl;
}