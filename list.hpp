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
		/*	typedef struct		s_list
			{
				T				_node;
				struct s_list	*_nxtNode;
			}					t_list;
			
			t_list				*_cont;*/
			int					_number;

		public:
			typedef struct		s_list
			{
				T				_node;
				struct s_list	*_nxtNode;
			}					t_list;

			t_list				*_cont;
			t_list				*_it;
			typename ft::list<T>::t_list *	increment();

			list();
			~list();
			list(list const & other);
			list &	operator=(list const & other);

			T*		clone() const;
			void	clear();
			bool	empty();
			int		size() const; //size
			T*		getUnit(int) const; //iterate
			int		push_back(T newNode);
			void	pop_back();

		//	typedef typename std::list<T>::iterator iterator;
			ft::list<T>::t_list *	begin();
			ft::list<T>::t_list *	end();
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
	
	template< typename T >
	void	list<T>::clear()
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


	template< typename T >
	bool	list<T>::empty()
	{
		if (_number == 0)
			return true;
		return false;
	}
	
	template< typename T >
	list<T>::~list()
	{
	//	this->clear();
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

	template< typename T >
	int	list<T>::size() const
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
	bool	are_diff(T tmp, T newNode)
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
			while (tmp->_nxtNode)
				tmp = tmp->_nxtNode;
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

	template< typename T >
	typename ft::list<T>::t_list *	list<T>::increment()
	{
		if (_it->_nxtNode)
			_it = _it->_nxtNode;
		return _it;
	}

	template< typename T >
	typename ft::list<T>::t_list *	list<T>::begin()
	{
		_it = _cont;
		return _it;
	}

	template< typename T >
	typename ft::list<T>::t_list *	list<T>::end()
	{
		t_list		*tmp;
		int	count = 1;

		tmp = _cont;
	//	while (tmp->_nxtNode->_nxtNode)
	//		tmp = tmp->_nxtNode;
		while (count < _number)
		{
			tmp = tmp->_nxtNode;
			count++;
		}
		return tmp;
	}

	std::ostream & operator<<(std::ostream & o, typename ft::list<int>::t_list const & to_print)
	{
		return o << to_print._node;
	}
}

#endif
