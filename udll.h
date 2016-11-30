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
  struct Node* prev;
};

typedef struct Node Node;

static void insert(int index, union Data data);
static void n_remove(int index);
static union Data get(int index);
static int length();