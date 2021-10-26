#include "testsContainers.hpp"

void	mapTests()
{
	std::cout << "Creating a string, int map, inserting elements with insert and []" << std::endl;
	ft::map<std::string, int>	myMap;
	myMap.insert(ft::make_pair("f", 10));
	myMap.insert(ft::make_pair("a", 9));
	myMap.insert(ft::make_pair("b", 3));
	myMap.insert(ft::make_pair("z", 1));
	myMap.insert(ft::make_pair("c", 7));
	myMap.insert(ft::make_pair("y", 6));
	std::cout << "map[r] = " << myMap["r"] << std::endl;
	
	myMap.insert(ft::make_pair("s", 79));
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
	
	ft::pair<ft::map<std::string, int>::iterator, bool> ret4;
	ret4 = myMap.insert(ft::make_pair("a", 9));
	ret4 = myMap.insert(ft::make_pair("d", 3));
	std::cout << "map size = " << myMap.size() << std::endl;

	myMap.insert(ft::make_pair("b", 23));
	ft::map<std::string, int>::iterator itbis = myMap.begin();
	ft::map<std::string, int>::iterator itebis = myMap.end();
	myMap["j"] = 4;
	std::cout << "print : "<<std::endl;
	for (itbis = myMap.begin(); itbis != itebis; ++itbis)
		std::cout << itbis->first << " :: " << itbis->second << " ; ";
	std::cout << std::endl;
	myMap["e"] = 2;
	itebis = myMap.end();
	for (itbis = myMap.begin(); itbis != itebis; ++itbis)
		std::cout << itbis->first << " :: " << itbis->second << " ; ";
	std::cout << std::endl;
	
	std::cout << "map size = " << myMap.size() << std::endl;
	
	std::cout << "\nFind elements, existing and not :" << std::endl;
	if (myMap.find("j") != myMap.end())
		std::cout << "j found" <<std::endl;
	else
		std::cout << "j not found" <<std::endl;
	if (myMap.find("k") != myMap.end())
		std::cout << "k found" <<std::endl;
	else
		std::cout << "k not found" <<std::endl;
	
	std::cout << "\nInsert iterator range :" << std::endl;
	ft::map<std::string, int> myMap2;
	itbis = myMap.begin();
	itbis++;
	myMap2.insert(itbis, myMap.end());
	ft::map<std::string, int>::iterator it2bis = myMap2.begin();
	ft::map<std::string, int>::iterator ite2bis = myMap2.end();
	myMap2["k"] = 6;
	std::cout <<"it2bis = " << it2bis->first << std::endl;
	std::cout << "Printing map2 : " <<std::endl;
	for (it2bis = myMap2.begin(); it2bis != ite2bis; ++it2bis)
		std::cout << it2bis->first << " :: " << it2bis->second << " ; ";
	std::cout << std::endl;

	
	std::cout << "\nInsert position & value" << std::endl;
	it2bis = myMap2.insert(it2bis, ft::make_pair("x", 99));
	myMap2["a"] = 86;
	myMap2["b"] = 89;
	std::cout << "\nPrinting map2 : " <<std::endl;
	for (it2bis = myMap2.begin(); it2bis != ite2bis; ++it2bis)
		std::cout << it2bis->first << " :: " << it2bis->second << " ; ";
	std::cout << std::endl;

	std::cout << "\nCopy constructor :" << std::endl;
	ft::map<std::string, int>	myMap3(myMap2);
	ft::map<std::string, int>::iterator it3bis = myMap3.begin();
	ft::map<std::string, int>::iterator ite3bis = myMap3.end();
	std::cout << "Printing map3 : " <<std::endl;
	for (it3bis = myMap3.begin(); it3bis != ite3bis; ++it3bis)
		std::cout << it3bis->first << " :: " << it3bis->second << " ; ";
	std::cout << std::endl;

	std::cout << "\nOperator = :" << std::endl;
	ft::map<std::string, int>	myMap4;
	myMap4 = myMap2;
	ft::map<std::string, int>::iterator it4bis = myMap4.begin();
	ft::map<std::string, int>::iterator ite4bis = myMap4.end();
	std::cout << "Printing map4 : " <<std::endl;
	for (it4bis = myMap4.begin(); it4bis != ite4bis; ++it4bis)
		std::cout << it4bis->first << " :: " << it4bis->second << " ; ";
	std::cout << std::endl;

	std::cout << "\nErase tests : " << std::endl;
	myMap2.erase("c");
	myMap2.erase("a");
	myMap2.erase("z");
	myMap2.erase("y");
	it2bis = myMap2.begin();
	it2bis++;
	ite2bis = it2bis;
	ite2bis++;
	std::cout <<"start of iterator erase : " << it2bis->first << std::endl;
	std::cout <<"end of iterator erase : " << ite2bis->first << std::endl;
	myMap2.erase("d");

	ite2bis = myMap2.end();
	std::cout << "Printing partially erased map (map2) : " <<std::endl;
	for (it2bis = myMap2.begin(); it2bis != ite2bis; ++it2bis)
		std::cout << it2bis->first << " :: " << it2bis->second << " ; ";
	std::cout << std::endl;
	it2bis = myMap2.begin();

	std::cout << "Printing map : " <<std::endl;
	itebis = myMap.end();
	for (itbis = myMap.begin(); itbis != itebis; ++itbis)
		std::cout << itbis->first << " :: " << itbis->second << " ; ";
	std::cout << std::endl;
	itbis = myMap.begin();

	std::cout<< "\nSwaping maps map and map2: " <<std::endl;
	myMap.swap(myMap2);
	int restSwap = (itbis == myMap2.begin());
	std::cout << "itbis == myMap2 ? " <<  restSwap <<std::endl;
	restSwap = (it2bis == myMap.begin());
	std::cout << "it2bis == myMap ? " <<  restSwap <<std::endl;

	std::cout << "Printing map2 : " <<std::endl;
	ite2bis = myMap2.end();
	for (it2bis = myMap2.begin(); it2bis != ite2bis; ++it2bis)
		std::cout << it2bis->first << " :: " << it2bis->second << " ; ";
	std::cout << std::endl;

	std::cout << "Printing map : " <<std::endl;
	itebis = myMap.end();
	for (itbis = myMap.begin(); itbis != itebis; ++itbis)
		std::cout << itbis->first << " :: " << itbis->second << " ; ";
	std::cout << std::endl;


	std::cout << "\nCount : " <<std::endl;
	std::cout << "count b : "<< myMap.count("b")<<std::endl;

	std::cout << "\nBounds & equal_range : " <<std::endl;
	itbis = myMap.lower_bound("j");
	std::cout << "return lower_bound for j = "<< itbis->first<<std::endl;
	itbis = myMap.upper_bound("j");
	std::cout << "return upper_bound for j = "<< itbis->first<<std::endl;
	ft::pair <ft::map<std::string, int>::iterator, ft::map<std::string, int>::iterator> retur;
	retur = myMap.equal_range("j");
	std::cout << "return equal_range for j = "<< retur.first->first<<std::endl;

	std::cout << "\nClear map2 :"<<std::endl;
	myMap2.clear();
	std::cout << "my map 2 empty ? " << myMap2.empty()<<std::endl;
	std::cout << "size of map2 ? " << myMap2.size()<<std::endl;
	std::cout << "\nPrinting map2 : " <<std::endl;
	ite2bis = myMap2.end();
	for (it2bis = myMap2.begin(); it2bis != ite2bis; ++it2bis)
		std::cout << it2bis->first << " :: " << it2bis->second << " ; ";
	std::cout << std::endl;


	std::cout << "\nConst iterators : " <<std::endl;
	ft::map<std::string, int>::const_iterator constIt = myMap3.begin();
	ft::map<std::string, int>::const_iterator constIte = myMap3.end();
	std::cout << "const : " << constIt->first << std::endl;

	ft::map<std::string, int>::const_iterator const_it_test = myMap3.find("b");
	std::cout << "find const it = " << const_it_test->first << std::endl;

	std::cout << "\nReverse iterators : " <<std::endl;
	ft::map<std::string, int>::reverse_iterator rev_deb1 (myMap3.end());
	ft::map<std::string, int>::reverse_iterator rev_end1 (myMap3.begin());
	while (rev_deb1 != rev_end1)
	{
		std::cout << ' ' << rev_deb1->first << " : " << rev_deb1->second << " - ";
		rev_deb1++;
	}
	std::cout << "\n";

	ft::pair<const int, std::string>	myP2(1, "hello there");
	ft::pair<const int, std::string>	myP2bis(87, "bilbo");
	ft::pair<const int, std::string>	myPA2(1248765, "SCHNELL");
	ft::pair<const int, std::string>	myPB2(183648, "bonjour ici");
	ft::pair<const int, std::string>	myPC2(-8, "michel");
	ft::pair<const int, std::string>	myPD2(-9, "bonjour");
	ft::pair<const int, std::string>	myPE2(-2147483648, "bonjour ici");
	ft::map<int, std::string>	test2;
	test2.insert(myP2);
	test2.insert(myP2bis);
	test2.insert(myPA2);
	test2.insert(myPB2);
	test2.insert(myPC2);
	test2.insert(myPD2);
	test2.insert(myPE2);
	std::cout << "\nConst iterators : " <<std::endl;
	ft::map<int, std::string>::const_iterator	test2It = test2.end();
	for (test2It = test2.end(); test2It != test2.begin(); test2It--)
		if (test2It != test2.end())
			std::cout << "[" << test2It->first << "][" << test2It->second << "] | ";
	std::cout<< std::endl;

	std::cout << "\nConst reverse iterators : " <<std::endl;
	ft::map<int, std::string>::const_reverse_iterator	revIt = test2.rbegin();
	std::cout <<"rbegin = " << revIt->first<<std::endl;
	ft::map<int, std::string>::const_reverse_iterator	revIte = test2.rend();
	for (revIt = test2.rbegin(); revIt != test2.rend(); ++revIt)
		std::cout << "[" << revIt->first << "][" << revIt->second << "] | ";
	std::cout<< std::endl;

	std::cout << "\nMax size = " << test2.max_size() << std::endl;

}