#ifndef SOLID_HH
#define SOLID_HH
#include "BaseOBJ.hh"
#include <string>

class Solid : protected BaseOBJ{
    string type;
    public:
        Solid(string type);
};
#endif