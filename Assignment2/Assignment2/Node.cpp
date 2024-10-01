#include "Node.h"
#include <iostream>
#include <stddef.h>

 Node::Node()
 {
	 this->value = 0;
	 this->next = nullptr;
 }
 Node::Node(int data, Node *next)
 {
	 this->value = data;
	 this->next = next;
 }
 int Node::getValue()
 {
	 return this->value;
 }
 Node* Node::getNext()
 {
	 return this->next;
 }
 void Node::setNext(Node* next)
 {
	 this->next = next;
 }
