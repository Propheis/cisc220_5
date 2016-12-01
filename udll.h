// Deven Bernard     - 10099810
// Marissa Huang     - 10179169
// Kevin Zuern       - 10134425
// Quentin Petraroia - 10145835

#include <stdio.h>

#define INTDATA      0
#define INTPTRDATA   1
#define FLOATDATA    2
#define FLOATPTRDATA 3
#define CHARDATA     4
#define CHARPTRDATA  5

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
  char dataType;
  struct Node* next;
  struct Node* prev;
};

typedef struct Node Node;

static void insert(int index, union Data data, char dataType);
static void n_remove(int index);
static union Data get(int index);
static int length();
static void printList();