#ifndef NORMAL_CLIENT_H
#define NORMAL_CLIENT_H
#include "client.h"
#include <iostream>
#include <string>
using namespace std;

class Normal : public Client{
    protected:
        double tarifa;
    public:
        double usedPower;
        Normal();
        Normal(double tarifa);
        double calcBill();
        void set_tarifa(double tarifa);
        double get_tarifa();
};

class NormalDayAndNight : protected Client{
    protected:
        double tarifaDay;
        double tarifaNight;

    public:
        double usedPowerDay;
        double usedPowerNight;
        NormalDayAndNight();
        NormalDayAndNight(double tarifaDay, double tarifaNight);
        double calcBill();
        void set_tarifaDay(double tarifaDay);
        double get_tarifaDay();
        void set_tarifaNight(double tarifaNight);
        double get_tarifaNight();
};

#endif