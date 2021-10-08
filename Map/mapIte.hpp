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

namespace ft
{
/*	template < class Category,		//iterator::iterator_category
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

	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	template<typename _Tp, _Tp __v>
	struct integral_constant
	{
		static constexpr _Tp				value = __v;
		typedef _Tp							value_type;
		typedef integral_constant<_Tp, __v>	type;
		constexpr operator value_type() const noexcept { return value; }
		constexpr value_type operator()() const noexcept { return value; }
	};

	template<class T>
	struct is_integral : public integral_constant<bool, __is_integral(T)> {};

	template < class Iterator >
	struct iterator_traits {
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
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

	template < class T >
	struct iterator_traits<const T*> {
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef random_access_iterator_tag		iterator_category;
	};
*/
	template <class Key, class T>
	class map_random_access_iterator
	{
		public:
			typedef ft::pair<Key, T>				value_type;
			typedef ft::pair<Key, T>&				reference;
			typedef ft::pair<Key, T>*				pointer;
			typedef ft::tree_node<Key, T>*			nodePtr;
			typedef ft::BinarySearchTree<Key, T>*	bstree;
			typedef ptrdiff_t						difference_type;
		
		/********* COPLIEN *********/
		// copy-constructible, copy-assignable and destructible (Forward : default-constructible)
		map_random_access_iterator() : _rootTree(0), _nodePtr(0) { };
		map_random_access_iterator(bstree root, nodePtr node) : _rootTree(root), _nodePtr(node) { };
		map_random_access_iterator<Key, T> & operator=(map_random_access_iterator<Key, T> const & other)
			{ _rootTree = other._rootTree; _nodePtr = other._nodePtr; return *this; };
		map_random_access_iterator(map_random_access_iterator<Key, T> const & other)
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
			{/* std::cout << "node to decrement = " << this->_nodePtr->data.first<<std::endl;
			*/this->_nodePtr = _rootTree->inorderPredecessor(this->_nodePtr);
				return *this; }
		map_random_access_iterator	operator--(int)
			{ map_random_access_iterator tmp(*this); operator--(); return tmp; };
		//*a--

		/********* GETTERS *********/
		bstree		getRootTree() const
		{	return this->_rootTree;	};

		nodePtr		getNodePtr() const
		{	return this->_nodePtr;	};

		private:
			nodePtr	_nodePtr;
			bstree	_rootTree;
	};

	/*********** CONST ITERATOR ***********/
	template <class Key, class T>
	class const_map_random_access_iterator
	{
		public:
			typedef ft::pair<Key, T>				value_type;
			typedef ft::pair<Key, T>&				reference;
			typedef ft::pair<Key, T>*				pointer;
			typedef ft::tree_node<Key, T>*			nodePtr;
			typedef ft::BinarySearchTree<Key, T>*	bstree;
			typedef ptrdiff_t						difference_type;
		
		/********* COPLIEN *********/
		const_map_random_access_iterator() : _rootTree(0), _nodePtr(0) { };
		const_map_random_access_iterator(bstree root, nodePtr node) : _rootTree(root), _nodePtr(node) { };
		const_map_random_access_iterator<Key, T> & operator=(const_map_random_access_iterator<Key, T> const & other)
			{ _rootTree = other._rootTree; _nodePtr = other._nodePtr; return *this; };
		const_map_random_access_iterator<Key, T> & operator=(map_random_access_iterator<Key, T> const & other)
			{ _rootTree = other.getRootTree(); _nodePtr = other.getNodePtr(); return *this; };
		const_map_random_access_iterator(const_map_random_access_iterator<Key, T> const & other)
			{ *this = other; };
		const_map_random_access_iterator(map_random_access_iterator<Key, T> const & other)
			{ *this = other; };
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
			{
				this->_nodePtr = _rootTree->inorderPredecessor(this->_nodePtr);
					return *this;
			};
		
