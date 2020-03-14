#include "vector.h"
#include <iostream>
using namespace std;

template<class T>
Vector<T>::Vector(){
    size = 0;
    data = new T[size];
}

template<class T>
Vector<T>::Vector(const Vector& vector){
    data = vector.data;
    size = vector.size;
}

template<class T>
void Vector<T>::push_back(T value){
    T* temp = new T[size];
    temp = data;
    delete [] data;
    size++;
    data = new T[size];
    data[0] = value;
    for(int i = 1; i <= size; i++){
        data[i] = temp[i - 1];
    }
    delete [] temp;
}

template<class T>
T Vector<T>::pop(){
    if(size <= 0){
        cout << "Ti si laino!" << endl;
        return 0;
    }

    return data[--size];
}

template<class T>
void Vector<T>::sort(){
    for(int i = 0; i < size - 1; i++){
        for(int j  = 0; j < size - i - 1; j++){
            if(data[j] > data[j + 1]){
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}