#include<stdio.h>

struct Node {
  int data;
  struct Node* next;
  struct Node* before;

};
typedef struct Node Node;
Node* head = NULL;
Node* tail = NULL;

void Remove(int index) {
  int indxPtr = 0;
  for (Node *i = head; i!=NULL; i=i->next) {
    if (indxPtr == (index -1)) {
      indxPtr = indxPtr->next->next;
    }
    break;
  }
}
int main() {
  Node n6 = {25, NULL, NULL}; head = &n6;
  tail = &n6;
  Node n5 = {1, &n6, NULL}; head = &n5;
  n6.before = &n5;
  Node n4 = {4, &n5, NULL}; head = &n4;
  n5.before = &n4;
	Node n3 = {2, &n4, NULL};  head = &n3;
  n4.before = &n3;
	Node n2 = {10, &n3, NULL};  head = &n2;
  n3.before = &n2;
	Node n1 = {3, &n2, NULL};  head = &n1;
  n2.before = &n1;

  Remove(4);
	for(Node *i = head; i!=NULL; i=i->next){
		printf("element = %d\n",i->data);
	}

  for(Node *i = tail; i!= NULL; i=i->before) {
    printf("element = %d\n", i->data);
  }
  return 0;


}
