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
  // Increment length
  head.data.intData++;

  if ( index == 0 ) { // insert to head of list
    printf("Inserting %c to head of list\n", data.charData);
    Node *new = node(data, dataType, &head, head.next);
    head.next = new;
    tail = new;

    return;
  }
  else if ( index ==  length()-1 ) { // insert to tail of list
    printf("Inserting %c to tail of list\n", data.charData);
    Node *new = node(data, dataType, tail, NULL);
    tail->next = new;

    return;
  }

  // Insert somewhere in the middle
  printf("Inserting %c at index %d\n", data.charData, index );
  Node* insertionPoint = getNodeAt(index);
  Node *new = node(data, dataType, insertionPoint->prev, insertionPoint->next);

  insertionPoint->next = new;
  new->next->prev = new;
}

static union Data get(int index) {
  return getNodeAt(index)->data;
}

static void removeNode(int index) {
  Node * toRemove = getNodeAt(index);
  if (toRemove == &head) {
    printf("Cannot delete head of linked list. Contains valuable information\n");
  }
  else {
  // Delete first node
    if ( index == 1 ) { 
      printf("Deleting node at beginning of list\n");
      head = *(head.next); 
      return;
    }
  // Delete tail
    else if ( index >= length() ) { 
      printf("Deleting tail of list\n");
      Node * prev = getNodeAt(index-1);
      prev->next = NULL;
      return;
    }
  // Delete somewhere in the middle
    else {
      printf("Deleting at index %d\n", index );
      Node * delPoint = getNodeAt(index);
      Node * prev = getNodeAt(index-1);
      prev->next = delPoint->next;
    }
  free(toRemove);
  head.data.intData--;
  }
}

static int length() {
  return head.data.intData;
}

static void printList() {

  printf("(%d)", head.data.intData);

  Node* cur = head.next;
  while (cur != NULL)
  {
    printf(" -> (%c)", cur->data.charData);
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
