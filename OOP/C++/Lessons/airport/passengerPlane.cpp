#include "passengerPlane.h"
#include <iostream>
#include <string>
using namespace std;

PassengerPlane::PassengerPlane(){}

PassengerPlane::PassengerPlane(int passenger_ammount, int seats_ammount, int exits_ammount){
    this->passenger_ammount = passenger_ammount;
    this->seats_ammount = seats_ammount;
    this->exits_ammount = exits_ammount;
}

PassengerPlane::PassengerPlane(PassengerPlane& p){
    this->passenger_ammount = p.passenger_ammount;
    this->seats_ammount = p.seats_ammount;
    this->exits_ammount = p.exits_ammount;    
}
