#include "normal_client.h"
#include "industrial_client.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    Normal biko = Normal(2);
    biko.usedPower = 10;
    cout << biko.calcBill() << endl;
    biko.print_info();
    return 0;
}