#ifndef PASSENGERPLANE_H
#define PASSENGERPLANE_H
#include "plane.h"
#include <iostream>
#include <string>
using namespace std;

class PassengerPlane : public Plane{
    public:
        int passenger_ammount;
        int seats_ammount;
        int exits_ammount;

        PassengerPlane();
        PassengerPlane(int passenger_ammount, int seats_ammount, int exits_ammount);
        PassengerPlane(PassengerPlane& p);

};

#endif