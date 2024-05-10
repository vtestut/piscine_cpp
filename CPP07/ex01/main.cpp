#include "Iter.hpp"

int main() {
	int arrInt[] = {1, 2, 3, 4, 5};
	double arrDouble[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	float arrFloat[] = {1.0f, 2.5f, 3.75f, 4.8f, 5.9f};
	char arrChar[] = {'a', 'b', 'c', 'd', 'e'};
	std::string arrString[] = {"am", "stram", "gram"};

	std::cout << YELLOW "INT: " RESET << std::endl;
	iter<int, void (*)(const int&)>(arrInt, 5, print);
	std::cout << std::endl;

	// ! pk ? iter<int, void (*)(const int&)> ???


	std::cout << YELLOW "DOUBLE: " RESET << std::endl;
	iter<double, void (*)(const double&)>(arrDouble, 5, print);
	std::cout << std::endl;

	std::cout << YELLOW "FLOAT: " RESET << std::endl;
	iter<float, void (*)(const float&)>(arrFloat, 5, print);
	std::cout << std::endl;

	std::cout << YELLOW "CHAR: " RESET << std::endl;
	iter<char, void (*)(const char&)>(arrChar, 5, print);
	std::cout << std::endl;

	std::cout << YELLOW "STRING: " RESET << std::endl;
	iter<std::string, void (*)(const std::string&)>(arrString, 3, print);
	std::cout << std::endl;

	std::cout << YELLOW "NULL: " RESET << std::endl;
	int* nullArr = NULL;
	iter<int, void (*)(const int&)>(nullArr, 5, print<int>);
	std::cout << std::endl;

	return 0;
}
