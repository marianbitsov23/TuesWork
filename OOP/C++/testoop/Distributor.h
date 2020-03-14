#ifndef DISTRIBUTOR_H
#define DISTRIBUTOR_H
#include <iostream>
#include <string>
#include "Truck.h"
#include "Construction.h"
#include <vector>
using namespace std;

class Distributor : public Construction{
    public:
        string name;
        int truck_count;
        vector<Truck> trucks = {};

        Distributor();
        Distributor(string name, int truck_count, vector<Truck> trucks);
        int order(string material, int quantity);
        void print_receipt();

};

#endif