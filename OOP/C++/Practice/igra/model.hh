#ifndef MODEL_HH
#define MODEL_HH
#include "BaseOBJ.hh"
#include <string>
#include <iostream>
using namespace std;

class model : protected BaseOBJ{
    private:
        string color;
        string texture;
        string material;
        string geometry;
};

#endif