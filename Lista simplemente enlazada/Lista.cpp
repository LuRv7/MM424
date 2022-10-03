#include <iostream>
using namespace std;

/**
 * ! ============= Clase Nodo =============
 * */

class Node {
  private:
    int value;
    Node *next;

  public:
    Node(int);
    ~Node();
    int getValue();
    Node *getNext();
    void setValue(int);
    void setNext(Node *);
};

Node::Node(int value){
  this->value = value;
  this->next = NULL;
}

Node::~Node(){
  delete next;
}

int Node::getValue(){
  return value;
}

Node *Node::getNext(){
  return next;
}

void Node::setValue(int value){
  this->value = value;
}

void Node::setNext(Node *node){
  this->next = node;
}

/**
 * ! ============= Clase Lista =============
 * */

class List {
  private:
    Node *root;
    int size;

  public:
    List();
    ~List();
    bool add(int);
    bool remove(int);
    void show();
    int getSize();
};

List::List(){
  this->root = NULL;
  size = 0;
}

List::~List(){
  delete root;
}

bool List::add(int value){
  if(root == NULL){
    root = new Node(value);
    size++;
    return true;
  }else{
    Node *temp = root;

    while(temp->getNext() != NULL)
      temp = temp->getNext();
    
    Node *newNode = new Node(value);
    temp->setNext(newNode);
    size++;
    return true;
  }
  return false;
}

void List::show(){
  if(root == NULL)
    cout << "Lista vacia" << endl;
  else{
    Node *temp = root;

    while(temp != NULL){
      cout << temp->getValue() << " ";
      temp = temp->getNext();
    }
    cout << endl;
  }
}

bool List::remove(int value){
  if(root == NULL)
    return false;
  else{
    if(root->getValue() == value){
      root = root->getNext();
      size--;
      return true;
    }else{

      Node *temp = root;

      while(temp->getNext() != NULL){
        if(temp->getNext()->getValue() != value)
          temp = temp->getNext();
        else{
          temp->setNext(temp->getNext()->getNext());
          size--;
          return true;
        }
      }
      return false;
    }
  }
}

int List::getSize(){
  return size;
}



/**
* ! ============= Función principal ============= 
* */

int main(){

  List *list = new List();

  list->add(4);
  list->add(8);
  list->add(2);
  list->add(5);
  list->add(0);
  list->add(1);
  list->add(3);
  list->add(1);
  list->add(9);

  list->show();
  cout << "Longitud: " << list->getSize() << endl;

  list->remove(4);
  list->remove(0);
  list->remove(3);
  list->remove(1);
  list->remove(3);

  list->show();
  cout << "Longitud: " << list->getSize() << endl;

  return 0;
}
