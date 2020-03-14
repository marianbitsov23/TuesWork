#include <iostream>
#include <string>
using namespace std;
const int STACK_SIZE = 10;

class StackException{
	string message = "";
	public:
		StackException(string message){
			this -> message = message;
		}

		string what(){
			return  message;
		}
};
/*
class StackIsFull{
	public:
	void printErrMessage(){
		cout << "Stack is full" << endl;
	};
};

class StackIsEmpty{
public:
	void printErrMessage(){
		cout << "Stack is empty" << endl;
	};
};
*/

class Stack{
	int data[STACK_SIZE];
	int top;

public:
	Stack(){
		top = 0;
	};

	void push(int value){
		if(isFull()){
			throw StackException("Stack is Full");
		}
		data[top++] = value;
	}

	int pop(){
		if(isEmpty()){
			throw StackException("Stack is empty");
		}
		return data[--top];
	}

	bool isEmpty(){
		return top == 0;
	}

	bool isFull(){
		return top == STACK_SIZE;
	}

	void printStack(){
		for(int i = 0; i < top; i++){
			cout << data[i]	;
		}
		cout << endl;
	}
};

class node{

};

int main(){
	Stack s;
	try{
		for(int i = 1; i < 12; i++){
			s.push(i);
		}
	}catch (StackException ex){
		cout << ex.what() << endl;
	}
	s.printStack();
	return 0;
}