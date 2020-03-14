#ifndef AIRPORT_H
#define AIRPORT_H
#include <iostream>
#include <string>
#include <vector>
#include "plane.h"
using namespace std;
class Plane;
class Airport{
    public:
        int plane_count;
        int max_plane_count;
        bool type;
        vector<Plane> landed_planes;
        double ax;

        Airport();
        Airport(int plane_count, int max_plane_count, bool type, vector<Plane> landed_planes, double ax);
        Airport(Airport& p);
        
        int can_fit_planes(const Plane& plane);
        void land_plane(const Plane& plane);

};

#endif