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
	std::cout << "myMap[r] = " << myMap["r"] << std::endl;
	
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
	std::cout << "myMap size = " << myMap.size() << std::endl;

	myMap.insert(ft::make_pair("b", 23));
	ft::map<std::string, int>::iterator itbis = myMap.begin();
	ft::map<std::string, int>::iterator itebis = myMap.end();
	myMap["j"] = 4;
	std::cout << "print my map : "<<std::endl;
	for (itbis = myMap.begin(); itbis != itebis; ++itbis)
		std::cout << itbis->first << " :: " << itbis->second << " ; ";
	std::cout << std::endl;
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
	
	ft::map<std::string, int> myMap2;
	itbis = myMap.begin();
	itbis++;
	myMap2.insert(itbis, myMap.end());
	ft::map<std::string, int>::iterator it2bis = myMap2.begin();
	ft::map<std::string, int>::iterator ite2bis = myMap2.end();
	myMap2["k"] = 6;
	std::cout <<"it2bis = " << it2bis->first << std::endl;
	std::cout << "\nPrinting myMap2 : " <<std::endl;
	for (it2bis = myMap2.begin(); it2bis != ite2bis; ++it2bis)
		std::cout << it2bis->first << " :: " << it2bis->second << " ; ";
	std::cout << std::endl;

	
	it2bis = myMap2.insert(it2bis, ft::make_pair("x", 99));
	myMap2["a"] = 86;
	myMap2["b"] = 89;
	std::cout << "\nPrinting myMap2 : " <<std::endl;
	for (it2bis = myMap2.begin(); it2bis != ite2bis; ++it2bis)
		std::cout << it2bis->first << " :: " << it2bis->second << " ; ";
	std::cout << std::endl;

	ft::map<std::string, int>	myMap3(myMap2);
	myMap3["v"] = 10;
	myMap3.insert(ft::make_pair("c", 2));
	myMap3["z"] = 1;
	std::cout <<"\nmap3 : " <<std::endl;
	myMap3.insert(ft::make_pair("u", 23));
	std::cout <<"Copy : " <<std::endl;
	std::cout <<"mymap3 v = " <<myMap3["v"]<<std::endl;
