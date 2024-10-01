// #include "vector.h"
#include "linkedList.h"
#include "Node.h"
#include "vector.h"
#include "vector.cpp"
#include <iostream>
#include <string>
#include <stdexcept>

int main()
{
	// initialize the 2 classes
	linkedList list;
	vector<int> stack;
	// initialize as y 
	std::string resume = "y";
	// string here works almost like the cmd
	std::string commandInput;
	int position;
	int input;
	
	try
	{
		// title for first program
		std::cout << "Integer Linked list program";
		// pre-initialized input removes need for first iteration to be outside
		// default is continue
		while (resume == "y")
		{
			// input help to list command
			std::cout << "\nenter 'help' if you need commands\nwhat would you like to do: ";
			std::cin >> commandInput;

			// lists all commands
			if (commandInput == "help")
			{
				std::cout << "|\nV\nenter 'add' to add element\nenter 'delete' to remove element with index input\nenter 'empty' to check if list is empty\nenter 'front' to check first element\nenter 'back' to check last element\nenter 'find' to check for element position\nenter anything else to exit program\n\n";
			}
			// adds with input and position number
			else if (commandInput == "add")
			{
				// prompts and takes input for position
				std::cout << "\nEnter position(Enter 0 if nothing): ";
				std::cin >> position;
				floor(position);
				if (std::cin.fail())													// catches invalid input error
				{
					throw std::invalid_argument("Input must be an integer");			// input must be an integer	
				}
				// prompts and takes input for integer
				std::cout << "Enter integer: ";
				std::cin >> input;
				floor(input);
				if (std::cin.fail())													// catches invalid input error
				{
					throw std::invalid_argument("Input must be an integer");			// input must be an integer	
				}
				// Down arrow to show results
				std::cout << "|\nV\n";
				list.insert(position, input);
				// stack.push(input);
				std::cout << "Output: ";
				list.printList();
			}
			// deletes node with position input
			else if (commandInput == "delete")
			{
				std::cout << "\nEnter position(Enter 0 if nothing): ";
				std::cin >> position;
				floor(position);
				if (std::cin.fail())													// catches invalid input error
				{
					throw std::invalid_argument("Input must be an integer");			// input must be an integer	
				}
				list.remove(floor(position));
				std::cout << "Output: ";
				list.printList();
			}
			// checks if list is empty
			else if (commandInput == "empty")
			{
				list.empty();
			}
			// checks and returns the head node
			else if (commandInput == "front")
			{
				list.front();
			}
			// checks and returns tail node
			else if (commandInput == "back")
			{
				list.back();
			}
			// checks and returns searched node
			// returns "Item can't be found" if node can't be found
			else if (commandInput == "find")
			{
				std::cout << "\nEnter integer in question: ";
				std::cin >> input;
				floor(input);
				if (std::cin.fail())													// catches invalid input error
				{
					throw std::invalid_argument("Input must be an integer");			// input must be an integer	
				}
				list.find(input);
			}
			// breaks out of loop if commandInput is anything else
			else
			{
				std::cout << "|\nV\nFinal Output: ";
				list.printList();
				break;
			}
		}
		std::cout << "\n---------------------------------------------------------------\n";
		// stack loop
		std::cout << "\n\nInteger vector stack program";
		resume = "y";
		while (resume == "y")
		{
			// prompts user to input command
			std::cout << "\nenter 'help' if you need commands\nwhat would you like to do: ";
			std::cin >> commandInput;
			// help command

			if (commandInput == "help")
			{
				// console outputs list of commands
				std::cout << "|\nV\nenter 'add' to add element\nenter 'delete' to remove element with index input\nnenter 'top' to check first element\n";
			}
			// push command
			else if (commandInput == "add")
			{
				std::cout << "Integer to be added: ";
				std::cin >> input;
				floor(input);
				if (std::cin.fail())													// catches invalid input error
				{
					throw std::invalid_argument("Input must be an integer");			// input must be an integer	
				}
				stack.push(floor(input));
			}
			// pop command
			else if (commandInput == "delete")
			{
				stack.pop();
			}
			// top commmand
			else if (commandInput == "top")
			{
				stack.top();
			}
			// average of elements command
			else if (commandInput == "avg")
			{
				stack.avg();
			}
			// exit loop if nothing else is inputed
			else
			{
				stack.printArray();
				break;
			}

			std::cout << "\nEnter 'y' if you want to continue\nOr 'n' to exit\nWould you like to continue?: ";
			std::cin >> resume;

			if (resume == "n")
			{
				stack.printArray();
				break;
			}
		} //*/	
	}
	catch (std::invalid_argument)
	{
		std::cerr << "Input must be an integer!\n"; // if character or string is inputed
	}
	catch (std::exception)
	{
		std::cerr << "Exception caught\n";		// umbrella
	}
	return 0;
}