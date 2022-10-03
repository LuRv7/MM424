
// * Nodo: Elementos individuales de listas

class Node{
  private:
    int value;
    Node *next, *prev;
  
  public:
    Node(int);
    ~Node();
    int getValue();
    Node *getNext();
    Node *getPrev();
    void setValue(int);
    void setNext(Node *);
    void setPrev(Node *);
};