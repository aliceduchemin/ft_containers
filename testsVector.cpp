#include "testsContainers.hpp"

void	testInt()
{
	ft::vector<int>		cont;

	cont.push_back(1);
	std::cout << "push back 1, capacity ? " << cont.capacity() << std::endl;
	std::cout << "push back 1, size ? " << cont.size() << std::endl;
	std::cout << "push backs et pop backs :"<<std::endl;
	cont.push_back(2);
	cont.push_back(3);
	cont.pop_back();
	cont.push_back(4);
	cont.push_back(5);
	cont.push_back(6);
	cont.pop_back();
	std::cout << "vct.front() : " << cont.front() << std::endl;
	std::cout << "vct.back() : " << cont.back() << std::endl;
	std::cout << "push back 1, capacity ? " << cont.capacity() << std::endl;
	std::cout << "push back 1, size ? " << cont.size() << std::endl;
	ft::vector<int>::iterator it = cont.begin();
	ft::vector<int>::iterator ite = cont.end();
	std::cout << "print vector : "<<std::endl;
	ite = cont.end();
	for (it = cont.begin(); it != ite; ++it)
		std::cout << *it << " ; ";
	std::cout << std::endl;
	
	std::cout << "it + n : "<<std::endl;
	it = cont.begin() + 2;
	std::cout << "it + 2 = " << *it << std::endl;
	it = cont.begin();
	it += 5;
	std::cout << "begin +=5 : " << *it << std::endl;
	it -= 3;
	std::cout << "-=3 : " << *it << std::endl;
	std::cout << "*it++ = " << *it++ << std::endl;
	std::cout << "*it++ = " << *it++ << std::endl;
	*it = 13;
	std::cout << "*it = 13 = " << *it << std::endl;

	size_t diff = 2;
	ft::vector<int>::iterator itRetour = cont.erase(it, it + diff);
	std::cout << "valeur retour erase = " << *itRetour << std::endl;


	std::cout << "print vector after resize : "<<std::endl;
	cont.resize(8, 12);
	ite = cont.end();
	for (it = cont.begin(); it != ite; ++it)
		std::cout << *it << " ; ";
	std::cout << std::endl;


	std::cout << "at() : "<<std::endl;
	cont.clear();
	cont.push_back(1);
	cont.push_back(2);
	cont.push_back(3);
	cont.push_back(4);
	cont.push_back(5);
	cont.push_back(6);
	cont.push_back(7);
	cont.push_back(8);
	ite = cont.end();
	for (it = cont.begin(); it != ite; ++it)
		std::cout << *it << " ; ";
	std::cout << std::endl;
	std::cout << "at(0) = " << cont.at(0) <<std::endl;
	std::cout << "at(1) = " << cont.at(1) <<std::endl;
	std::cout << "at(2) = " << cont.at(2) <<std::endl;
}

void	testInt2()
{
	ft::vector<int>	vct;

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

	ft::vector<int>::iterator it0 = vct.begin();
	ft::vector<int>::iterator ite0 = vct.end();

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
	ft::vector<int>	vct3(vct);
	std::cout << "X u(a) -> std::vector<int>	vct4(vct)" << std::endl;
	ft::vector<int>	vct4(vct);
	std::cout << "X u = a -> std::vector<int>	vct2 = vct" << std::endl;
	ft::vector<int>	vct2 = vct;

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
	ft::vector<int>::iterator it = vct2.begin();
	ft::vector<int>::iterator ite = vct2.end();

	std::cout << "vct2 : " << std::endl;
	while (it != ite)
	{
		std::cout << *it << " ; ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "\nsequence requirements" << std::endl;
	std::cout << "X(n, t) -> vct5(4, 1000) (constructs a sequence with n copies of t)" << std::endl;
	ft::vector<int>	vct5(4, 1000);
	ft::vector<int>::iterator it3 = vct5.begin();
	ft::vector<int>::iterator ite3 = vct5.end();

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

	ft::vector<int> vct6;
	vct6.insert(vct6.begin(), 287);

	ite3 = vct5.end(); //pas nécessaire pour une liste
	std::cout << "vct5 : " << std::endl;
	for (it3 = vct5.begin(); it3 != ite3; ++it3)
		std::cout << *it3 << " ; ";
	std::cout << std::endl;

	std::cout << "vct5 erase first elem -> vct5.erase(it3, 4) : " << std::endl;
	it3 = vct5.begin();
	vct5.erase(it3);
	std::cout << "vct5 erase several elem -> vct5.erase(it3, it3bis) : " << std::endl;
	it3 = vct5.begin();
	it3++;
	ft::vector<int>::iterator it3bis = it3;
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
