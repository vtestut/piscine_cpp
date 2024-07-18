#pragma once

#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <stdexcept>
#include <limits>
#include <exception>
#include <cmath>
#include <iterator> 
#include <algorithm>
#include <bits/stdc++.h>
#include <time.h>
#include <algorithm> 
#include <cctype>
#include <locale>

typedef std::list<unsigned int>::iterator	lst_iter;
typedef std::vector<unsigned int>::iterator	vec_iter;

class PmergeMe {
	
	public:

	clock_t	t_lst;
	clock_t t_vec;

	PmergeMe();
	PmergeMe(const PmergeMe &obj);
	PmergeMe &operator=(const PmergeMe &obj);
	~PmergeMe();

	std::list<unsigned int> run(std::list<unsigned int> lst);
	std::vector<unsigned int>run(std::vector<unsigned int> vec);
};


// CONSTRUCTORS

PmergeMe::PmergeMe() {
  t_lst          = 0;
  t_vec          = 0;
}

PmergeMe::PmergeMe(const PmergeMe& o) { *this = o; }

PmergeMe& PmergeMe::operator=(const PmergeMe& o) { (void)o; return *this; }

PmergeMe::~PmergeMe() {} 

// VECTOR

vec_iter midle_(vec_iter begin, vec_iter end) {
	vec_iter midle = begin;
	std::advance(midle, (std::distance(begin, end) + 1) / 2);
	return midle;
}

std::vector<std::pair<unsigned int, unsigned int> > pairs_(std::vector<unsigned int> c) {
	std::vector<std::pair<unsigned int, unsigned int> > pairs;
	vec_iter it1 = c.begin();
	vec_iter it2 = midle_(c.begin(), c.end());
	
	for( ; it2 != c.end(); ++it1, ++it2)
		pairs.push_back(std::pair<unsigned int, unsigned int> (*it1, *it2));
	if(c.size() % 2 == 1)
		pairs.push_back(std::pair<unsigned int, unsigned int> (*it1, 0));
	return pairs;
}

std::vector<unsigned int> deep_copy_left_half(std::vector<unsigned int> c1) {
	std::vector<unsigned int> c2;
	vec_iter midle = midle_(c1.begin(), c1.end());
	for(vec_iter it = c1.begin(); it != midle; ++it)
		c2.push_back(*it);
	return c2;
}

std::vector<unsigned int> sort_elements_in_every_pair(std::vector<unsigned int> c) {
	vec_iter it1 = c.begin();
	vec_iter it2 = midle_(c.begin(), c.end());
	for( ; it2 != c.end(); ++it1, ++it2)
		if(*it1 > *it2)
			std::swap(*it1, *it2);
	return c;
}

std::vector<unsigned int> right_half_(std::vector<unsigned int> left_half, std::vector<std::pair<unsigned int, unsigned int> > pairs) {
	std::vector<unsigned int> right_half;
	for(std::vector<unsigned int>::iterator it1 = left_half.begin(); it1 != left_half.end(); ++it1) {
		unsigned int wanted_first = *it1;
		unsigned int wanted_second = 0;
		for(std::vector<std::pair<unsigned int, unsigned int> >::iterator it2 = pairs.begin(); it2 != pairs.end(); ++it2)
			if(it2->first == wanted_first) {
				wanted_second = it2->second;
				if(wanted_second > 0)
					right_half.push_back(wanted_second);
				pairs.erase(it2);
				break;
			}
	}
	return right_half;
}

void reverse(std::vector<unsigned int> *c, int n, int m) {
	int i = n;
	int j = m;
	for(; i < j; i++, j--)
		std::swap((*c)[i], (*c)[j]);
}

int change_order(std::vector<unsigned int> *c) {
	unsigned long size_group = 2;
	unsigned long begin_group = 0;
	unsigned long end_group = begin_group + size_group - 1;
	clock_t start = clock();

	for(int pow2 = 4; ; pow2 *= 2) {
		if(end_group >= c->size() - 1) {
			reverse(c, begin_group, c->size() - 1);
			break;
		}
		reverse(c, begin_group, end_group);
		begin_group += size_group;
		size_group = pow2 - size_group;
		end_group = begin_group + size_group - 1;
	}
	return 1000000 * (clock() - start) / CLOCKS_PER_SEC;
}

