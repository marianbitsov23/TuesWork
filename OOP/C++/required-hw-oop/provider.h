#ifndef PROVIDER_H
#define PROVIDER_H
#include <string>
#include <iostream>
using namespace std;

class Provider{
    public:
        string name;
        string typeOfStock;

        Provider();
        Provider(string name, string typeOfStock);

        void print_info();
};

#endif