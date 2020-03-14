#include "manager.h"
#include <vector>

void printALL(vector<Employee*> v){
    for(vector<Employee*>::iterator it = v.begin(); it != v.end(); it++){
        (*it) -> print();
    }
}

int main(){
    vector<Employee*> employees;

    Employee e = Employee("Ivan", 123456);
    Manager m = Manager("Petkan", 9087, 10);

    employees.push_back(&e);
    employees.push_back(&m);

    printALL(employees);

    return 0;
}