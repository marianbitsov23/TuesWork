#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;

class Employee{
    string name;
    double id;
    
    public:
        Employee(string name, double id);

        virtual void print() const;
};

#endif