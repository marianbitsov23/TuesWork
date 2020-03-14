#include <iostream>
using namespace std;

namespace firstSpace{
	void say_hello(){
		cout << "Hello from first name space" << endl;
	}

	namespace innerSpace{
		void say_hello(){
			cout << "Hello from inner name space" << endl;
		}	
	}
};

namespace secondSpace{
	void say_hello(){
		cout << "Hello from the second name spcace" << endl;
	}
};

using namespace firstSpace;	
//using namespace secondSpace;

int main(){
	say_hello();
	innerSpace::say_hello();
	secondSpace::say_hello();
	return 0;
}