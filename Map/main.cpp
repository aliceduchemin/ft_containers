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
	std::cout << "print end " << theirMap.end()->first<<std::endl;
	while (it != theirMap.end())
	{
		std::cout << it->first << " :: " << it->second << std::endl;
		it++;
	}	
	theirMap.insert(std::make_pair("sun", 9));
	theirMap.insert(std::make_pair("moon", 7));
	int loli = theirMap["pluto"] = 6;
	std::cout << "pluto = " << theirMap["pluto"] << std::endl;
	theirMap["earth"] = 2;
	theirMap["sun"] = 4;
	theirMap["earth"] = 18;
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

	theirMap.insert(std::make_pair("b", 3));
	int lola = theirMap["b"] = 60;
	std::cout << "retour [b] : " << lola <<std::endl;
	theirMap.insert(std::make_pair("b", 23));
	it = theirMap.begin();
	while (it != theirMap.end())
	{
		std::cout << it->first << " :: " << it->second << std::endl;
		it++;
	}	

	std::cout << "\n--- MAP ITERATORS ---" <<std::endl;
	it = theirMap.begin();
//	it = it + 5; pas possible
	std::cout << theirMap["sun"] << std::endl;


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
	

	std::cout << "\n--- BST ---" <<std::endl;/*
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
	std::cout << "pair a is in tree ? " << tr.search(a.first) << std::endl;
	std::cout << "pair c is in tree ? " << tr.search(c.first) << std::endl;
	std::cout << "print tree in order : " << std::endl;
	tr.print_inorder();
	std::cout << std::endl;
	ft::pair<std::string, int> h("bob", 38);
	tr.remove(h.first);
	tr.print_inorder();
	std::cout << std::endl;
	std::cout << "pair a is in tree ? " << tr.search(a.first) << std::endl;
	tr.remove(c.first);
	tr.remove(d.first);
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
	std::cout << std::endl;
	tr.print_inorder();
	std::cout << std::endl;
	tr.remove(j.first);
	tr.remove(a.first);
	tr.remove(c.first);
	tr.remove(g.first);
	std::cout << std::endl;
	tr.print_inorder();
	std::cout << std::endl;*/

	std::cout << "\n--- FT::MAP ---" <<std::endl;
	ft::map<std::string, int>	myMap;
	myMap.insert(ft::make_pair("f", 10));
	myMap.insert(ft::make_pair("a", 9));
	myMap.insert(ft::make_pair("b", 3));
	myMap.insert(ft::make_pair("z", 1));
	myMap.insert(ft::make_pair("c", 7));
	std::cout << "myMap[r] = " << myMap["r"] << std::endl;
	
	int lol = myMap["a"];
	std::cout << "retour [a] : " << lol <<std::endl;
	lol = myMap["c"] = 8;
	std::cout << "retour [c] : " << lol <<std::endl;
	lol = myMap["y"] = 6;
	std::cout << "retour [y] : " << lol <<std::endl;
	lol = myMap["u"] = 41;
	std::cout << "retour [u] : " << lol <<std::endl;
	lol = myMap["b"] = 60;
	std::cout << "retour [b] : " << lol <<std::endl;
	
	ft::pair<ft::map<std::string, int>::iterator, bool> ret4;
