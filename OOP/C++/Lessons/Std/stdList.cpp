#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void print_list(list<int> l){
	list<int>::iterator it;
	for(it = l.begin(); it != l.end(); it++){
		cout << *it << endl;
	}
}

int main(){
	list<int> l;

	for(int i = 1; i <= 10; i++){
		l.push_back(i);
	}

	print_list(l);

	return 0;
}