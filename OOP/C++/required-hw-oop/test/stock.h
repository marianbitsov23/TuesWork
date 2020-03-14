#ifndef STOCK_H
#define STOCK_H
#include <string>
#include <iostream>
#include "provider.h"
using namespace std;

class Stock{
    public:
        string name;
        double price;
        double quantity;
        Provider provider;
        int shippingDays;

        Stock();
        Stock(string name, double price, double quantity, Provider provider, int shippingDays);

        virtual void print_info();
};

#endif