vec_iter next(vec_iter it) {
  std::advance(it, 1);
  return it;
}

int insert_dichotom(std::vector<unsigned int> *c, unsigned int a) {
	vec_iter left = c->begin();
	vec_iter right = c->end();
	clock_t start = clock();

	if(a< *(c->begin())) {
		c->insert(c->begin(), a);
		return 1000000 * (clock() - start) / CLOCKS_PER_SEC;
	}
	while(std::distance(left, right) > 1) {
		vec_iter midle = midle_(left, right);
		if(next(left) == c->end())
			break;
		else if(a < *midle)
			right = midle;
		else if(a > *midle)
			left = midle;
		else if(a == *midle) {
			c->insert(midle, a);
			return 1000000 * (clock() - start) / CLOCKS_PER_SEC;
		}
	}
	++left;
	c->insert(left, a);
	return 1000000 * (clock() - start) / CLOCKS_PER_SEC;
}

std::vector<unsigned int> run2(std::vector<unsigned int> c, int *t_insert0, int *t_ch_order0) {
	static int t_insert = 0;
	static int t_ch_order = 0;

	if(c.size() <= 1)
		return c;
	if(c.size() == 2 && *(c.begin()) < *(next(c.begin())))
		return c;
	if(c.size() == 2 && *(c.begin()) >= *(next(c.begin()))) {
		std::swap(*(c.begin()), *(next(c.begin())));
		return c;
	}

	std::vector<std::pair<unsigned int, unsigned int> > pairs = pairs_(c);
	std::vector<unsigned int> res = deep_copy_left_half(c);
	c = sort_elements_in_every_pair(c);
	res = run2(res, NULL, NULL);
	std::vector<unsigned int> right_half = right_half_(res, pairs);
	t_ch_order += change_order(&right_half);
	for(vec_iter it = right_half.begin(); it != right_half.end(); ++it)
		t_insert += insert_dichotom(&res, *it);
	if(t_insert0 != NULL) {
		*t_insert0 = t_insert;
		*t_ch_order0 = t_ch_order;
	}
	return res;
}

std::vector<unsigned int> PmergeMe::run(std::vector<unsigned int> c) {
	
	int t_insert;
	int t_ch_order;

	clock_t start = clock();
	int nb_zeros = c.size();

	c.erase(std::remove(c.begin(), c.end(), 0), c.end()); // erase all zeros
	nb_zeros -= c.size();

	std::vector<unsigned int> res = run2(c, &t_insert, &t_ch_order);

	for(int i = 0; i < nb_zeros; i++)
		res.insert(res.begin(), 0);
	
	this->t_vec = 1000000 * (clock() - start) / CLOCKS_PER_SEC;
	
	return res;
}

bool is_valid_int(const char* str) {
    std::string s(str);

    if (!s.empty() && s[0] == '+')
        s = s.substr(1);
    if (s.empty() || s[0] == '-')
        return false;
    for (size_t i = 0; i < s.size(); i++) {
        if (!isdigit(s[i]))
            return false;
    }
    if (s.size() > std::string("4294967295").size())
        return false;
    if (s.size() == std::string("4294967295").size() && s.compare("4294967295") > 0)
        return false;	
    return true;
}

bool check_args(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        if (!is_valid_int(argv[i])) {
            std::cerr << "Invalid argument: " << argv[i] << std::endl;
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv) {

	std::list<unsigned int> lst;
	std::vector<unsigned int> vec;

	if(!check_args(argc, argv)) {
		std::cerr<< "Error: invalid arguments" << std::endl;
		return EXIT_FAILURE;
	}

	for(int i = 1; i < argc; i++) {
		lst.push_back(std::strtoul(argv[i], NULL, 10));
		vec.push_back(std::strtoul(argv[i], NULL, 10));
	}

	std::cout << "Before:\t";
	for(lst_iter it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	PmergeMe data;
	std::list<unsigned int> sorted_list = data.run(lst);
	std::vector<unsigned int> sorted_vector = data.run(vec);

	std::cout << "After:\t";
    for (lst_iter it = sorted_list.begin(); it != sorted_list.end(); ++it)
      std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << lst.size() << " elements with std::list   : " << data.t_lst << " mircosec\n";
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << data.t_vec << " microsec\n";

	return EXIT_SUCCESS;
}