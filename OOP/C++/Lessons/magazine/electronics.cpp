#include "electronics.h"
#include <iostream>
#include <string>
using namespace std;

Electronics::Electronics(){}

Electronics::Electronics(string type, string warranty, string conditions){
    this->type = type;
    this->warranty = warranty;
    this->conditions = conditions;
}

void Electronics::set_type(string type){
    this->type = type;
}

string Electronics::get_type(){
    return type;
}

void Electronics::set_warranty(string warranty){
    this->warranty = warranty;
}

string Electronics::get_warranty(){
    return warranty;
}

void Electronics::set_conditions(string conditions){
    this->conditions = conditions;
}

string Electronics::get_conditions(){
    return conditions;
}