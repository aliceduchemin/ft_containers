#include <iostream>
#include <string>
#include <map>
#include "pair.hpp"
#include "map.hpp"
#include "mapIte.hpp"

int	main()
{
	std::map<std::string, int>	myMap;

	myMap["earth"] = 2;
	myMap["jupiter"] = 6;
	std::cout << "myMap[earth] = " << myMap["earth"] << std::endl;
	std::cout << "myMap size = " << myMap.size() << std::endl;

	std::map<std::string, int>::iterator it = myMap.begin();
	while (it != myMap.end())
	{
		std::cout << it->first << " :: " << it->second << std::endl;
		it++;
	}	
	myMap.insert(std::make_pair("moon", 7));
	myMap.insert(std::make_pair("sun", 9));
	myMap["sun"] = 4;

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
	return 0;
}