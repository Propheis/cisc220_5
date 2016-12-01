// Deven Bernard     - 10099810
// Marissa Huang     - 10179169
// Kevin Zuern       - 10134425
// Quentin Petraroia - 10145835

#include "udll.h"
#include <stdlib.h>

static Node* node(union Data data, char dataType, Node* prev, Node* next);

// Stores the start of the list. Data in head is the length of the list
static Node head;
// Points to the end of the list
static Node* tail = &head;

static void insert(int index, union Data data, char dataType) {
  head.data.intData++;

  if ( index == 0 ) {
    printf("Inserting to head of list\n");
    Node *new = node(data, dataType, &head, head.next);
    head.next = new;

    return;
  }
  else if ( index == length() ) {
    
    return;
  }
}

static union Data get(int index) {
  // Quentin

  // Traverse list from shortest end (head or tail). use length() to figure that out
  printf("get() not implemented.\n");
  printf("Exiting now...\n");
  exit(1);
}

// temporarily renamed to n_remove b/c "remove" conflicts with a function in stdio.h
static void n_remove(int index) {
  // Marissa

  // Traverse list from shortest end (head or tail). use list length to figure that out
  // Don't forget to decrement list length when removing a node (length stored in head.data.intData)
  printf("remove() not implemented.\n");
  printf("Exiting now...\n");
  exit(1);
}

static int length() {
  // The length of the list is always stored in the data of the head of the list
  return head.data.intData;
}

static void printList() {
  
  printf("(%d)", head.data.intData);

  Node* cur = head.next;
  while (cur != NULL)
  {
    printf(" -> (%d)", cur->data.intData);
    cur = cur->next;
  }

  printf("\n");
}

static Node* node(union Data data, char dataType, Node* prev, Node* next) {
  Node *new = malloc(sizeof(Node));

  new->data = data;
  new->dataType = dataType;
  new->next = next;
  new->prev = prev;

  return new;
}