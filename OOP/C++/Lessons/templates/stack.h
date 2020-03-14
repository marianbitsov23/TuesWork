#ifndef STACH_H
#define STACK_H
#include <iostream>
using namespace std;

template<class T>
class Stack{
    static const unsigned int chunk = 2;
    int size;
    T* data;
    int top;
    
    public:
        Stack();
        Stack(const Stack& other);
        ~Stack();
        Stack& operator=(const Stack& other);
        T pop();
        void push(const T& value);
    
    private:
        void resize();
};

// template<class T>
// class Musical {
//	vector<T> actions;
// 	void add_action(T action);
//      T most_crowded_action() const;	
// };


// Musical<Action> musical;


// class Musical {
//	vector<Action> actions;
//	void add_action(Action action);
// };



#endif
