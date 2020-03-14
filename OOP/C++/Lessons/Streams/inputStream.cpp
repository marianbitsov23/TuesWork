#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/*
Streams:
i - input
o - output

<< - write
>> - read

good - everything is ok
bad - something went wrong
fail -  stream is broken
eof - end of stream

open - open the stream
close - close the stram
*/

int main(){
    string test = "3.14 ak";

    istringstream in(test);

    double pi;
    in >> pi;

    if(in.good()){
        cout << "Everythinh is fine!" << endl;
        cout << "pi: " << pi << endl;
    } else{
        cout << "Something went wrong !" << endl;
    }

    int number;
    in >> number;

    if(in.good()){
        cout << "Everything is fine bace!" << endl;
        cout << "number: " << number << endl;
    } else {
        cout << "Something went wrong !" << endl;
    }

    in.clear();

    char end;
    in >> end;

    if(in.good()){
        cout << "Everything is fine bace!" << endl;
        cout << "char: " << end << endl;
    } else {
        cout << "Something went wrong !" << endl;
    }

    if(in.eof()){
        cout << "At the end of stream" << endl;
    }

    return 0;
}