//	ft::map<std::string, int>::iterator ret5;// = myMap.begin();
//	std::cout << "retour insert, key " << ret4.first.getNodePtr()->data.first << std::endl;
	ret4 = myMap.insert(ft::make_pair("a", 9));
	ret4 = myMap.insert(ft::make_pair("d", 3));
	std::cout << "myMap size = " << myMap.size() << std::endl;

	ft::map<std::string, int>::iterator itbis = myMap.begin();
	ft::map<std::string, int>::iterator itebis = myMap.end();
	ret4 = myMap.insert(ft::make_pair("b", 23));
	itebis = myMap.end();
	std::cout << "print my map : "<<std::endl;
	while (itbis != myMap.end())
	{
		std::cout << itbis->first << " :: " << itbis->second << std::endl;
		itbis++;
	}
	myMap.insert(ft::make_pair("z", 7));
	myMap["j"] = 4;
	myMap["e"] = 2;
	itebis = myMap.end();
	for (itbis = myMap.begin(); itbis != itebis; ++itbis)
		std::cout << itbis->first << " :: " << itbis->second << " ; ";
	std::cout << std::endl;
	
	std::cout << "myMap size = " << myMap.size() << std::endl;
	if (myMap.find("j") != myMap.end())
		std::cout << "j found" <<std::endl;
	else
		std::cout << "j not found" <<std::endl;
	if (myMap.find("k") != myMap.end())
		std::cout << "k found" <<std::endl;
	else
		std::cout << "k not found" <<std::endl;

	itbis = myMap.begin();
	std::cout <<"itbis begin = " << itbis->first<<std::endl;
	itbis++;
	std::cout << "itbis++ : " << itbis->first << std::endl;
	itbis++;
	std::cout << "itbis++ : " << itbis->first << std::endl;
	itbis++;
	std::cout << "itbis++ : " << itbis->first << std::endl;
	itbis--;
	std::cout << "itbis-- : " << itbis->first << std::endl;
	itbis--;
	std::cout << "itbis-- : " << itbis->first << std::endl;
	itbis--;
	std::cout << "itbis-- : " << itbis->first << std::endl;
	
	ft::map<std::string, int> myMap2;
	itbis++;
	itbis++;
	myMap2.insert(itbis, myMap.end());
	ft::map<std::string, int>::iterator it2bis = myMap2.begin();
	ft::map<std::string, int>::iterator ite2bis = myMap2.end();
	myMap2["f"] = 6;
	std::cout <<"it2bis = " << it2bis->first<<std::endl;
	std::cout <<"ite2bis = " << myMap2.end()->first<<std::endl;
	std::cout << "\nPrinting myMap2 : " <<std::endl;
	for (it2bis = myMap2.begin(); it2bis != ite2bis; ++it2bis)
		std::cout << it2bis->first << " :: " << it2bis->second << " ; ";
	std::cout << std::endl;

	it2bis = myMap2.begin();
	std::cout << "it2bis begin : " << it2bis->first << std::endl;
	it2bis++;
	std::cout << "it2bis++ : " << it2bis->first << std::endl;
	it2bis++;
	std::cout << "it2bis++ : " << it2bis->first << std::endl;
	it2bis++;
	std::cout << "it2bis++ : " << it2bis->first << std::endl;
	it2bis++;
	std::cout << "it2bis++ : " << it2bis->first << std::endl;
	it2bis++;
	std::cout << "it2bis++ : " << it2bis->first << std::endl;
	it2bis--;
	std::cout << "it2bis-- : " << it2bis->first << std::endl;
	it2bis--;
	std::cout << "it2bis-- : " << it2bis->first << std::endl;
	it2bis--;
	std::cout << "it2bis-- : " << it2bis->first << std::endl;
	it2bis--;
	std::cout << "it2bis-- : " << it2bis->first << std::endl;
	it2bis--;
	std::cout << "it2bis-- : " << it2bis->first << std::endl;
	it2bis = myMap2.insert(it2bis, ft::make_pair("x", 99));
	myMap2["a"] = 86;
	myMap2["b"] = 89;
	std::cout << "\nPrinting myMap2 : " <<std::endl;
	for (it2bis = myMap2.begin(); it2bis != ite2bis; ++it2bis)
		std::cout << it2bis->first << " :: " << it2bis->second << " ; ";
	std::cout << std::endl;
	ft::map<std::string, int>	myMap3(myMap2);
//	myMap3 = myMap2;
	std::cout <<"Copy : " <<std::endl;
//	myMap2.erase
	ft::map<std::string, int>::iterator it3bis = myMap3.begin();
	ft::map<std::string, int>::iterator ite3bis = myMap3.end();
	std::cout << "\nPrinting myMap3 : " <<std::endl;
	for (it3bis = myMap2.begin(); it3bis != ite3bis; ++it3bis)
		std::cout << it3bis->first << " :: " << it3bis->second << " ; ";
	std::cout << std::endl;

	std::cout << "erase tests : " << std::endl;
	myMap2.erase("c");
	myMap2.erase("a");
	myMap2.erase("z");
	myMap2.erase("y");
	it2bis = myMap2.begin();
	it2bis++;
	ite2bis = it2bis;
	ite2bis++;
	ite2bis++;
	ite2bis++;
	std::cout <<"start of iterator erase : " << it2bis->first << std::endl;
	std::cout <<"end of iterator erase : " << ite2bis->first << std::endl;
	myMap2.erase(it2bis, ite2bis);
	ite2bis = myMap2.end();
	std::cout << "\nPrinting myMap2 : " <<std::endl;
	for (it2bis = myMap2.begin(); it2bis != ite2bis; ++it2bis)
		std::cout << it2bis->first << " :: " << it2bis->second << " ; ";
	std::cout << std::endl;

//à tester après implémentation reverse iterator :
/*	std::cout << "Comp : " << std::endl;
	std::map<char,int>	theirTestMap;
	std::map<char,int>::key_compare theirComp = theirTestMap.key_comp();
	theirTestMap['a']=100;
	theirTestMap['c']=200;
	theirTestMap['b']=300;
	char highest = theirTestMap.rbegin()->first;
	std::map<char,int>::iterator ik = theirTestMap.begin();
	do {
		std::cout << ik->first << " => " <<ik->second<<"\n";
	} while ( theirComp((*ik++).first, highest));
	std::cout << std::endl;*/
	return 0;
}