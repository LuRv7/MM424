#include <iostream>
#include "LinkedList.h"

using namespace std;

// * Constructor *************************
LinkedList::LinkedList()
{
  this->root = NULL;
  this->end = NULL;
}

// * Destructor **************************
LinkedList::~LinkedList()
{
  delete root;
  delete end;
}

// * Agregar un nuevo nodo ***************
// ? En tiempo lineal ********************
void LinkedList::add(int value)
{
  if (root == NULL)
  {
    root = new Node(value);
    end = root;
  }
  else
  {
    Node *temp = root;

    while (temp->getNext() != NULL)
      temp = temp->getNext();

    Node *newNode = new Node(value);
    temp->setNext(newNode);
    temp->getNext()->setPrev(temp);
    end = temp->getNext();
  }
}

// * Agregar un nuevo nodo ***************
// ? En tiempo constante *****************
void LinkedList::add2(int value)
{
  if (root == NULL)
  {
    root = new Node(value);
    end = root;
  }
  else
  {
    Node *newNode = new Node(value);
    end->setNext(newNode);
    newNode->setPrev(end);
    end = newNode;
  }
  cout << "agregado\n";
}

// * eliminar un nodo exisitente *********
void LinkedList::remove(int value) {
  if (root == NULL) {
    cout << "lista vacía" << endl;
  } else if (root->getValue() == value) {
    if(root == end)
      root = NULL;
    else{
      root = root->getNext();
      root->setPrev(NULL);
    }
  } else {
    Node *temp = root;
    while(temp->getNext() != NULL) {
      if(temp->getNext()->getValue() == value) {
        temp->setNext(temp->getNext()->getNext());
        if(temp->getNext() != NULL)
          temp->getNext()->setPrev(temp);
        else
          end = temp;
        return;
      } else {
        temp = temp->getNext();
      }
    }
  }
}

// * Imprime la lista en pantalla ********
void LinkedList::print() {
  if (root == NULL)
    cout << "[]\n";
  else {
    Node *temp = root;
    cout << "[";
    while (temp->getNext() != NULL) {
      cout << temp->getValue() << " ";
      temp = temp->getNext();
    }
    cout << temp->getValue() << "]\n";
  }
}

// * Impime la lista en orden inverso ****
void LinkedList::reverse(){
  if(root == NULL)
    cout << "[]\n";
  else{
    Node *temp = end;
    cout << "[";
    while(temp != root){
      cout << temp->getValue() << " ";
      temp = temp->getPrev();
    }
    cout << temp->getValue() << "]\n";
  }
}