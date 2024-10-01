#pragma once
#ifndef NODE_H
#define NODE_H

class Node
{
public:
	int value;
	Node* next;
	Node();
	Node(int data, Node* next = nullptr);
	int getValue();
	Node* getNext();
	void setNext(Node* next);
};
#endif


