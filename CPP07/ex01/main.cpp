#include "Iter.hpp"

int main() 
{
	std::cout << YELLOW "INT: " RESET << std::endl;
	int intArr[] = {1, 2, 3, 4, 5};
	iter(intArr, LEN, print<int>);
	std::cout << std::endl;

	std::cout << YELLOW "DOUBLE: " RESET << std::endl;
	double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	iter(doubleArr, LEN, print<double>);
	std::cout << std::endl;

	std::cout << YELLOW "FLOAT: " RESET << std::endl;
	float floatArr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	iter(floatArr, LEN, print<float>);
	std::cout << std::endl;

	std::cout << YELLOW "CHAR: " RESET << std::endl;
	char charArr[] = {'a', 'b', 'c', 'd', 'e'};
	iter(charArr, LEN, print<char>);
	std::cout << std::endl;

	std::cout << YELLOW "STRING: " RESET << std::endl;
	std::string strArr[] = {"je", "pense", "donc", "je", "suis"};
	iter(strArr, LEN, print<std::string>);
	std::cout << std::endl;

	std::cout << YELLOW "NULL: " RESET << std::endl;
	int* nullArr = NULL;
	iter(nullArr, LEN, print<int>);

	std::cout << std::endl;

	return 0;
}
