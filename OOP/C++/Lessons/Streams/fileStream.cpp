#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream out;

    out.open("test.txt");

    string test;

    cout << "Enter your name: ";
    getline(cin, test);

    out << test;
    out << "\n";

    int age;
    cout << "Enter your age: ";
    cin >> age;

    out << age;
    out << "\n";

    out.close();

    ifstream in;
    in.open("test.txt");

    string name;
    getline(in, name);
    cout << name << endl;

    int age1;
    in >> age1;
    cout << age1 << endl;

    return 0;
}