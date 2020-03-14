#ifndef CLOTHES_H
#define CLOTHES_H
#include <string>
#include <iostream>
#include "product.h"
using namespace std;

class Clothes : public Product{
    protected:
        string type;
        string material;
        int used;

    public:
        Clothes();
        Clothes(string type, string material, int used);
        void set_type(string type);
        string get_type();
        void set_material(string material);
        string get_material();
        void set_used(int used);
        int get_used();
};

#endif