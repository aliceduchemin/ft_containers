/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:00:18 by aduchemi          #+#    #+#             */
/*   Updated: 2021/05/05 13:00:19 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include "vectorIte.hpp"

void	testRealvector()
{
	std::vector<int>	vct;

	/*****************************/
	std::cout << "optional sequence operations" << std::endl;
	std::cout << "push back/front, pop back/front" << std::endl;
	vct.push_back( 1 );
	vct.push_back( 2 );
	vct.push_back( 4 );
	vct.pop_back();
	vct.push_back( 7 );

	std::cout << "vct.front()" << std::endl;
	std::cout << vct.front() << std::endl;

	std::cout << "vct.back()" << std::endl;
	std::cout << vct.back() << std::endl;

	std::vector<int>::iterator it0 = vct.begin();
	std::vector<int>::iterator ite0 = vct.end();

	std::cout << "vct : " << std::endl;
	while (it0 != ite0)
	{
		std::cout << *it0 << " ; ";
		it0++;
	}
	std::cout << std::endl;

	/*****************************/
	std::cout << "container requirements" << std::endl;
	std::cout << "+ default constructor & destructor" << std::endl;
	std::cout << "+ iterator & const_iterator" << std::endl;

	std::cout << "X(a) -> std::vector<int>	vct3(vct)" << std::endl;
	std::vector<int>	vct3(vct);
	std::cout << "X u(a) -> std::vector<int>	vct4(vct)" << std::endl;
	std::vector<int>	vct4(vct);
	std::cout << "X u = a -> std::vector<int>	vct2 = vct" << std::endl;
	std::vector<int>	vct2 = vct;

	bool	comp;
	comp = vct2 == vct3;
	std::cout << "vct2 == vct3 ? " << comp << std::endl;
	comp = vct2 != vct3;
	std::cout << "vct2 != vct3 ? " << comp << std::endl;

	vct3.assign(3, 100);
	std::cout << "vct3 is empty ? "  << vct3.empty() << std::endl;
	std::cout << "vct3.swap(vct2)" << std::endl;
	vct3.swap(vct2);

	std::cout << "size of vct2 : "  << vct2.size() << std::endl;
	std::cout << "max size vct2 : " << vct2.max_size() << std::endl;

	comp = vct2 < vct3;
	std::cout << "vct2 < vct3 ? "  << comp << std::endl;

	std::cout << "a.begin() et a.end()" << std::endl;
	std::vector<int>::iterator it = vct2.begin();
	std::vector<int>::iterator ite = vct2.end();

	std::cout << "vct2 : " << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ; ";
		it++;
	}
	std::cout << std::endl;

	/*****************************/
	std::cout << "\nsequence requirements" << std::endl;
	std::cout << "X(n, t) -> vct5(4, 1000) (constructs a sequence with n copies of t)" << std::endl;
	std::vector<int>	vct5(4, 1000);
	std::vector<int>::iterator it3 = vct5.begin();
	std::vector<int>::iterator ite3 = vct5.end();

	std::cout << "vct5 : " << std::endl;
	while (it3 != ite3)
	{
		std::cout << *it3 << " ; ";
		it3++;
	}
	std::cout << std::endl;

	std::cout << "X(i, j) ->  (constructs a sequence equal to the range [i, j))" << std::endl;

	std::cout << "a.insert(iterator position, valeur) -> vct5.insert(it, 7). Inserts a copy of 7 before it" << std::endl;
	vct5.insert(it3, 7);

	std::cout << "a.insert(iterator position, nb éléments à insérer, valeur) -> vct5.insert(it, 2, 124)" << std::endl;
	vct5.insert(vct5.begin(), 2, 124);

	std::vector<int> vct6;
	vct6.insert(vct6.begin(), 287);
/*	std::vector<int>::iterator it4 = vct6.begin();
	std::vector<int>::iterator ite4 = vct6.end();
	std::cout << "a.insert(iterator position, iterator début insertion, iterator fin insertion) -> vct5.insert(ite3, it4, ite4)" << std::endl;
	vct5.insert(ite3, it4, ite4);*/

	ite3 = vct5.end(); //pas nécessaire pour une liste
	std::cout << "vct5 : " << std::endl;
	for (it3 = vct5.begin(); it3 != ite3; ++it3)
		std::cout << *it3 << " ; ";
	std::cout << std::endl;

	std::cout << "vct5 erase first elem -> vct5.erase(it3, 4) : " << std::endl;
	it3 = vct5.begin();
//	advance(it3, 4);
	vct5.erase(it3);
	std::cout << "vct5 erase several elem -> vct5.erase(it3, it3bis) : " << std::endl;
	it3 = vct5.begin();
	it3++;
	std::vector<int>::iterator it3bis = it3;
	it3bis++;
	it3bis++;
	it3bis++;
	vct5.erase(it3, it3bis);
	for (it3 = vct5.begin(); it3 != ite3; ++it3)
		std::cout << *it3 << " ; ";
	std::cout << std::endl;
	std::cout << "clear vct5 : " << std::endl;
	vct5.clear();
}

void	ft_vector_2(ft::vector<int> myVector)
{
//	ft::vector<int>	myVector2(myVector);
	ft::vector<int>	myVector2;
	myVector2 = myVector;
	myVector2.push_back(1);
	myVector2.push_back(2);
	ft::vector<int>::iterator it2;
	ft::vector<int>::iterator ite2 = myVector2.end();
	std::cout << "vector size = " << myVector2.size() << std::endl;
	for (it2 = myVector2.begin(); it2 != ite2; ++it2)
		std::cout << *it2 << " ; ";
	std::cout << std::endl;
}

int	main()
{
//	testRealvector();

	std::cout << "\n****************************" << std::endl;
	std::cout << "custom vector" << std::endl;
	ft::vector<int>		myVector;
//	std::vector<int>	theirVector;

	myVector.push_back(1);
//	theirVector.push_back(1);
	myVector.push_back(2);
//	theirVector.push_back(2);
	myVector.push_back(3);
//	theirVector.push_back(3);
	myVector.pop_back();
//	theirVector.pop_back();
	myVector.push_back(4);
//	theirVector.push_back(4);
	myVector.push_back(5);
//	theirVector.push_back(5);
	myVector.push_back(6);
//	theirVector.push_back(6);
	myVector.pop_back();
//	theirVector.pop_back();
	std::cout << "vct.front()" << std::endl;
	std::cout << myVector.front() << std::endl;
	std::cout << "vct.back()" << std::endl;
	std::cout << myVector.back() << std::endl;
	std::cout << "vector capacity = " << myVector.capacity() << std::endl;
//	std::cout << "their vector capacity = " << theirVector.capacity() << std::endl;

	ft::vector<int>::iterator it0 = myVector.begin();
	ft::vector<int>::iterator ite = myVector.end();

	ft::vector<int>	myVector2(myVector);
//	ft::vector<int>	myVector2;
//	myVector2 = myVector;

	myVector2.push_back(1);
	myVector2.push_back(2);

//	std::cout << "vector is empty ? " << myVector.empty() << std::endl;

//	myVector.resize(2);
	myVector.resize(17, 12);
	myVector.push_back(12);
	myVector.push_back(22);
	myVector.push_back(32);
	ite = myVector.end();
	for (it0 = myVector.begin(); it0 != ite; ++it0)
		std::cout << *it0 << " ; ";
	std::cout << std::endl;
	myVector.clear();
	std::cout << "size of my vector = " << myVector.size() << std::endl;
//	std::cout << "vector is empty ? " << myVector.empty() << std::endl;
	return 0;
}