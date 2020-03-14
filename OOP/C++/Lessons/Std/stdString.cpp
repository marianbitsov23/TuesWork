#include <iostream>
#include <string>
using namespace std;

int main(){
	string firstName;
	string lastName;
	string fullName;

	cout << "Enter first name" << endl;
	getline(cin, firstName);
	cout << "Enter last name" << endl;
	getline(cin, lastName);
	cout << "Full name:"<< firstName + " " + lastName << endl;
	cout << "First name lenght:" << firstName.length() << endl;
	cout << "First name capacity:" << firstName.capacity() << endl;
	getline(cin, fullName); //reads to enter
	cout << "Full name:" << fullName << endl;

	return 0;
}