#include "Span.hpp"
#include <cstdlib>
#include <ctime>

void title(std::string str) {
	std::cout << YELLOW "*** " << str << RESET << std::endl;
}

void test_span() {
	title("Testing shortestSpan");
	Span span(5);
	span.addNumber(1);
	span.addNumber(2);
	span.addNumber(9);
	span.addNumber(9);
	span.addNumber(43);
	
	try {
		int ret = span.shortestSpan();
		std::cout << "Shortest: " << ret << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	} try {
		int ret = span.longestSpan();
		std::cout << "Longest : " << ret << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	} std::cout << std::endl;
}

void test_sizeMax() {
	title("Testing size max");
	Span span(3);
	
	try {
		span.addNumber(1);
		span.addNumber(2);
		span.addNumber(3);
		span.addNumber(4);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	} std::cout << std::endl;
}

void test_empty() {
	title("Testing with empty span");
	Span span(2);
	
	try {
		int ret = span.shortestSpan();
		std::cout << "Shortest Span: " << ret << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	} try {
		int ret = span.longestSpan();
		std::cout << "Longest Span: " << ret << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	} std::cout << std::endl;
}

void test_10000() {
	title("Testing addNumbers with 10k numbers");
	Span span(10000);
	std::vector<int> nums;

	std::srand(std::time(0));
	for (int i = 0; i < 10000; ++i)
		nums.push_back(std::rand() % 1000000);
	
	try {
		span.addNumbers(nums.begin(), nums.end());
		std::cout << "Shortest: " << span.shortestSpan() << std::endl;
		std::cout << "Longest\t: " << span.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	} std::cout << std::endl;
}

void test_15000() {
	title("Testing addNumbers with 15k numbers");
	Span span(15000);
	std::vector<int> nums(15000);

	for (int i = 0; i < 15000; ++i)
		nums[i] = i;
	try {
		span.addNumbers(nums.begin(), nums.end());
		std::cout << "Shortest: " << span.shortestSpan() << std::endl;
		std::cout << "Longest : " << span.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	} std::cout << std::endl;
}

int main() {
	try {
		test_span();
		test_sizeMax();
		test_empty();
		test_10000();
		test_15000();
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
