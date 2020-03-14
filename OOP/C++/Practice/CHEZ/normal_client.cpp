#include "normal_client.h"
#include <iostream>
#include <string>
using namespace std;

Normal::Normal(){}

Normal::Normal(double tarifa) : Client("abcd", "adsf", 11){
    this->tarifa = tarifa;
}

double Normal::calcBill(){
    return usedPower * (tarifa + expenses); 
}

void Normal::set_tarifa(double tarifa){
    this->tarifa = tarifa;
}

double Normal::get_tarifa(){
    return tarifa;
}

NormalDayAndNight::NormalDayAndNight(){}

NormalDayAndNight::NormalDayAndNight(double tarifaDay, double tarifaNight){
    this->tarifaDay = tarifaDay;
    this->tarifaNight = tarifaNight;
}

double NormalDayAndNight::calcBill(){
    return (usedPowerDay + usedPowerNight) * (tarifaDay + tarifaNight + expenses);
}

void NormalDayAndNight::set_tarifaDay(double tarifaDay){
    this->tarifaDay = tarifaDay;
}

double NormalDayAndNight::get_tarifaDay(){
    return tarifaDay;
}

void NormalDayAndNight::set_tarifaNight(double tarifaNight){
    this->tarifaNight = tarifaNight;
}

double NormalDayAndNight::get_tarifaNight(){
    return tarifaNight;
}