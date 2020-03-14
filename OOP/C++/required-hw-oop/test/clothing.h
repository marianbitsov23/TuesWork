#ifndef CLOTHING_H
#define CLOTHING_H
#include <string>
#include <iostream>
#include "stock.h"
using namespace std;

class Clothing : public Stock{
    public:
        string color;
        double size;
        string material;

        Clothing();
        Clothing(string name, double price, double quantity, Provider provider, int shippingDays, string color, double size, string material);
        Clothing(string color, double size, string material);

        void print_info();
};

#endif