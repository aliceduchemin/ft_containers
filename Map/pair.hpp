/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:05:58 by aduchemi          #+#    #+#             */
/*   Updated: 2021/05/10 15:05:59 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PAIR_HPP__
# define __PAIR_HPP__

#include <iostream>

namespace ft
{
	template <class T1,	class T2>														// map::mapped_type
	struct pair
	{
		public:
			typedef T1		first_type;
			typedef T2		second_type;
		
			/********* CONSTRUCTEURS *********/
			pair();
			template<class U, class V>
			pair(const pair<U,V>& pr);
			pair(const first_type& a, const second_type& b);
			pair(pair const & other);
			pair & operator=(pair const & other);
			~pair() {};

		private:
			first_type	first;
			second_type	second;
	};

	/********* CONSTRUCTEURS *********/

}

template< class T1, class T2 >
bool	operator==(const ft::pair<T1, T2>& lhs,
					const ft::pair<T1, T2>& rhs)
{	return lhs.first==rhs.first && lhs.second==rhs.second;	}

template< class T1, class T2 >
bool	operator!=(const ft::pair<T1, T2>& lhs,
					const ft::pair<T1, T2>& rhs)
{	return !(lhs == rhs);	}

template< class T1, class T2 >
bool	operator<(const ft::pair<T1, T2>& lhs,
					const ft::pair<T1, T2>& rhs)
{	return lhs.first<rhs.first || (!(rhs.first<lhs.first) && (lhs.second<rhs.second));	}

template< class T1, class T2 >
bool	operator<=(const ft::pair<T1, T2>& lhs,
					const ft::pair<T1, T2>& rhs)
{	return !(rhs<lhs);	}

template< class T1, class T2 >
bool	operator>(const ft::pair<T1, T2>& lhs,
					const ft::pair<T1, T2>& rhs)
{	return rhs<lhs;	}

template< class T1, class T2 >
bool	operator>=(const ft::pair<T1, T2>& lhs,
					const ft::pair<T1, T2>& rhs)
{	return !(lhs<rhs);	}
/*
template< class T1, class T2 >
ft::pair<T1,T2> make_pair(T1 x, T2 y)
{
	return ( pair<T1,T2>(x,y) );
}*/

#endif