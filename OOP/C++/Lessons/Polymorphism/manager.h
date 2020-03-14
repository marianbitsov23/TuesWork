#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <string>
#include "employee.h"
using namespace std;

class Manager : public Employee{
    int level;
    
    public:
        Manager(string name, double id, int level);
        void print() const;
};

#endif