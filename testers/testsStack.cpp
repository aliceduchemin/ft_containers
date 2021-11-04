/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsStack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:46:14 by aduchemi          #+#    #+#             */
/*   Updated: 2021/10/27 17:46:15 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testsContainers.hpp"
#include <list>

void stackTests()
{
	std::cout << "Creating an int Stack :" << std::endl;
	NMSPC::stack<int>	myStack;
	std::cout << "Testing size and empty :" << std::endl;
	std::cout << "stack size = " << myStack.size() << std::endl;
	std::cout << "stack is empty ? = " << myStack.empty() << std::endl;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Push test (1) :" << std::endl;
	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	myStack.push(4);
	myStack.push(5);
	std::cout << "stack is empty ? = " << myStack.empty() << std::endl;
	std::cout << "stack size = " << myStack.size() << std::endl;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "stack top = " << myStack.top() << std::endl;
	
	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "stack pop, twice : " << std::endl;
	myStack.pop();
	myStack.pop();
	std::cout << "stack size = " << myStack.size() << std::endl;
	std::cout << "stack top = " << myStack.top() << std::endl;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Second stack(first) : " << std::endl;
	NMSPC::stack<int> mySecondStack(myStack);
	std::cout << "2nd stack size = " << mySecondStack.size() << std::endl;
	std::cout << "2nd stack top = " << mySecondStack.top() << std::endl;
	mySecondStack.pop();
	std::cout << "2nd stack size = " << mySecondStack.size() << std::endl;
	std::cout << "2nd stack top = " << mySecondStack.top() << std::endl;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Comparators : " << std::endl;
	bool ret = myStack != mySecondStack;
	std::cout << "!= ? " << ret << std::endl;

	ret = myStack == mySecondStack;
	std::cout << "== ? " << ret << std::endl;
	ret = myStack <= mySecondStack;
	std::cout << "<= ? " << ret << std::endl;
	ret = myStack > mySecondStack;
	std::cout << "> ? " << ret << std::endl;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Second stack = first : " << std::endl;
	myStack = mySecondStack;
	std::cout << "Comparators : " << std::endl;
	ret = myStack == mySecondStack;
	std::cout << "== ? " << ret << std::endl;
	ret = myStack <= mySecondStack;
	std::cout << "<= ? " << ret << std::endl;
	ret = myStack > mySecondStack;
	std::cout << "> ? " << ret << std::endl;
	ret = myStack < mySecondStack;
	std::cout << "< ? " << ret << std::endl;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Creating an empty vector stack :" << std::endl;
	NMSPC::stack<int> firstVectorStack;
	std::cout << "size of vector stack : " << firstVectorStack.size() <<std::endl;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Creating a vector stack -> stack<int, vector<int>>:" << std::endl;
	NMSPC::vector<int> myVector (2,200);
	NMSPC::stack<int, NMSPC::vector<int> > secondVectorStack(myVector);
	std::cout << "size of vector stack : " << secondVectorStack.size() <<std::endl;
	std::cout << "top of vector stack : " << secondVectorStack.top() <<std::endl;
	secondVectorStack.pop();
	std::cout << "size of vector stack after pop(): " << secondVectorStack.size() <<std::endl;
	std::cout << "top of vector stack : " << secondVectorStack.top() <<std::endl;
	secondVectorStack.pop();
	std::cout << "size of vector stack after pop(): " << secondVectorStack.size() <<std::endl;
	std::cout << "top of vector stack : " << secondVectorStack.top() <<std::endl;


	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Creating a MutantStack<char> :" << std::endl;
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Creating a stack with std::list as underlying container :" << std::endl;
	std::list<int> liste (2,200);
	NMSPC::stack<int, std::list<int> > listStack(liste);

	for (int num = 0; num <= 38; num++)
		listStack.push(num);
	std::cout << "list stack size : " << listStack.size() << std::endl;
	std::cout << "list stack top : " << listStack.top() << std::endl;
	listStack.pop();
	std::cout << "list stack pop" << std::endl;
	std::cout << "list stack top : " << listStack.top() << std::endl;
	listStack.pop();
	std::cout << "list stack pop" << std::endl;
	std::cout << "list stack top : " << listStack.top() << std::endl;
	std::cout << "list stack size : " << listStack.size() << std::endl;
}
