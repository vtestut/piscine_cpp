#include "easyfind.hpp"

void title(std::string str) {
	std::cout << YELLOW "*** " << str << RESET << std::endl;
}

void test_vector() {
	title("Testing std::vector");
	int int_arr[] = {10, 20, 30, 40, 50};
	std::vector<int> int_vec(int_arr, int_arr + sizeof(int_arr) / sizeof(int));
	try {
		std::vector<int>::iterator it = easyfind(int_vec, 30);
		std::cout << "Value found: " GREEN << *it << RESET << std::endl;
		it = easyfind(int_vec, 60);
		std::cout << "Value found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	} std::cout << std::endl;
}

void test_list() {
	title("Testing std::list");
	int int_arr[] = {10, 20, 30, 40, 50};
	std::list<int> int_lst(int_arr, int_arr + sizeof(int_arr) / sizeof(int));
	try {
		std::list<int>::iterator it = easyfind(int_lst, 40);
		std::cout << "Value found: " GREEN << *it << RESET << std::endl;
		it = easyfind(int_lst, 60);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	} std::cout << std::endl;
}

void test_deque() {
	title("Testing std::deque");
	int int_arr[] = {10, 20, 30, 40, 50};
	std::deque<int> int_deq(int_arr, int_arr + sizeof(int_arr) / sizeof(int)); // ! adresse du 1 et du dernier elen du tableau
	try {
		std::deque<int>::iterator it = easyfind(int_deq, 50);
		std::cout << "Value found: " GREEN << *it << RESET << std::endl;
		it = easyfind(int_deq, 60);
		std::cout << "Value found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	} std::cout << std::endl;
}

void test_empty() {
	title("Testing with empty container");
	std::vector<int> empty_vec;
	try {
		std::vector<int>::iterator it = easyfind(empty_vec, 10);
		std::cout << "Value found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {
	try {
		test_vector();
		test_list();
		test_deque();
		test_empty();
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
