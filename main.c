// Deven Bernard     - 10099810
// Marissa Huang     - 10179169
// Kevin Zuern       - 10134425
// Quentin Petraroia - 10145835

#include "udll.c"
#include <stdlib.h>

// int main() {
//   //
//   // Setup
//   //

//   printf("Setting up testing...\n");

//   int intData     = 1;
//   char charData   = 'a';
//   float floatData = 0.1;

//   union Data a,b,c,d,e,f;

//   a.intData      =  intData;
//   b.intPtrData   = &intData;
//   c.charData     =  charData;
//   d.charPtrData  = &charData;
//   e.floatData    =  floatData;
//   f.floatPtrData = &floatData;

//   //
//   // Test insert()
//   //

//   printf("Testing insert() function\n");

//   // Inserting to last half of list, so should traverse from tail
//   insert(0, a);
//   insert(1, b);
//   insert(2, c);
//   insert(3, d);
  
//   // Inserting to first half of list, so should traverse from head
//   insert(0, e);
//   insert(2, f);

//   //
//   // Test length()
//   //

//   printf("Testing length() function\n");

//   if (length() != 6) {
//     printf("Something went wrong inserting nodes\n");
//     exit(1);
//   }

//   // //
//   // // Test get()
//   // //

//   // printf("Testing get() function\n");

//   // union Data result = get(0);
//   // if (result.floatData != floatData)
//   //   printf("get() returned the wrong result or insert() is broken\n");

//   // result = get(2);
//   // if (result.floatPtrData != &floatData)
//   //   printf("get() returned the wrong result or insert() is broken\n");

//   // //
//   // // Test remove()
//   // //

//   // printf("Testing remove() function\n");

//   // n_remove(0);

//   // if (length() != 5)
//   //   printf("remove() didn't remove anything or length() is broken.\n");

//   // if (get(0).intData != intData)
//   //   printf("remove() didn't remove the right element or get() is broken\n");

//   // printf("Testing complete. Exiting now\n");

//   return 0;
// }

int main() {
  union Data a,b,c,d;
  a.charData = 'a';
  b.charData = 'b';
  c.charData = 'c';
  d.charData = 'd';

  printf("The empty list:\n");
  printList();

  insert(0, a, CHARDATA);
  printList();
  
  insert(1, c, CHARDATA);
  printList();

  insert(1, b, CHARDATA);
  printList();

  char x;
  int y;

  printf("\nFetching data from node 0 (expecting 3)...\n");
  y = get(0).intData;
  printf("Got %d\n\n", y);

  printf("Fetching data from node 1 (expecting a)...\n");
  x = get(1).charData;
  printf("Got %c\n\n", x);


  printf("Fetching data from node 2 (expecting b)...\n");
  x = get(2).charData;
  printf("Got %c\n\n", x);


  printf("Fetching data from node 3 (expecting c)...\n");
  x = get(3).charData;
  printf("Got %c\n\n", x);



}