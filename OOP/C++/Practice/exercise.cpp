#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>

struct node_int_t {
	int value;
	struct node_int_t *next;
};

struct list_int_t{	
	struct node_int_t *head;
};

class List{
	struct node_int_t *head;
public:
	List(){
		head = NULL;
	};

	int is_empty(){
		return head == NULL;
	};

	void push(int value){
		struct node_int_t *new_node = (struct node_int_t*)malloc(sizeof(struct node_int_t));
		new_node -> value = value;
		new_node -> next =NULL;
		if(is_empty())
		{
			head = new_node;
			return;
		}
		struct node_int_t *current_node = head;
		while(current_node -> next)
		{
			current_node = current_node -> next;
		}
		current_node -> next = new_node;
	}

	int pop(){
		if(is_empty()) {return -1;}
		struct node_int_t *current_node = head;
		struct node_int_t *prev_node = NULL;
		while(current_node -> next)
		{	
			prev_node = current_node;
			current_node = current_node -> next;
		}
		if(prev_node) 
		{
			prev_node -> next = NULL;
		}else{
			head = NULL;
		}
		return current_node -> value;
	}
};

int main(){
	List l1;
	//List* l2 = new List();
	//List l3 = List();
	//l1.init();
	//printf("%d\n", l1.is_empty());
	cout << l1.is_empty() << endl;

	return 0;
}