#include "manager.h"

Manager::Manager(string name, double id, int level) : Employee(name, id){
    this->level = level;
}

void Manager::print() const{
    Employee::print();
    cout << "\tlevel:" << level << endl;
}