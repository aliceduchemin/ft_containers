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

#include "node.hpp"

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
		
		ListIterator() : _nodePtr(NULL) { /*std::cout << "ite default constr\n";*/ };
		ListIterator(listNode<T> *node) : _nodePtr(node) { /*std::cout << "ite constr\n";*/ };
		ListIterator	operator++(int) 
		{ if (this->_nodePtr->_nxtNode)
			this->_nodePtr = this->_nodePtr->_nxtNode;
		return *this; };
		reference operator* (void) { return this->_nodePtr->_node; }

	//	private:
			listNode<T>	*_nodePtr;
	};
}

#endif