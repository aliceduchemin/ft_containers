#include <iostream>
#include <string>
#include <map>
#include "utils.hpp"
#include "pair.hpp"
#include "map.hpp"
#include "mapIte.hpp"

int	main()
{
	std::map<std::string, int>	theirMap;
//	ft::map<std::string, int>	myMap;
	
	theirMap["jupiter"] = 6;
	std::cout << "theirMap[earth] = " << theirMap["earth"] << std::endl;
	std::cout << "theirMap size = " << theirMap.size() << std::endl;

	std::map<std::string, int>::iterator it = theirMap.begin();
	while (it != theirMap.end())
	{
		std::cout << it->first << " :: " << it->second << std::endl;
		it++;
	}	
	theirMap.insert(std::make_pair("sun", 9));
	theirMap.insert(std::make_pair("moon", 7));
	theirMap["earth"] = 2;
	theirMap["sun"] = 4;
	std::cout << std::endl;
	it = theirMap.begin();
	while (it != theirMap.end())
	{
		std::cout << it->first << " :: " << it->second << std::endl;
		it++;
	}	
	std::cout << "theirMap size = " << theirMap.size() << std::endl;
	if (theirMap.find("sun") != theirMap.end())
		std::cout << "word sun found" <<std::endl;
	else
		std::cout << "word sun not found" <<std::endl;
	if (theirMap.find("uranus") != theirMap.end())
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


	std::cout << "\n---- test bst ----" << std::endl;
	ft::BinarySearchTree<int, std::string> tr;
	std::cout << "tree is empty ? " << tr.isEmpty() << std::endl;
	ft::pair<int, std::string> a(9, "lol");
	ft::pair<int, std::string> b(3, "koq");
	ft::pair<int, std::string> c(7, "cao");
	ft::pair<int, std::string> d(1, "zut");
	ft::pair<int, std::string> e(47, "blop");
	ft::pair<int, std::string> f(3, "bil");
	ft::pair<int, std::string> g(2, "boul");
	tr.insert(a);
	tr.insert(b);
	tr.insert(c);
	tr.insert(d);
	tr.insert(e);
	tr.insert(f);
	tr.insert(g);
	std::cout << "tree is empty ? " << tr.isEmpty() << std::endl;
	std::cout << "pair a is in tree ? " << tr.search(a) << std::endl;
	std::cout << "pair c is in tree ? " << tr.search(c) << std::endl;
	std::cout << "print tree in order : " << std::endl;
	tr.print_inorder();
	std::cout << std::endl;
	ft::pair<int, std::string> h(38, "bob");
	tr.remove(h);
	tr.print_inorder();
	std::cout << std::endl;
	std::cout << "pair a is in tree ? " << tr.search(a) << std::endl;
	tr.remove(c);
	tr.remove(d);
	tr.print_inorder();
	std::cout << std::endl;
	tr.insert(a);
	ft::pair<int, std::string> i(18, "mark");
	tr.insert(i);
	tr.insert(c);
	ft::pair<int, std::string> j(75, "paris");
	tr.insert(j);
	ft::pair<int, std::string> k(59, "cotentin");
	tr.insert(k);
	tr.insert(d);
	ft::pair<int, std::string> l(4, "sudoku");
	tr.insert(l);
	ft::pair<int, std::string> m(11, "zak");
	tr.insert(m);
	tr.print_inorder();
	std::cout << std::endl;
	tr.remove(j);
	tr.remove(a);
	tr.remove(c);
	tr.remove(g);
	tr.print_inorder();
	std::cout << std::endl;

	/*std::pair <std::string, int> product1;
	ft::pair <std::string, int> product1bis;
	std::pair <std::string, int> product2 ("tomatoes", 2);
	ft::pair <std::string, int> product2bis ("tomatoes", 2);
	ft::pair <std::string, int> product3 (product2bis);
	ft::pair <std::string, int> product4;

	product1bis = ft::make_pair(std::string("lightbulbs"), 1);
	product4.first = "shoes";
	product4.second = 39;

	std::cout << "The price of " << product1.first << " is €" << product1.second << std::endl;
	std::cout << "The price of " << product1bis.first << " is €" << product1bis.second << std::endl;
	std::cout << "The price of " << product2.first << " is €" << product2.second << std::endl;
	std::cout << "The price of " << product3.first << " is €" << product3.second << std::endl;
	std::cout << "The price of " << product4.first << " is €" << product4.second << std::endl;
	bool ret = product1 < product2;
	bool ret2 = product1bis < product2bis;
	std::cout << "product1 < product2 ? " << ret << " " << ret2 << std::endl;
	ret = product1 > product2;
	ret2 = product1bis > product2bis;
	std::cout << "product1 > product2 ? " << ret << " " << ret2 << std::endl;
	ret = product1 <= product2;
	ret2 = product1bis <= product2bis;
	std::cout << "product1 <= product2 ? " << ret << " " << ret2 << std::endl;
	ret = product1 >= product2;
	ret2 = product1bis >= product2bis;
	std::cout << "product1 >= product2 ? " << ret << " " << ret2 << std::endl;
	ret = product1 == product2;
	ret2 = product1bis == product2bis;
	std::cout << "product1 == product2 ? " << ret << " " << ret2 << std::endl;
	ret = product1 != product2;
	ret2 = product1bis != product2bis;
	std::cout << "product1 != product2 ? " << ret << " " << ret2 << std::endl;
	*/
	
	return 0;
}