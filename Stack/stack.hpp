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
			explicit stack(const container_type& ctnr = container_type()) { _container = ctnr; };
			stack(stack const & other) { this->_container = other._container; };
			stack & operator=(stack const & other) { this->_container = other._container; return *this; };
			~stack() {};

			/********* CAPACITY *********/
			size_type	size() const { return this->_container.size(); };
			bool		empty() { return (this->_container.size() == 0); };
		
			/********* ELEMENT ACCESS *********/
			value_type&			top() { return this->_container.back(); };
			const value_type&	top() const { return this->_container.back(); };

			/********* MODIFIERS *********/
			void		push(const value_type& val) { this->_container.push_back(val); };
			void		pop() { this->_container.pop_back(); };

			/********* COMPARATORS *********/
			friend bool	operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
				{ return lhs._container != rhs._container; };

			friend bool	operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
				{ return lhs._container == rhs._container; };

			friend bool	operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
				{ return lhs._container <= rhs._container; };

			friend bool	operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
				{ return lhs._container < rhs._container; };

			friend bool	operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
				{ return lhs._container >= rhs._container; };
			
			friend bool	operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
				{ return lhs._container > rhs._container; };

		private:
			container_type	_container;		
	};
}

#endif