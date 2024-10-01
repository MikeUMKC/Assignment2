#pragma once

#ifndef VECTOR_H
#define VECTOR_H

template<typename V>
class vector
{
	int size = 0;
	int capacity;
	V* array;

public:
		// Create a stack object.
	vector();
	vector(int space);
		// deconstructor
	~vector();
		// 2) Check the stack is empty or not.
	bool checkEmpty();
		// 3) allocate more memory should capacity be inadequate
	void reallocate();
		// 4) Insert some integer values onto the stack.
	void push(const int& the_value);
		// 5) Remove an element from the stack.
	void pop();
		// 6) gets the Top of the stack.
	int top();
		// 7) returns average of all elements
	double avg();
		// 8) print vector array
	void printArray();
};
#endif