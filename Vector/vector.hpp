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
#include "vectorIte.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <limits>

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class	vector
	{
		public:
			typedef typename Allocator::value_type		value_type;
			typedef Allocator 							allocator_type;
			typedef typename Allocator::reference 		reference;
			typedef typename Allocator::const_reference const_reference;
			typedef typename Allocator::pointer			pointer;
			typedef typename Allocator::const_pointer	const_pointer;
			typedef typename Allocator::difference_type difference_type;
			typedef typename Allocator::size_type 		size_type;

			typedef ft::random_access_iterator<T>			iterator;
			typedef ft::const_random_access_iterator<T>		const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::const_reverse_iterator<iterator>	const_reverse_iterator;
		
			/********* CONSTRUCTEURS *********/
			explicit vector(const allocator_type& alloc = allocator_type());
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
				{	this->_endNode = NULL;
				 	this->_cap = 0;
					this->_allocator = alloc;
					this->_headNode = this->_allocator.allocate(0);
					this->_number = 0;
					this->insert(this->begin(), n, val); };
			template< class InputIterator >
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
				{ 	this->_endNode = NULL;
				  	this->_cap = 0;
					this->_allocator = alloc;
				  	this->_headNode = this->_allocator.allocate(0);
				  	this->_number = 0;
				  	this->assign(first, last); };
			vector(vector const & other);
			vector & operator=(vector const & other);
			~vector();

			/********* ITERATORS *********/
			iterator 				begin() { return pointer(_headNode); };
			const_iterator	 		begin() const { return pointer(_headNode); };
			iterator				end() { return pointer(_endNode + 1); };
			const_iterator			end() const { return pointer(_endNode + 1); };
			reverse_iterator 		rbegin() { return pointer(_endNode + 1); };
			const_reverse_iterator 	rbegin() const { return pointer(_endNode + 1); };
			reverse_iterator 		rend() { return pointer(_headNode); };
			const_reverse_iterator 	rend() const { return pointer(_headNode); };

			/********* CAPACITY *********/
			size_type	size() const { return _number; };
			size_type	max_size() const { return _allocator.max_size(); };
			void		resize(size_type n, value_type val = value_type());
			size_type	capacity() const { return _cap; };
			bool		empty() const { return (_number == 0); };
			void		reserve(size_type n);
		
			/********* ELEMENT ACCESS *********/
			reference		operator[] (size_type n) { return _headNode[n]; };
			const_reference	operator[] (size_type n) const { return _headNode[n]; };
			reference		at(size_type n);
			const_reference	at(size_type n) const;
			reference		front() { return *_headNode; };
			const_reference	front() const { return *_headNode; };
			reference		back() { return *_endNode; };
			const_reference	back() const { return *_endNode; };

			/********* MODIFIERS *********/
		//	template < class InputIterator >
			void	assign(iterator first, iterator last);
		/*	void	assign(typename ft::enable_if<!std::numeric_limits<InputIterator>::is_integer, InputIterator first, InputIterator last)
				{	if (this->_number != 0)
						this->clear();
					while (first != last)
					{
						if (this->_cap <= this->_number)
							this->reserve(this->_number + 1);
						this->_allocator.construct(&this->_headNode[this->_number], *first);
						this->_endNode = &this->_headNode[this->_number];
						this->_number++;
						first++;
					} };*/
			void		assign(size_type n, const value_type& val);
			void		push_back(const value_type& val);
			void		pop_back();
			iterator	insert(iterator position, const value_type& val);
			void		insert(iterator position, size_type n, const value_type& val);
		//	template < class InputIterator >
			void		insert(iterator position, iterator first, iterator last);
			iterator	erase(iterator position);
			iterator	erase(iterator first, iterator last);
			void		swap(vector& x);
			void		clear();

			/********* ALLOCATOR *********/
			allocator_type	get_allocator() const;

		private:
			pointer			_headNode;
			pointer			_endNode;
			pointer			_container;			
			size_type		_number;
			size_type		_cap;
			allocator_type	_allocator;
	};

	/********* CONSTRUCTEURS *********/
	template< typename T, typename Allocator >
	vector<T, Allocator>::vector(const allocator_type& alloc)
	{
		this->_endNode = NULL;
		this->_cap = 0;
		this->_allocator = alloc;
		this->_headNode = this->_allocator.allocate(0);
		this->_number = 0;
	}

	template< typename T, typename Allocator >
	vector<T, Allocator>::~vector()
	{
		if (this->_number > 0)
			this->clear();
		this->_allocator.deallocate(this->_headNode, this->_cap);
	}

	template< typename T, typename Allocator >
	vector<T, Allocator>::vector(vector<T, Allocator> const & other)
	{
		this->_endNode = NULL;
		this->_cap = 0;
		this->_headNode = this->_allocator.allocate(0);
		this->_number = 0;
		*this = other;
	}

	template< typename T, typename Allocator >
	vector<T, Allocator> &	vector<T, Allocator>::operator=(vector<T, Allocator> const & other)
	{
		size_type	i;
		const_iterator it = other.begin();

		if (this->_number > 0)
			this->clear();

		i = 1;
		while (i <= other.size())
		{
			this->push_back(*it);
			it++;
			i++;
		}
		return *this;
	}

	/********* CAPACITY *********/
	template< typename T, typename Allocator >
	void	vector<T, Allocator>::resize(size_type n, value_type val)
	{
		if (n < this->_number)
		{
			while (this->_number > n)
				this->pop_back();
		}
		if (n > this->_number * 2)
			this->reserve(n);
		if (n > this->_number)
		{
			while (this->_number < n)
				this->push_back(val);
		}
	}

	template< typename T, typename Allocator >
	void	vector<T, Allocator>::reserve(size_type n)
	{
		if (n <= this->_cap)
			return ;
	
		pointer	tmp = this->_allocator.allocate(n);
		size_type i = 0;
		while (i < this->_number)
		{
			this->_allocator.construct(&tmp[i], this->_headNode[i]);
			this->_allocator.destroy(&this->_headNode[i]);
			i++;
		}
		this->_allocator.deallocate(this->_headNode, this->_cap);
		this->_headNode = tmp;
		this->_cap = n;
	}

	/********* ELEMENT ACCESS *********/
	template< typename T, typename Allocator >
	typename vector<T, Allocator>::reference	vector<T, Allocator>::at(size_type n)
	{
		if (n >= this->_number)
		{
		//	std::string num = static_cast<std::ostringstream*>( &(std::ostringstream() << n))->str();
		//	std::string msg = "vector::_M_range_check: __n (which is " + num + ") >= this->size() (which is " + this->_number + ")";
			throw std::out_of_range("vector:: request of an element beyond size()");
		}
		return this->_headNode[n];
	}

	template< typename T, typename Allocator >
	typename vector<T, Allocator>::const_reference	vector<T, Allocator>::at(size_type n) const
	{
		if (n >= this->_number)
		{
			throw std::out_of_range("vector:: request of an element beyond size()");
		}
		return this->_headNode[n];
	}

	/********* MODIFIERS *********/
	template< typename T, typename Allocator >
	void	vector<T, Allocator>::assign(size_type n, const value_type& val)
	{
		if (this->_number != 0)
			this->clear();
		size_type i = 0;
		while (i < n)
		{
			if (this->_cap <= this->_number)
				this->reserve(this->_number + 1);
			this->_allocator.construct(&this->_headNode[this->_number], val);
			this->_endNode = &this->_headNode[this->_number];
			this->_number++;
			i++;
		}
	}
	
	template< typename T, typename Allocator >
	void	vector<T, Allocator>::assign(iterator first, iterator last)
	{
		if (this->_number != 0)
			this->clear();
		while (first != last)
		{
			if (this->_cap <= this->_number)
				this->reserve(this->_number + 1);
			this->_allocator.construct(&this->_headNode[this->_number], *first);
			this->_endNode = &this->_headNode[this->_number];
			this->_number++;
			first++;
		}
	}

	template< typename T, typename Allocator >
	void	vector<T, Allocator>::push_back(const value_type& val)
	{
		if (this->_cap == 0)
			this->reserve(1);
		if (this->_cap <= this->_number)
			this->reserve(this->_number * 2);
		this->_allocator.construct(&this->_headNode[this->_number], val);
		this->_endNode = &this->_headNode[this->_number];
		this->_number++;
	}

	template< typename T, typename Allocator >
	void	vector<T, Allocator>::pop_back()
	{
		this->_number--;
		this->_endNode = &this->_headNode[this->_number - 1];
		this->_allocator.destroy(&this->_headNode[this->_number]);
	}

	template< typename T, typename Allocator >
	ft::random_access_iterator<T>	vector<T, Allocator>::insert(iterator position, const value_type& val)
	{
		size_type dist = 0;
		iterator it;
		for (it = this->begin(); it != position; it++)
			dist++;
		pointer tmp = this->_allocator.allocate(this->_cap = this->_number + 1);

		size_type j = 0;
		while (j < dist)
		{
			this->_allocator.construct(&tmp[j], this->_headNode[j]);
			this->_allocator.destroy(&this->_headNode[j]);
			j++;
		}
		this->_allocator.construct(&tmp[j++], val);
		it = &tmp[0] + dist;
		this->_number++;

		while (j < this->_number)
		{
			this->_allocator.construct(&tmp[j], this->_headNode[j - 1]);
			this->_allocator.destroy(&this->_headNode[j - 1]);
			j++;
		}

		this->_allocator.deallocate(this->_headNode, this->_cap);
		this->_headNode = tmp;
		this->_endNode = &this->_headNode[this->_number - 1];
		return it;
	}

	template< typename T, typename Allocator >
	void	vector<T, Allocator>::insert(iterator position, size_type n, const value_type& val)
	{
		size_type i = 0;
		iterator ret = position;
		while (i < n)
		{
			ret = this->insert(ret, val);
			i++;
		}
	}

	template< typename T, typename Allocator >
	void	vector<T, Allocator>::insert(iterator position, iterator first, iterator last)
	{
		iterator ret = position;
		while (first != last)
		{
			ret = this->insert(ret, *first);
			first++;
		}
	}

	template< typename T, typename Allocator >
	ft::random_access_iterator<T>	vector<T, Allocator>::erase(iterator position)
	{
		this->_number--;
		iterator it = this->begin();
		size_type i = 0;
		while (it != position)
		{
			it++;
			i++;
		}
		this->_allocator.destroy(&this->_headNode[i]);
		while (i < this->_number)
		{
			this->_allocator.construct(&this->_headNode[i], this->_headNode[i + 1]);
			this->_allocator.destroy(&this->_headNode[i + 1]);
			i++;
		}
		this->_endNode = &this->_headNode[this->_number - 1];
		
		return it--;
	}

	template< typename T, typename Allocator >
	ft::random_access_iterator<T>	vector<T, Allocator>::erase(iterator first, iterator last)
	{
		size_type diff = last - first;
		this->_number -= diff;

		iterator it = this->begin();
		size_type i = 0;
		while (it != first)
		{
			it++;
			i++;
		}
		while (first != last)
		{
			this->_allocator.destroy(&this->_headNode[i]);
			first++;
			i++;
		}
		i -= diff;
		while (i < this->_number)
		{
			this->_allocator.construct(&this->_headNode[i], this->_headNode[i + diff]);
			this->_allocator.destroy(&this->_headNode[i + diff]);
			i++;
		}
		this->_endNode = &this->_headNode[this->_number - 1];
	
		return it--;
	}
	
	template< typename T, typename Allocator >
	void	vector<T, Allocator>::swap(vector& x)
	{
		vector	tmp;
		tmp = *this;
		*this = x;
		x = tmp;
	}
		
	template< typename T, typename Allocator >
	void	vector<T, Allocator>::clear()
	{
		while (this->_number > 0)
		{
			this->pop_back();
		}
	}

	/********* ALLOCATOR *********/
	template< typename T, typename Allocator >
	Allocator	vector<T, Allocator>::get_allocator() const
	{
		return this->_allocator;
	}
}

