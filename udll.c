



typedef struct Node Node;
Node* head = NULL;
Node* tail = NULL;

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