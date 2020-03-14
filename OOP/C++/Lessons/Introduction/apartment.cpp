#include <iostream>
using namespace std;

class Apartment {
private:
	char street[6];
	int floor;
	int apNumber;
	int blockNumber;
	char *owner;

public:
	void sell(char newOwner[6]) {
		owner = newOwner;
	};

	char* getOwner(){
		return owner;
	};
};

int main(){
	Apartment a;
	char str[6] = "Gosho";
	a.sell(str);
	cout << a.getOwner() << endl;
}