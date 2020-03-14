#include <iostream>
#include <stack>
using namespace std;

int main(){
	stack<int> stack1;

	for(int i = 0; i < 10; i++){
		stack1.push(i);
	}

	cout << "Empty: " << stack1.empty() << endl;

	cout << "Size: " << stack1.size() << endl;
	stack1.pop();
	cout << "Size: " << stack1.size() << endl;

	cout << "Top element: " << stack1.top() << endl;
}