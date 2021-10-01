/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:05:58 by aduchemi          #+#    #+#             */
/*   Updated: 2021/05/10 15:05:59 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_HPP__
# define __MAP_HPP__

#include <memory>
#include "mapIte.hpp"
#include "pair.hpp"
#include "utils.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <limits>

namespace ft
{
	template <class Key,													// map::key_type
			  class T,														// map::mapped_type
			  class Compare = std::less<Key>,								// map::key_comapre
			  class Allocator = std::allocator<ft::pair<const Key,T> > >	// map::allocator_type
	class	map
	{
		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef Compare									key_compare;
			typedef Allocator 								allocator_type;
			typedef typename Allocator::reference 			reference;
			typedef typename Allocator::const_reference 	const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef typename Allocator::difference_type 	difference_type;
			typedef typename Allocator::size_type 			size_type;
			
			typedef ft::BinarySearchTree<Key, T>			bstree;

			typedef ft::map_random_access_iterator<Key, T>	iterator;
		//	typedef ft::const_random_access_iterator<T>		const_iterator;
		//	typedef ft::reverse_iterator<iterator>			reverse_iterator;
		//	typedef ft::const_reverse_iterator<iterator>	const_reverse_iterator;
			class value_compare
			{
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) :comp(c) {} // constructed with map's comparison object
				public:
					typedef bool		result_type;
					typedef	value_type	first_argument_type;
					typedef	value_type	second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{	return comp(x.first, y.first);	}
			};

			/********* CONSTRUCTEURS *********/
			explicit map(const key_compare& comp = key_compare(), 
						const allocator_type& alloc = allocator_type())
				{	this->_comp = comp;
					this->_allocator = alloc;
					this->_tree = new ft::BinarySearchTree<Key, T>();
				//	this->_pair = ft::pair<Key, T>();
					this->_number = 0; };
			template< class InputIterator >
			map(InputIterator first, InputIterator last, 
				const key_compare& comp = key_compare(), 
				const allocator_type& alloc = allocator_type())
				{	this->_comp = comp;
					this->_allocator = alloc;
					this->_tree = ft::BinarySearchTree<Key, T>();
					this->_number = 0;
					this->insert(first, last); };
			map(map const & other) {};
			map & operator=(map const & other) {};
			~map() {};

			/********* ITERATORS *********/
			iterator 				begin() { return pointer(_headNode); };
		//	const_iterator	 		begin() const { return pointer(_headNode); };
		/*	iterator				end() { return pointer(_endNode + 1); };
			const_iterator			end() const { return pointer(_endNode + 1); };
			reverse_iterator 		rbegin() { return pointer(_endNode + 1); };
			const_reverse_iterator 	rbegin() const { return pointer(_endNode + 1); };
			reverse_iterator 		rend() { return pointer(_headNode); };
			const_reverse_iterator 	rend() const { return pointer(_headNode); };
*/
			/********* CAPACITY *********/
			bool		empty() const { return (_number == 0); };
			size_type	size() const { return _number; };
			size_type	max_size() const { return _allocator.max_size(); };
		
			/********* ELEMENT ACCESS *********/
			mapped_type&	operator[] (const key_type& k)
				{	value_type pair = ft::make_pair(k,mapped_type());
					this->_tree->insert(pair);
					this->_number++;
					return pair.second; };
			//	{ (*((this->insert(ft::make_pair(k,mapped_type()))).first)).second; };

			/********* MODIFIERS *********/
			ft::pair<iterator, bool>	insert(const value_type& val)
				{	this->_tree->insert(val);
					iterator it(this->_tree);
				//	while (*it != val)
				//		it++;
					return ft::make_pair(it, true); };
			
			iterator 					insert(iterator position, const value_type& val);
			template < class InputIterator >
			void						insert(InputIterator first, InputIterator last);
		/*	{	iterator ret = position;
				while (first != last)
				{
					ret = this->insert(ret, *first);
					first++;
				} };*/
			void						erase(iterator position);
			size_type					erase(const key_type& k);
			void						erase(iterator first, iterator last);
			void						swap(map& x);
			void						clear();

			/********* OBSERVERS *********/
			key_compare		key_comp() const;
			value_compare	value_comp() const;

			/********* OPERATIONS *********/
			iterator								find(const key_type& k);
		//	const_iterator							find(const key_type& k) const;
			size_type								count(const key_type& k) const;
			iterator								lower_bound(const key_type& k);
		//	const_iterator							lower_bound(const key_type& k) const;
			iterator								upper_bound(const key_type& k);
		//	const_iterator							upper_bound(const key_type& k) const;
		//	pair<const_iterator, const_iterator>	equal_range(const key_type& k) const;
			pair<iterator, iterator>				equal_range(const key_type& k);

			/********* ALLOCATOR *********/
			allocator_type	get_allocator() const;

		private:
			pointer			_headNode;
			pointer			_endNode;
			pointer			_container;	
		
			bstree*			_tree;
			key_compare		_comp;
		//	value_type		_pair;
			size_type		_number;
			allocator_type	_allocator;
	};

	/********* MODIFIERS *********/
