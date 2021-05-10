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

int	main()
{
	std::list<int>	lst;

	lst.push_back( 1 );
	lst.push_back( 2 );
	lst.push_back( 4 );
	lst.pop_back();
	lst.push_back( 7 );

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
	std::cout << "X(n, t) -> lst5(4, 1000)" << std::endl;
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

	return 0;
}