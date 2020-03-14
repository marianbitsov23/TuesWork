#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Media{
public:
    string header;
    string author;
    double price;
    
    Media();
    Media(string header, string author, double price);
    virtual double PayPrice();
};

#endif