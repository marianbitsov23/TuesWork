#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;


class MyExceptionPush{};

class MyExceptionPop{};

class MyExceptionMaxInt{};

struct node_int_t {
  int value;
  struct node_int_t *next;
};

class List {
  int max_size = 1;
  int current_size = 1;
  int max_num = 1000;
  struct node_int_t *head;
public:
  List() {
    head = NULL;
  }

  List(long int a1, long int a2) {
      max_size = a1;
      max_num = a2;
  }

  int is_empty() {
    return head == NULL;
  }

  void push(int value) {
    if(value > max_num){
      throw MyExceptionMaxInt();
    }
    if(current_size == max_size){ 
      throw MyExceptionPush();
    }
    current_size++;
    struct node_int_t *new_node = (struct node_int_t*)malloc(sizeof(struct node_int_t));
    new_node->value = value;
    new_node->next = NULL;
    if (is_empty()) {
      head = new_node;
      return;
    }
    struct node_int_t *current_node = head;
    while (current_node->next) {
      current_node = current_node->next;
    }
    current_node->next = new_node;
  }

  int pop() {
    if (is_empty()) { 
      throw MyExceptionPop(); 
    }
    struct node_int_t *current_node = head;
    struct node_int_t *prev_node = NULL;
    while (current_node->next) {
      prev_node = current_node;
      current_node = current_node->next;
    }
    if (prev_node) {
      prev_node->next = NULL;
    } else {
      head = NULL;
    }
    return current_node->value;
  }
};


int main() {
  List l1 = List(10, 1000);

  try{
    l1.push(1);
    l1.push(1);
    l1.push(1);
    l1.push(1);
    l1.push(1000);
    l1.push(1);
    l1.push(1);
    l1.push(1);
    l1.push(1);
    l1.push(1);
    l1.push(1);


  }catch (MyExceptionPush ex){
    cout << "U reached the maximum size of list" << endl;
  }catch (MyExceptionMaxInt ex){
    cout << "U pushed bigger number than 1000" << endl;
  }

  try {
    while(1){
      int value = l1.pop();
      cout << "Removed:" << value << endl;
    }
  }catch (MyExceptionPop ex){
    cout << "List is already empty" << endl;
  }

  cout << l1.is_empty() << endl;

  return 0;
}
