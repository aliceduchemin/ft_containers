/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:38:39 by aduchemi          #+#    #+#             */
/*   Updated: 2021/05/17 11:38:41 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
/*
template <class T, class Allocator>
template <class Iterator>
set<T, Allocator>::set(Iterator start, Iterator finish, Allocator alloc)
:	buffer_size(finish-start + DEFAULT_CUSHION + buffer_start(0), 
	current_end(0), end_of_buffer(0)
{
	the_allocator = alloc;
	buffer_start = the_allocator.allocate(buffer_size);
	end_of_buffer = buffer_start + buffer_size;
	for (current_end = buffer_start;
		start != finish;
		current_end++, start++)
	the_allocator.construct(current_end, *start);
	std::unique(begin(), end());
}*/