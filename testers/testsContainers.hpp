#ifndef __TESTS_FT_CONTAINERS_HPP__
# define __TESTS_FT_CONTAINERS_HPP__

#include <iostream>
#include <string>
#include <deque>
#include <stdlib.h>
#include <sys/time.h>

#define CHOICE 2

#if CHOICE == 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "../Map/map.hpp"
	#include "../Stack/stack.hpp"
	#include "../includes/Vector/vector.hpp"
#endif

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096

struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

void	test_push(void);
void	test_element_access(void);
void	test_re_serve_size(void);
void	test_pop_back(void);
void	test_iterator_incrementers_ft();
void	test_iterator_booleans_ft();
void	test_iterator_deref_ft();
void	test_iterator(void);
void	test_reverse_iterator(void);
void	test_constructors(void);
void	test_assign(void);
void	test_insert(void);
void	test_clear_erase(void);
void	test_swap(void);

#endif