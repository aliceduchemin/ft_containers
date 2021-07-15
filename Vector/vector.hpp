/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:05:58 by aduchemi          #+#    #+#             */
/*   Updated: 2021/05/10 15:05:59 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

#include <memory>
#include "vectorNode.hpp"
#include "vectorIte.hpp"
#include <iostream>

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class	vector
	{
		public:
			typedef Allocator 							allocator_type;
			typedef typename Allocator::value_type		value_type;
			typedef typename Allocator::reference 		reference;
			typedef typename Allocator::const_reference const_reference;
		//	typedef value_type*				pointer;
			typedef T*						pointer;
		//	typedef typename Allocator::pointer			pointer;
			typedef typename Allocator::const_pointer	const_pointer;
			typedef typename Allocator::size_type 		size_type;
			typedef typename Allocator::difference_type difference_type;
			typedef ft::VectorIterator<T>				iterator;
		
			/********* COPLIEN *********/
			vector();
			vector(vector & other);
			vector &	operator=(vector & other);
			~vector();

			/********* ITERATION *********/
			iterator begin() { return pointer(_headNode); };
			iterator end() { return pointer(_endNode);
			/*	pointer tmp = pointer(_headNode);
				int count = 1;
				tmp = _headNode;
				while (count < _number)
				{
					tmp = tmp.getNodePtr()->getNxt();
					count++;
				}
				tmp = tmp.getNodePtr()->getNxt();
				tmp = NULL;
				return tmp;*/ };
			iterator rbegin() { return this->end(); };
			iterator rend() { return pointer(_headNode); };

			/********* FUNCTIONS *********/
		//	T*		clone() const;
			void	clear();
			bool	empty();
			int		size() const { return _number; };
			void	push_back(const value_type& val);
			void	pop_back();
			reference front() { return *_headNode; };
			reference back() { return *_endNode; };
			size_type	max_size() const { return this->_allocator.max_size(); };
			void		resize(size_type n, value_type val = value_type());
			void		reserve(size_type n);
			size_type	capacity() const { return _cap; };

			//ACCESSEURS
			reference	operator[] (size_type n);

		private:
			pointer			_headNode;
			pointer			_endNode;
			pointer			_container;			
			size_type		_number;
			size_type		_cap;
			allocator_type	_allocator;
	};


	//COPLIEN
	template< typename T, typename Allocator >
	vector<T, Allocator>::vector()
	{
	//	std::cout << "vector default constructor" << std::endl;
		_endNode = NULL;
		_headNode = _allocator.allocate(0);
		_number = 0;
	}
	
	template< typename T, typename Allocator >
	void	vector<T, Allocator>::clear()
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
	vector<T, Allocator>::~vector()
	{
		std::cout << "vector destructor, number = " << _number << std::endl;
	//	this->clear();
		if (_number > 0)
			_allocator.deallocate(_headNode, _number);
	}


	template< typename T, typename Allocator >
	vector<T, Allocator>::vector(vector<T, Allocator> & other)
	{
		_number = 0;
		*this = other;
	}

	template< typename T, typename Allocator >
	vector<T, Allocator> &	vector<T, Allocator>::operator=(vector<T, Allocator> & other)
	{
		int		i;
		iterator it = other.begin();

		if (_headNode)
			this->clear();

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

	//MEMBER FUNCTIONS
	template< typename T, typename Allocator >
	bool	vector<T, Allocator>::empty()
	{
		if (_number == 0)
			return true;
		return false;
	}

	template< typename T, typename Allocator >
	void	vector<T, Allocator>::resize(size_type n, value_type val)
	{
		if (n > this->max_size())
		{
			perror("resize");
			exit(EXIT_FAILURE);
		}
		if (n < _number)
		{
			int i = _number;
			while (i > n)
			{
				this->pop_back();
				i--;
			}
		}
		if (n > _number)
		{
			this->reserve(n);
		/*	while (_number < n)
			{
				this->push_back(0);
				_number++;
			}*/
		}
	}

	template< typename T, typename Allocator >
	void	vector<T, Allocator>::reserve(size_type n)
	{
		if (n > _cap)
		{
			pointer	tmp = _allocator.allocate(n);
			size_type i = 0;
			while (i < _number)
			{
				//_allocator.construct(tmp, )
				i++;
			}
			_container = _allocator.deallocate(_container, _number);
			_cap *= 2;
		}
	}

	template< typename T, typename Allocator >
	void	vector<T, Allocator>::push_back(const value_type& val)
	{
		if (_number == 0)
		{
			_headNode = _allocator.allocate(1);
			_allocator.construct(_headNode, val);
			_cap = 1;
			_endNode = _headNode;
			_number++;
		}
		else
		{
			if (_cap < _number + 1)
			{
				pointer tmp = _allocator.allocate(_number);
				size_type i = 0;
				for (i = 0; i < _number; i++)
				{
					_allocator.construct(&tmp[i], _headNode[i]);
					_allocator.destroy(&_headNode[i]);
				}
				_allocator.construct(&tmp[i], val);
				_endNode = &tmp[i];
				_allocator.deallocate(_headNode, _cap);
				_headNode = tmp;
				_cap *= 2;
			}
			else
			{
				int i = 0;
				while (i < _number)
					i++;
				_allocator.construct(&_headNode[_number], val);
				_endNode = &_headNode[_number];
			}
			_number++;
		}
	}

	template< typename T, typename Allocator >
	void	vector<T, Allocator>::pop_back()
	{
		_endNode = &_headNode[_number - 1];
		_allocator.destroy(&_headNode[_number]);
		_headNode[_number] = 0;
		_number--;
	}

	template< typename T, typename Allocator >
	typename vector<T, Allocator>::reference	vector<T, Allocator>::operator[] (size_type n)
	{
		int i = 0;
		while (i < _number)
		{
			
			i++;
		}
	}

	//std::ostream & operator<<(std::ostream & o, typename ft::list<int>::t_list const & to_print)
/*	std::ostream & operator<<(std::ostream & o, typename ft::list<int>::iterator const & to_print)
	{
		return o << to_print._node;
	}*/
}

#endif
