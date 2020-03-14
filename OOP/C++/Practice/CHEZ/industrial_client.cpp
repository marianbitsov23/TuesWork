#include "industrial_client.h"
#include <iostream>
#include <string>
using namespace std;

Industrial::Industrial(){}

Industrial::Industrial(double tarifa){
    this->tarifa = tarifa;
}

double Industrial::calcBill(){
    return usedPower * (tarifa + expenses); 
}

void Industrial::set_tarifa(double tarifa){
    this->tarifa = tarifa;
}

double Industrial::get_tarifa(){
    return tarifa;
}

IndustrialDayAndNight::IndustrialDayAndNight(){}

IndustrialDayAndNight::IndustrialDayAndNight(double tarifaDay, double tarifaNight){
    this->tarifaDay = tarifaDay;
    this->tarifaNight = tarifaNight;
}

double IndustrialDayAndNight::calcBill(){
    return (usedPowerDay + usedPowerNight) * (tarifaDay + tarifaNight + expenses);
}

void IndustrialDayAndNight::set_tarifaDay(double tarifaDay){
    this->tarifaDay = tarifaDay;
}

double IndustrialDayAndNight::get_tarifaDay(){
    return tarifaDay;
}

void IndustrialDayAndNight::set_tarifaNight(double tarifaNight){
    this->tarifaNight = tarifaNight;
}

double IndustrialDayAndNight::get_tarifaNight(){
    return tarifaNight;
}