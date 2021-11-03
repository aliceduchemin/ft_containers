/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:46:33 by aduchemi          #+#    #+#             */
/*   Updated: 2021/10/27 17:46:35 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testsContainers.hpp"

int main() 
{
	struct timeval begin, end;
	gettimeofday(&begin, 0);
	
	std::cout << "########## VECTOR TESTS : ##########\n" << std::endl;
//	vectorTests();

	std::cout << "\n\n\n########## STACK TESTS : ##########\n" << std::endl;
//	stackTests();

	std::cout << "\n\n\n########## MAP TESTS : ##########\n" << std::endl;
	mapTests();

	gettimeofday(&end, 0);
	long seconds = end.tv_sec - begin.tv_sec;
	long microseconds = end.tv_usec - begin.tv_usec;
	double elapsed = seconds + microseconds * 1e-6;
	std::cout << "\n\nDuration : " << elapsed << " seconds" << std::endl;
	return (0);
}
