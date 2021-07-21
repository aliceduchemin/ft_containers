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
		VectorIterator() : _nodePtr(NULL) { };
		VectorIterator(pointer nodePtr) : _nodePtr(nodePtr) { };
		VectorIterator<T> & operator=(VectorIterator<T> const & other)
			{ _nodePtr = other._nodePtr; return *this; };
		VectorIterator(VectorIterator<T> const & other)
			{ *this = other; };
		~VectorIterator() {};
	
		/********* ITERATORS *********/
		VectorIterator	operator++(int) //i++
			{ VectorIterator tmp(*this); operator++(); return tmp; };
		VectorIterator &	operator++() //++i
			{ this->_nodePtr++; return *this; }
		VectorIterator	operator--(int)
			{ VectorIterator tmp(*this); operator--(); return tmp; };
		VectorIterator &	operator--()
			{ this->_nodePtr--; return *this; }

		reference operator*() const
			{ return *this->_nodePtr; };
		pointer operator->() 
			{ return *this->_nodePtr; };
		bool operator!=(VectorIterator const & other) const
			{ return this->_nodePtr != other._nodePtr; };
		bool operator==(VectorIterator const & other) const
			{ return this->_nodePtr == other._nodePtr; };
		
		difference_type operator +(VectorIterator other)
			{ return (this->_nodePtr + other._nodePtr); };
		difference_type operator -(VectorIterator other)
			{ return (this->_nodePtr - other._nodePtr); };
		friend VectorIterator operator+(VectorIterator const & other, int n)
			{ return (other._nodePtr + n); };
		friend VectorIterator operator+(int n, VectorIterator const & other)
			{ return (n + other._nodePtr); };
		friend VectorIterator operator-(VectorIterator const & other, int n)
			{ return (other._nodePtr - n); };

		/********* RANDOM ACCESS ITERATORS *********/
		bool operator<(VectorIterator const & other) const
			{ return this->_nodePtr < other._nodePtr; };
		bool operator<=(VectorIterator const & other) const
			{ return this->_nodePtr <= other._nodePtr; };
		bool operator>(VectorIterator const & other) const
			{ return this->_nodePtr > other._nodePtr; };
		bool operator>=(VectorIterator const & other) const
			{ return this->_nodePtr >= other._nodePtr; };

		/********* GET SET *********/
	//	pointer		getNodePtr() const { return _nodePtr; };
	//	void		setNodePtr(pointer *nodePtr) { _nodePtr = nodePtr; };

		private:
			pointer	_nodePtr;
	};
}

#endif