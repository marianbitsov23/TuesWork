#ifndef BILL_H
#define BILL_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Bill{
public:
    string startdate;
    string endate;
    double price;
    bool status;

    Bill();
    Bill(string startdate, string endate, double price, bool status);
};

#endif