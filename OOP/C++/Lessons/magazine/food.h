#ifndef FOOD_H
#define FOOD_H
#include <string>
#include <iostream>
#include "product.h"
using namespace std;

class Food : public Product{
    protected:
        string type;
        string expiration_date;
        string alergens;
        bool standard;

    public:
        Food();
        Food(string type, string expiration_date, string alergens, bool standard);
        void set_type(string type);
        string get_type();
        void set_expiration_date(string expiration_date);
        string get_expiration_date();
        void set_alergens(string alergens);
        string get_alergens();
        void set_standard(bool standard);
        bool get_standard();
};

#endif