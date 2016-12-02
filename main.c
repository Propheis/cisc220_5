// Deven Bernard     - 10099810
// Marissa Huang     - 10179169
// Kevin Zuern       - 10134425
// Quentin Petraroia - 10145835

#include "udll.c"
#include <stdlib.h>

int main() {
  union Data a,b,c,d;
  a.charData = 'a';
  b.charData = 'b';
  c.charData = 'c';
  d.intData = -25;

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

  char x;
  int y;

  printf("\nFetching data from node 0 (expecting 3)...\n");
  y = get(0).intData;
  printf("Got %d\n", y);

  printf("Fetching data from node 1 (expecting a)...\n");
  x = get(1).charData;
  printf("Got %c\n", x);


  printf("Fetching data from node 2 (expecting c)...\n");
  x = get(2).charData;
  printf("Got %c\n", x);

  printf("\n");
}