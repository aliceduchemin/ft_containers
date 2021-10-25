#include "./testers/testsContainers.hpp"
#include <chrono>
#include <sys/time.h>

int main(int argc, char** argv) 
{
	/*if (argc != 2)
	{
	//	std::cerr << "Usage: ./test seed" << std::endl;
	//	std::cerr << "Provide a seed please" << std::endl;
	//	std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}*/

	std::cout << std::endl <<"You are testing the ";
	if (CHOICE == 0)
		std::cout << "std library" << std::endl;
	else if (CHOICE == 1)
		std::cout << "ft library" << std::endl;

	struct timeval begin, end;
	gettimeofday(&begin, 0);
	//auto start = std::chrono::high_resolution_clock::now();
	
/*	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<int> > stack_deq_buffer;
	ft::map<int, int> map_int;

	std::cout<<"etape 1\n";
	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}
	std::cout<<"etape 2\n";

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	std::cout<<"etape 3\n";
	ft::vector<Buffer>().swap(vector_buffer);
	std::cout<<"etape 4\n";

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	std::cout<<"etape 5\n";
	
	for (int i = 0; i < 100; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}
	std::cout<<"etape 6\n";

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}
	std::cout<<"etape 7\n";
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	
	std::cout<<"etape 8\n";
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
*/
	test_push();
	test_element_access();
	test_re_serve_size();
	test_pop_back();
	test_constructors();
	test_iterator_incrementers_ft();
	test_iterator_booleans_ft();
	test_iterator_deref_ft();
	test_iterator();
	test_reverse_iterator();
	test_assign();
	test_insert();
	test_clear_erase();
	test_swap();

	gettimeofday(&end, 0);
	long seconds = end.tv_sec - begin.tv_sec;
	long microseconds = end.tv_usec - begin.tv_usec;
	double elapsed = seconds / 1e-6 + microseconds ;
	std::cout << "Duration : " << elapsed << " microseconds" << std::endl;

/*	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Duration : " << duration.count() << " microseconds" << std::endl;
*/	return (0);
}
