#include <iostream>
#include <string>
#include <map>
#include "utils.hpp"
#include "pair.hpp"
#include "map.hpp"
#include "mapIte.hpp"

int	main()
{
	std::cout << "\n--- STD::MAP ---" <<std::endl;
	std::map<std::string, int>	theirMap;
	
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

	std::cout << "\n--- LEXICOGRAPHICAL COMPARE ---" <<std::endl;
	char foo[] = "Apple";
	char bar[] = "apartment";
	std::cout << "comparison apple vs apartment" << std::endl;
	std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9)<<std::endl;
	char foo2[] = "ple";
	std::cout << "comparison ple vs apartment" << std::endl;
	std::cout << ft::lexicographical_compare(foo2,foo2+3,bar,bar+9)<<std::endl;

	std::cout << "\n--- PAIR ---" <<std::endl;
	std::pair <std::string, int> product1;
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
	

	std::cout << "\n--- BST ---" <<std::endl;
	ft::BinarySearchTree<std::string, int> tr;
	std::cout << "tree is empty ? " << tr.isEmpty() << std::endl;
	ft::pair<std::string, int> a("lol", 9);
	ft::pair<std::string, int> b("koq", 3);
	ft::pair<std::string, int> c("cao", 7);
	ft::pair<std::string, int> d("zut", 1);
	ft::pair<std::string, int> e("blop", 47);
	ft::pair<std::string, int> f("bil", 3);
	ft::pair<std::string, int> g("boul", 2);
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
	ft::pair<std::string, int> h("bob", 38);
	tr.remove(h);
	tr.print_inorder();
	std::cout << std::endl;
	std::cout << "pair a is in tree ? " << tr.search(a) << std::endl;
	tr.remove(c);
	tr.remove(d);
	tr.print_inorder();
	std::cout << std::endl;
	tr.insert(a);
	ft::pair<std::string, int> i("mark", 18);
	tr.insert(i);
	tr.insert(c);
	ft::pair<std::string, int> j("paris", 75);
	tr.insert(j);
	ft::pair<std::string, int> k("cotentin", 59);
	tr.insert(k);
	tr.insert(d);
	ft::pair<std::string, int> l("sudoku", 4);
	tr.insert(l);
	ft::pair<std::string, int> m("zak", 11);
	tr.insert(m);
	tr.print_inorder();
	std::cout << std::endl;
	tr.remove(j);
	tr.remove(a);
	tr.remove(c);
	tr.remove(g);
	tr.print_inorder();
	std::cout << std::endl;

	std::cout << "\n--- FT::MAP ---" <<std::endl;
	ft::map<std::string, int>	myMap;
	
	int lol = myMap["c"] = 6;
	std::cout << "retour [] : " << lol <<std::endl;
	
	ft::pair<ft::map<std::string, int>::iterator, bool> ret4;
	ft::map<std::string, int>::iterator ret5;// = myMap.begin();
//	std::cout << "ret5* = " << (*ret5).first<<std::endl;
	ret4 = myMap.insert(ft::make_pair("a", 9));
//	std::cout << "retour insert, key " << ret4.first.getNodePtr()->data.first << std::endl;
	ret4 = myMap.insert(ft::make_pair("d", 3));
//	std::cout << "retour insert, key " << ret4.first.getNodePtr()->data.first << std::endl;
	std::cout << "myMap size = " << myMap.size() << std::endl;

	ft::map<std::string, int>::iterator itbis = myMap.begin();
	std::cout << "\nitbis->first = " << itbis->first<<std::endl;
	ft::map<std::string, int>::iterator itebis = myMap.end();
	std::cout << "itebis* = " << (*itebis).first<<std::endl;
	ret4 = myMap.insert(ft::make_pair("b", 23));
	itebis = myMap.end();
	//std::cout << "itebis* = " << (*itebis).first<<std::endl;
	while (itbis != myMap.end())
	{
		std::cout << itbis->first << " :: " << itbis->second << std::endl;
		itbis++;
	}
	myMap.insert(ft::make_pair("z", 7));
	myMap["e"] = 2;
	myMap["j"] = 4;
	itebis = myMap.end();
	for (itbis = myMap.begin(); itbis != itebis; ++itbis)
		std::cout << itbis->first << " :: " << itbis->second << " ; ";
	std::cout << std::endl;
	
	std::cout << "myMap size = " << myMap.size() << std::endl;
/*	if (myMap.find("j") != myMap.end())
		std::cout << "j found" <<std::endl;
	else
		std::cout << "j not found" <<std::endl;
	if (myMap.find("k") != myMap.end())
		std::cout << "k found" <<std::endl;
	else
		std::cout << "k not found" <<std::endl;
*/
	
	return 0;
}