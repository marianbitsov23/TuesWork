#include <iostream>
using namespace std;

class DivisionByZeroException{
	public:
		void printErrMessage(){
			cout << "Cant't devide by zero" << endl;
		};
};

double division(double a, double b){
	if (b == 0){
		throw DivisionByZeroException();
	}
    return a/b;
}

int main(){
    double a;
    double b;
    while(true){
        cout << "Value of a: ";
        cin >> a;
        cout << "Value of b: ";
        cin >> b;
        double result;
        try{
        	result = division(a, b);
        }catch (DivisionByZeroException ex){
        	ex.printErrMessage();
        	continue;
        }
        cout << "Result: " << result << endl;
    }
}