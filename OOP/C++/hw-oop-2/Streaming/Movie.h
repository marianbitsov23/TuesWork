#ifndef MOIVE_H
#define MOIVE_H
#include <iostream>
#include <string>
#include <vector>
#include "Media.h"
using namespace std;

class Movie : public Media{
public:    
    double lenght;
    double watched;
    
    Movie();
    Movie(double lenght, double watched, string header, string auhtor, double price);

    double PayPrice();
};

#endif