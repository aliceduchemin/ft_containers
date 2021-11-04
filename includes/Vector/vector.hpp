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

#include <iostream>
#include "vectorIte.hpp"
#include "../utils.hpp"

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
			typedef typename Allocator::pointer			pointer;
			typedef typename Allocator::const_pointer	const_pointer;
			typedef typename Allocator::difference_type difference_type;
			typedef typename Allocator::size_type 		size_type;

			typedef ft::random_access_iterator<T>			iterator;
			typedef ft::const_random_access_iterator<T>		const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::const_reverse_iterator<iterator>	const_reverse_iterator;
		
			/********* CONSTRUCTEURS *********/
			explicit vector(const allocator_type& alloc = allocator_type())
			{
				this->_headNode = NULL;
				this->_endNode = NULL;
				this->_cap = 0;
				this->_allocator = alloc;
				this->_number = 0;
			}

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{	
				this->_headNode = NULL;
				this->_endNode = NULL;
				this->_cap = 0;
				this->_allocator = alloc;
				this->_number = 0;
				this->insert(this->begin(), n, val);
			};

			template< class InputIterator >
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			{ 	
				this->_headNode = NULL;
				this->_endNode = NULL;
				this->_cap = 0;
				this->_allocator = alloc;
				this->_number = 0;
				this->assign(first, last);
			};

			vector(const vector& x)
			{
				this->_headNode = NULL;
				this->_endNode = NULL;
				this->_cap = 0;
				this->_number = 0;
				*this = x;
			};

			vector & operator=(vector const & x)
			{
				if (!this->empty())
					this->clear();
			
				size_type i = 0;
				while (i < x._number)
				{
					push_back(x[i]);
					i++;
				}
				return *this;
			};

			~vector()
			{
				if (!this->empty())
					this->clear();
				this->_allocator.deallocate(this->_headNode, this->_cap);
			};

			/********* ITERATORS *********/
			iterator 				begin() { return iterator(_headNode); };

			const_iterator	 		begin() const { return const_iterator(_headNode); };

			iterator				end()
			{ 	
				if (this->empty())
					return iterator(_headNode);
				return iterator(_endNode + 1);
			};

			const_iterator			end() const
			{
				if (this->empty())
					return const_iterator(_headNode);
				return const_iterator(_endNode + 1);
			};

			reverse_iterator 		rbegin()
			{
				if (this->empty())
					return reverse_iterator(_headNode);
				return reverse_iterator(_endNode + 1);
			};

			const_reverse_iterator 	rbegin() const
			{
				if (this->empty())
					return reverse_iterator(_headNode);
				return reverse_iterator(_endNode + 1);
			};

			reverse_iterator 		rend() { return reverse_iterator(_headNode); };

			const_reverse_iterator 	rend() const { return reverse_iterator(_headNode); };

			/********* CAPACITY *********/
			size_type	size() const { return _number; };

			size_type	max_size() const { return _allocator.max_size(); };

			void		resize(size_type n, value_type val = value_type())
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
			};

			size_type	capacity() const { return this->_cap; };

			bool		empty() const { return (this->_number == 0); };

			void		reserve(size_type n)
			{
				if (n <= this->_cap)
					return ;
				if (n > this->max_size())
					throw std::out_of_range("vector:: capacity request beyond max_size()");

				if (this->empty())
					this->_headNode = this->_allocator.allocate(n);
				else
				{
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
				}
				this->_cap = n;
			};

			/********* ELEMENT ACCESS *********/
			reference		operator[] (size_type n) { return _headNode[n]; };

			const_reference	operator[] (size_type n) const { return _headNode[n]; };

			reference		at(size_type n)
			{
				if (n < 0 || n >= this->_number)
					throw std::out_of_range("vector:: request of an element beyond size()");
				return this->_headNode[n];
			};

			const_reference	at(size_type n) const
			{
				if (n < 0 || n >= this->_number)
					throw std::out_of_range("vector:: request of an element beyond size()");
				return this->_headNode[n];
			};

			reference		front() { return *_headNode; };

			const_reference	front() const { return *_headNode; };

			reference		back() { return *_endNode; };

			const_reference	back() const { return *_endNode; };

			/********* MODIFIERS *********/
			template < class InputIterator >
			void	assign(InputIterator first, InputIterator last, 
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = ft::nullptr_t)
			{	
				size_type n = 0;
				iterator tmp = first;
				while (tmp != last)
				{ tmp++; n++; }
				this->reserve(n);

				if (this->_number > 0)
					this->clear();

				while (first != last)
				{
					this->_allocator.construct(&this->_headNode[this->_number], *first);
					this->_endNode = &this->_headNode[this->_number];
					this->_number++;
					first++; 
				} 
			};

			void		assign(size_type n, const value_type& val)
			{
				this->reserve(this->_number + n);

				if (this->_number > 0)
					this->clear();

				size_type i = 0;
				while (i < n)
				{
					this->_allocator.construct(&this->_headNode[this->_number], val);
					this->_endNode = &this->_headNode[this->_number];
					this->_number++;
					i++;
				}
			};

			void		push_back(const value_type& val)
			{
				if (this->_cap == 0)
					this->reserve(1);
				if (this->_cap <= this->_number)
					this->reserve(this->_number * 2);
				this->_allocator.construct(&this->_headNode[this->_number], val);
				this->_endNode = &this->_headNode[this->_number];
				this->_number++;
			};

			void		pop_back()
			{
				this->_number--;
				this->_endNode = &this->_headNode[this->_number - 1];
				this->_allocator.destroy(&this->_headNode[this->_number]);
			};

			iterator	insert(iterator position, const value_type& val)
			{
				size_type	distFromBegin = position - this->begin();
				size_type	oldSize = this->_number;

				this->resize(this->_number + 1);

				iterator	oldEnd = this->begin() + oldSize;
				iterator	end = this->end();
				iterator	injection = this->begin() + distFromBegin;
				while (oldEnd != injection)
				{	*--end = *--oldEnd;	}
				*injection++ = val;
				return --injection;
			};

			void		insert(iterator position, size_type n, const value_type& val)
			{
				size_type	distFromBegin = position - this->begin();
				size_type	oldSize = this->_number;

				this->resize(this->_number + n);

				iterator	oldEnd = this->begin() + oldSize;
				iterator	end = this->end();
				iterator	injection = this->begin() + distFromBegin;
				while (oldEnd != injection)
				{	*--end = *--oldEnd;	}
				while (n > 0)
				{	*injection++ = val; n--;	}
			};

			template < class InputIterator >
			void		insert(iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
			{	
				iterator ret = position;
				iterator it;
				while (first != last)
				{
					if (ret == position)
						ret = this->insert(ret, *first);
					else
						ret = this->insert(++ret, *first);
					first++;
				} 
			};

			iterator	erase(iterator position)
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
			};

			iterator	erase(iterator first, iterator last)
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
			};

			void		swap(vector& x)
			{
				ft::ft_swap(this->_headNode, x._headNode);
				ft::ft_swap(this->_endNode, x._endNode);
				ft::ft_swap(this->_number, x._number);
				ft::ft_swap(this->_cap, x._cap);
				ft::ft_swap(this->_allocator, x._allocator);
			};

			void		clear()
			{
				while (this->_number > 0)
				{	this->pop_back();	}
			};

			/********* ALLOCATOR *********/
			allocator_type	get_allocator() const
			{	return this->_allocator;	};

		private:
			pointer			_headNode;
			pointer			_endNode;
			size_type		_number;
			size_type		_cap;
			allocator_type	_allocator;
	};

	/********* COMPARATORS *********/
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
	{	return (!(lhs == rhs)) ? true : false;	}

	template< class T, class Alloc >
	bool	operator<(const ft::vector<T, Alloc>& lhs,
						const ft::vector<T, Alloc>& rhs)
	{	return (lhs.size() < rhs.size()) ? true : false;	}

	template< class T, class Alloc >
	bool	operator<=(const ft::vector<T, Alloc>& lhs,
						const ft::vector<T, Alloc>& rhs)
	{	return (lhs.size() <= rhs.size()) ? true : false;	}

	template< class T, class Alloc >
	bool	operator>(const ft::vector<T, Alloc>& lhs,
						const ft::vector<T, Alloc>& rhs)
	{	return (lhs.size() > rhs.size()) ? true : false;	}

	template< class T, class Alloc >
	bool	operator>=(const ft::vector<T, Alloc>& lhs,
						const ft::vector<T, Alloc>& rhs)
	{	return (lhs.size() >= rhs.size()) ? true : false;	}

	template <class T, class Alloc>
	void	swap(ft::vector<T, Alloc>& x, ft::vector<T, Alloc>& y)
	{	x.swap(y);	}
}
#endif