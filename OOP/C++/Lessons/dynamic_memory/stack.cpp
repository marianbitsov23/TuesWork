#include <iostream>
using namespace std;

class Exception{};

class Stack{
    static const int chunk = 2;
    int size;
    int* data;
    int top;

public:
    Stack(){
        size = chunk;
        data = new int[size];
        top = -1;
    }

    void push(int v){
        if(top >= size - 1){
            resize();
        }

        data[++top] = v;

    } 

    int pop(){
        if(top < 0){
            throw Exception();
        }

        return data[top--];
    }

private:
    void resize(){
        cout << "Resize stack is called" << endl;
        int* temp = data;
        data = new int[size + chunk];
        for(int i = 0; i < size; i++){
            data[i] = temp[i];

        }
        size += chunk;
        delete temp;
        cout << "New size: " << size << endl;
    }
};

int main(){
    Stack stack;
    stack.push(3);
    stack.push(2);
    stack.push(1);
    stack.push(0);

    try{
        cout << stack.pop() << endl;
        cout << stack.pop() << endl;
        cout << stack.pop() << endl;

    }catch(const Exception& ex){
        cout << "error while popping" << endl;
    }
    return 0;
}