#include "food.h"
#include <string>
#include <iostream>
using namespace std;

Food::Food(){}

Food::Food(string type, string expiration_date, string alergens, bool standard){
    this->type = type;
    this->expiration_date = expiration_date;
    this->alergens = alergens;
    this->standard = standard;
}

void Food::set_type(string type){
    this->type = type;
}

string Food::get_type(){
    return type;
}

void Food::set_expiration_date(string expiration_date){
    this->expiration_date = expiration_date;
}

string Food::get_expiration_date(){
    return expiration_date;
}

void Food::set_alergens(string alergens){
    this->alergens = alergens;
}

string Food::get_alergens(){
    return alergens;
}

void Food::set_standard(bool standard){
    this->standard = standard;
}

bool Food::get_standard(){
    return standard;
}