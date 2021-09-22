#include <iostream>
#include <string>
#include <stack>
#include "stack.hpp"

int main()
{
	ft::stack<int>	myStack;

	std::cout << "stack size = " << myStack.size() << std::endl;
	std::cout << "stack is empty ? = " << myStack.empty() << std::endl;

	myStack.push(1);
	std::cout << "stack size = " << myStack.size() << std::endl;
	std::cout << "stack top = " << myStack.top() << std::endl;
	myStack.push(2);
	myStack.push(3);
	myStack.push(4);
	myStack.push(5);
	std::cout << "stack size = " << myStack.size() << std::endl;
	std::cout << "stack top = " << myStack.top() << std::endl;
	myStack.pop();
	myStack.pop();
	std::cout << "stack size = " << myStack.size() << std::endl;
	std::cout << "stack top = " << myStack.top() << std::endl;

	ft::stack<int> mySecondStack(myStack);
	std::cout << "2nd stack size = " << mySecondStack.size() << std::endl;
	std::cout << "2nd stack top = " << mySecondStack.top() << std::endl;
	mySecondStack.pop();
	std::cout << "2nd stack size = " << mySecondStack.size() << std::endl;
	std::cout << "2nd stack top = " << mySecondStack.top() << std::endl;


//	bool ret = myStack != mySecondStack;
//	std::cout << "my <= = " << ret << std::endl;
/*
	ret = myStack != mySecondStack;
	std::cout << "my comparaison = " << ret << std::endl;

	myStack = mySecondStack;
	ret = myStack != mySecondStack;
	std::cout << "my comparaison = " << ret << std::endl;
*/
	return 0;
}