		bool operator==(const_map_random_access_iterator const & other) const
			{ return this->_nodePtr == other._nodePtr; };
		bool operator!=(const_map_random_access_iterator const & other) const
			{ return this->_nodePtr != other._nodePtr; };
		bool operator!=(value_type const & other) const
			{ return this->_nodePtr->data != other; };
		reference operator*() const
			{ return this->_nodePtr->data; };
		pointer operator->() 
			{ return &this->_nodePtr->data; };

		private:
			nodePtr	_nodePtr;
			bstree	_rootTree;
	};

	/*********** REVERSE ITERATOR ***********/
	template <class map_random_access_iterator>
	class map_reverse_iterator
	{
		public:
			typedef	map_random_access_iterator					iterator_type;
			typedef typename iterator_type::value_type			value_type;
			typedef typename iterator_type::reference			reference;
			typedef typename iterator_type::pointer				pointer;
			typedef typename iterator_type::nodePtr				nodePtr;
			typedef typename iterator_type::bstree				bstree;
			typedef typename iterator_type::difference_type		difference_type;
		
		/********* COPLIEN *********/
		map_reverse_iterator() : _it() {};
		map_reverse_iterator(pointer other) : _it(other) {};
		explicit map_reverse_iterator (iterator_type other) : _it(other) {};
		map_reverse_iterator & operator=(map_reverse_iterator const & other)
			{ _it = other._it; return *this; };
		map_reverse_iterator(map_reverse_iterator const & other)
			{ *this = other; };
		~map_reverse_iterator() {};
	
		/********* ITERATORS *********/
		iterator_type base() const { return _it; };
		map_reverse_iterator &	operator++() //++i
			{ this->_it--; return *this; }
		map_reverse_iterator	operator++(int) //i++
			{ map_reverse_iterator tmp(*this); operator++(); return tmp; };
		map_reverse_iterator &	operator--()
			{ this->_it++; return *this; }
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
	
		private:
			iterator_type _it;
	};

	/*********** CONST REVERSE ITERATOR ***********/
	template <class map_random_access_iterator>
	class const_map_reverse_iterator : ft::map_reverse_iterator<map_random_access_iterator>
	{
		public:
			typedef	map_random_access_iterator					iterator_type;
			typedef typename iterator_type::value_type			value_type;
			typedef typename iterator_type::reference			reference;
			typedef typename iterator_type::pointer				pointer;
			typedef typename iterator_type::nodePtr				nodePtr;
			typedef typename iterator_type::bstree				bstree;
			typedef typename iterator_type::difference_type		difference_type;
		
		/********* COPLIEN *********/
		const_map_reverse_iterator() : _it() {};
		const_map_reverse_iterator(pointer other) : _it(other) {};
		explicit const_map_reverse_iterator (iterator_type other) : _it(other) {};
		const_map_reverse_iterator & operator=(const_map_reverse_iterator const & other)
			{ _it = other._it; return *this; };
		const_map_reverse_iterator(const_map_reverse_iterator const & other)
			{ *this = other; };
		~const_map_reverse_iterator() {};
	
		/********* ITERATORS *********/
		iterator_type base() const { return _it; };
		const_map_reverse_iterator &	operator++() //++i
			{ this->_it--; return *this; }
		const_map_reverse_iterator	operator++(int) //i++
			{ const_map_reverse_iterator tmp(*this); operator++(); return tmp; };
		const_map_reverse_iterator &	operator--()
			{ this->_it++; return *this; }
		const_map_reverse_iterator	operator--(int)
			{ const_map_reverse_iterator tmp(*this); operator--(); return tmp; };

		bool operator==(const_map_reverse_iterator const & other) const
			{ return this->_it == other._it; };
		bool operator!=(const_map_reverse_iterator const & other) const
			{ return this->_it != other._it; };
		reference operator*() const
			{ iterator_type tmp(this->_it); tmp--; return *tmp; };
		pointer operator->() 
			{ iterator_type tmp(this->_it); tmp--; return tmp.operator->(); };
	
		private:
			iterator_type _it;
	};
}
#endif