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
			~list();
			template <class ListIterator>
			list(ListIterator start, ListIterator finish, Allocator alloc = Allocator());

			listNode<T>	*_node;
		//	iterator begin() { return (iterator(_node->getNxt())); };
			iterator begin() { return ListIterator<T>(_node); };
			int	_number;
/*
			template <class Iterator>
			list(Iterator start, Iterator finish, Allocator alloc = Allocator());
			list(list const & other);
			list &	operator=(list const & other);
			iterator begin();
			iterator end();*/


		//	t_list				*_cont;
		//	t_list				*_it;
		//	typename ft::list<T>::t_list *	increment();
		//	typename ft::list<T, Allocator>::iterator	increment();
			

			T*		clone() const;
			void	clear();
			bool	empty();
			int		size() const; //size
			T*		getUnit(int) const; //iterate
			int		push_back(T newNode);
			void	pop_back();

		//	typedef typename std::list<T>::iterator iterator;
		//	ft::list<T>::t_list *	begin();
	};

	template< typename T, typename Allocator >
	list<T, Allocator>::list()
	{
		std::cout << "list default constructor" << std::endl;
		_number = 0;
	}

/*	template< typename T, typename Allocator >
	T*	list<T, Allocator>::clone() const
	{
		T* copy = new list<T>;

		return copy;
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
	
*/	template< typename T, typename Allocator >
	list<T, Allocator>::~list()
	{
		std::cout << "list destructor" << std::endl;
//		this->clear();
	}

/*	template< typename T, typename Allocator >
	list<T, Allocator>::list(list<T, Allocator> const & other)
	{
		*this = other;
	}

	template< typename T, typename Allocator >
	list<T, Allocator> &	list<T, Allocator>::operator=(list<T, Allocator> const & other)
	{
		int		i;

		if (_cont)
			this->clear();
		i = 0;
		while (i < other.size())
		{
			this->push_back(other.getUnit(i)->clone());
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
	T*	list<T, Allocator>::getUnit(int N) const
	{
		int			count;
		t_list		*tmp;

		tmp = _cont;
		count = 0;
		while (tmp->_nxtNode && count < N)
		{
			tmp = tmp->_nxtNode;
			count++;
		}
		if (count < N)
			return NULL;
		return tmp->_node;
	}

	template< typename T >
	bool	are_diff(T tmp, T newNode)
	{
		if (tmp == newNode)
			return false;
		return true;
	}*/

	template< typename T, typename Allocator >
	int		list<T, Allocator>::push_back(T newNode)
	{
		std::cout << "PUSH BACK number=" << _number <<std::endl;
	//	t_list		*tmp;
		listNode<T>	*tmp;

	//	if (newNode == 0)
	//		return _number;
		if (_number == 0)
		{
			std::cout << "PUSH BACK cond 0" <<std::endl;
			_node = new listNode<T>;
			_node->_node = newNode;
			_node->_nxtNode = NULL;
		}
		else
		{
			tmp = _node;
			while (tmp->_nxtNode)
				tmp = tmp->_nxtNode;
			tmp->_nxtNode = new listNode<T>;
			tmp->_nxtNode->_node = newNode;
			tmp->_nxtNode->_nxtNode = NULL;
		}
		_number++;
		std::cout << "number = " << _number << std::endl;
		return _number;
	}
/*
	template< typename T, typename Allocator >
	void	list<T, Allocator>::pop_back()
	{
		t_list		*tmp;
		int			count;

		count = 1;
		if (_number == 1)
			delete _cont;
		else
		{
			tmp = _cont;
			while (count < _number - 1)
			{
				_cont = _cont->_nxtNode;
				count++;
			}
			_cont->_nxtNode = NULL;
			_cont = tmp;
		}
		_number--;
	}

	template< typename T, typename Allocator >
	typename list<T, Allocator>::iterator	list<T, Allocator>::increment()
	{
		std::cout << "ici" << std::endl;
		if (_it->_nxtNode)
			_it = _it->_nxtNode;
		return iterator(_it);
	}

	template< typename T, typename Allocator >
	typename list<T, Allocator>::iterator	list<T, Allocator>::begin()
	{
		_it = _cont;
		return iterator(_it);
	}

	template< typename T, typename Allocator >
	typename list<T, Allocator>::iterator	list<T, Allocator>::end()
	{
		t_list		*tmp;
		int	count = 1;

		tmp = _cont;
		while (count < _number)
		{
			tmp = tmp->_nxtNode;
			count++;
		}
		return iterator(tmp);
	}*/

	//std::ostream & operator<<(std::ostream & o, typename ft::list<int>::t_list const & to_print)
/*	std::ostream & operator<<(std::ostream & o, typename ft::list<int>::iterator const & to_print)
	{
		return o << to_print._node;
	}*/
}

#endif
