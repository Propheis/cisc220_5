// Deven Bernard     - 10099810
// Marissa Huang     - 10179169
// Kevin Zuern       - 10134425
// Quentin Petraroia - 10145835

#include <udll.h>

void insert(int index, union Data data) {

}

union Data get(int index) {

}

int length() {

}

void remove(int index) {
  int indxPtr = 0;
  for (Node *i = head; i!=NULL; i=i->next) {
    if (indxPtr == (index -1)) {
      indxPtr = indxPtr->next->next;
    }
    break;
  }
}