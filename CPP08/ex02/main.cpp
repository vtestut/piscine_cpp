#include "MutantStack.hpp"

void title(std::string str) {
	std::cout << YELLOW "*** " << str << RESET << std::endl;
}

void test_mutant() {
	title("Testing MutantStack:");
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	mstack.pop();
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl;
}

void test_list() {
	title("Testing std::list");
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	lst.push_back(5);
	lst.push_back(5);
	lst.push_back(5);
	lst.push_back(5);
	lst.push_back(5);
	lst.push_back(5);
	lst.push_back(5);

	std::cout << "Size after pop: " << lst.size() << std::endl;
	std::cout << "Top element: " << lst.back() << std::endl;
	std::cout << "Front element: " << lst.front() << std::endl;
	printIterator(lst.begin(), lst.end());
	printIterator(lst.rbegin(), lst.rend());
	std::cout << std::endl;
}

void test_vector() {
	title("Testing std::vector");
	std::vector<int> vec;
	vec.push_back(0);
	vec.push_back(5);
	vec.push_back(17);
	vec.pop_back();
	vec.push_back(3);
	vec.push_back(737);
	vec.push_back(5);

	std::cout << "Size after pop: " << vec.size() << std::endl;
	std::cout << "Top element: " << vec.back() << std::endl;
	std::cout << "Front element: " << vec.front() << std::endl;
	printIterator(vec.begin(), vec.end());
	printIterator(vec.rbegin(), vec.rend());
	std::cout << std::endl;
}

void test_deque() {
	title("Testing std::deque");
	std::deque<int> deq;
	deq.push_back(5);
	deq.push_back(17);
	deq.push_back(3);
	deq.push_back(737);
	deq.push_back(5);
	deq.push_back(0);
	deq.pop_back();
	deq.pop_back();

	std::cout << "Size after pop: " << deq.size() << std::endl;
	std::cout << "Top element: " << deq.back() << std::endl;
	std::cout << "Front element: " << deq.front() << std::endl;
	printIterator(deq.begin(), deq.end());
	printIterator(deq.rbegin(), deq.rend());
	std::cout << std::endl;
}

int main() {
	try {
		test_mutant();
		test_list();
		test_vector();
		test_deque();
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
