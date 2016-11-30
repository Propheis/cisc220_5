// Deven Bernard     - 10099810
// Marissa Huang     - 10179169
// Kevin Zuern       - 10134425
// Quentin Petraroia - 10145835

#include <stdio.h>

union Data {
  int    intData;
  int*   intPtrData;

  float  floatData;
  float* floatPtrData;

  char   charData;
  char*  charPtrData;
};

struct Node {
  union Data data;
  struct Node* next;
  struct Node* previous;
  int type;

};

typedef struct Node Node;

Node *getHead();
void insert(int index, union Data data, int type);
void n_remove(int index);
union Data get(int index);
int length();
