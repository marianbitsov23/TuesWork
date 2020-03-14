#ifndef PLANE_H
#define PLANE_H
#include <iostream>
#include <string>
#include "airport.h"
#include <vector>
using namespace std;

class Airport;
class Plane{
    public:
        int size;
        string model;
        bool is_allowed;
        int velocity;
        int fuel;
        int fuel_per_kilometer;
        float x;

        Plane();
        Plane(int size, string model, bool is_allowed, int velocity, int fuel, int fuel_per_kilometer, float x);
        Plane(Plane &p);

        double distance_to_airport(Airport& airport);
        int can_reach(Airport& airport);
        void land_in_nearest_airport(vector<Airport> airports);
};

ostream& operator<<(ostream& out, Plane&p);

#endif