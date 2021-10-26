#include "./testers/testsContainers.hpp"

int main(int argc, char** argv) 
{
	std::cout << std::endl <<"You are testing the ";
	if (CHOICE == 0)
		std::cout << "std library" << std::endl;
	else if (CHOICE == 1)
		std::cout << "ft library" << std::endl;

	struct timeval begin, end;
	gettimeofday(&begin, 0);
	
	std::cout << "##### VECTOR TESTS : #####\n" << std::endl;
//	vectorTests();

	std::cout << "##### STACK TESTS : #####\n" << std::endl;
//	stackTests();

	std::cout << "##### MAP TESTS : #####\n" << std::endl;
	mapTests();


	gettimeofday(&end, 0);
	long seconds = end.tv_sec - begin.tv_sec;
	long microseconds = end.tv_usec - begin.tv_usec;
	double elapsed = seconds / 1e-6 + microseconds ;
	std::cout << "Duration : " << elapsed << " microseconds" << std::endl;
	return (0);
}
