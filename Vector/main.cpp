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
	std::vector<int>	theirVector;

	myVector.push_back(1);
	theirVector.push_back(1);
	myVector.push_back(2);
	theirVector.push_back(2);
	myVector.push_back(3);
	theirVector.push_back(3);
	myVector.pop_back();
	theirVector.pop_back();
	myVector.push_back(4);
	theirVector.push_back(4);
	myVector.push_back(5);
	theirVector.push_back(5);
	myVector.push_back(6);
	theirVector.push_back(6);
	myVector.pop_back();
	theirVector.pop_back();
	std::cout << "vct.front()" << std::endl;
	std::cout << myVector.front() << std::endl;
	std::cout << theirVector.front() << std::endl;
	std::cout << "vct.back()" << std::endl;
	std::cout << myVector.back() << std::endl;
	std::cout << theirVector.back() << std::endl;
	std::cout << "vector capacity = " << myVector.capacity() << std::endl;
	std::cout << "their vector capacity = " << theirVector.capacity() << std::endl;

	ft::vector<int>::iterator it0 = myVector.begin();
	ft::vector<int>::iterator ite = myVector.end();
	std::cout << "print my vector : "<<std::endl;
	ite = myVector.end();
	for (it0 = myVector.begin(); it0 != ite; ++it0)
		std::cout << *it0 << " ; ";
	std::cout << std::endl;

	ft::vector<int>	myVector2(myVector);
//	ft::vector<int>	myVector2;
//	myVector2 = myVector;

	myVector2.push_back(1);
	myVector2.push_back(2);

//	std::cout << "vector is empty ? " << myVector.empty() << std::endl;

	myVector.resize(8, 12);
	theirVector.resize(8, 12);
//	myVector.resize(17, 12);
//	myVector.push_back(12);
//	myVector.push_back(22);
//	myVector.push_back(32);
	std::cout << "print my vector after resize : "<<std::endl;
	ite = myVector.end();
	for (it0 = myVector.begin(); it0 != ite; ++it0)
		std::cout << *it0 << " ; ";
	std::cout << std::endl;
	ite = myVector.end();
	
//	myVector.clear();
	it0 = myVector.begin() + 2;
	std::cout << "mine : it0 + 2 = " << *it0 << std::endl;
//	ft::vector<int>::iterator itRetour = myVector.erase(it0);
	size_t diff = 2;
	ft::vector<int>::iterator itRetour = myVector.erase(it0, it0 + diff);
	std::cout << "mine : it retour = " << *itRetour << std::endl;

	std::vector<int>::iterator itT = theirVector.begin() + 2;
	std::cout << "theirs : itT + 2 = " << *itT << std::endl;
	std::vector<int>::iterator itTR = theirVector.erase(itT, itT + diff);
	std::cout << "theirs : itT retour = " << *itTR << std::endl;

	it0 = myVector.begin();
	ite = myVector.end();
	it0 + 4;
	std::cout << "MY VECTOR = " << std::endl;
	std::cout << "it0 + 4 = " << *it0 << std::endl;
	std::cout << "ite = " << *ite << std::endl;
	for (it0 = myVector.begin(); it0 != ite; ++it0)
		std::cout << *it0 << " ; ";
	std::cout << std::endl;

	itT = theirVector.begin();
	itT + 4;
	std::cout << "THEIR VECTOR = " << std::endl;
	std::cout << "itT + 4 = " << *itT << std::endl;
	std::vector<int>::iterator itTR2 = theirVector.end();
	for (itT = theirVector.begin(); itT != itTR2; ++itT)
		std::cout << *itT << " ; ";
	std::cout << std::endl;
	
	//	std::cout << "vector is empty ? " << myVector.empty() << std::endl;
	
	std::cout << "my vector = " <<std::endl;
//	myVector.assign(10, 100);
	myVector.clear();
	myVector.push_back(1);
	myVector.push_back(2);
	myVector.push_back(3);
	myVector.push_back(4);
	myVector.push_back(5);
	myVector.push_back(6);
	myVector.push_back(7);
	myVector.push_back(8);
	ite = myVector.end();
	for (it0 = myVector.begin(); it0 != ite; ++it0)
		std::cout << *it0 << " ; ";
	std::cout << std::endl;

	std::cout << "their vector = " <<std::endl;