template< class T, class Alloc >
bool	operator==(const ft::vector<T, Alloc>& lhs,
					const ft::vector<T, Alloc>& rhs)
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

template< class T, class Alloc >
bool	operator!=(const ft::vector<T, Alloc>& lhs,
					const ft::vector<T, Alloc>& rhs)
{
	return (!(lhs == rhs)) ? true : false;
}

template< class T, class Alloc >
bool	operator<(const ft::vector<T, Alloc>& lhs,
					const ft::vector<T, Alloc>& rhs)
{
	return (lhs.size() < rhs.size()) ? true : false;
}

template< class T, class Alloc >
bool	operator<=(const ft::vector<T, Alloc>& lhs,
					const ft::vector<T, Alloc>& rhs)
{
	return (lhs.size() <= rhs.size()) ? true : false;
}

template< class T, class Alloc >
bool	operator>(const ft::vector<T, Alloc>& lhs,
					const ft::vector<T, Alloc>& rhs)
{
	return (lhs.size() > rhs.size()) ? true : false;
}

template< class T, class Alloc >
bool	operator>=(const ft::vector<T, Alloc>& lhs,
					const ft::vector<T, Alloc>& rhs)
{
	return (lhs.size() >= rhs.size()) ? true : false;
}

template <class T, class Alloc>
void	swap(ft::vector<T, Alloc>& x, ft::vector<T, Alloc>& y)
{
	x.swap(y);
}

#endif