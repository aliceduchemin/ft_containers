/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:05:58 by aduchemi          #+#    #+#             */
/*   Updated: 2021/05/10 15:05:59 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIST_HPP__
# define __LIST_HPP__

#include <memory>
#include "node.hpp"
#include "listIte.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class	list//<T, Allocator>
	{
		public:
			typedef Allocator 							allocator_type;
			typedef typename Allocator::size_type 		size_type;
			typedef typename Allocator::difference_type difference_type;
			typedef typename Allocator::reference 		reference;
			typedef typename Allocator::const_reference const_reference;
			typedef ft::ListIterator<T>					iterator;
		
			list();
			list(list & other);
			list &	operator=(list & other);
			~list();
			template <class ListIterator>
			list(ListIterator start, ListIterator finish, Allocator alloc = Allocator());

			listNode<T>	*_headNode;
			int			_number;
			iterator begin() { return ListIterator<T>(_headNode); };
			iterator end() { 
				ListIterator<T> tmp = ListIterator<T>(_headNode);
				int count = 1;
				tmp = _headNode;
				while (count < _number)
				{
					tmp = tmp._nodePtr->_nxtNode;
					count++;
				}
				tmp = tmp._nodePtr->_nxtNode;
				tmp = NULL;
				return tmp; };

			T*		clone() const;
			void	clear();
			bool	empty();
			int		size() const; //size
			int		push_back(T newNode);
			void	pop_back();
	};

	template< typename T, typename Allocator >
	list<T, Allocator>::list()
	{
	//	std::cout << "list default constructor" << std::endl;
		_number = 0;
	}
	
	template< typename T, typename Allocator >
	void	list<T, Allocator>::clear()
	{
		int			count;
		int			total;

		total = _number;
		count = 1;
		while (count <= total)
		{
			this->pop_back();
			count++;
		}
	}

	template< typename T, typename Allocator >
	bool	list<T, Allocator>::empty()
	{
		if (_number == 0)
			return true;
		return false;
	}
	
	template< typename T, typename Allocator >
	list<T, Allocator>::~list()
	{
	//	std::cout << "list destructor, number = " << _number << std::endl;
		if (_headNode)
			this->clear();
	}


	template< typename T, typename Allocator >
	list<T, Allocator>::list(list<T, Allocator> & other)
	{
		_number = 0;
		*this = other;
	}

	template< typename T, typename Allocator >
	list<T, Allocator> &	list<T, Allocator>::operator=(list<T, Allocator> & other)
	{
		int		i;

		if (_headNode)
			this->clear();

		iterator it = other.begin();
		i = 0;
		while (i < other.size())
		{
			this->push_back(*it);
			it++;
			i++;
		}
		_number = other.size();
		return *this;
	}

	template< typename T, typename Allocator >
	int	list<T, Allocator>::size() const
	{
		return _number;
	}

	template< typename T, typename Allocator >
	int		list<T, Allocator>::push_back(T newNode)
	{
		listNode<T>	*tmp;

		if (_number == 0)
		{
			_headNode = new listNode<T>;
			_headNode->_node = newNode;
			_headNode->_nxtNode = NULL;
		}
		else
		{
			tmp = _headNode;
			while (tmp->_nxtNode)
				tmp = tmp->_nxtNode;
			tmp->_nxtNode = new listNode<T>;
			tmp->_nxtNode->_node = newNode;
			tmp->_nxtNode->_nxtNode = NULL;
		}
		_number++;
		return _number;
	}

	template< typename T, typename Allocator >
	void	list<T, Allocator>::pop_back()
	{
		listNode<T>		*tmp;
		int				count;

		count = 1;
		if (_number == 1)
			delete _headNode;
		else
		{
			tmp = _headNode;
			while (count < _number - 1)
			{
				_headNode = _headNode->_nxtNode;
				count++;
			}
			_headNode->_nxtNode = NULL;
			_headNode = tmp;
		}
		_number--;
	}

	//std::ostream & operator<<(std::ostream & o, typename ft::list<int>::t_list const & to_print)
/*	std::ostream & operator<<(std::ostream & o, typename ft::list<int>::iterator const & to_print)
	{
		return o << to_print._node;
	}*/
}

#endif
