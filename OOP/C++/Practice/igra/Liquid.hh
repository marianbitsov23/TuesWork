#ifndef LIQUID_HH
#define LIQUID_HH
#include "BaseOBJ.hh"
#include <string>

class Liquid : protected BaseOBJ{
    string type;
    public:
        Liquid(string type);
};
#endif