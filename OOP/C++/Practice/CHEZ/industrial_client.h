#ifndef INDUSTRIAL_CLIENT_H
#define INDUSTRIAL_CLIENT_H
#include <iostream>
#include "client.h"
#include <string>
using namespace std;

class Industrial : protected Client{
    protected:
        double tarifa;
    public:
        double usedPower;
        Industrial();
        Industrial(double tarifa);
        double calcBill();
        void set_tarifa(double tarifa);
        double get_tarifa();     
};

class IndustrialDayAndNight : protected Client{
        protected:
        double tarifaDay;
        double tarifaNight;

    public:
        double usedPowerDay;
        double usedPowerNight;
        IndustrialDayAndNight();
        IndustrialDayAndNight(double tarifaDay, double tarifaNight);
        double calcBill();
        void set_tarifaDay(double tarifaDay);
        double get_tarifaDay();
        void set_tarifaNight(double tarifaNight);
        double get_tarifaNight();
};

#endif