//	theirVector.assign(10, 100);
	theirVector.clear();
	theirVector.push_back(1);
	theirVector.push_back(2);
	theirVector.push_back(3);
	theirVector.push_back(4);
	theirVector.push_back(5);
	theirVector.push_back(6);
	theirVector.push_back(7);
	theirVector.push_back(8);
	itTR2 = theirVector.end();
	for (itT = theirVector.begin(); itT != itTR2; ++itT)
		std::cout << *itT << " ; ";
	std::cout << std::endl;

	it0 = myVector.begin();
	it0 += 5;
	std::cout << "my +=5 : " << *it0 << std::endl;
	it0 -= 3;
	std::cout << "my -=3 : " << *it0 << std::endl;
	std::cout << "*it0++ = " << *it0++ << std::endl;
	std::cout << "*it0++ = " << *it0++ << std::endl;
	*it0 = 13;
	std::cout << "*it0 = 13 = " << *it0 << std::endl;
	
	itT = theirVector.begin();
	itT += 5;
	std::cout << "their +=5 : " << *itT << std::endl;
	itT -= 3;
	std::cout << "their -=3 : " << *itT << std::endl;
	std::cout << "*itT++ = " << *itT++ << std::endl;
	std::cout << "*itT++ = " << *itT++ << std::endl;
	*itT = 13;
	std::cout << "*it0 = 13 = " << *itT << std::endl;


	it0 = myVector.begin() + 2;
	itT = theirVector.begin() + 2;
	ft::vector<int>		myVector3;
	std::vector<int>	theirVector2;

	myVector3.assign(it0, it0 + 5);
	theirVector2.assign(itT, itT + 5);



	std::cout << "my vector 3= " <<std::endl;
	ite = myVector3.end();
	for (it0 = myVector3.begin(); it0 != ite; ++it0)
		std::cout << *it0 << " ; ";
	std::cout << std::endl;

	itTR2 = theirVector2.end();
	std::cout << "their vector 2= " <<std::endl;
	for (itT = theirVector2.begin(); itT != itTR2; ++itT)
		std::cout << *itT << " ; ";
	std::cout << std::endl;

	std::cout << "my vector = " <<std::endl;
	ite = myVector.end();
	for (it0 = myVector.begin(); it0 != ite; ++it0)
		std::cout << *it0 << " ; ";
	std::cout << std::endl;

	itTR2 = theirVector.end();
	std::cout << "their vector = " <<std::endl;
	for (itT = theirVector.begin(); itT != itTR2; ++itT)
		std::cout << *itT << " ; ";
	std::cout << std::endl;

	std::cout << "size of my vector = " << myVector.size() << std::endl;
	std::cout << "size of their vector = " << theirVector.size() << std::endl;
	std::cout << "capacity of my vector = " << myVector.capacity() << std::endl;
	std::cout << "capacity of their vector = " << theirVector.capacity() << std::endl;

	it0 = myVector.begin() + 3;
	myVector3.clear();
	myVector3.assign(10, 42);
	ft::vector<int>::iterator it1 = myVector3.begin() + 2;
//	std::cout << "return insert my = " << *(myVector.insert(it0, 42)) << std::endl;
//	myVector.insert(it0, 5, 19);
	myVector.insert(it0, it1, it1 + 2);
	ite = myVector.end();
	std::cout << "\nmy vector = " <<std::endl;
	for (it0 = myVector.begin(); it0 != ite; ++it0)
		std::cout << *it0 << " ; ";
	std::cout << std::endl;
	std::cout << "size of my vector = " << myVector.size() << std::endl;
	std::cout << "capacity of my vector = " << myVector.capacity() << std::endl;


	itT = theirVector.begin() + 3;
	theirVector2.clear();
	theirVector2.assign(10, 42);
	itTR2 = theirVector2.begin() + 2;
//	std::cout << "return insert their = " << *(theirVector.insert(itT, 42)) << std::endl;
//	theirVector.insert(itT, 5, 19);
	theirVector.insert(itT, itTR2, itTR2 + 2);
	itTR = theirVector.end();
	std::cout << "\ntheir vector = " <<std::endl;
	for (itT = theirVector.begin(); itT != itTR; ++itT)
		std::cout << *itT << " ; ";
	std::cout << std::endl;
	std::cout << "size of their vector = " << theirVector.size() << std::endl;
	std::cout << "capacity of their vector = " << theirVector.capacity() << std::endl;

//	myVector.swap(myVector3);
	swap(myVector, myVector3);
	ite = myVector.end();
	std::cout << "\nmy vector = " <<std::endl;
	for (it0 = myVector.begin(); it0 != ite; ++it0)
		std::cout << *it0 << " ; ";
	std::cout << std::endl;

//	theirVector.swap(theirVector2);
	swap(theirVector, theirVector2);
	itTR = theirVector.end();
	std::cout << "\ntheir vector = " <<std::endl;
	for (itT = theirVector.begin(); itT != itTR; ++itT)
		std::cout << *itT << " ; ";
	std::cout << std::endl;

	bool ret = myVector2 <= myVector;
	std::cout << "my <= = " << ret << std::endl;
	ret = theirVector2 <= theirVector;
	std::cout << "their <= = " << ret << std::endl;


	ret = myVector2 != myVector;
	std::cout << "my comparaison = " << ret << std::endl;

	ret = theirVector2 != theirVector;
	std::cout << "their comparaison = " << ret << std::endl;

	myVector2 = myVector;
	ret = myVector2 != myVector;
	std::cout << "my comparaison = " << ret << std::endl;

	theirVector2 = theirVector;
	ret = theirVector2 != theirVector;
	std::cout << "their comparaison = " << ret << std::endl;


	

	//ft::vector<int>::reverse_iterator it_rev = myVector.begin();
	ft::vector<int>::const_iterator it_rev = myVector.begin();
	std::cout << "const it = " << *it_rev << std::endl;
	ret = it_rev != it0;
	std::cout << "comparaison const_it et it = " << ret << std::endl;

	return 0;
}