#include "employee.h"

Employee::Employee(string name, double id){
    this->name = name;
    this->id = id;
}

void Employee::print() const{
    cout << name << " " << id << endl; 
}