/*	template< class Key, class T, class Compare, class Allocator >
	ft::random_access_iterator<Key, T>	map<Key, T, Compare, Allocator>::insert(iterator position, const value_type& val)
	{
	}

	template< class Key, class T, class Compare, class Allocator >
	void	map<Key, T, Compare, Allocator>::erase(iterator position)
	{
		
	}

	template< class Key, class T, class Compare, class Allocator >
	typename map<Key, T, Compare, Allocator>::size_type	
		map<Key, T, Compare, Allocator>::erase(const key_type& k)
	{
		
	}

	template< class Key, class T, class Compare, class Allocator >
	void	map<Key, T, Compare, Allocator>::erase(iterator first, iterator last)
	{
		
	}
		
	template< class Key, class T, class Compare, class Allocator >
	void	map<Key, T, Compare, Allocator>::clear()
	{
	
	}
*/
	/********* ALLOCATOR *********/
	template< class Key, class T, class Compare, class Allocator >
	Allocator	map<Key, T, Compare, Allocator>::get_allocator() const
	{
		return this->_allocator;
	}
}


template< class Key, class T, class Compare, class Allocator >
bool	operator==(const ft::map<Key, T, Compare, Allocator>& lhs,
					const ft::map<Key, T, Compare, Allocator>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	size_t i = 0;
	while (i < lhs.size())
	{
		if (lhs[i] != rhs[i])
			return false;
		i++;
	}
	return true;
}

template< class Key, class T, class Compare, class Allocator >
bool	operator!=(const ft::map<Key, T, Compare, Allocator>& lhs,
					const ft::map<Key, T, Compare, Allocator>& rhs)
{
	return (!(lhs == rhs)) ? true : false;
}

template< class Key, class T, class Compare, class Allocator >
bool	operator<(const ft::map<Key, T, Compare, Allocator>& lhs,
					const ft::map<Key, T, Compare, Allocator>& rhs)
{
	return (lhs.size() < rhs.size()) ? true : false;
}

template< class Key, class T, class Compare, class Allocator >
bool	operator<=(const ft::map<Key, T, Compare, Allocator>& lhs,
					const ft::map<Key, T, Compare, Allocator>& rhs)
{
	return (lhs.size() <= rhs.size()) ? true : false;
}

template< class Key, class T, class Compare, class Allocator >
bool	operator>(const ft::map<Key, T, Compare, Allocator>& lhs,
					const ft::map<Key, T, Compare, Allocator>& rhs)
{
	return (lhs.size() > rhs.size()) ? true : false;
}

template< class Key, class T, class Compare, class Allocator >
bool	operator>=(const ft::map<Key, T, Compare, Allocator>& lhs,
					const ft::map<Key, T, Compare, Allocator>& rhs)
{
	return (lhs.size() >= rhs.size()) ? true : false;
}

#endif