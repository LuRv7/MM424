#include <iostream>
#include "Node.h"

Node::Node(int value){
  this->value = value;
  this->next = NULL;
  this->prev = NULL;
}

Node::~Node(){
  delete next;
  delete prev;
}

int Node::getValue(){
  return value;
}

Node *Node::getNext(){
  return next;
}

Node *Node::getPrev(){
  return prev;
}

void Node::setValue(int value){
  this->value = value;
}

void Node::setNext(Node *next){
  this->next = next;
}

void Node::setPrev(Node *prev){
  this->prev = prev;
}
