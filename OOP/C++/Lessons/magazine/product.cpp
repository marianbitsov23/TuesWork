#include "product.h"
#include <iostream>
#include <string>
using namespace std;

Product::Product(){}

Product::Product(string name, string producer, double price, double barcode, string description){
    this->name = name;
    this->producer = producer;
    this->price = price;
    this->barcode = barcode;
}

void Product::set_name(string name){
    this->name = name;
}

string Product::get_name(){
    return name;
}

void Product::set_producer(string producer){
    this->producer = producer;
}

string Product::get_producer(){
    return producer;
}

void Product::set_price(double price){
    this->price = price;
}

double Product::get_price(){
    return price;
}

void Product::set_barcode(double barcode){
    this->barcode = barcode;
}

double Product::get_barcode(){
    return barcode;
}

void Product::set_description(string description){
    this->description = description;
}

string Product::get_description(){
    return description;
}