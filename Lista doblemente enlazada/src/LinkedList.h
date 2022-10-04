
// * Lista doblemente enlazada

#include "Node.h"

class LinkedList{
  private:
    Node *root, *end;

  public:
    LinkedList();
    ~LinkedList();
    void add(int);
    void add2(int);
    void remove(int);
    void print();
    void reverse();
};