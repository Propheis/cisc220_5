// Deven Bernard     - 10099810
// Marissa Huang     - 10179169
// Kevin Zuern       - 10134425
// Quentin Petraroia - 10145835

#include "udll.h"
#include <stdlib.h>

// Stores the start of the list. Data in head is the length of the list
static Node head = { 0, NULL, NULL };

// Points to the end of the list
// static Node tail = { 0, NULL, NULL};
static Node *tail;

Node *getHead() { return &head; }

 void insert(int index, union Data data, int type) {
  // Traverse list from shortest end (head or tail). use length() to figure that out
  // Don't forget to increment list length when doing insertion (length stored in head.data.intData)
  //printf("insert() not implemented.\n");
  int indxPtr = 0;

  if (head.next == NULL) {
    Node *new = malloc(sizeof(Node));
    //{data, NULL, NULL, type};
    head.next = new;
    tail = new;
    new->data = data;
    new->type = type;
    new->previous = &head;
  } else {
    Node *i;
    if (index > head.data.intData / 2) {
      indxPtr = head.data.intData - 1;
      for (i = tail; i->previous != NULL; i=i->previous) {
        if (indxPtr == (index - 1)) {
          break;
        }
        indxPtr --;
      }
      Node *new = malloc(sizeof(Node));
      //{data, i->next, i, type};
      new->data = data;
      new->type = type;
      if (i->next == NULL) {
        tail->next = new;
        new->previous = i;
        new->next = NULL;
        tail = new;
      } else {
        Node *temp;
        temp = i->previous;
        new->next = i;
        new->previous = temp;
        i->previous = new;
        temp->next = new;
      }
      //i->next = new;
      //new.next->previous = new;

    } else {
      for(i = head.next; i->next != NULL; i=i->next) {
        if (indxPtr == (index -1)) {
          break;
        }
        indxPtr++;
      }
      Node *new = malloc(sizeof(Node));
      //{data, i->next, i, type};
      new->data = data;
      new->type = type;
      if (i->next == NULL) {
        i->next = new;
        new->previous = i;
        tail = new;
      } else {
        Node *temp;
        temp = i->next;
        i->next = new;
        new->next = temp;
        temp->previous = new;
        new->previous = i;
      }
    }
  }
  head.data.intData++;
  //printf("Exiting now...\n");
  return;
}

 union Data get(int index) {
  // me

  // Traverse list from shortest end (head or tail). use length() to figure that out
  printf("get() not implemented.\n");
  printf("Exiting now...\n");
  exit(1);
}

// temporarily renamed to n_remove b/c "remove" conflicts with a function in stdio.h
 void n_remove(int index) {
  // Marissa

  // Traverse list from shortest end (head or tail). use list length to figure that out
  // Don't forget to decrement list length when removing a node (length stored in head.data.intData)
  printf("remove() not implemented.\n");
  printf("Exiting now...\n");
  exit(1);
}

 int length() {
  // The length of the list is always stored in the data of the head of the list
  return head.data.intData;
}
