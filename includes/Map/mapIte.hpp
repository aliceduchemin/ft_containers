/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIte.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:59:17 by aduchemi          #+#    #+#             */
/*   Updated: 2021/05/19 11:59:23 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAPITE_HPP__
# define __MAPITE_HPP__

#include "../utils.hpp"

namespace ft
{
	template <class Key,
			  class T,
			  class Node = ft::tree_node< ft::pair<Key, T> >,
			  class Allocator = std::allocator<Node> >
	class map_random_access_iterator
	{
		public:
			typedef ft::pair<Key, T>				value_type;
			typedef Allocator						allocator_type;
			typedef value_type&						reference;
			typedef value_type*						pointer;
			typedef ft::tree_node<value_type>		node;
			typedef ft::tree_node<value_type>*		nodePtr;
			typedef ft::BinarySearchTree<value_type>*	bstree;
			typedef std::ptrdiff_t					difference_type;
		
		/********* COPLIEN *********/
		// copy-constructible, copy-assignable and destructible (Forward : default-constructible)
		map_random_access_iterator(const allocator_type& alloc = allocator_type()) : _nodePtr(), _rootTree()
		{	this->_allocator = alloc;	};

		map_random_access_iterator(bstree root, nodePtr node, const allocator_type& alloc = allocator_type()) : _nodePtr(node), _rootTree(root)
		{	this->_allocator = alloc;	};

		map_random_access_iterator<Key, T, node, Allocator> & operator=(map_random_access_iterator<Key, T, node, Allocator> const & other)
		{ _nodePtr = other._nodePtr; _rootTree = other._rootTree; return *this; };

		map_random_access_iterator(map_random_access_iterator<Key, T, node, Allocator> const & other)
		{ *this = other; };

		~map_random_access_iterator() {};
	
		/********* ITERATORS *********/
		// can be incremented
		map_random_access_iterator	operator++(int) //i++
		{ map_random_access_iterator tmp(*this); operator++(); return tmp; };

		map_random_access_iterator &operator++() //++i
		{	
			if (this->_nodePtr == this->_rootTree->_biggestNode)
				this->_nodePtr = this->_nodePtr->right;
			else
				this->_nodePtr = _rootTree->inorderSuccessor(this->_nodePtr);
			return *this;
		};
		
		/********* INPUT ITERATORS *********/
		// Supports equality/inequality comparisons
		bool operator==(map_random_access_iterator const & other) const
		{ return this->_nodePtr == other._nodePtr; };

		bool operator!=(map_random_access_iterator const & other) const
		{ return this->_nodePtr != other._nodePtr; };

		bool operator!=(value_type const & other) const
		{ return this->_nodePtr->data != other; };

		// Can be dereferenced as an rvalue
		reference operator*() const
		{ return this->_nodePtr->data; };

		pointer operator->() const
		{ return &this->_nodePtr->data; };

		/********* BIDIRECTIONAL ITERATORS *********/
		// Can be decremented
		map_random_access_iterator &	operator--()
		{
			if (this->_nodePtr == this->_rootTree->_smallestNode)
				this->_nodePtr = this->_nodePtr->left;
			else
				this->_nodePtr = _rootTree->inorderPredecessor(this->_nodePtr);
			return *this;
		};

		map_random_access_iterator	operator--(int)
		{ map_random_access_iterator tmp(*this); operator--(); return tmp; };
		//*a--

		/********* GETTERS *********/
		bstree		getRootTree() const
		{	return this->_rootTree;	};

		nodePtr		getNodePtr() const
		{	return this->_nodePtr;	};

		private:
			nodePtr			_nodePtr;
			bstree			_rootTree;
			allocator_type	_allocator;
	};

	/*********** CONST ITERATOR ***********/
	template <class Key,
			  class T,
			  class Node = ft::tree_node<ft::pair<Key, T> >,
			  class Allocator = std::allocator<Node> >
	class const_map_random_access_iterator
	{
		public:
			typedef ft::pair<Key, T>				value_type;
			typedef Allocator						allocator_type;
			typedef value_type&						reference;
			typedef value_type*						pointer;
			typedef ft::tree_node<value_type>		node;
			typedef ft::tree_node<value_type>*		nodePtr;
			typedef ft::BinarySearchTree<value_type>*	bstree;
			typedef std::ptrdiff_t						difference_type;
		
		/********* COPLIEN *********/
		const_map_random_access_iterator(const allocator_type& alloc = allocator_type()) :  _nodePtr(0), _rootTree(0)
		{	this->_allocator = alloc;	};

		const_map_random_access_iterator(const bstree root, const nodePtr node, const allocator_type& alloc = allocator_type()) : _nodePtr(node), _rootTree(root)
		{	this->_allocator = alloc;	};

		const_map_random_access_iterator<Key, T, node, Allocator> & operator=(const_map_random_access_iterator<Key, T, node, Allocator> const & other)
		{	_nodePtr = other._nodePtr; _rootTree = other._rootTree; return *this; };

		const_map_random_access_iterator<Key, T, node, Allocator> & operator=(map_random_access_iterator<Key, T, node, Allocator> const & other)
		{	_nodePtr = other.getNodePtr(); _rootTree = other.getRootTree(); return *this; };

		const_map_random_access_iterator(const_map_random_access_iterator<Key, T, node, Allocator> const & other)
		{	*this = other; };

		const_map_random_access_iterator(map_random_access_iterator<Key, T, node, Allocator> const & other)
		{	*this = other; };

		~const_map_random_access_iterator() {};
	
		/********* ITERATORS *********/
		const_map_random_access_iterator	operator++(int) //i++
		{ const_map_random_access_iterator tmp(*this); operator++(); return tmp; };

		const_map_random_access_iterator &operator++() //++i
		{	
			if (this->_nodePtr == this->_rootTree->_biggestNode)
				this->_nodePtr = this->_nodePtr->right;
			else
				this->_nodePtr = _rootTree->inorderSuccessor(this->_nodePtr);
			return *this; 
		};

		const_map_random_access_iterator	operator--(int)
		{ const_map_random_access_iterator tmp(*this); operator--(); return tmp; };

		const_map_random_access_iterator &	operator--()
		{	this->_nodePtr = _rootTree->inorderPredecessor(this->_nodePtr); return *this;	};
		
		bool operator==(const_map_random_access_iterator const & other) const
		{ return this->_nodePtr == other._nodePtr; };

		bool operator!=(const_map_random_access_iterator const & other) const
		{ return this->_nodePtr != other._nodePtr; };

		bool operator!=(value_type const & other) const
		{ return this->_nodePtr->data != other; };

		reference operator*() const
		{ return this->_nodePtr->data; };

		pointer operator->() const
		{ return &this->_nodePtr->data; };

		private:
			nodePtr	_nodePtr;
			bstree	_rootTree;
			allocator_type	_allocator;
	};

	/*********** REVERSE ITERATOR ***********/
	template <class Iterator>
	class map_reverse_iterator
	{
		public:
			typedef	Iterator									iterator_type;
			typedef typename iterator_type::value_type			value_type;
			typedef typename iterator_type::reference			reference;
			typedef typename iterator_type::pointer				pointer;
			typedef typename iterator_type::nodePtr				nodePtr;
			typedef typename iterator_type::bstree				bstree;
			typedef typename iterator_type::difference_type		difference_type;
		
		/********* COPLIEN *********/
		map_reverse_iterator() : _it() {};

		explicit map_reverse_iterator (iterator_type other) : _it(other) {};

		template <class Iter>
		map_reverse_iterator(const map_reverse_iterator<Iter>& rev_it)
		{	*this = rev_it._it;	};

		template <class Iter>
		map_reverse_iterator& operator=(const map_reverse_iterator<Iter>& rev_it)
		{	_it = rev_it._it; return *this;	};

		~map_reverse_iterator() {};
	
		/********* ITERATORS *********/
		iterator_type base() const { return _it; };
		map_reverse_iterator &	operator++() //++i
		{ this->_it--; return *this; };

		map_reverse_iterator	operator++(int) //i++
		{ map_reverse_iterator tmp(*this); operator++(); return tmp; };

		map_reverse_iterator &	operator--()
		{ this->_it++; return *this; };

		map_reverse_iterator	operator--(int)
		{ map_reverse_iterator tmp(*this); operator--(); return tmp; };

		bool operator==(map_reverse_iterator const & other) const
		{ return this->_it == other._it; };

		bool operator!=(map_reverse_iterator const & other) const
		{ return this->_it != other._it; };

		reference operator*() const
		{ iterator_type tmp(this->_it); tmp--; return *tmp; };

		pointer operator->() 
		{ iterator_type tmp(this->_it); tmp--; return tmp.operator->(); };

		iterator_type getNodePtr() const
		{ iterator_type tmp(this->_it); tmp--; return tmp; };
	
		private:
			iterator_type _it;
	};

	/*********** CONST REVERSE ITERATOR ***********/
	template <class Iterator>
	class const_map_reverse_iterator : ft::map_reverse_iterator<Iterator>
	{
		public:
			typedef	Iterator									iterator_type;
			typedef typename iterator_type::value_type			value_type;
			typedef typename iterator_type::reference			reference;
			typedef typename iterator_type::pointer				pointer;
			typedef typename iterator_type::nodePtr				nodePtr;
			typedef typename iterator_type::bstree				bstree;
			typedef typename iterator_type::difference_type		difference_type;
		
		/********* COPLIEN *********/
		const_map_reverse_iterator() : _it() {};

		explicit const_map_reverse_iterator (iterator_type other) : _it(other) {};

		template <class Iter>
		const_map_reverse_iterator(const const_map_reverse_iterator<Iter>& rev_it)
		{	*this = rev_it._it;	};

		template <class Iter>
		const_map_reverse_iterator(const map_reverse_iterator<Iter>& rev_it)
		{	_it = rev_it.getNodePtr();	};

		template <class Iter>
		const_map_reverse_iterator& operator=(const const_map_reverse_iterator<Iter>& rev_it)
		{	_it = rev_it._it; return *this;	};

		template <class Iter>
		const_map_reverse_iterator& operator=(const map_reverse_iterator<Iter>& rev_it)
		{	_it = rev_it.getNodePtr(); return *this;	};

		const_map_reverse_iterator(pointer other) : _it(other) {};

		~const_map_reverse_iterator() {};
	
		/********* ITERATORS *********/
		iterator_type base() const { return _it; };

		const_map_reverse_iterator &	operator++() //++i
		{ this->_it--; return *this; };

		const_map_reverse_iterator	operator++(int) //i++
		{ const_map_reverse_iterator tmp(*this); operator++(); return tmp; };

		const_map_reverse_iterator &	operator--()
		{ this->_it++; return *this; };

		const_map_reverse_iterator	operator--(int)
		{ const_map_reverse_iterator tmp(*this); operator--(); return tmp; };

		bool operator==(const_map_reverse_iterator const & other) const
		{ return this->_it == other._it; };

		bool operator!=(const_map_reverse_iterator const & other) const
		{ return this->_it != other._it; };

		reference operator*() const
		{ iterator_type tmp(this->_it); return *tmp; };

		pointer operator->() 
		{ iterator_type tmp(this->_it); return tmp.operator->(); };
	
		private:
			iterator_type _it;
	};
}
#endif