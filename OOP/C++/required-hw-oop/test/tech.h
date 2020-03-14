#ifndef TECH_H
#define TECH_H
#include <string>
#include <iostream>
#include "stock.h"
using namespace std;

class Tech : public Stock{
    public:
        string typeOfTech;
        int warranty;
        double weight;

        Tech();
        Tech(string name, double price, double quantity, Provider provider, int shippingDays, string typeOfTech, int warranty, double weight);
        Tech(string typeOfTech, int warranty, double weight);

      void print_info();  
};

#endif