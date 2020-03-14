#include <iostream>
using namespace std;

int main(){
    const int a = 4;
    char str1[] = "hello";
    char str2[] = "hello 2";

    const char* pc = str1;
    pc = str2;
    cout << pc << endl;
    //pc[2] = 'A'; WRONG!

    char* const cp = str1;
    //cp = str2; WRONG!
    cp[2] = 'A';

    cout << cp << endl;

    const char* const c = str2;
    //c = str2; WRONG!
    //c[2] = 'A'; WRONG!

    cout << c << endl;

    int b = 5;
    int& rb = b;
    int t = 10;
    cout << rb << endl;
    rb = t;
    cout << b << endl;
    
    const int& crb = rb;
    //crb = 8; WRONG!

    cout << crb << endl;
    b = 10;
    cout << crb << endl;

    char d = 'A';
    char& pd = d;
    d = 'B';

    cout << pd << endl;

    return 0;
}