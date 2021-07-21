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
	template < class Category,		//iterator::iterator_category
			   class T,				//iterator::value_type
			   class Distance,		//iterator::difference_type
			   class Pointer,		//iterator::pointer
			   class Reference		//iterator::reference
			   > class iterator;

	template < class Category, class T, class Distance = ptrdiff_t,
			   class Pointer = T*, class Reference = T& >
		struct iterator {
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
		};

	template <class iterator> struct iterator_traits;
	template <class T> struct iterator_traits<T*>;
	template <class T> struct iterator_traits<const T*>;

	template < class iterator >
	struct iterator_traits {
		typedef typename iterator::value_type			value_type;
		typedef typename iterator::difference_type		difference_type;
		typedef typename iterator::pointer				pointer;
		typedef typename iterator::reference			reference;
		typedef typename iterator::iterator_category	iterator_category;
	};

	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

	template < class T >
	struct iterator_traits<T*> {
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef random_access_iterator_tag		iterator_category;
	};

	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	template <class T>
	class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
		
		/********* COPLIEN *********/
		random_access_iterator() : _nodePtr(0) { };
		random_access_iterator(pointer nodePtr) : _nodePtr(nodePtr) { };
		random_access_iterator<T> & operator=(random_access_iterator<T> const & other)
			{ _nodePtr = other._nodePtr; return *this; };
		random_access_iterator(random_access_iterator<T> const & other)
			{ *this = other; };
		~random_access_iterator() {};
	
		/********* ITERATORS *********/
		random_access_iterator	operator++(int) //i++
			{ random_access_iterator tmp(*this); operator++(); return tmp; };
		random_access_iterator &	operator++() //++i
			{ this->_nodePtr++; return *this; }
		random_access_iterator	operator--(int)
			{ random_access_iterator tmp(*this); operator--(); return tmp; };
		random_access_iterator &	operator--()
			{ this->_nodePtr--; return *this; }

		reference operator*() const
			{ return *this->_nodePtr; };
		pointer operator->() 
			{ return *this->_nodePtr; };
		bool operator!=(random_access_iterator const & other) const
			{ return this->_nodePtr != other._nodePtr; };
		bool operator==(random_access_iterator const & other) const
			{ return this->_nodePtr == other._nodePtr; };
		
		difference_type operator +(random_access_iterator other)
			{ return (this->_nodePtr + other._nodePtr); };
		difference_type operator -(random_access_iterator other)
			{ return (this->_nodePtr - other._nodePtr); };
		friend random_access_iterator operator+(random_access_iterator const & other, int n)
			{ return (other._nodePtr + n); };
		friend random_access_iterator operator+(int n, random_access_iterator const & other)
			{ return (n + other._nodePtr); };
		friend random_access_iterator operator-(random_access_iterator const & other, int n)
			{ return (other._nodePtr - n); };

		/********* RANDOM ACCESS ITERATORS *********/
		bool operator<(random_access_iterator const & other) const
			{ return this->_nodePtr < other._nodePtr; };
		bool operator<=(random_access_iterator const & other) const
			{ return this->_nodePtr <= other._nodePtr; };
		bool operator>(random_access_iterator const & other) const
			{ return this->_nodePtr > other._nodePtr; };
		bool operator>=(random_access_iterator const & other) const
			{ return this->_nodePtr >= other._nodePtr; };

		private:
			pointer	_nodePtr;
	};
}

#endif