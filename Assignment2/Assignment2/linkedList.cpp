#include "linkedList.h"
#include <iostream>
#include <stddef.h>

// constructor
linkedList::linkedList()
{
	this->head = nullptr;
}

// parameterized constructor
linkedList::linkedList(int data)
{
	head->next = next;
	head->value = data;
	
	// traverses and assigns tail to last node
	Node* last = head;
	while (last->next != nullptr)
	{
		last = last->next;
	}
	tail = last;
}


// deconstructor
linkedList::~linkedList()
{
	currentNode = head;
	while(currentNode != NULL)
	{
		Node* next = currentNode->next;
		delete currentNode;
		currentNode = next;
	}
	head = NULL;
}

// pushes inputed data in front of the list
void linkedList::push_front(const int newData)
{
	// create node for inputed data
	Node* newNode = new Node(newData);
	this->head = new Node(newData, this->head);

	// empty list results in head becoming the new node
	if (head == NULL) 
	{
		head = newNode;
		return;
	}

	// newNode ptr set to head
	newNode->next = this->head;
	// newNode value is newData
	newNode->value = newData;

	return;
}

void linkedList::push_back(const int newData)
{
	// prepare a node
	Node* newNode = new Node();
	// newNode attributes set to be in rear
	newNode->value = newData;
	newNode->next = NULL;

	// if list is empty, new node will be head
	if (head == NULL)
	{
		head = newNode;
		return;
	}

	// find tail node and counts item
	tail = head;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}

	// set tail as pushed node
	tail->next = newNode;
	newNode = tail;
}

// Insert item at position index (starting at 0)
// Insert at the end if index is beyond the end of the list
void linkedList::insert(size_t index, const int& item)
{
	Node* traverse = new Node;
	traverse = head;
	int num_items = 0;

	// num_items = 0;
	while (traverse != NULL)
	{
		traverse = traverse->next;
		num_items++;
	}

	// push_front at head if inputed position is <= 0
	if (index <= 0)
	{
		push_front(item);
		return;
	}
	// push_back at tail if inputed position is >= number of items to which we can treat it as position
	if (index >= num_items)
	{
		push_back(item);
		return;
	}
	
	// if all 3 conditions fail
	traverse = head;
	Node* previous = new Node();
	
	// traverse node this many times; index
	// stop before stated index to insert 
	for (int i = 0; i < index; i++)
	{
		previous = traverse;
		traverse = traverse->next;
	}

	// inputed item becomes new node
	Node* newNode = new Node(item);
	// the pointer of node before inserted index is now pointing to new node
	previous->next = newNode;
	// new Node pointer replaces that of previous pointer to continue list
	newNode->next = traverse;
	num_items++;
	return;
}

// delete head
void linkedList::pop_front()
{
	// checks if list is empty
	if (head == nullptr)
	{
		std::cout << "List is empty";
	}

	// temporary node = head
	Node* temp = head;

	// head is now reassigned to adjacent node
	head = head->next;

	// delete the temporary node
	delete temp;
	std::cout << "\nItem deleted: " << head->value << '\n';
}

// delete the tail
void linkedList::pop_back()
{
	Node* temp = new Node();
	// If the list is empty, return nullptr
	if (head == nullptr) 
	{
		return;
	}

	// If the list has only one node, delete it and return
	// nullptr
	if ((head->next) == nullptr) 
	{
		delete head;
		return;
	}

	// Find the second last node
	Node* second_last = head;
	while ((second_last->next->next) != nullptr) 
	{
		second_last = second_last->next;
	}
	// Change next of new tail
	tail = second_last;
	temp = second_last->next;
	tail->next = nullptr;

	// Delete the last node
	std::cout << "\nItem deleted: " << temp->value << '\n';
	delete temp;

	// decrement item-count
}

// Remove the item at position index.Return true if successful; return false if index is beyond the end of the list.
bool linkedList::remove(size_t index)
{
	// set current node for traversal
	currentNode = head;
	num_items = 0;

	// node traversal for item count
	while(currentNode->next != nullptr)
	{
		currentNode = currentNode->next;
		num_items++;
	}

	// when the head is to be removed
	if (index <= 0)
	{
		pop_front();
		return true;
	}
	// else if tail is to be removed
	// num_items-1 because index starts at 0
	if (index >= num_items)
	{
		pop_back();
		return true;
	}

	// list traversal
	Node* previous = head;
	// reset node traversal
	currentNode = head;
	
	// traversal stops at before index
	for (int i = 0; i < index; i++) 
	{
		previous = currentNode;
		currentNode = currentNode->next;
	}

	//assign next node as the one after it
	previous->next = currentNode->next;
	
	// print linked list to see changes
	printList();
	std::cout << "Item deleted: " << currentNode->value << "\n|\nV\n";
	delete currentNode;
	return true;
}

// returns value at front
int  linkedList::front()
{
	// returns head value
	std::cout << head->value;
	return head->value;
}

// returns value at rear
int  linkedList::back()
{
	// tail end is traversing
	tail = head;
	while (tail->next != nullptr)
	{
		tail = tail->next;
	}

	// returns the tail value
	std::cout << "tail-end: " << tail->value << '\n';
	return tail->value;
}

// checks for empty list
bool linkedList::empty()
{
	if (head == NULL) 
	{
		// assigns head as empty ptr
		head = nullptr;
		std::cout << "list is empty\n\n";
		return false;
	}
}

// Return the position of the first occurrence of item if it is found. Return the size of the list if it is not found.
size_t linkedList::find(const int item)
{
	// declare traversal node and index
	Node* currentNode = head;
	int index = 0;

	// traverse list if 
	// if (currentNode->value != item && index <= num_items)
	while (currentNode->next != nullptr)
	{
		// if item is found throughout traversing
		if (currentNode->value == item)
		{
			// outputs position of item starting at 0
			std::cout << item << " found at: " << index;
			return index;
		}
		// traverse list
		currentNode = currentNode->next;
		// if item is nowhere to be found
		if (currentNode->next == nullptr)
		{
			// result is Item not found
			std::cout << "Item not found\n\n";
			return num_items;
		}
		// increments position to ensure success
		index++;
	}
}

// outputs list
void linkedList::printList()
{
	// declare traversal node
	Node* traverse = head;
	int itemCount = 0;

	// Check for empty list
	if (head == NULL) 
	{
		std::cout << "List empty\n\n";
		return;
	}

	// outputs all elements sequentially
	// first iteration of output
	std::cout << traverse->value;
	traverse = traverse->next;
	// All other iterations and node travels
	while (traverse != NULL) 
	{
		std::cout << " => " << traverse->value;
		traverse = traverse->next;
	}

	num_items = 0;
	// outputs position of each node 
	// first iteration
	std::cout << "\nPosition: " << num_items;
	traverse = head;
	// all other iterations
	while (traverse != NULL)
	{
		num_items++;
		std::cout << " => " << num_items;
		traverse = traverse->next;
	}

	// prints out item count
	std::cout << "\ntotal number of elements: " << num_items << "\n\n";
}

