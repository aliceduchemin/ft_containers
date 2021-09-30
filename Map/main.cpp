#include <iostream>
#include <string>
#include <map>
#include "utils.hpp"
#include "pair.hpp"
#include "map.hpp"
#include "mapIte.hpp"

int	main()
{
	std::map<std::string, int>	myMap;
	
	myMap["jupiter"] = 6;
	std::cout << "myMap[earth] = " << myMap["earth"] << std::endl;
	std::cout << "myMap size = " << myMap.size() << std::endl;

	std::map<std::string, int>::iterator it = myMap.begin();
	while (it != myMap.end())
	{
		std::cout << it->first << " :: " << it->second << std::endl;
		it++;
	}	
	myMap.insert(std::make_pair("sun", 9));
	myMap.insert(std::make_pair("moon", 7));
	myMap["earth"] = 2;
	myMap["sun"] = 4;
	std::cout << std::endl;
	it = myMap.begin();
	while (it != myMap.end())
	{
		std::cout << it->first << " :: " << it->second << std::endl;
		it++;
	}	
	std::cout << "myMap size = " << myMap.size() << std::endl;
	if (myMap.find("sun") != myMap.end())
		std::cout << "word sun found" <<std::endl;
	else
		std::cout << "word sun not found" <<std::endl;
	if (myMap.find("uranus") != myMap.end())
		std::cout << "word uranus found" <<std::endl;
	else
		std::cout << "word uranus not found" <<std::endl;

	char foo[] = "Apple";
	char bar[] = "apartment";
	std::cout << "comparison apple vs apartment" << std::endl;
	std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9)<<std::endl;
	char foo2[] = "ple";
	std::cout << "comparison ple vs apartment" << std::endl;
	std::cout << ft::lexicographical_compare(foo2,foo2+3,bar,bar+9)<<std::endl;


	std::cout << "test bst" << std::endl;
	ft::BinarySearchTree<int> tr;
	std::cout << "tree is empty ? " << tr.isEmpty() << std::endl;
	tr.insert(9);
	tr.insert(3);
	tr.insert(7);
	tr.insert(1);
	tr.insert(47);
	tr.insert(3);
	tr.insert(2);
	std::cout << "tree is empty ? " << tr.isEmpty() << std::endl;
	std::cout << "value 9 is in tree ? " << tr.search(9) << std::endl;
	std::cout << "value 7 is in tree ? " << tr.search(7) << std::endl;
	std::cout << "print tree in order : " << std::endl;
	tr.print_inorder();
	std::cout << std::endl;
	tr.remove(38);
	tr.print_inorder();
	std::cout << std::endl;
	std::cout << "value 9 is in tree ? " << tr.search(9) << std::endl;
	tr.remove(7);
	tr.remove(1);
	tr.print_inorder();
	std::cout << std::endl;
	tr.insert(9);
	tr.insert(18);
	tr.insert(7);
	tr.insert(75);
	tr.insert(59);
	tr.insert(1);
	tr.insert(4);
	tr.insert(11);
	tr.print_inorder();
	std::cout << std::endl;
	tr.remove(75);
	tr.remove(9);
	tr.remove(7);
	tr.remove(2);
	tr.print_inorder();
	std::cout << std::endl;
	return 0;
}