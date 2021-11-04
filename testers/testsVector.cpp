/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsVector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduchemi <aduchemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:46:22 by aduchemi          #+#    #+#             */
/*   Updated: 2021/10/27 17:46:23 by aduchemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testsContainers.hpp"

void	test_push(void)
{
	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Creating vector test." << std::endl;
	NMSPC::vector<int> test;

	std::cout << "Empty() = " << test.empty() << std::endl;

	std::cout << "Push tests :" << std::endl;
	test.push_back(56);
	std::cout << "Push : " << test[0] << std::endl;
	test.push_back(42);
	std::cout << "Push : " << test[1] << std::endl;

	std::cout << "Empty() = " << test.empty() << std::endl;

	std::cout << "Size = " <<  test.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << std::endl;

	std::cout << "Push tests :" << std::endl;
	test.push_back(9);
	std::cout << "Push : " << test[2] << std::endl;
	test.push_back(0);
	std::cout << "Push : " << test[3] << std::endl;
	test.push_back(13);
	std::cout << "Push : " << test[4] << std::endl;

	std::cout << "Size = " <<  test.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << std::endl;

	std::cout << "Max size : " << test.max_size() << std::endl;
}

void	test_element_access(void)
{
	NMSPC::vector<int> test;
	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Element access :" << std::endl;

	test.push_back(43);
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(56);

	std::cout << "For a vector<int> = {43, 1, 2, 3, 56}" << std::endl;
	std::cout << "----- TEST AT() -----" << std::endl;
	std::cout << "at(0) = " << test.at(0) << std::endl;
	std::cout << "at(1) = " << test.at(1) << std::endl;
	std::cout << "at(3) = " << test.at(3) << std::endl;
	std::cout << "at(4) = " << test.at(4) << std::endl;
	std::cout << "at(6) = ";
	try
	{
		std::cout << test.at(6) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Test front() and back() :" << std::endl;
	std::cout << "For a vector<std::string> = {\"999\", \"666\", \"123\", \"321\"}" << std::endl;

	NMSPC::vector<std::string> test1;

	test1.push_back("999");
	test1.push_back("666");
	test1.push_back("123");
	test1.push_back("321");

	std::cout << "front() = " << test1.front() << std::endl;
	std::cout << "back() = " << test1.back() << std::endl;

	std::cout << "For a vector<std::string> = {\"2727\"}" << std::endl;

	NMSPC::vector<std::string> test2;

	test2.push_back("2727");

	std::cout << "front() = " << test2.front() << std::endl;
	std::cout << "back() = " << test2.back() << std::endl;
}

void	test_re_serve_size(void)
{
	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Reserve() and resize() :" << std::endl;

	std::cout << "Test reserve :" << std::endl;
	std::cout << "For a empty int vector v :" << std::endl;

	NMSPC::vector<int> v;

	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	v.reserve(100);
	std::cout << "v.reserve(100)" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	v.reserve(1);
	std::cout << "v.reserve(1)" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;

	std::cout << "Test resize :" << std::endl;
	std::cout << "For a empty int vector v2 :" << std::endl;

	NMSPC::vector<int> v2;

	std::cout << "v2.capacity() = " << v2.capacity() << std::endl;
	std::cout << "v2.size() = " << v2.size() << std::endl;

	v2.resize(10);
	std::cout << "v2.resize(10);" << std::endl;
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << v2[i] << std::endl;
	std::cout << std::endl;

	v2.resize(15, 15);
	std::cout << "v2.resize(15, 15);" << std::endl;
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << v2[i] << std::endl;
	std::cout << std::endl;

	v2.resize(3);
	std::cout << "v2.resize(3);" << std::endl;
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << v2[i] << std::endl;
	std::cout << std::endl;
}

void	test_pop_back(void)
{
	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Pop back() :" << std::endl;

	std::cout << "For a vector<std::string> empty :" << std::endl;

	NMSPC::vector<std::string> v;

	v.resize(10, "coucou !");
	std::cout << "v.resize(10, \"coucou !\");" << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << std::endl;
	v.pop_back();
	std::cout << "v.pop_back();" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;
}

void	test_iterator_incrementers()
{
	NMSPC::vector<int>				v;
	NMSPC::vector<int>::iterator	it;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Test incrementers :" << std::endl;
	std::cout << "For a vector : ";
	v.push_back(5);
	v.push_back(42);
	v.push_back(56);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << "*(v.begin()) = " << *(v.begin()) << std::endl;

	std::cout << "Testing : i++ ++i --i i--" << std::endl;
	it = v.begin();
	std::cout << "it = v.begin();" << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(it++) = " << *(it++) << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(it--) = " << *(it--) << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(++it) = " << *(++it) << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(--it) = " << *(--it) << std::endl;
	std::cout << "*it = " << *it << std::endl << std::endl;
}

void	test_iterator_booleans()
{
	NMSPC::vector<int>				v;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Comparators on iterators :" << std::endl;
	std::cout << "For a vector v : ";
	v.push_back(5);
	v.push_back(42);
	v.push_back(56);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	NMSPC::vector<int>::iterator	it_beg = v.begin();
	NMSPC::vector<int>::iterator	it_end = v.end();
	std::cout << "For an iterator it_beg = v.begin()" << std::endl;
	std::cout << "For an iterator it_end = v.end()" << std::endl << std::endl;

	std::cout << "it_beg < it_end is " << std::boolalpha << (it_beg < it_end) << std::endl;
	std::cout << "it_end < it_beg is " << std::boolalpha << (it_end < it_beg) << std::endl;
	std::cout << "it_beg > it_end is " << std::boolalpha << (it_beg > it_end) << std::endl;
	std::cout << "it_end > it_beg is " << std::boolalpha << (it_end > it_beg) << std::endl << std::endl;

	std::cout << "it_beg == it_end is " << std::boolalpha << (it_beg == it_end) << std::endl;
	std::cout << "it_beg == it_beg is " << std::boolalpha << (it_beg == it_beg) << std::endl;
	std::cout << "it_beg != it_end is " << std::boolalpha << (it_beg != it_end) << std::endl;
	std::cout << "it_beg != it_beg is " << std::boolalpha << (it_beg != it_beg) << std::endl << std::endl;

	std::cout << "it_beg <= it_end is " << std::boolalpha << (it_beg <= it_end) << std::endl;
	std::cout << "it_end <= it_beg is " << std::boolalpha << (it_end <= it_beg) << std::endl;
	std::cout << "it_end <= it_end is " << std::boolalpha << (it_end <= it_end) << std::endl;
	std::cout << "it_beg >= it_end is " << std::boolalpha << (it_beg >= it_end) << std::endl;
	std::cout << "it_end >= it_beg is " << std::boolalpha << (it_end >= it_beg) << std::endl;
	std::cout << "it_end >= it_end is " << std::boolalpha << (it_end >= it_end) << std::endl << std::endl;
}

void	test_iterator_booleans_const()
{
	NMSPC::vector<int>				v;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Comparators on iterators :" << std::endl;
	std::cout << "For a vector v : ";
	v.push_back(5);
	v.push_back(42);
	v.push_back(56);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	NMSPC::vector<int>::const_iterator	it_beg = v.begin();
	NMSPC::vector<int>::iterator	it_end = v.end();
	std::cout << "For an iterator it_beg = v.begin()" << std::endl;
	std::cout << "For an iterator it_end = v.end()" << std::endl << std::endl;

	std::cout << "it_beg < it_end is " << std::boolalpha << (it_beg < it_end) << std::endl;
	std::cout << "it_end < it_beg is " << std::boolalpha << (it_end < it_beg) << std::endl;
	std::cout << "it_beg > it_end is " << std::boolalpha << (it_beg > it_end) << std::endl;
	std::cout << "it_end > it_beg is " << std::boolalpha << (it_end > it_beg) << std::endl << std::endl;

	std::cout << "it_beg == it_end is " << std::boolalpha << (it_beg == it_end) << std::endl;
	std::cout << "it_beg == it_beg is " << std::boolalpha << (it_beg == it_beg) << std::endl;
	std::cout << "it_beg != it_end is " << std::boolalpha << (it_beg != it_end) << std::endl;
	std::cout << "it_beg != it_beg is " << std::boolalpha << (it_beg != it_beg) << std::endl << std::endl;

	std::cout << "it_beg <= it_end is " << std::boolalpha << (it_beg <= it_end) << std::endl;
	std::cout << "it_end <= it_beg is " << std::boolalpha << (it_end <= it_beg) << std::endl;
	std::cout << "it_end <= it_end is " << std::boolalpha << (it_end <= it_end) << std::endl;
	std::cout << "it_beg >= it_end is " << std::boolalpha << (it_beg >= it_end) << std::endl;
	std::cout << "it_end >= it_beg is " << std::boolalpha << (it_end >= it_beg) << std::endl;
	std::cout << "it_end >= it_end is " << std::boolalpha << (it_end >= it_end) << std::endl << std::endl;
}

void	test_iterator_deref()
{
	NMSPC::vector<int>				v;
	NMSPC::vector<int>::iterator	it;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Test iterator dereferencing :" << std::endl;
	std::cout << "For a vector v : ";
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	it = v.begin();
	std::cout << "it = v.begin()" << std::endl;

	std::cout << "dereferencing with * : " << *it << std::endl;
	*it = 5;
	std::cout << "*it = 5" << std::endl;
	std::cout << "cout *it = " << *it << std::endl << std::endl;

	std::cout << "dereferencing with [] :" << std::endl;
	std::cout << "cout it[3] = " << it[3] << std::endl;
	it[3] = 42;
	std::cout << "it[3] = 42" << std::endl;
	std::cout << "cout it[3] = " << it[3] << std::endl;

	std::cout << "*i++ *i-- :" << std::endl;
	std::cout << "For a vector v : ";
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;
	it = v.begin() + 3;
	std::cout << "it = v.begin() + 3" << std::endl;
	std::cout << "cout *it = " << *it << std::endl;

	*it++ = 345879;
	std::cout << "*it++ = 345879;" << std::endl;
	std::cout << "cout *(it - 1) = " << *(it - 1) << std::endl;
	*it-- = 999;
	std::cout << "*it-- = 999;" << std::endl;
	std::cout << "cout *(it + 1) = " << *(it + 1) << std::endl << std::endl;
	std::cout << "now v  : ";
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl << std::endl;
	std::cout << "it = v.begin() + 0" << std::endl;
	std::cout << "cout *it = " << *it << std::endl;
	it += 4;
	std::cout << "it += 4" << *it << std::endl;
	std::cout << "cout *it = " << *it << std::endl;
	it -= 4;
	std::cout << "it -= 4" << *it << std::endl;
	std::cout << "cout *it = " << *it << std::endl << std::endl;
	NMSPC::vector<int>::iterator it_cpy(it);
	std::cout << "iterator it_cpy(it);" << std::endl;
	std::cout << "cout *it_cpy = " << *it_cpy << std::endl << std::endl;
}

void	test_reverse_iterator(void)
{
	NMSPC::vector<int>	v;
	NMSPC::vector<int>::reverse_iterator	it;

	std::cout << "\n---------------------------- " << std::endl;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	std::cout << "Reverse iterators :" << std::endl;
	std::cout << "For a vector v = ";
	std::cout << "{";
	for (size_t i = 0; i < v.size() - 1; i++)
		std::cout << v[i] << ", ";
	std::cout << v[v.size() - 1];
	std::cout << "}" << std::endl;

	std::cout << "for it = v.rbegin(); it != v.rend(); it++" << std::endl;
	std::cout << "std::cout << *it << std::endl;" << std::endl;
	for (NMSPC::vector<int>::reverse_iterator it2 = v.rbegin(); it2 != v.rend(); it2++)
		std::cout << *it2 << std::endl;

	it = v.rbegin();
	std::cout << "*it = v.rbegin()" << std::endl;
	std::cout << "cout *it = " << *it << std::endl;
	it += 4;
	std::cout << "it += 4" << std::endl;
	std::cout << "cout *it = " << *it << std::endl;
	it -= 4;
	std::cout << "it -= 4" << std::endl;
	std::cout << "cout *it = " << *it << std::endl << std::endl;
}

void	test_constructors(void)
{
	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Constructors :" << std::endl;

	NMSPC::vector<int> v;

	std::cout << "Default constructor :" << std::endl;
	std::cout << "vector<int> v;" << std::endl;
	std::cout << "v.capacity() = " << v.capacity() << std::endl;
	std::cout << "v.size() = " << v.size() << std::endl;

	v.push_back(42);
	v.push_back(1);
	v.push_back(56);
	v.push_back(123);
	std::cout << "v.push_back(42);" << std::endl;
	std::cout << "v.push_back(1);" << std::endl;
	std::cout << "v.push_back(56);" << std::endl;
	std::cout << "v.push_back(123);" << std::endl;

	NMSPC::vector<int>::iterator it1 = v.begin();
	NMSPC::vector<int>::iterator ite1 = v.end();
	for (it1 = v.begin(); it1 != ite1 ; it1++)
		std::cout << *it1 << " -- ";
	std::cout << std::endl;

	std::cout << "Iterator constructor :" << std::endl;
	std::cout << "vector<int> v_it(v.begin(), v.end());" << std::endl;
	NMSPC::vector<int> v_it(v.begin(), v.end());

	std::cout << "for (vector<int>::iterator it = v_it.begin(); it != v_it.end(); it++)" << std::endl;
	std::cout << "    std::cout << *it << std::endl;" << std::endl;
	for (NMSPC::vector<int>::iterator it = v_it.begin(); it != v_it.end(); it++)
		std::cout << *it << " -- ";
	std::cout << std::endl;

	std::cout << "Copy constructor :" << std::endl;
	std::cout << "vector<int> v_cpy(v_it);" << std::endl;
	NMSPC::vector<int> v_cpy(v_it);

	std::cout << "for (vector<int>::iterator it = v_cpy.begin(); it != v_cpy.end(); it++)" << std::endl;
	std::cout << "std::cout << *it << std::endl;" << std::endl;
	for (NMSPC::vector<int>::iterator it = v_cpy.begin(); it != v_cpy.end(); it++)
		std::cout << *it << " -- ";
	std::cout << std::endl;

	std::cout << "Fill constructor :" << std::endl;
	std::cout << "vector<int> v_fill(25, 42);" << std::endl;
	NMSPC::vector<int> v_fill(25, 42);

	std::cout << "for (vector<int>::iterator it = v_fill.begin(); it != v_fill.end(); it++)" << std::endl;
	std::cout << "std::cout << *it << std::endl;" << std::endl;
	for (NMSPC::vector<int>::iterator it = v_fill.begin(); it != v_fill.end(); it++)
		std::cout << *it << " -- ";
	std::cout << std::endl;
}

void	test_assign(void)
{
	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Assign() :" << std::endl;

	NMSPC::vector<int> v1;
	v1.push_back(42);
	v1.push_back(1);
	v1.push_back(56);
	v1.push_back(123);

	std::cout << "vector<int> v1;" << std::endl;
	std::cout << "For a vector v1 = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	NMSPC::vector<int> v2;
	v2.push_back(420);
	v2.push_back(9999);
	v2.push_back(66666);
	v2.push_back(1234567);
	v2.push_back(507317);
	v2.push_back(2147483640);
	std::cout << "vector<int> v2;" << std::endl;
	std::cout << "For a vector v2 = ";
	std::cout << "{";
	for (size_t i = 0; i < v2.size() - 1; i++)
		std::cout << v2[i] << ", ";
	std::cout << v2[v2.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "\nRange assign :" <<std::endl;
	v1.assign(v2.begin(), v2.end());
	std::cout << "v1.assign(v2.begin(), v2.end())" << std::endl;
		std::cout << "v1 = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "\nFill assign :" <<std::endl;
	v2.assign(10, 8);
	std::cout << "v2.assign(10, 8);" << std::endl;
		std::cout << "v2 = ";
	std::cout << "{";
	for (size_t i = 0; i < v2.size() - 1; i++)
		std::cout << v2[i] << ", ";
	std::cout << v2[v2.size() - 1];
	std::cout << "}" << std::endl << std::endl;
}

void	test_insert(void)
{
	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Insert from end() - x position : " << std::endl;
	NMSPC::vector<int> vct(10);
	NMSPC::vector<int> vct2;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;

	vct2.insert(vct2.end(), 42);
	vct2.insert(vct2.begin(), 2, 21);
	for (NMSPC::vector<int>::iterator it = vct2.begin(); it != vct2.end(); it++)
		std::cout << *it << " -- ";
	std::cout << std::endl;

	vct2.insert(vct2.end() - 2, 42);
	for (NMSPC::vector<int>::iterator it = vct2.begin(); it != vct2.end(); it++)
		std::cout << *it << " -- ";
	std::cout << std::endl;

	vct2.insert(vct2.end(), 2, 84);
	for (NMSPC::vector<int>::iterator it = vct2.begin(); it != vct2.end(); it++)
		std::cout << *it << " -- ";
	std::cout << std::endl;


	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Insert() :" << std::endl << std::endl;

	std::cout << "Single element insertion :" << std::endl;
	NMSPC::vector<std::string>	v1;

	v1.push_back("coucou");
	v1.push_back("comment");
	v1.push_back("il");
	v1.push_back("va ?");

	std::cout << "Insert at the begining :" << std::endl << std::endl;
	std::cout << "For a std::string vector v1 = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	NMSPC::vector<std::string>::iterator ret = v1.insert(v1.begin(), "BANANAS SUKS ");
	std::cout << "insert(v1.begin(), \"BANANAS SUKS \")" << std::endl;
	std::cout << "return from insert = " << *ret << std::endl;

	std::cout << "v1 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "Insert in the middle :" << std::endl << std::endl;
	v1.insert(v1.begin() + 3, "WIN SUKS ");
	std::cout << "insert(v1.begin() + 3, \"WIN SUKS \")" << std::endl;

	std::cout << "v1 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "Insert at the end :" << std::endl << std::endl;
	v1.insert(v1.end(), "WIN SUKS ");
	std::cout << "insert(v1.end(), \"WIN SUKS \")" << std::endl;

	std::cout << "v1 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v1.size() - 1; i++)
		std::cout << v1[i] << ", ";
	std::cout << v1[v1.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "Insert in empty vector :" << std::endl << std::endl;
	NMSPC::vector<std::string> v2;
	std::cout << "For a std::string vector v2 = {}" << std::endl << std::endl;

	v2.insert(v2.begin(), "I'm alone here, it suks !");
	std::cout << "insert(v2.begin(), \"I'm alone here, it suks !\")" << std::endl;

	std::cout << "v2 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v2.size() - 1; i++)
		std::cout << v2[i] << ", ";
	std::cout << v2[v2.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "\nFill insertion :" << std::endl << std::endl;

	NMSPC::vector<std::string>	v3;

	v3.push_back("i");
	v3.push_back("dont");
	v3.push_back("like");
	v3.push_back("all");
	v3.push_back("bananas");
	v3.push_back("bwark");

	std::cout << "Insert at the begining :" << std::endl << std::endl;

	std::cout << "For a std::string vector v3 = ";
	std::cout << "{";
	for (size_t i = 0; i < v3.size() - 1; i++)
		std::cout << v3[i] << ", ";
	std::cout << v3[v3.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	v3.insert(v3.begin(), 3 ,"BANANA");
	std::cout << "v3.insert(v3.begin(), 3 ,\"BANANA\");" << std::endl << std::endl;
	std::cout << "v3 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v3.size() - 1; i++)
		std::cout << v3[i] << ", ";
	std::cout << v3[v3.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "Insert in the middle :" << std::endl << std::endl;

	std::cout << "For a std::string vector v3 = ";
	std::cout << "{";
	for (size_t i = 0; i < v3.size() - 1; i++)
		std::cout << v3[i] << ", ";
	std::cout << v3[v3.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	v3.insert(v3.begin() + 6, 3,"🍌");
	std::cout << "v3.insert(v3.begin() + 6, 3,\"🍌\");" << std::endl << std::endl;
	std::cout << "v3 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v3.size() - 1; i++)
		std::cout << v3[i] << ", ";
	std::cout << v3[v3.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "Insert at the end :" << std::endl << std::endl;

	std::cout << "For a std::string vector v3 = ";
	std::cout << "{";
	for (size_t i = 0; i < v3.size() - 1; i++)
		std::cout << v3[i] << ", ";
	std::cout << v3[v3.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	v3.insert(v3.end(), 5,"ANANAB");
	std::cout << "v3.insert(v3.end(), 5,\"ANANAB\");" << std::endl << std::endl;
	std::cout << "v3 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v3.size() - 1; i++)
		std::cout << v3[i] << ", ";
	std::cout << v3[v3.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "\nFill insert :" << std::endl << std::endl;

	NMSPC::vector<std::string> v4;

	std::cout << "For a std::string vector v4 = {}" << std::endl << std::endl;

	v4.insert(v4.begin(), 5, "🍌");
	std::cout << "v4.insert(v4.begin(), 5,\"🍌\");" << std::endl;

	std::cout << "v4 now = ";
	std::cout << "{";
	for (size_t i = 0; i < v4.size() - 1; i++)
		std::cout << v4[i] << ", ";
	std::cout << v4[v4.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	std::cout << "\nRange insertion :" << std::endl << std::endl;

	NMSPC::vector<std::string> apple(10, "🍎");
	NMSPC::vector<std::string> lemon(5, "🍋");

	std::cout << "For a std::string vector apple = ";
	std::cout << "{";
	for (size_t i = 0; i < apple.size() - 1; i++)
		std::cout << apple[i] << ", ";
	std::cout << apple[apple.size() - 1];
	std::cout << "}" << std::endl << std::endl;
	std::cout << "For a std::string vector lemon = ";
	std::cout << "{";
	for (size_t i = 0; i < lemon.size() - 1; i++)
		std::cout << lemon[i] << ", ";
	std::cout << lemon[lemon.size() - 1];
	std::cout << "}" << std::endl << std::endl;

	apple.insert(apple.begin() + 5, lemon.begin(), lemon.end());
	std::cout << "apple.insert(apple.begin() + 5, lemon.begin(), lemon.end());" << std::endl << std::endl;

	std::cout << "Now apple = ";
	std::cout << "{";
	for (size_t i = 0; i < apple.size() - 1; i++)
		std::cout << apple[i] << ", ";
	std::cout << apple[apple.size() - 1];
	std::cout << "}" << std::endl;
}

void	test_clear_erase(void)
{
	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Clear() :" << std::endl << std::endl;

	NMSPC::vector<std::string> mess(20, "MESS");

	std::cout << "For a vector named mess = {";
	for (NMSPC::vector<std::string>::iterator it = mess.begin(); it + 1 != mess.end(); it++)
		std::cout << *it << ", ";
	if (mess.empty() == false)
		std::cout << mess[mess.size() - 1] << "}" << std::endl;
	else
		std::cout << "}" << std::endl;

	std::cout << "vector<std::string> mess(20, \"MESS\");" << std::endl;
	std::cout << "mess.size() = " << mess.size() << std::endl;
	std::cout << "mess.capacity() = " << mess.capacity() << std::endl << std::endl;

	mess.clear();
	std::cout << "mess.clear();" << std::endl;
	std::cout << "mess = {";
	if (mess.empty() == false)
	{
		for (NMSPC::vector<std::string>::iterator it = mess.begin(); it + 1 != mess.end(); it++)
			std::cout << *it << ", ";
		std::cout << mess[mess.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << "mess.size() = " << mess.size() << std::endl;
	std::cout << "mess.capacity() = " << mess.capacity() << std::endl << std::endl;

	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Erase() :" << std::endl;

	NMSPC::vector<std::string> alien_hidden(10, "🎅");

	alien_hidden.insert(alien_hidden.begin() + 2, "👽");
	alien_hidden.insert(alien_hidden.begin() + 5, "👽");
	alien_hidden.insert(alien_hidden.begin() + 5, "👽");
	alien_hidden.insert(alien_hidden.begin() + 9, "👽");
	std::cout << "For a string vector alien_hidden = {";
	if (alien_hidden.empty() == false)
	{
		for (NMSPC::vector<std::string>::iterator it = alien_hidden.begin(); it + 1 != alien_hidden.end(); it++)
			std::cout << *it << ", ";
		std::cout << alien_hidden[alien_hidden.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << std::endl;

	alien_hidden.erase(alien_hidden.begin() + 2);
	std::cout << "alien_hidden.erase(alien_hidden.begin() + 2);" << std::endl;
	std::cout << "now alien_hidden = {";
	if (alien_hidden.empty() == false)
	{
		for (NMSPC::vector<std::string>::iterator it = alien_hidden.begin(); it + 1 != alien_hidden.end(); it++)
			std::cout << *it << ", ";
		std::cout << alien_hidden[alien_hidden.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << std::endl;

	alien_hidden.erase(alien_hidden.begin() + 8);
	std::cout << "alien_hidden.erase(alien_hidden.begin() + 8);" << std::endl;
	std::cout << "now alien_hidden = {";
	if (alien_hidden.empty() == false)
	{
		for (NMSPC::vector<std::string>::iterator it = alien_hidden.begin(); it + 1 != alien_hidden.end(); it++)
			std::cout << *it << ", ";
		std::cout << alien_hidden[alien_hidden.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << std::endl;

	alien_hidden.erase(alien_hidden.begin() + 4, alien_hidden.begin() + 6);
	std::cout << "alien_hidden.erase(alien_hidden.begin() + 4, alien_hidden.begin() + 6);" << std::endl;
	std::cout << "now alien_hidden = {";
	if (alien_hidden.empty() == false)
	{
		for (NMSPC::vector<std::string>::iterator it = alien_hidden.begin(); it + 1 != alien_hidden.end(); it++)
			std::cout << *it << ", ";
		std::cout << alien_hidden[alien_hidden.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << std::endl;

	alien_hidden.erase(alien_hidden.begin(), alien_hidden.end());
	std::cout << "alien_hidden.erase(alien_hidden.begin(), alien_hidden.end());" << std::endl;
	std::cout << "now alien_hidden = {";
	if (alien_hidden.empty() == false)
	{
		for (NMSPC::vector<std::string>::iterator it = alien_hidden.begin(); it + 1 != alien_hidden.end(); it++)
			std::cout << *it << ", ";
		std::cout << alien_hidden[alien_hidden.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	std::cout << std::endl;
}

void	test_swap(void)
{
	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Swap() :" << std::endl << std::endl;

	NMSPC::vector<std::string> victor(10, "🌹");
	std::cout << "For a string vector victor = {";
	if (victor.empty() == false)
	{
		for (NMSPC::vector<std::string>::iterator it = victor.begin(); it + 1 != victor.end(); it++)
			std::cout << *it << ", ";
		std::cout << victor[victor.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	NMSPC::vector<std::string>::iterator itVictor = victor.begin();

	NMSPC::vector<std::string> vincent(5, "🌷");
	std::cout << "For a string vector vincent = {";
	if (vincent.empty() == false)
	{
		for (NMSPC::vector<std::string>::iterator it = vincent.begin(); it + 1 != vincent.end(); it++)
			std::cout << *it << ", ";
		std::cout << vincent[vincent.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;
	NMSPC::vector<std::string>::iterator itVincent = vincent.begin();

	vincent.swap(victor);
	std::cout << "vincent.swap(victor);" << std::endl;
	std::cout << "Checking validity of iterators and pointers after the swap : " <<std::endl;
	int restSwap = (itVictor == vincent.begin());
	std::cout << "itVictor == vincent.begin() ? " <<  restSwap <<std::endl;
	restSwap = (itVincent == victor.begin());
	std::cout << "itVincent == victor.begin() ? " <<  restSwap <<std::endl;
	std::cout << "Now iterating with the old iterators in the swapped containers : " <<std::endl;
	while (itVincent != victor.end())
	{
		std::cout << *itVincent << ", ";
		++itVincent;
	}
	std::cout << std::endl;

	std::cout << "now victor = {";
	if (victor.empty() == false)
	{
		for (NMSPC::vector<std::string>::iterator it = victor.begin(); it + 1 != victor.end(); it++)
			std::cout << *it << ", ";
		std::cout << victor[victor.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	std::cout << "now vicent = {";
	if (vincent.empty() == false)
	{
		for (NMSPC::vector<std::string>::iterator it = vincent.begin(); it + 1 != vincent.end(); it++)
			std::cout << *it << ", ";
		std::cout << vincent[vincent.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	vincent.swap(victor);
	std::cout << "vincent.swap(victor);" << std::endl;

	std::cout << "now victor = {";
	if (victor.empty() == false)
	{
		for (NMSPC::vector<std::string>::iterator it = victor.begin(); it + 1 != victor.end(); it++)
			std::cout << *it << ", ";
		std::cout << victor[victor.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	std::cout << "now vicent = {";
	if (vincent.empty() == false)
	{
		for (NMSPC::vector<std::string>::iterator it = vincent.begin(); it + 1 != vincent.end(); it++)
			std::cout << *it << ", ";
		std::cout << vincent[vincent.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	victor.swap(vincent);
	std::cout << "victor.swap(vincent);" << std::endl;

	std::cout << "now victor = {";
	if (victor.empty() == false)
	{
		for (NMSPC::vector<std::string>::iterator it = victor.begin(); it + 1 != victor.end(); it++)
			std::cout << *it << ", ";
		std::cout << victor[victor.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	std::cout << "now vicent = {";
	if (vincent.empty() == false)
	{
		for (NMSPC::vector<std::string>::iterator it = vincent.begin(); it + 1 != vincent.end(); it++)
			std::cout << *it << ", ";
		std::cout << vincent[vincent.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	NMSPC::vector<std::string>	empty_one;
	NMSPC::vector<std::string>	empty_two;

	std::cout << "For a string vector empty_one = {";
	if (empty_one.empty() == false)
	{
		for (NMSPC::vector<std::string>::iterator it = empty_one.begin(); it + 1 != empty_one.end(); it++)
			std::cout << *it << ", ";
		std::cout << empty_one[empty_one.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	std::cout << "For a string vector empty_two = {";
	if (empty_two.empty() == false)
	{
		for (NMSPC::vector<std::string>::iterator it = empty_two.begin(); it + 1 != empty_two.end(); it++)
			std::cout << *it << ", ";
		std::cout << empty_two[empty_two.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	empty_one.swap(empty_two);
	std::cout << "empty_one.swap(empty_two);" << std::endl;

	std::cout << "now empty_one = {";
	if (empty_one.empty() == false)
	{
		for (NMSPC::vector<std::string>::iterator it = empty_one.begin(); it + 1 != empty_one.end(); it++)
			std::cout << *it << ", ";
		std::cout << empty_one[empty_one.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl;

	std::cout << "now empty_two = {";
	if (empty_two.empty() == false)
	{
		for (NMSPC::vector<std::string>::iterator it = empty_two.begin(); it + 1 != empty_two.end(); it++)
			std::cout << *it << ", ";
		std::cout << empty_two[empty_two.size() - 1] << "}" << std::endl;
	}
	else
		std::cout << "}" << std::endl << std::endl;
}

void	test_buffer()
{
	std::cout << "\n---------------------------- " << std::endl;
	std::cout << "Buffer test :" << std::endl;
	NMSPC::vector<Buffer> vector_buffer;
	std::cout <<"COUNT value = " << COUNT << std::endl;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}

	NMSPC::vector<Buffer>().swap(vector_buffer);

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
		std::cout << "All went well" << std::endl;
		//NORMAL ! :P
	}
}

void	vectorTests()
{
	test_push();
	test_element_access();
	test_re_serve_size();
	test_pop_back();
	test_constructors();
	test_iterator_incrementers();
	test_iterator_booleans();
	test_iterator_booleans_const();
	test_iterator_deref();
	test_reverse_iterator();
	test_assign();
	test_insert();
	test_clear_erase();
	test_swap();
	test_buffer();
}
