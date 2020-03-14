//------------------------------------------------------------------------
// NAME: Mariyan Bitsov
// CLASS: XIa
// NUMBER: 17
// PROBLEM: #1
// FILE NAME: mystack.c (unix file name)
// FILE PURPOSE:
// Програма, която прави проста имплементация на стек. 
//------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

typedef struct{ //дефиниране на нов тип (stack) 
    size_t size;
    size_t capacity;
    int *elements;
}stack;

void stack_init(stack *); //инициализиране на функцията
//------------------------------------------------------------------------
// FUNCTION: stack_init (име на функцията)
// инициализира елементите на стека
// PARAMETERS:
// stack *mystack : указател към предифиниран тип структура (stack)
//------------------------------------------------------------------------
void stack_destroy(stack *);//инициализиране на функцията
//------------------------------------------------------------------------
// FUNCTION: stack_destroy (име на функцията)
// унищожаване на стека
// PARAMETERS:
// stack *mystack : указател към предифиниран тип структура (stack)
//------------------------------------------------------------------------
int stack_empty(stack *);//инициализиране на функцията
//------------------------------------------------------------------------
// FUNCTION: stack_destroy (име на функцията)
// унищожаване на стека
// PARAMETERS:
// stack *mystack : указател към предифиниран тип структура (stack)
//------------------------------------------------------------------------
void stack_push(stack *, int);//инициализиране на функцията
//------------------------------------------------------------------------
// FUNCTION: stack_push (име на функцията)
// добавяне на елемент в стека
// PARAMETERS:
// stack *mystack : указател към предифиниран тип структура (stack)
// int element : променлива от тип (int), елемента, който ще бъде добавен в стека
//------------------------------------------------------------------------
int stack_top(stack *);//инициализиране на функцията
//------------------------------------------------------------------------
// FUNCTION: stack_top (име на функцията)
// връща последния елемент от стека
// PARAMETERS:
// stack *mystack : указател към предифиниран тип структура (stack)
//------------------------------------------------------------------------
void stack_pop(stack *);//инициализиране на функцията
//------------------------------------------------------------------------
// FUNCTION: stack_pop (име на функцията)
// унищожава последния елемент от стека
// PARAMETERS:
// stack *mystack : указател към предифиниран тип структура (stack)
//------------------------------------------------------------------------

int main(){
    stack mystack; //инициализиране на стека

    stack_init(&mystack); //създаване на стека
    printf("empty = %d\n",stack_empty(&mystack));
    stack_push(&mystack, 1); //добавяне на елемент = 1, в стека
    printf("empty = %d\n",stack_empty(&mystack));
    stack_push(&mystack, 2); //добавяне на елемент = 2, в стека
    stack_push(&mystack, 3); //добавяне на елемент = 3, в стека
    stack_push(&mystack, 4); //добавяне на елемент = 4, в стека
    printf("Last element: %d\n", stack_top(&mystack)); //принтира последния елемент от стека
    stack_pop(&mystack); //трие последния елемент от стека
    printf("Last element: %d\n", stack_top(&mystack)); //принтира последния елемент от стека
    stack_destroy(&mystack); //изтрива целя стек

    return 0; //край на програмата
}

void stack_init(stack *mystack){
    mystack->size = 0; //задаваме размера на нула в началото
    mystack->elements = malloc(sizeof(int)); //освобождаваме памет за масива с елементите от стека
}

void stack_destroy(stack *mystack){
    free(mystack->elements); //освобождаваме паметта отделена за масива с елемнтите на стека
}

int stack_empty(stack *mystack){
    return mystack->size == 0;
}


void stack_push(stack* mystack, int element){
	mystack->elements = (int*)realloc(mystack->elements, sizeof(int)*(++mystack->size));//освобождаваме памет за още един елемент
    mystack->elements[mystack->size - 1] = element; //добавяме елемента
}

int stack_top(stack* mystack){
    return mystack->elements[mystack->size - 1]; //връшаме последния елемент от стека

}

void stack_pop(stack* mystack){
	if(!stack_empty(mystack)){
    	mystack->elements = (int*)realloc(mystack->elements, sizeof(int)*(--mystack->size));//освобождаваме паметта на последния елемент от стека
    }
}