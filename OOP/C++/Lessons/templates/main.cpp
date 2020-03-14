#include "stack.cpp"

int main(){
    Stack<int> intStack;
// void fhfd();
    for(int i = 0; i < 10; i++){
        intStack.push(i);
    }

    for(int i = 0; i < 10; i++){
        cout << intStack.pop() << endl;
    }

    

    return 0;
}
