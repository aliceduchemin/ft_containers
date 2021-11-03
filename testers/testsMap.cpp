/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsMap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:46:04 by aduchemi          #+#    #+#             */
/*   Updated: 2021/10/27 17:46:06 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testsContainers.hpp"

void	mapTests()
{
	std::cout << "Creating a map, NMSPC::make_pair, inserting elements with insert and [] :" << std::endl;
	std::cout << "Values inserted : [f][10], [a][9], [b][3], [z][1], [c][7], [y][6], [s][79]" << std::endl;
	NMSPC::map<std::string, int>	myMap;
	myMap.insert(NMSPC::make_pair("f", 10));
	myMap.insert(NMSPC::make_pair("a", 9));
	myMap.insert(NMSPC::make_pair("b", 3));
	myMap.insert(NMSPC::make_pair("z", 1));
	myMap.insert(NMSPC::make_pair("c", 7));
	myMap.insert(NMSPC::make_pair("y", 6));
	myMap.insert(NMSPC::make_pair("s", 79));

	std::cout << "\nAdding via operator[], checking the return value :" << std::endl;
	std::cout << "map[r] = " << myMap["r"] << std::endl;
	int lol = myMap["u"] = 567;
	std::cout << "retour [u] : " << lol <<std::endl;
	lol = myMap["c"] = 8;
	std::cout << "retour [c] : " << lol <<std::endl;
	lol = myMap["y"] = 6;
	std::cout << "retour [y] : " << lol <<std::endl;
	lol = myMap["u"] = 41;
	std::cout << "retour [u] : " << lol <<std::endl;
	lol = myMap["b"] = 60;
	std::cout << "retour [b] : " << lol <<std::endl;
	std::cout << "Values inserted : [r]X, [u][567], [c][8], [y][6], [u][41], [b][60]" << std::endl;
	std::cout << "Map size : " << myMap.size() << std::endl;
	std::cout << "\nChanging value of already existing key with operator[] ([b][78])" << std::endl;
	myMap["b"] = 78;
	
	std::cout << "Trying to insert already existing key ([a][18])" << std::endl;
	myMap.insert(NMSPC::make_pair("a", 18));
	std::cout << "Map size : " << myMap.size() << std::endl;

	NMSPC::map<std::string, int>::iterator itbis = myMap.begin();
	NMSPC::map<std::string, int>::iterator itebis = myMap.end();
	std::cout << "Print map : "<<std::endl;
	for (itbis = myMap.begin(); itbis != itebis; ++itbis)
		std::cout << itbis->first << " :: " << itbis->second << " ; ";
	std::cout << std::endl;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "begin() and end() :" << std::endl;
	std::cout << "map.begin() = " << myMap.begin()->first << " :: " << myMap.begin()->second << std::endl;
	itebis = myMap.end();
	itebis--;
	std::cout << "map.end() - 1 = " << itebis->first << " :: " << itebis->second << std::endl;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Find elements, existing and not :" << std::endl;
	if (myMap.find("s") != myMap.end())
		std::cout << "s found" <<std::endl;
	else
		std::cout << "s not found" <<std::endl;
	if (myMap.find("k") != myMap.end())
		std::cout << "k found" <<std::endl;
	else
		std::cout << "k not found" <<std::endl;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Insert range (from 2nd to last elem of map in new map (map2)) :" << std::endl;
	NMSPC::map<std::string, int> myMap2;
	itbis = myMap.begin();
	itbis++;
	myMap2.insert(itbis, myMap.end());
	NMSPC::map<std::string, int>::iterator it2bis = myMap2.begin();
	NMSPC::map<std::string, int>::iterator ite2bis = myMap2.end();
	std::cout << "Printing new map (map2) : " <<std::endl;
	for (it2bis = myMap2.begin(); it2bis != ite2bis; ++it2bis)
		std::cout << it2bis->first << " :: " << it2bis->second << " ; ";
	std::cout << std::endl;
	
	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Insert value at position ([x][99] at last position) :" << std::endl;
	it2bis = myMap2.insert(it2bis, NMSPC::make_pair("x", 99));
	std::cout << "Printing map2 : " <<std::endl;
	for (it2bis = myMap2.begin(); it2bis != ite2bis; ++it2bis)
		std::cout << it2bis->first << " :: " << it2bis->second << " ; ";
	std::cout << std::endl;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Copy constructor :" << std::endl;
	NMSPC::map<std::string, int>	myMap3(myMap2);
	NMSPC::map<std::string, int>::iterator it3bis = myMap3.begin();
	NMSPC::map<std::string, int>::iterator ite3bis = myMap3.end();
	std::cout << "Printing new map (map3) : " <<std::endl;
	for (it3bis = myMap3.begin(); it3bis != ite3bis; ++it3bis)
		std::cout << it3bis->first << " :: " << it3bis->second << " ; ";
	std::cout << std::endl;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Operator = :" << std::endl;
	NMSPC::map<std::string, int>	myMap4;
	myMap4 = myMap2;
	NMSPC::map<std::string, int>::iterator it4bis = myMap4.begin();
	NMSPC::map<std::string, int>::iterator ite4bis = myMap4.end();
	std::cout << "Printing new map (map4) : " <<std::endl;
	for (it4bis = myMap4.begin(); it4bis != ite4bis; ++it4bis)
		std::cout << it4bis->first << " :: " << it4bis->second << " ; ";
	std::cout << std::endl;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Erase tests : " << std::endl;
	std::cout << "Erase iterator position (2nd element)" << std::endl;
	it2bis = myMap2.begin();
	it2bis++;
	myMap2.erase(it2bis);
	std::cout << "Printing partially erased map (map2) : " <<std::endl;
	for (it2bis = myMap2.begin(); it2bis != myMap2.end(); ++it2bis)
		std::cout << it2bis->first << " :: " << it2bis->second << " ; ";
	std::cout << std::endl;

	std::cout << "\nErase key (y and z)" << std::endl;
	myMap2.erase("y");
	myMap2.erase("z");
	std::cout << "Printing partially erased map (map2) : " <<std::endl;
	for (it2bis = myMap2.begin(); it2bis != myMap2.end(); ++it2bis)
		std::cout << it2bis->first << " :: " << it2bis->second << " ; ";
	std::cout << std::endl;

	std::cout << "\nErase range (2nd to 4th element)" << std::endl;
	it2bis = myMap2.begin();
	it2bis++;
	ite2bis = it2bis;
	ite2bis++;
	ite2bis++;
	ite2bis++;
	ite2bis++;
	std::cout <<"Start of iterator erase : " << it2bis->first << std::endl;
	std::cout <<"End of iterator erase : " << ite2bis->first << std::endl;
	myMap2.erase(it2bis, ite2bis);
	std::cout << "Printing partially erased map (map2) : " <<std::endl;
	for (it2bis = myMap2.begin(); it2bis != myMap2.end(); ++it2bis)
		std::cout << it2bis->first << " :: " << it2bis->second << " ; ";
	std::cout << std::endl;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Swaping maps map and map2: " <<std::endl;
	std::cout << "Printing map before swap : " <<std::endl;
	itebis = myMap.end();
	for (itbis = myMap.begin(); itbis != itebis; ++itbis)
		std::cout << itbis->first << " :: " << itbis->second << " ; ";
	std::cout << std::endl;
	itbis = myMap.begin();

	ite2bis = myMap2.end();
	std::cout << "Printing map2 before swap : " <<std::endl;
	for (it2bis = myMap2.begin(); it2bis != ite2bis; ++it2bis)
		std::cout << it2bis->first << " :: " << it2bis->second << " ; ";
	std::cout << std::endl;
	it2bis = myMap2.begin();

	std::cout << "Swap" <<std::endl;
	myMap.swap(myMap2);
	int restSwap = (itbis == myMap2.begin());
	std::cout << "Checking validity of iterators and pointers after the swap : " <<std::endl;
	std::cout << "itbis == myMap2.begin() ? " <<  restSwap <<std::endl;
	restSwap = (it2bis == myMap.begin());
	std::cout << "it2bis == myMap.begin() ? " <<  restSwap <<std::endl;

	std::cout << "Printing map : " <<std::endl;
	itebis = myMap.end();
	for (itbis = myMap.begin(); itbis != itebis; ++itbis)
		std::cout << itbis->first << " :: " << itbis->second << " ; ";
	std::cout << std::endl;

	std::cout << "Printing map2 : " <<std::endl;
	ite2bis = myMap2.end();
	for (it2bis = myMap2.begin(); it2bis != ite2bis; ++it2bis)
		std::cout << it2bis->first << " :: " << it2bis->second << " ; ";
	std::cout << std::endl;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Count : " <<std::endl;
	std::cout << "count b : "<< myMap.count("b")<<std::endl;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Key_comp() :" <<std::endl;
	NMSPC::map<char, int> test;
	NMSPC::map<char, int>::key_compare mycomp = test.key_comp();
	test['a']=100;
	test['c']=300;
	test['b']=200;
	char highest = test.rbegin()->first;
	NMSPC::map<char, int>::iterator testIt = test.begin();
	do {
		std::cout << testIt->first << " => " << testIt->second << std::endl;
	} while ( mycomp((*testIt++).first, highest) );
	std::cout << std::endl;

	std::cout << "Value_comp() :" <<std::endl;
	NMSPC::pair<char, int> highest2 = *test.rbegin();
	testIt = test.begin();
	do {
		std::cout << testIt->first << " => " << testIt->second << std::endl;
	} while ( test.value_comp()(*testIt++, highest2) );

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Bounds & equal_range : " <<std::endl;
	itbis = myMap.lower_bound("s");
	std::cout << "return lower_bound for s = "<< itbis->first<<std::endl;
	itbis = myMap.upper_bound("s");
	std::cout << "return upper_bound for s = "<< itbis->first<<std::endl;
	NMSPC::pair <NMSPC::map<std::string, int>::iterator, NMSPC::map<std::string, int>::iterator> retur;
	retur = myMap.equal_range("s");
	std::cout << "return equal_range for s = "<< retur.first->first<<std::endl;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Clear, empty, size and max_size :" << std::endl;
	std::cout << "map2 empty ? " << myMap2.empty()<<std::endl;
	std::cout << "size of map2 ? " << myMap2.size()<<std::endl;
	std::cout << "Clear map2"<<std::endl;
	myMap2.clear();
	std::cout << "map2 empty ? " << myMap2.empty()<<std::endl;
	std::cout << "size of map2 ? " << myMap2.size()<<std::endl;
	std::cout << "Printing map2 : " <<std::endl;
	for (it2bis = myMap2.begin(); it2bis != myMap2.end(); ++it2bis)
		std::cout << it2bis->first << " :: " << it2bis->second << " ; ";
	std::cout << std::endl;
	std::cout << "Max size = " << myMap2.max_size() << std::endl;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Const and reverse iterators : " <<std::endl;
	std::cout << "Const iterators : " <<std::endl;
	NMSPC::map<std::string, int>::const_iterator constIt = myMap3.begin();
	std::cout << "const begin() : " << constIt->first << " :: " << constIt->second << std::endl;

	NMSPC::map<std::string, int>::const_iterator const_it_test = myMap3.find("b");
	std::cout << "find const it = " << const_it_test->first << std::endl;

	std::cout << "\nCreate <const int, std::string> map and const_iterate on it :" << std::endl;
	NMSPC::pair<const int, std::string>	myP2(1, "hello there");
	NMSPC::pair<const int, std::string>	myP2bis(87, "bilbo");
	NMSPC::pair<const int, std::string>	myPA2(1248765, "SCHNELL");
	NMSPC::pair<const int, std::string>	myPB2(183648, "bonjour ici");
	NMSPC::pair<const int, std::string>	myPC2(-8, "michel");
	NMSPC::pair<const int, std::string>	myPD2(-9, "bonjour");
	NMSPC::pair<const int, std::string>	myPE2(-2147483648, "bonjour ici");
	NMSPC::map<int, std::string>	test2;
	test2.insert(myP2);
	test2.insert(myP2bis);
	test2.insert(myPA2);
	test2.insert(myPB2);
	test2.insert(myPC2);
	test2.insert(myPD2);
	test2.insert(myPE2);
	NMSPC::map<int, std::string>::const_iterator	test2It = test2.end();
	for (test2It = test2.end(); test2It != test2.begin(); test2It--)
		if (test2It != test2.end())
			std::cout << "[" << test2It->first << "][" << test2It->second << "] | ";
	std::cout<< std::endl;

	std::cout << "\nReverse iterators on map3 : " <<std::endl;
	NMSPC::map<std::string, int>::reverse_iterator rev_deb1 (myMap3.end());
	NMSPC::map<std::string, int>::reverse_iterator rev_end1 (myMap3.begin());
	std::cout << "reverse begin() : " << rev_deb1->first << " :: " << rev_deb1->second << std::endl;
	while (rev_deb1 != rev_end1)
	{
		std::cout << ' ' << rev_deb1->first << " : " << rev_deb1->second << " - ";
		rev_deb1++;
	}
	std::cout << "\n";

	std::cout << "\nConst reverse iterators : " <<std::endl;
	NMSPC::map<int, std::string>::const_reverse_iterator	revIt = test2.rbegin();
	std::cout << "const reverse begin() : " << revIt->first << " :: " << revIt->second << std::endl;
	for (revIt = test2.rbegin(); revIt != test2.rend(); ++revIt)
		std::cout << "[" << revIt->first << "][" << revIt->second << "] | ";
	std::cout<< std::endl;
}
