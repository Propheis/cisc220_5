// Deven Bernard     - 10099810
// Marissa Huang     - 10179169
// Kevin Zuern       - 10134425
// Quentin Petraroia - 10145835

#include "udll.c"
#include <stdlib.h>

int main() {
  union Data a,b,c,d,ptr;
  a.charData = 'a';
  b.charData = 'b';
  c.charData = 'c';
  d.intData = -25;

  float floatData = 3.141596;
  ptr.floatPtrData = &floatData;

  printf("List is currently empty. Attempting to print list:\n");
  printList();
  printf("  List Length: %d\n\n", length());

  insert(0, a, CHARDATA);
  printList();
  printf("  List Length: %d\n\n", length());
  
  insert(1, c, CHARDATA);
  printList();
  printf("  List Length: %d\n\n", length());

  insert(1, b, CHARDATA);
  printList();
  printf("  List Length: %d\n\n", length());

  insert(3, d, INTDATA);
  printList();
  printf("  List Length: %d\n\n", length());

  removeNode(1);
  printList();
  printf("  List Length: %d\n\n", length());

  insert(0, a, CHARDATA);
  printList();
  printf("  List Length: %d\n\n", length());

  removeNode(2);
  printList();
  printf("  List Length: %d\n\n", length());

  insert(3, ptr, FLOATPTRDATA);
  printList();
  printf("  List Length: %d\n\n", length());

  insert(1, b, CHARDATA);
  printList();
  printf("  List Length: %d\n\n", length());

  insert(4, a, CHARDATA);
  printList();
  printf("  List Length: %d\n\n", length());

  char x;
  int y;


  printf("Fetching data from node 1 (expecting a)...\n");
  x = get(1).charData;
  printf("Got %c\n\n", x);


  printf("Fetching data from node 2 (expecting b)...\n");
  x = get(2).charData;
  printf("Got %c\n\n", x);

  printf("Fetching data from node 4 (expecting -25)...\n");
  y = get(4).intData;
  printf("Got %d\n\n", y);

  printf("\n");
}