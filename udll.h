// Deven Bernard     - 10099810
// Marissa Huang     - 10179169
// Kevin Zuern       - 10134425
// Quentin Petraroia - 10145835

#include <stdio.h>

#define MODE_int    0;
#define MODE_intP   1;
#define MODE_float  2;
#define MODE_floatP 3;
#define MODE_char   4;
#define MODE_charP  5;

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
  
  // One of the MODE_* constants. 
  // Used to identify which type is being stored in data
  char currentNodeType;

  struct Node* next;
  struct Node* before;
};

typedef struct Node Node;

void insert(int index, union Data data);
void remove(int index);
union Data get(int index);
int length();