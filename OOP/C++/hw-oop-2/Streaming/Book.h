#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <vector>
#include "Media.h"
using namespace std;

class Book : public Media{
public:
    Book();
    Book(string header, string author, double price);

    double PayPrice();
};

#endif