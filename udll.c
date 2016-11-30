// Deven Bernard     - 10099810
// Marissa Huang     - 10179169
// Kevin Zuern       - 10134425
// Quentin Petraroia - 10145835

#include "udll.h"
#include <stdlib.h>

// Stores the start of the list. Data in head is the length of the list
static Node head = { 0, NULL, NULL };

// Points to the end of the list
static Node tail = { 0, NULL, NULL};

static void insert(int index, union Data data, int type) {
  // Deven

  // Traverse list from shortest end (head or tail). use length() to figure that out
  // Don't forget to increment list length when doing insertion (length stored in head.data.intData)
  printf("insert() not implemented.\n");
  int indxPtr = 0;

  if (head.next == NULL) {
    Node new = {data, NULL, NULL};
    head.next = &new;
    tail.previous = &new;
  } else {
    Node *i;
    if (index > head.data.intData / 2) {
      indxPtr = head.data.intData;
      for (i = &tail; i->previous != NULL; i=i->previous) {
        if (indxPtr == (index - 1)) {
          break;
        }
        indxPtr --;
      }
      Node new = {data, i->next, i, type};
      if (i->next == NULL) {
        tail.previous = &new;
      }
      i->next = &new;
      new.next->previous = &new;

    } else {
      for(i = &head; i->next != NULL; i=i->next) {
        if (indxPtr == (index -1)) {
          break;
        }
        indxPtr++;
      }
      }
    Node new = {data, i->next, i, type};
    if (i->next == NULL) {
      tail.previous = &new;
    }
    i->next = &new;
  }
  head.data.intData++;
  printf("Exiting now...\n");
  return;
}

static union Data get(int index) {
  // me

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