//	myMap3 = myMap2;
	std::cout <<"\nend of Copy\n" <<std::endl;
	ft::map<std::string, int>::iterator it3bis = myMap3.begin();
	ft::map<std::string, int>::iterator ite3bis = myMap3.end();
	std::cout << "\nPrinting myMap3 : " <<std::endl;
	for (it3bis = myMap3.begin(); it3bis != ite3bis; ++it3bis)
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
	std::cout <<"start of iterator erase : " << it2bis->first << std::endl;
	std::cout <<"end of iterator erase : " << ite2bis->first << std::endl;
	myMap2.erase("d");

	ite2bis = myMap2.end();
	std::cout << "\nPrinting myMap2 : " <<std::endl;
	for (it2bis = myMap2.begin(); it2bis != ite2bis; ++it2bis)
		std::cout << it2bis->first << " :: " << it2bis->second << " ; ";
	std::cout << std::endl;
	it2bis = myMap2.begin();

	std::cout << "\nPrinting mymap : " <<std::endl;
	itebis = myMap.end();
	for (itbis = myMap.begin(); itbis != itebis; ++itbis)
		std::cout << itbis->first << " :: " << itbis->second << " ; ";
	std::cout << std::endl;
	itbis = myMap.begin();

	std::cout<< "Swaping maps : " <<std::endl;
	myMap.swap(myMap2);
	int restSwap = (itbis == myMap2.begin());
	std::cout << "itbis == myMap2 ? " <<  restSwap <<std::endl;
	restSwap = (it2bis == myMap.begin());
	std::cout << "it2bis == myMap ? " <<  restSwap <<std::endl;

	std::cout << "\nPrinting myMap2 : " <<std::endl;
	ite2bis = myMap2.end();
	for (it2bis = myMap2.begin(); it2bis != ite2bis; ++it2bis)
		std::cout << it2bis->first << " :: " << it2bis->second << " ; ";
	std::cout << std::endl;

	std::cout << "\nPrinting myMap : " <<std::endl;
	itebis = myMap.end();
	for (itbis = myMap.begin(); itbis != itebis; ++itbis)
		std::cout << itbis->first << " :: " << itbis->second << " ; ";
	std::cout << std::endl;
	std::cout << "count b : "<< myMap.count("b")<<std::endl;
	itbis = myMap.lower_bound("j");
	std::cout << "return lower_bound for j = "<< itbis->first<<std::endl;
	itbis = myMap.upper_bound("j");
	std::cout << "return upper_bound for j = "<< itbis->first<<std::endl;
	ft::pair <ft::map<std::string, int>::iterator, ft::map<std::string, int>::iterator> retur;
	retur = myMap.equal_range("j");
	std::cout << "return equal_range for j = "<< retur.first->first<<std::endl;

	std::cout << "clear map2 :"<<std::endl;
	std::cout << "size of my map 2 ? " << myMap2.size()<<std::endl;
	myMap2.clear();
	std::cout << "my map 2 empty ? " << myMap2.empty()<<std::endl;
	std::cout << "size of my map 2 ? " << myMap2.size()<<std::endl;
	std::cout << "\nPrinting myMap2 : " <<std::endl;
	ite2bis = myMap2.end();
	for (it2bis = myMap2.begin(); it2bis != ite2bis; ++it2bis)
		std::cout << it2bis->first << " :: " << it2bis->second << " ; ";
	std::cout << std::endl;


	ft::map<std::string, int>::const_iterator constIt = myMap3.begin();
	ft::map<std::string, int>::const_iterator constIte = myMap3.end();
	std::cout << "const : " << constIt->first<<std::endl;

	ft::map<std::string, int>::const_iterator const_it_test = myMap3.find("b");
	std::cout << "find const it = " << const_it_test->first<<std::endl;

	ft::map<std::string, int>::reverse_iterator rev_deb1 (myMap3.end());
	ft::map<std::string, int>::reverse_iterator rev_end1 (myMap3.begin());
	while (rev_deb1 != rev_end1)
	{
		std::cout << ' ' << rev_deb1->first << " : " << rev_deb1->second << " - ";
		rev_deb1++;
	}
	std::cout << "\n";

	ft::map<std::string, int>::const_reverse_iterator rev_const_deb1 (myMap3.end());
	ft::map<std::string, int>::const_reverse_iterator rev_const_end1 (myMap3.begin());

	std::cout << "Comp : " << std::endl;
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
	ft::map<int, std::string>::const_iterator	test2It = test2.end();
	for (test2It = test2.end(); test2It != test2.begin(); test2It--)
		if (test2It != test2.end())
			std::cout << "[" << test2It->first << "][" << test2It->second << "] | ";
	std::cout<< std::endl;

	std::cout<<"\nReverse iterators"<< std::endl;
	ft::map<int, std::string>::const_reverse_iterator	revIt = test2.rbegin();
	std::cout <<"rbegin = " << revIt->first<<std::endl;
	ft::map<int, std::string>::const_reverse_iterator	revIte = test2.rend();
	for (revIt = test2.rbegin(); revIt != test2.rend(); ++revIt)
		std::cout << "[" << revIt->first << "][" << revIt->second << "] | ";
	std::cout<< std::endl;

	std::cout << "Max size = " << test2.max_size() << std::endl;

	ft::map<int, int> mp;
	mp.insert(ft::make_pair(4, 5));
	mp.insert(ft::make_pair(6, 7));
	mp.insert(ft::make_pair(2, 7));
	mp.insert(ft::make_pair(1, 7));
	mp.insert(ft::make_pair(10, 5));
	mp.insert(ft::make_pair(18, 7));
	mp.insert(ft::make_pair(56, 7));
	mp.insert(ft::make_pair(24, 7));
	mp.insert(ft::make_pair(98, 7));
	mp.insert(ft::make_pair(111, 7));

	std::cout << "\nPrinting mp : " <<std::endl;
	ft::map<int, int>::iterator	itit;
	for (itit = mp.begin(); itit != mp.end(); ++itit)
		std::cout << itit->first << " :: " << itit->second << " ; ";
	std::cout << std::endl;

	mp.erase(--(--(--mp.end())), --mp.end());

	std::cout << "\nPrinting mp after erase: " <<std::endl;
	for (itit = mp.begin(); itit != mp.end(); ++itit)
		std::cout << itit->first << " :: " << itit->second << " ; ";
	std::cout << std::endl;

	const int valeur = 12;
	ft::map<int, int>::iterator titi;
	titi = mp.find(valeur);
	ft::map<int, int>::iterator titiEnd = mp.end();
	if (titi == titiEnd)
		std::cout<<"value not found\n";
	else
		std::cout<<"value found\n";

	(++(++myMap.begin()))->second = 42;
	int resComp = (myMap > myMap2);

	std::cout << "rest comp myMap avec myMap2 = " << resComp <<std::endl;
	ft::map<float, MutantStack<int>> mp3;
	ft::map<float, MutantStack<int>>::reverse_iterator it(mp3.rbegin());
}