/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsContainers.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:45:51 by aduchemi          #+#    #+#             */
/*   Updated: 2021/10/27 17:45:54 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TESTS_FT_CONTAINERS_HPP__
# define __TESTS_FT_CONTAINERS_HPP__

#include <iostream>
#include <string>
#include <stdlib.h>
#include <sys/time.h>

#define CHOICE 2

#if CHOICE == 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#elif CHOICE == 1
	#include "../includes/Map/map.hpp"
	#include "../includes/Stack/stack.hpp"
	#include "../includes/Vector/vector.hpp"
#endif

#define MAX_RAM 429496729
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

void	vectorTests();
void	stackTests();
void	mapTests();

#endif
