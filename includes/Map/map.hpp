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
#include "../utils.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <limits>

namespace ft
{
	template <class Key,													// map::key_type
			  class T,														// map::mapped_type
			  class Compare = std::less<Key>,								// map::key_compare
			  class Allocator = std::allocator<ft::pair<Key,T> > >	// map::allocator_type

	class	map
	{
		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<key_type, mapped_type>			value_type;
			typedef Compare									key_compare;
			typedef Allocator 								allocator_type;
			typedef typename Allocator::reference 			reference;
			typedef typename Allocator::const_reference 	const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef typename Allocator::difference_type 	difference_type;
			typedef typename Allocator::size_type 			size_type;
			
			typedef ft::tree_node<value_type>				node;
			typedef node*									nodePtr;
			typedef ft::BinarySearchTree<value_type>		bstree;

			typedef ft::map_random_access_iterator<Key, T, node, Allocator>			iterator;
			typedef ft::const_map_random_access_iterator<Key, T, node, Allocator>	const_iterator;
			typedef ft::map_reverse_iterator<iterator>								reverse_iterator;
			typedef ft::const_map_reverse_iterator<iterator>						const_reverse_iterator;
			
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
			{	
				this->_comp = comp;
				this->_number = 0;
				this->_allocator = alloc;
			};

			template< class InputIterator >
			map(InputIterator first, InputIterator last, 
				const key_compare& comp = key_compare(), 
				const allocator_type& alloc = allocator_type())
			{	
				this->_comp = comp;
				this->_number = 0;
				this->_allocator = alloc;
				this->insert(first, last);
			};

			map(map const & other)
			{	
				this->_number = 0;
				*this = other;
			};

			map & operator=(map const & other)
			{
				this->_comp = other._comp;
				this->_allocator = other._allocator;
				this->clear();
				this->insert(other.begin(), other.end());
				return *this;
			};

			~map()
			{	
				this->clear(); 
			};

			/********* ITERATORS *********/
			iterator 				begin() 
			{	return iterator(&_tree, _tree._smallestNode); };

			const_iterator	 		begin() const
			{	return const_iterator(const_cast<bstree*>(&_tree), _tree._smallestNode); };

			iterator				end()
			{
				if (this->empty())
					return iterator(&_tree, _tree._smallestNode);
				return iterator(&_tree, _tree._lastNode);
			};

			const_iterator			end() const
			{
				if (this->empty())
					return const_iterator(const_cast<bstree*>(&_tree), _tree._smallestNode);
				return const_iterator(const_cast<bstree*>(&_tree), _tree._lastNode);
			};

			reverse_iterator 		rbegin()
			{
				if (this->empty())
					return reverse_iterator(iterator(&_tree, _tree._smallestNode));
				return reverse_iterator(iterator(&_tree, _tree._lastNode));
			};

			const_reverse_iterator 	rbegin() const
			{
				if (this->empty())
					return const_reverse_iterator(const_iterator(&_tree, _tree._smallestNode));
				return const_reverse_iterator(const_iterator(&_tree, _tree._lastNode));
			};

			reverse_iterator 		rend() 
			{	return reverse_iterator(iterator(&_tree, _tree._smallestNode));	};

			const_reverse_iterator 	rend() const
			{	return const_reverse_iterator(const_iterator(&_tree, _tree._smallestNode));	};

			/********* CAPACITY *********/
			bool		empty() const { return (this->size() == 0); };

			size_type	size() const { return this->_number; };

			size_type	max_size() const
			{	return std::numeric_limits<difference_type>::max() / (sizeof(tree_node<value_type>) ?: 1); };
		
			/********* ELEMENT ACCESS *********/
			mapped_type&	operator[] (const key_type& k)
			{
				if (this->empty() == false)
				{
					iterator	tmp = this->find(k);
					if (tmp != this->end())
						return tmp->second;
				}
				return (*((this->insert(ft::make_pair(k,mapped_type()))).first)).second;
			};

			/********* MODIFIERS *********/
			ft::pair<iterator, bool>	insert(const value_type& val)
			{	
				iterator	tmp;
				if (this->empty() == false)
				{	
					tmp = this->find(val.first);
					if (tmp != this->end())
						return ft::make_pair(tmp, false);
				}
				this->_tree.insert(val);
				tmp = this->begin();
				while (tmp != val)
					tmp++;
				this->_number++;
				return ft::make_pair(tmp, true);
			};
			
			iterator 					insert(iterator position, const value_type& val)
			{	
				(void)position;
				return (this->insert(val)).first;
			};

			template < class InputIterator >
			void						insert(InputIterator first, InputIterator last)
			{	
				while (first != last) {
					this->insert(*first++); }
			};

			void						erase(iterator position)
			{
				iterator it = this->begin();
				while (it != position)
					it++;
				this->_number--;
				this->_tree.remove(ft::make_pair(it->first, mapped_type()));
			};

			size_type					erase(const key_type& k)
			{	
				if (this->empty() == false)
				{
					if (this->find(k) == this->end())
						return 0;
				}
				this->_tree.remove(ft::make_pair(k, mapped_type()));
				this->_number--;
				return 1;
			};

