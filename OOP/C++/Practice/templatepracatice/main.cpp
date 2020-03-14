#include "vector.cpp"
#include <iostream>
using namespace std;

int main(){
    Vector<int> intVetor;
    
    cout << intVetor.data[1] << "   FIRST" << endl;
    for(int i = 1; i <= 3; i++){
        intVetor.push_back(i);
        cout << intVetor.data[i] << endl;
    }

    cout << "POP" << endl;

    for(int i = 1; i <= 3; i++){
        cout << intVetor.pop() << endl;
    }
}