#include "employee.h"
#include "manager.h"
#include <string>
using std::string;

Manager::Manager(){
    level = 0;
}

Manager::Manager(std::string name, int level) : Employee(name, id){
    this->level = level;
}

void Manager::setLevel(int level){
    this->level = level;
}

int Maneger::getLevel() const{
    return level;
}