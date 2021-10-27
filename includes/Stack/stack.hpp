/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:05:58 by aduchemi          #+#    #+#             */
/*   Updated: 2021/05/10 15:05:59 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __STACK_HPP__
# define __STACK_HPP__

#include <memory>
#include <iostream>
#include <stdexcept>
#include "../Vector/vector.hpp"

namespace ft
{
	template <class T, class Container = vector<T> >
	class	stack
	{
		public:
			typedef Container 							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type 		size_type;

			/********* CONSTRUCTEURS *********/
			explicit stack(const container_type& ctnr = container_type()) { c = ctnr; };

			stack(stack const & other) { this->c = other.c; };

			stack & operator=(stack const & other) { this->c = other.c; return *this; };

			~stack() {};

			/********* CAPACITY *********/
			size_type	size() const { return this->c.size(); };

			bool		empty() { return (this->c.size() == 0); };
		
			/********* ELEMENT ACCESS *********/
			value_type&			top() { return this->c.back(); };

			const value_type&	top() const { return this->c.back(); };

			/********* MODIFIERS *********/
			void		push(const value_type& val) { this->c.push_back(val); };

			void		pop() { this->c.pop_back(); };

			/********* COMPARATORS *********/
			friend bool	operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
			{ return lhs.c != rhs.c; };

			friend bool	operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
			{ return lhs.c == rhs.c; };

			friend bool	operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
			{ return lhs.c <= rhs.c; };

			friend bool	operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
			{ return lhs.c < rhs.c; };

			friend bool	operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
			{ return lhs.c >= rhs.c; };
			
			friend bool	operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
			{ return lhs.c > rhs.c; };

		protected:
			container_type	c;		
	};
}
#endif