/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIte.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:59:17 by aduchemi          #+#    #+#             */
/*   Updated: 2021/05/19 11:59:23 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __VECTORITE_HPP__
# define __VECTORITE_HPP__

#include "vectorNode.hpp"

namespace ft
{
	template <class T>
	class VectorIterator
	{
		public:
			typedef T							value_type;
			typedef value_type&					reference;
			typedef const value_type&			const_reference;
			typedef value_type*					pointer;
			typedef value_type* const			const_pointer;
			typedef typename std::ptrdiff_t 	difference_type;
		
		/********* COPLIEN *********/
		VectorIterator() : _nodePtr(NULL) { /*std::cout << "ite default constr\n";*/ };
		VectorIterator(vectorNode<T> *nodePtr) : _nodePtr(nodePtr) { /*std::cout << "ite constr\n";*/ };
		VectorIterator<T> & operator=(VectorIterator<T> const & other) { _nodePtr = other.getNodePtr(); return *this; };
		VectorIterator(VectorIterator<T> const & other) { *this = other; };
		~VectorIterator() {};
	
		/********* ITERATORS *********/
		VectorIterator	operator++(int)
			{ VectorIterator tmp = *this; this->_nodePtr = this->_nodePtr->getNxt(); return tmp; };
		VectorIterator &	operator++()
			{ this->_nodePtr = this->_nodePtr->getNxt(); return *this; };
		VectorIterator	operator--(int)
			{ VectorIterator tmp = *this; this->_nodePtr = this->_nodePtr->getPrv(); return tmp; };
		VectorIterator &	operator--()
			{ this->_nodePtr = this->_nodePtr->getPrv(); return *this; };

	//	T &	operator++()
	//		{ T tmp = this->_nodePtr->getNode(); tmp return *this; };
		T operator*() 
			{ /*std::cout << "\nprv = " << this->_nodePtr->getPrv()->getNode() \
			<< " node = " << this->_nodePtr->getNode() \
			<< " next = " << this->_nodePtr->getNxt() <<"\t";*/
			 return this->_nodePtr->getNode(); };
		T operator->() 
			{ return this->_nodePtr->getNode(); };
		//reference operator*() 
		//	{ return this->_nodePtr->_node; };
		bool operator!=(VectorIterator const & other) const { return _nodePtr != other._nodePtr; };
		bool operator==(VectorIterator const & other) const { return _nodePtr == other._nodePtr; };
		
		/********* RANDOM ACCESS ITERATORS *********/
		bool operator<(VectorIterator const & other) const { return _nodePtr < other._nodePtr; };
		bool operator<=(VectorIterator const & other) const { return _nodePtr <= other._nodePtr; };
		bool operator>(VectorIterator const & other) const { return _nodePtr > other._nodePtr; };
		bool operator>=(VectorIterator const & other) const { return _nodePtr >= other._nodePtr; };

		/********* GET SET *********/
		vectorNode<T>	*getNodePtr() const {/* std::cout << "get nxt\n";*/ return _nodePtr; };
		void		setNodePtr(vectorNode<T> *nodePtr) {/* std::cout << "set nxt\n";*/ _nodePtr = nodePtr; };

		private:
			vectorNode<T>	*_nodePtr;
	};
}

#endif