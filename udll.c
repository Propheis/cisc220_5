// Deven Bernard     - 10099810
// Marissa Huang     - 10179169
// Kevin Zuern       - 10134425
// Quentin Petraroia - 10145835

#include "udll.h"
#include <stdlib.h>

// Private functions
static Node* node(union Data data, char dataType, Node* prev, Node* next);
static Node* getNodeAt(int index);

// Stores the start of the list. Data in head is the length of the list
static Node head;
// Points to the end of the list
static Node* tail = &head;

static void insert(int index, union Data data, char dataType) {
  // if ( index == 0 ) { // insert to head of list
  //   printf("Inserting (%c) to head of list\n", data.charData);
  //   Node *new = node(data, dataType, &head, head.next);
  //   head.next = new;
  // }
  // else if ( index == length() ) { // insert to tail of list
  //   printf("Inserting (%c) to tail of list\n", data.charData);
  //   Node *new = node(data, dataType, tail, NULL);
  //   tail->next = new;
  //   tail = new;
  // }
  // else { // Insert somewhere in the middle
  //   printf("Inserting (%c) at index %d\n", data.charData, index );
  //   Node* insertionPoint = getNodeAt(index);
  //   Node *new = node(data, dataType, insertionPoint->prev, insertionPoint->next);

  //   insertionPoint->next = new;
  //   new->next->prev = new;
  // }

  Node* insertionPoint = getNodeAt(index);
  Node* new;

  if (index == 0) {
    printf("Inserting (%c) to head of list\n", data.charData);
    new = node(data, dataType, &head, head.next);
    head.next->prev = new;
  }
  else if (index == length()) {
    printf("Inserting (%c) to tail of list\n", data.charData);
    new = node(data, dataType, tail, NULL);
    tail->next = new;
    tail = new;
  }
  else {
    printf("Inserting (%c) at index %d\n", data.charData, index );
    new = node(data, dataType, insertionPoint, insertionPoint->next);
  }

  if (new->prev != NULL)
    new->prev->next = new;
  else if (new->next != NULL)
    new->next->prev = new;

  // Increment length
  head.data.intData++;
}

static union Data get(int index) {
  return getNodeAt(index)->data;
}

static int length() {
  return head.data.intData;
}

static void printList() {
  printf("  Printing head to tail: ");
  printf("(%d)", head.data.intData);

  Node* cur = head.next;
  while (cur != NULL)
  {
    printf(" -> (%c)", cur->data.charData);
    cur = cur->next;
  }

  printf("\n");
  printf("  Printing tail to head: ");
  printr();
}

// Creates a new node and returns the pointer to it
static Node* node(union Data data, char dataType, Node* prev, Node* next) {
  Node *new = malloc(sizeof(Node));

  new->data = data;
  new->dataType = dataType;
  new->next = next;
  new->prev = prev;

  return new;
}

// Fetches a node at a given index from the list
static Node* getNodeAt(int index) {

  if ( index < 0 || index > length() ) {
    fprintf(stderr, "Tried to access an index outside the range of the list!\n");
    exit(1);
  }

  Node* ptr;

  char traverseFromHead = (index <= length() / 2);
  int currentIndex;

  if (traverseFromHead) {
    currentIndex = 0;
    ptr = &head;
  }
  else {
    currentIndex = length();
    ptr = tail;
  }

  while (currentIndex != index) {

    if (traverseFromHead) {
      currentIndex++;
      ptr = ptr->next;
    }
    else {
      currentIndex--;
      ptr = ptr->prev;
    }

  } // end while

  return ptr;
}
static void printr() {
  // if (length() >= 1) {
  //   Node* next = tail->prev;

  //   printf("(%c)", tail->data.charData);

  //   while (next != &head) {
  //     printf(" -> (%c)", next->data.charData);

  //     next = next->prev;
  //   }
  //   printf(" -> (%d)\n\n", head.data.intData);
  // }
  // else
  //   printf("(%d)\n\n", head.data.intData);

  if (length() > 0)
    printf("(%c) -> (%d)\n", tail->data.charData, head.data.intData);
  else
    printf("(%d)\n", head.data.intData);
}