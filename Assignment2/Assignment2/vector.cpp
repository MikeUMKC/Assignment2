#include "vector.h"
#include <iostream>

// Create a stack object.
template <typename V>
vector<V>::vector()
{
	V* array;
	int size = 5;
	int capacity = 5;
}

// parameterized
template <typename V>
vector<V>::vector(int space)
{
	V* array[space];
	int size = 10;
	int capacity = 10;
}

// deconstructor
template <typename V>
vector<V>::~vector()
{
	for (int i = 0; i <= size; i++)
	{
		pop();
	}
}

// 2) Check the stack is empty or not.
template <typename V>
bool vector<V>::checkEmpty()
{
	// if size is 0 then return true
	if (size <= 0)
	{
		std::cout << "List is empty\n";
		return true;
	}
	else
	{
		return false;
	}
}

// 3) allocate more memory
template <typename V>
void vector<V>::reallocate()
{
	// declare new array
	V* temp = new V[capacity+5];
	// expand size
	capacity = 2 * size;

	// copy data to new array
	for (int i = 0; i < size; i++)
	{
		temp[i] = array[i];
	}
	array = temp;
	// delete temp
	delete[]temp;
}

// 4) Insert some integer values onto the stack.
template <typename V>
void vector<V>::push(const int& the_value)
{
	// if inserted value results in overflow
	if (size == capacity)
	{
		reallocate();
	}
	// otherwise take it on
	array[size] = the_value;
	size++;
}

// 5) Remove an element from the stack.
template <typename V>
void vector<V>::pop()
{
	// if list is empty
	if (size <= 0)
	{
		std::cout << "Can't pop from empty list\n";
		return;
	}
	size--;
}

// 6) Find the Top of the stack.
template <typename V>
int vector<V>::top()
{
	std::cout << "last element: " << array[size];
	return array[size];
}

// 7) returns average of all elements
template <typename V>
double vector<V>::avg()
{
	// declare total as double
	double total = 0.0;
	// take in array
	for (int i = 0; i < size; i++)
	{
		total += array[i];
	}

	std::cout << "\nAverage of all elements: " << total / size << '\n';
	return total/size;
}

// 8) outputs array
template <typename V>
void vector<V>::printArray()
{
	int itemCount = 0;
	std::cout << array[0];
	itemCount++;
	for (int i = 1; i < size; i++)
	{
		std::cout << ", " << array[i];
		itemCount++;
	}
	std::cout << "\nNumber of elements: " << itemCount << '\n';
}