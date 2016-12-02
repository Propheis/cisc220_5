// Deven Bernard     - 10099810
// Marissa Huang     - 10179169
// Kevin Zuern       - 10134425
// Quentin Petraroia - 10145835

#include "udll.h"
#include <stdlib.h>

// Stores the start of the list. Data in head is the length of the list
static Node head;
// Points to the end of the list
static Node* tail;

static void insert(int index, union Data data, char dataType) {
  Node* insertionPoint = getNodeAt(index);
  Node* new;

  if (index == 0) {
    printMessage("Inserting ", data, dataType, " to head of the list\n");
    new = node(data, dataType, &head, head.next);
    
    if (length() == 0)
      tail = new;
    else
      head.next->prev = new;

    head.next = new;
  }
  else if (index == length()) {
    printMessage("Inserting ", data, dataType, " to the tail of the list\n");
    new = node(data, dataType, tail, NULL);
    tail->next = new;
    tail = new;
  }
  else {
    printMessage("Inserting ", data, dataType, "");
    printf(" at index %d\n", index);
    new = node(data, dataType, insertionPoint, insertionPoint->next);
    insertionPoint->next->prev = new;
    insertionPoint->next = new;
  }

  // Increment length
  head.data.intData++;
}

static void removeNode(int index) {
  Node * toRemove = getNodeAt(index);
  if (toRemove == &head) {
    printf("The remove function is 1-indexed. Index 0 is out of bounds\n");
    return;
  }

  // Delete first node
  if ( index == 1 ) { 
    printMessage("Deleting node ", toRemove->data, toRemove->dataType, " from the beginning of the list\n");
    head.next = head.next->next;
    head.next->prev = &head;
  }
  // Delete tail
  else if ( index >= length() ) { 
    printMessage("Deleting node ", toRemove->data, toRemove->dataType, " from the tail of the list\n");
    Node * prev = tail->prev;
    prev->next = NULL;
  }
  // Delete somewhere in the middle
  else {
    printMessage("Deleting node ", toRemove->data, toRemove->dataType, " from index ");
    printf("%d\n", index);
    toRemove->prev->next = toRemove->next;
    toRemove->next->prev = toRemove->prev;
  }

  // Decrement length counter
  head.data.intData--;
  free(toRemove);
}

static union Data get(int index) {
  return getNodeAt(index)->data;
}

static int length() {
  return head.data.intData;
}

static void printList() {
  if (length() == 0) {
    printf("  Printing list: List is empty\n");
    return;
  }

  printf("  Printing head to tail: ");

  Node* cur = head.next;
  printMessage("", cur->data, cur->dataType, "");
  cur = cur->next;
  while (cur != NULL)
  {
    printMessage(" -> ", cur->data, cur->dataType, "");
    cur = cur->next;
  }

  printf("\n");
  printr();
}

//
// Internal functions below
//

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

// Prints the linked list in reverse
static void printr() {
  if (length() == 0) {
    printf("  Printing list: List is empty\n");
    return;
  }

  printf("  Printing tail to head: ");

  Node* next = tail;
  printMessage("", tail->data, tail->dataType, "");
  next = next->prev;

  while (next != &head) {
    printMessage(" -> ", next->data, next->dataType, "");
    next = next->prev;
  }
  printf("\n");
}

// Facilitates printing output involving union Data types. Doesn't print a newline
static void printMessage(char* verb, union Data data, char dataType, char* restOfMessage) {
  printf("%s", verb);

  switch (dataType) {
    case INTDATA:      printf("(%d)", data.intData);
    break;
    case INTPTRDATA:   printf("(%d)", *(data.intPtrData));
    break;
    case FLOATDATA:    printf("(%f)", data.floatData);
    break;
    case FLOATPTRDATA: printf("(%f)", *(data.floatPtrData));
    break;
    case CHARDATA:     printf("(%c)", data.charData);
    break;
    case CHARPTRDATA:  printf("(%c)", *(data.charPtrData));
    break;
  }

  printf("%s", restOfMessage);
}