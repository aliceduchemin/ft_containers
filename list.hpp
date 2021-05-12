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

#include <iterator>

namespace ft
{
	template< typename T >
	class	list
	{
		private:
	/*		typedef struct		s_list
			{
				T				_node;
				struct s_list	*_nxtNode;
			}					t_list;*/
			
		//	t_list				*_cont;
			int					_number;
			T					*_it;

		public:
			typedef struct		s_list
			{
				T				_node;
				struct s_list	*_nxtNode;
			}					t_list;
			t_list				*_cont;

			list();
			~list();
			list(list const & other);
			list &	operator=(list const & other);

			T*		clone() const;
		//	void	listDeleting(list* list);
			int		size() const; //size
			T*		getUnit(int) const; //iterate
			int		push_back(T newNode);
			void	pop_back();

		/*	typedef typename std::list<T>::iterator iterator;

			iterator	begin();
			iterator	end();*/
			ft::list<T>::t_list *	begin();
			T *	end();
			T &	operator++();
		/*	class iterator
			{
				private:
					T *	_it;
				public:
			//		T &	operator++();
			//		T	operator++(T);
			};
			iterator	_listIt;*/
	};

	template< typename T >
	list<T>::list()
	{
		_number = 0;
	}

	template< typename T >
	T*	list<T>::clone() const
	{
		T* copy = new list<T>;

		return copy;
	}
	/*
	template< typename T >
	void	list<T>::listDeleting(list* list)
	{
		int			count;
		t_list		*tmp;

		tmp = list->_cont;
		count = 0;
		while (count < _number)
		{
			tmp = list->_cont->_nxtNode;
			delete list->_cont->_node;
			delete list->_cont;
			list->_cont = tmp;
			count++;
		}
		list->_number = 0;
	}*/
	
	template< typename T >
	list<T>::~list()
	{
	//	listDeleting(this);
	}

	template< typename T >
	list<T>::list(list<T> const & other)
	{
		int		i;

		i = 0;
		while (i < other.size())
		{
			this->push_back(other.getUnit(i)->clone());
			i++;
		}
		_number = other.size();
	}

	template< typename T >
	list<T> &	list<T>::operator=(list<T> const & other)
	{
		int		i;

	//	if (_cont)
	//		listDeleting(this);
		i = 0;
		while (i < other.size())
		{
			this->push_back(other.getUnit(i)->clone());
			i++;
		}
		_number = other.size();
		return *this;
	}

	template< typename T >
	int				list<T>::size() const
	{
		return _number;
	}

	template< typename T >
	T*	list<T>::getUnit(int N) const
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
	bool			are_diff(T tmp, T newNode)
	{
		if (tmp == newNode)
			return false;
		return true;
	}

	template< typename T >
	int		list<T>::push_back(T newNode)
	{
		t_list		*tmp;

		if (newNode == 0)
			return _number;
		if (_number == 0)
		{
			_cont = new t_list;
			_cont->_node = newNode;
			_cont->_nxtNode = NULL;
		}
		else
		{
			tmp = _cont;
			while (tmp->_nxtNode && are_diff(tmp->_node, newNode))
				tmp = tmp->_nxtNode;
			if (!are_diff(tmp->_node, newNode))
				return _number;
			tmp->_nxtNode = new t_list;
			tmp->_nxtNode->_node = newNode;
			tmp->_nxtNode->_nxtNode = NULL;
		}
		_number++;
		return _number;
	}

	template< typename T >
	void	list<T>::pop_back()
	{
		int			count;
		t_list		*tmp;

		tmp = _cont;
		count = 0;
		while (count < _number - 2)
		{
			_cont = _cont->_nxtNode;
			count++;
		}
		_cont->_nxtNode = NULL;
		_cont = tmp;
		_number--;
	}

	template< typename T >
	T &	list<T>::operator++()
	{
	//	_it += sizeof(t_list);
		if (_it->nxtNode)
			_it = _it->_nxtNode;
		return _it;
	}

/*	template< typename T >
	T	list<T>::iterator::operator++(T)
	{
		T	res(*this);

		_it += sizeof(t_list);
		return res;
	}*/

	template< typename T >
//	typename list<T>::iterator	list<T>::begin()
	ft::list<T>::t_list *	list<T>::begin()
	{
	//	T *	it = new T;

		_it = _cont;
		return _it;
	}

	template< typename T >
//	typename list<T>::iterator	list<T>::end()
	T *	list<T>::end()
	{
		int		i;

		_it = _cont;
		i = 0;
		while (_it->_nxtNode && i < _number)
		{
			_it = _it->_nxtNode;
			i++;
		}
		return _it;
	//	iterator	it;
	/*	int			count;
		t_list		tmp;
	//	T * it = new T;

		tmp = _cont;
		count = 0;
		while (tmp->_nxtNode && count < _number)
		{
			tmp = tmp->_nxtNode;
			count++;
		}
	//	_it = tmp->_node;
		return tmp;*/
	}
}

#endif
