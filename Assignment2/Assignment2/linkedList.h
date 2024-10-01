#pragma once
 #include "Node.h"

class linkedList : Node // , public vector<Item_Type>::vector
{
private:
	Node* head;
	Node* currentNode;
	Node* tail;

	int num_items = 0;
	int pos = 0;
public:
	linkedList();
	linkedList(int value);
	~linkedList();
	void push_front(const int value);
	void push_back(const int value);
	void pop_front();
	void pop_back();
	int  front();
	int  back();
	bool empty();
	void insert(size_t index, const int& item); // : public vector; // Insert item at position index (starting at 0). Insert at the end if index is beyond the end of the list
	bool remove(size_t index);					// : public vector; // Remove the item at position index. Return true if successful; return false if index is beyond the end of the list.
	size_t find(const int item);				// : public vector; // Return the position of the first occurrence of item if it is found. // Return the size of the list if it is not found.
	void printList();
};
