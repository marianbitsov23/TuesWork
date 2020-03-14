#ifndef ELECTRONICS_H
#define ELECTRONICS_H
#include <string>
#include <iostream>
#include "product.h"
using namespace std;

class Electronics : public Product{
    protected:
        string type;
        string warranty;
        string conditions;

    public:
        Electronics();
        Electronics(string type, string warranty, string conditions);
        void set_type(string type);
        string get_type();
        void set_warranty(string warranty);
        string get_warranty();
        void set_conditions(string conditions);
        string get_conditions();
};

#endif