//------------------------------------------------------------------------
// NAME: Mariyan Bitsov
// CLASS: XIa
// NUMBER: 17
// PROBLEM: #1
// FILE NAME: myswap.c (unix file name)
// FILE PURPOSE:
// Програма, която сменя стойностите на две числа. 
//------------------------------------------------------------------------

//инициализация на функцията swap от тип (void)
void swap(int *, int *);

#include <stdio.h>
#include <stdlib.h>

int main(){
	int a = 5; //инициализиране на променливите
	int b = 3;

	int *pa = &a; //инициализиране на оказатели към двете променливи
	int *pb = &b;

	swap(pa, pb); //извикване на функцията, която сменя стойностите на двете променливи

	printf("a = %d, b = %d\n", a, b); //принтиране на вече размененените променливи	

	return 0; 
}

void swap(int *a, int *b){
	*a = *a + *b; //събираме и на двете числа и ги присвояваме на първата променлива
	*b = *a - *b; //изваждаме от първата променлива второто число и така остава само първото -> a 
	*a = *a - *b; //изважадме от първата променила първото число и така остава само втората -> b
}

//------------------------------------------------------------------------
// FUNCTION: swap (име на функцията)
// разменя стойностите на две променливи
// PARAMETERS:
// int a*: указател от тип (int*)
// int b*: указател от тип (int*) 
//------------------------------------------------------------------------