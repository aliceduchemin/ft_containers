/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listIte.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:59:17 by aduchemi          #+#    #+#             */
/*   Updated: 2021/05/19 11:59:23 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __LISTITE_HPP__
# define __LISTITE_HPP__

#include "listNode.hpp"

namespace ft
{
	template <class T>
	class ListIterator
	{
		public:
			typedef T							value_type;
			typedef value_type&					reference;
			typedef const value_type&			const_reference;
			typedef value_type*					pointer;
			typedef value_type* const			const_pointer;
			typedef typename std::ptrdiff_t 	difference_type;
		
		/********* COPLIEN *********/
		ListIterator() : _nodePtr(NULL) { /*std::cout << "ite default constr\n";*/ };
		ListIterator(listNode<T> *nodePtr) : _nodePtr(nodePtr) { /*std::cout << "ite constr\n";*/ };
		ListIterator<T> & operator=(ListIterator<T> const & other) { _nodePtr = other.getNodePtr(); return *this; };
		ListIterator(ListIterator<T> const & other) { *this = other; };
		~ListIterator() {};
	
		/********* OPERATORS *********/
		ListIterator	operator++(int)
			{ ListIterator tmp = *this; this->_nodePtr = this->_nodePtr->getNxt(); return tmp; };
		//	{ this->_nodePtr = this->_nodePtr->getNxt(); return *this; };
		ListIterator &	operator++()
			{ this->_nodePtr = this->_nodePtr->getNxt(); return *this; };
		T operator*() 
			{ return this->_nodePtr->getNode(); };
		//reference operator*() 
		//	{ return this->_nodePtr->_node; };
		bool operator!=(ListIterator const & other) const { return _nodePtr != other._nodePtr; };
		bool operator==(ListIterator const & other) const { return _nodePtr == other._nodePtr; };
	// random access ite ?
	//	bool operator<(ListIterator const & other) const { return _nodePtr < other._nodePtr; };
	//	bool operator<=(ListIterator const & other) const { return _nodePtr <= other._nodePtr; };
	//	bool operator>(ListIterator const & other) const { return _nodePtr > other._nodePtr; };
	//	bool operator>=(ListIterator const & other) const { return _nodePtr >= other._nodePtr; };

		/********* GET SET *********/
		listNode<T>	*getNodePtr() const { /*std::cout << "get nxt\n"; */return _nodePtr; };
		void		setNodePtr(listNode<T> *nodePtr) {/* std::cout << "set nxt\n";*/ _nodePtr = nodePtr; };

		private:
			listNode<T>	*_nodePtr;
	};
}

#endif