#include <iostream>
#include <string>
#include <map>
#include "pair.hpp"
#include "map.hpp"
#include "mapIte.hpp"

int	main()
{
	std::map<int, int>	myMap;
	
	myMap[1] = 2;
	myMap[3] = 4;
	myMap[5] = 6;
	std::cout << "myMap[1] = " << myMap[1] << std::endl;
	std::cout << "myMap[3] = " << myMap[3] << std::endl;
	std::cout << "myMap[5] = " << myMap[5] << std::endl;
	std::cout << "myMap size = " << myMap.size() << std::endl;

	return 0;
}