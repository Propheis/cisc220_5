// Deven Bernard     - 10099810
// Marissa Huang     - 10179169
// Kevin Zuern       - 10134425
// Quentin Petraroia - 10145835

#include "udll.h"
#include <stdlib.h>

int main() {
  //
  // Setup
  //
  printf("Setting up testing...\n");

  int intData     = 1;
  char charData   = 'a';
  float floatData = 0.1;

  union Data a,b,c,d,e,f;

  a.intData      =  intData;
  b.intPtrData   = &intData;
  c.charData     =  charData;
  d.charPtrData  = &charData;
  e.floatData    =  floatData;
  f.floatPtrData = &floatData;

  //
  // Test insert()
  //

  printf("Testing insert() function\n");

  // Inserting to last half of list, so should traverse from tail

  insert(0, a, 0);
  insert(1, b, 1);
  insert(2, c, 2);
  insert(3, d, 3);
  // Inserting to first half of list, so should traverse from head
//  insert(0, e, 4);
//  insert(2, f, 5);
  Node *i;
  for(i = getHead()->next; i; i=i->next) {
/*
    if(i->type == 0) {
    printf("%d", i->data.intData);
  } else if (i->type == 1) {
    printf("%p", i->data.intPtrData);
  } else if (i->type == 2) {
    printf("%c", i->data.charData);
  } else if (i->type == 3) {
    printf("%s", i->data.charPtrData);
  } else if (i->type == 4) {
    printf("%f", i->data.floatData);
  } else {
    printf("%p", i->data.floatPtrData);
  }
*/}

  //
  // Test length()
  //

  printf("Testing length() function\n");

  if (length() != 6) {
    printf("Something went wrong inserting nodes\n");
    exit(1);
  }

  //
  // Test get()
  //

  printf("Testing get() function\n");

  union Data result = get(0);
  if (result.floatData != floatData)
    printf("get() returned the wrong result or insert() is broken\n");

  result = get(2);
  if (result.floatPtrData != &floatData)
    printf("get() returned the wrong result or insert() is broken\n");

  //
  // Test remove()
  //

  printf("Testing remove() function\n");

  n_remove(0);

  if (length() != 5)
    printf("remove() didn't remove anything or length() is broken.\n");

  if (get(0).intData != intData)
    printf("remove() didn't remove the right element or get() is broken\n");

  printf("Testing complete. Exiting now\n");

  return 0;
}
