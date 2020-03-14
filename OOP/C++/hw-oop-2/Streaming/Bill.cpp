#include "Bill.h"

Bill::Bill(){}

Bill::Bill(string startdate, string endate, double price, bool status){
    this->startdate = startdate;
    this->endate = endate;
    this->price = price;
    this->status = status;
}