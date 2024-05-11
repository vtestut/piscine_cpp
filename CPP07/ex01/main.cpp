#include "Iter.hpp"

int main() 
{
	int arrInt[] = {1, 2, 3, 4, 5};
	double arrDouble[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	float arrFloat[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	char arrChar[] = {'a', 'b', 'c', 'd', 'e'};
	std::string arrString[] = {"je", "pense", "donc", "je", "suis"};
	int* nullArr = NULL;

	std::cout << YELLOW "INT: " RESET << std::endl;
	iter(arrInt, LEN, print<int>);
	std::cout << std::endl;

	std::cout << YELLOW "DOUBLE: " RESET << std::endl;
	iter(arrDouble, LEN, print<double>);
	std::cout << std::endl;

	std::cout << YELLOW "FLOAT: " RESET << std::endl;
	iter(arrFloat, LEN, print<float>);
	std::cout << std::endl;

	std::cout << YELLOW "CHAR: " RESET << std::endl;
	iter(arrChar, LEN, print<char>);
	std::cout << std::endl;

	std::cout << YELLOW "STRING: " RESET << std::endl;
	iter(arrString, LEN, print<std::string>);
	std::cout << std::endl;

	std::cout << YELLOW "NULL: " RESET << std::endl;
	iter(nullArr, LEN, print<int>);

	std::cout << std::endl;

	return 0;
}
