#include <iostream>
using namespace std;

class Fibonacci{
    int* numbers = new int[2];
    int size;
public:
    Fibonacci(){}
    Fibonacci(int first, int second, int size){
        numbers = new int[size];
        this->size = size;
        numbers[0] = first;
        numbers[1] = second;
    }

    Fibonacci(int size){
        numbers = new int[size];
        this-> size = size;
        numbers[0] = 0;
        numbers[1] = 1;
    }

    Fibonacci(const Fibonacci& other){
        size = other.size;
        numbers = other.numbers;
    }

    void generate_numbers(){
        for(int i = 2; i < size; i++){
            numbers[i] = numbers[i -1] + numbers[i - 2];
        }
        for(int i = 0; i < size; i++){
            cout << numbers[i] << " ";
        }
        cout << endl;
    }

    Fibonacci& operator=(const Fibonacci f){
        this->numbers = f.numbers;
        this->size = f.size;
        return *this;
    }

};

int main(){
    Fibonacci f1 = Fibonacci(10);
    f1.generate_numbers();
    
    Fibonacci f2 = Fibonacci(f1);
    f2.generate_numbers();
    
    Fibonacci f3 = f1;
    f3.generate_numbers();

    f1 = Fibonacci(3, 4, 5);
    f1.generate_numbers();

    return 0;
}