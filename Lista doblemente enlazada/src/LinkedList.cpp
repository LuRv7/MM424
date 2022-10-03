#include <iostream>
#include "LinkedList.h"

using namespace std;

// * Constructor *************************
LinkedList::LinkedList(){
  this->root = NULL;
  this->end = NULL;
}

// * Destructor **************************
LinkedList::~LinkedList(){
  delete root;
  delete end;
}

// * Agregar un nuevo nodo ***************
void LinkedList::add(int value){
  if(root == NULL){
    root = new Node(value);
    end = root;
  }else{
    Node *temp = root;

    while(temp->getNext() != NULL)
      temp = temp->getNext();
    
    Node *newNode = new Node(value);
    temp->setNext(newNode);
    temp->getNext()->setPrev(temp);
    end = temp->getNext();
  }
}

// * eliminar un nodo exisitente *********
void LinkedList::remove(int){

}

// * Imprime la lista en pantalla ********
void LinkedList::print(){
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

// * Impime la lista en orden inverso ****
void LinkedList::reverse(){

}