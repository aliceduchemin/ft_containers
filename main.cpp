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
#include <list>
#include "list.hpp"

void	testRealList()
{
	std::list<int>	lst;

	/*****************************/
	std::cout << "optional sequence operations" << std::endl;
	std::cout << "push back/front, pop back/front" << std::endl;
	lst.push_back( 1 );
	lst.push_back( 2 );
	lst.push_back( 4 );
	lst.pop_back();
	lst.push_back( 7 );

	std::cout << "lst.front()" << std::endl;
	std::cout << lst.front() << std::endl;

	/*****************************/
	std::cout << "container requirements" << std::endl;
	std::cout << "+ default constructor & destructor" << std::endl;
	std::cout << "+ iterator & const_iterator" << std::endl;

	std::cout << "X(a) -> std::list<int>	lst3(lst)" << std::endl;
	std::list<int>	lst3(lst);
	std::cout << "X u(a) -> std::list<int>	lst4(lst)" << std::endl;
	std::list<int>	lst4(lst);
	std::cout << "X u = a -> std::list<int>	lst2 = lst" << std::endl;
	std::list<int>	lst2 = lst;

	bool	comp;
	comp = lst2 == lst3;
	std::cout << "lst2 == lst3 ? " << comp << std::endl;
	comp = lst2 != lst3;
	std::cout << "lst2 != lst3 ? " << comp << std::endl;

	lst3.assign(3, 100);
	std::cout << "lst3 is empty ? "  << lst3.empty() << std::endl;
	std::cout << "lst3.swap(lst2)" << std::endl;
	lst3.swap(lst2);

	std::cout << "size of lst2 : "  << lst2.size() << std::endl;
	std::cout << "max size lst2 : " << lst2.max_size() << std::endl;

	comp = lst2 < lst3;
	std::cout << "lst2 < lst3 ? "  << comp << std::endl;

	std::cout << "a.begin() et a.end()" << std::endl;
	std::list<int>::iterator it = lst2.begin();
	std::list<int>::iterator ite = lst2.end();

	std::cout << "lst2 : " << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ; ";
		it++;
	}
	std::cout << std::endl;

	/*****************************/
	std::cout << "\nreversible container requirements" << std::endl;
	std::cout << "+ reverse_iterator & const_reverse_iterator" << std::endl;

	std::cout << "a.rbegin() et a.rend()" << std::endl;
	std::list<int>::reverse_iterator it2 = lst.rbegin();
	std::list<int>::reverse_iterator ite2 = lst.rend();
	
	std::cout << "lst1 : " << std::endl;
	while (it2 != ite2)
	{
		std::cout << *it2 << " ; ";
		it2++;
	}
	std::cout << std::endl;
	/*****************************/
	std::cout << "\nsequence requirements" << std::endl;
	std::cout << "X(n, t) -> lst5(4, 1000) (constructs a sequence with n copies of t)" << std::endl;
	std::list<int>	lst5(4, 1000);
	std::list<int>::iterator it3 = lst5.begin();
	std::list<int>::iterator ite3 = lst5.end();

	std::cout << "lst5 : " << std::endl;
	while (it3 != ite3)
	{
		std::cout << *it3 << " ; ";
		it3++;
	}
	std::cout << std::endl;

	std::cout << "X(i, j) ->  (constructs a sequence equal to the range [i, j))" << std::endl;


	std::cout << "a.insert(iterator position, valeur) -> lst5.insert(it, 7). Inserts a copy of 7 before it" << std::endl;
	lst5.insert(it3, 7);

	std::cout << "a.insert(iterator position, nb éléments à insérer, valeur) -> lst5.insert(it, 2, 124)" << std::endl;
	lst5.insert(it3, 2, 124);

	std::list<int> lst6;
	lst6.insert(lst6.begin(), 287);
	std::list<int>::iterator it4 = lst6.begin();
	std::list<int>::iterator ite4 = lst6.end();
	std::cout << "a.insert(iterator position, iterator début insertion, iterator fin insertion) -> lst5.insert(ite3, it4, ite4)" << std::endl;
	lst5.insert(ite3, it4, ite4);

	std::cout << "lst5 : " << std::endl;
	for (it3 = lst5.begin(); it3 != ite3; ++it3)
		std::cout << *it3 << " ; ";
	std::cout << std::endl;

	std::cout << "lst5 erase first elem -> lst5.erase(it3, 4) : " << std::endl;
	it3 = lst5.begin();
//	advance(it3, 4);
	lst5.erase(it3);
	std::cout << "lst5 erase several elem -> lst5.erase(it3, it3bis) : " << std::endl;
	it3 = lst5.begin();
	it3++;
	std::list<int>::iterator it3bis = it3;
	it3bis++;
	it3bis++;
	it3bis++;
	lst5.erase(it3, it3bis);
	for (it3 = lst5.begin(); it3 != ite3; ++it3)
		std::cout << *it3 << " ; ";
	std::cout << std::endl;
	
	std::cout << "clear lst5 : " << std::endl;
	lst5.clear();
	std::cout << "lst5 is empty ? " << lst5.empty() << std::endl;
}

int	main()
{
	testRealList();

	std::cout << "\ncustom list" << std::endl;
	ft::list<int>	myList;

	myList.push_back(1);
	myList.push_back(2);
	myList.push_back(3);
	myList.push_back(4);
	myList.push_back(5);
	myList.push_back(6);

	/*std::list<int>::iterator it = myList.begin();
	std::list<int>::iterator ite = myList.end();
	for (it = myList.begin(); it != ite; ++it)
		std::cout << *it << " ; ";
	std::cout << std::endl;*/
//	ft::list<int>::iterator it = myList.begin();
	ft::list<int>::t_list * it;
//	int * ite;
	it = myList.begin();
/*	std::cout << *it << std::endl;
	//it += sizeof(int *);
	//std::cout << it << std::endl;
	ite = myList.end();
	std::cout << *ite << std::endl;*/
/*
	std::cout << "list size = " << myList.size() << std::endl;
	myList.pop_back();
	std::cout << "list size = " << myList.size() << std::endl;
	it = myList.begin();
	std::cout << "begin = " << *it << std::endl;
	ite = myList.end();
	std::cout << "end = " << *it << std::endl;

	while (it != ite)
	{
		std::cout << *it << " ; ";
		it++;
	}*/
//	for (it = myList.begin(); it != ite; ++it)
//		std::cout << *it << " ; ";
	std::cout << std::endl;
	return 0;
}