			void						erase(iterator first, iterator last)
			{	
				size_t length = 0;
				iterator tmp = last;
				tmp--;
				while (first != last) {first++; length++;}
				
				while (length)
				{
					this->_tree.remove(ft::make_pair(tmp->first, mapped_type()));
					tmp = last;
					tmp--;
					this->_number--;
					length--;
				}
			};

			void						swap(map& x)
			{
				ft::ft_swap(this->_allocator, x._allocator);
				ft::ft_swap(this->_number, x._number);
				ft::ft_swap(this->_tree, x._tree);
				ft::ft_swap(this->_comp, x._comp);
			};

			void						clear()
			{
				if (this->empty() == false)
				{
					size_t i = 0;
					while (this->begin() != this->end())
					{
						this->_tree.remove(ft::make_pair(this->begin()->first, mapped_type()));
						this->_number--;
						i++;
					}
					this->_tree.removeExtremNodes();
				}
			};

			/********* OBSERVERS *********/
			key_compare		key_comp() const {	return this->_comp;	};
			
			value_compare	value_comp() const {	return value_compare(this->_comp);	};

			/********* OPERATIONS *********/
			iterator								find(const key_type& k)
			{	
				nodePtr	tmp = this->_tree.findNode(ft::make_pair(k, mapped_type()));
				return iterator(&_tree, tmp);
			};

			const_iterator							find(const key_type& k) const
			{
				nodePtr	tmp = this->_tree.findNode(ft::make_pair(k, mapped_type()));
				return const_iterator(const_cast<bstree*>(&_tree), tmp);
			};
		
			size_type								count(const key_type& k) const
			{	
				if (this->find(k) != this->end())
					return 1;
				return 0;
			};
		
			iterator								lower_bound(const key_type& k)
			{
				iterator it = this->begin();
				while (it != this->end() && _comp(it->first, k))
					it++;
				return it;
			};

			const_iterator							lower_bound(const key_type& k) const
			{
				const_iterator it = this->begin();
				while (it != this->end() && _comp(it->first, k))
					it++;
				return it;
			};
			
			iterator								upper_bound(const key_type& k)
			{
				iterator it = this->begin();
				while (it != this->end() && !_comp(k, it->first))
					it++;
				return it;
			};

			const_iterator							upper_bound(const key_type& k) const
			{
				const_iterator it = this->begin();
				while (it != this->end() && !_comp(k, it->first))
					it++;
				return it;
			};
		
			ft::pair<iterator, iterator>				equal_range(const key_type& k)
			{	return ft::make_pair(this->lower_bound(k), this->upper_bound(k));	};
	
			ft::pair<const_iterator, const_iterator>	equal_range(const key_type& k) const
			{	return ft::make_pair(this->lower_bound(k), this->upper_bound(k));	};

			/********* ALLOCATOR *********/
			allocator_type	get_allocator() const
			{	return this->_allocator;	};

		private:
			bstree			_tree;
			key_compare		_comp;
			allocator_type	_allocator;
			size_type		_number;
	};

	template< class Key, class T, class Compare, class Allocator >
	bool	operator==(const ft::map<Key, T, Compare, Allocator>& lhs,
						const ft::map<Key, T, Compare, Allocator>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;

		typename map<Key, T, Compare, Allocator>::const_iterator lhsFirst = lhs.begin();
		typename map<Key, T, Compare, Allocator>::const_iterator rhsFirst = rhs.begin();
		while (lhsFirst != lhs.end())
		{
			if (*lhsFirst != *rhsFirst)
				return false;
			++lhsFirst;
			++rhsFirst;
		}
		return true;
	}

	template< class Key, class T, class Compare, class Allocator >
	bool	operator!=(const ft::map<Key, T, Compare, Allocator>& lhs,
						const ft::map<Key, T, Compare, Allocator>& rhs)
	{	return (!(lhs == rhs)) ? true : false;	}

	template< class Key, class T, class Compare, class Allocator >
	bool	operator<(const ft::map<Key, T, Compare, Allocator>& lhs,
						const ft::map<Key, T, Compare, Allocator>& rhs)
	{	return (lhs.size() < rhs.size()) ? true : false;	}

	template< class Key, class T, class Compare, class Allocator >
	bool	operator<=(const ft::map<Key, T, Compare, Allocator>& lhs,
						const ft::map<Key, T, Compare, Allocator>& rhs)
	{	return (lhs.size() <= rhs.size()) ? true : false;	}

	template< class Key, class T, class Compare, class Allocator >
	bool	operator>(const ft::map<Key, T, Compare, Allocator>& lhs,
						const ft::map<Key, T, Compare, Allocator>& rhs)
	{	return (lhs.size() > rhs.size()) ? true : false;	}

	template< class Key, class T, class Compare, class Allocator >
	bool	operator>=(const ft::map<Key, T, Compare, Allocator>& lhs,
						const ft::map<Key, T, Compare, Allocator>& rhs)
	{	return (lhs.size() >= rhs.size()) ? true : false;	}
}
#endif