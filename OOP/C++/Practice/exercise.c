#include <stdio.h>
#include <stdlib.h>

struct node_t 
{
	int value;
	struct node_t *next;
};

struct list_t
{
	struct node_t *head;
};

struct list_t *init();
void push(struct list_t *list, int value);
int pop(struct list_t *list);
int is_empty(struct list_t *list);

int main()
{
	return 0;
}

struct list_t *init()
{
	struct list_t *list = malloc(sizeof(struct list_t));
	list -> head = NULL;
	return list;

}

void push (struct list_t *list, int value)
{
	struct node_t *new_node = list -> head;
	new_node -> value = value;
	new_node -> next =NULL;
	if(is_empty(list))
	{
		list -> head = new_node;
		return;
	}
	struct node_t *current_node = list -> head;
	while(current_node -> next)
	{
		current_node = current_node -> next;
	}
	current_node -> next = new_node;

}

int pop(struct list_t *list)
{
	if(is_empty(list)) {return -1;}
	struct node_t *current_node = list -> head;
	struct node_t *prev_node = NULL;
	while(current_node -> next)
	{	
		prev_node = current_node;
		current_node = current_node -> next;
	}
	if(prev_node) 
	{
		prev_node -> next = NULL;
	}else{
		list->head = NULL;
	}
	return current_node -> value;
}

int is_empty(struct list_t *list)
{
	return list -> head == NULL;
}