#include <iostream>
using namespace std;

template<class T, class S>
S Max(T a, S b){
    return a > b ? a:b;
}

int main(){
    int a = 5;
    int b = 6;
    double c = 5.2;
    double d = 5.6;

    cout << Max(a, b) << endl;

    cout << Max(c, d) << endl;

    cout << Max(a, c) << endl;

    return 0;
}