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
			typedef typename std::ptrdiff_t 	difference_type;
			typedef value_type*					pointer;
			typedef value_type&					reference;
			typedef const value_type&			const_reference;
			typedef value_type* const			const_pointer;
			//size_type (size_t)
		
		/********* COPLIEN *********/
		VectorIterator() : _nodePtr(NULL) { /*std::cout << "ite default constr\n";*/ };
		VectorIterator(pointer nodePtr) : _nodePtr(nodePtr) { /*std::cout << "ite constr\n";*/ };
		VectorIterator<T> & operator=(VectorIterator<T> const & other) { _nodePtr = other.getNodePtr(); return *this; };
		VectorIterator(VectorIterator<T> const & other) { *this = other; };
		~VectorIterator() {};
	
		/********* ITERATORS *********/
		VectorIterator	operator++(int) //i++
			{ VectorIterator tmp(*this); operator++(); return tmp; };
		//	{ VectorIterator tmp = *this; this->_nodePtr = this->_nodePtr->getNxt(); return tmp; };
		VectorIterator &	operator++() //++i
			{ this->_nodePtr++; return *this; }
		//	{ this->_nodePtr = this->_nodePtr->getNxt(); return *this; };
		VectorIterator	operator--(int)
			{ VectorIterator tmp(*this); operator--(); return tmp; };
		//	{ VectorIterator tmp = *this; this->_nodePtr = this->_nodePtr->getPrv(); return tmp; };
		VectorIterator &	operator--()
			{ _nodePtr--; return *this; }
		//	{ this->_nodePtr = this->_nodePtr->getNxt(); return *this; };
/*		VectorIterator 	operator+(int n) const
			{ VectorIterator tmp(*this); 
			while (n--)
				tmp++;
			return tmp; };*/
		
		reference operator*() const
			{ return *_nodePtr; };
		pointer operator->() 
			{ return *_nodePtr; };
		bool operator!=(VectorIterator const & other) const { return _nodePtr != other._nodePtr; };
		bool operator==(VectorIterator const & other) const { return _nodePtr == other._nodePtr; };
		
		difference_type operator +(VectorIterator other) { return (_nodePtr + other._nodePtr); };
		friend VectorIterator operator+(VectorIterator const & other, int n) { return (other + n); };

		/********* RANDOM ACCESS ITERATORS *********/
		bool operator<(VectorIterator const & other) const { return _nodePtr < other._nodePtr; };
		bool operator<=(VectorIterator const & other) const { return _nodePtr <= other._nodePtr; };
		bool operator>(VectorIterator const & other) const { return _nodePtr > other._nodePtr; };
		bool operator>=(VectorIterator const & other) const { return _nodePtr >= other._nodePtr; };

		/********* GET SET *********/
		pointer		getNodePtr() const { return _nodePtr; };
		void		setNodePtr(pointer *nodePtr) { _nodePtr = nodePtr; };

		private:
			pointer	_nodePtr;
		//	vectorNode<T>	*_nodePtr;
	};
}

#endif