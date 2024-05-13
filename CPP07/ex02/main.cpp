#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

void test2()
{
	std::cout << std::endl << YELLOW "MORE TESTS" RESET << std::endl;

	Array<int> emptyArray;
	std::cout << "*** Test with no param. size = " << GREEN << emptyArray.size() << RESET << std::endl << std::endl;

	Array<int> intArr(5);
	std::cout << "*** Test with param (5). size = " << GREEN << intArr.size() << RESET << std::endl;
	std::cout << CYAN << "Display array : " << intArr << RESET << std::endl << std::endl;

	try 
	{
		intArr[0] = 10;
		std::cout << "*** Test to write :" GREEN << std::endl;
		for (int i = 0; i < 5; i++)
			intArr[i] = i+1;
		std::cout << CYAN << "Display array : " << intArr << RESET << std::endl << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << "Test: Write access using [] -> Failed, " << e.what() << RESET << std::endl;
	}

	try 
	{
		std::cout << "*** Test out of range : " << std::endl;
		intArr[10] = 100;
	} catch (const std::out_of_range& e) {
		std::cout << GREEN << e.what() << RESET << std::endl << std::endl;
	} catch (...) {
		std::cout << RED << "Test: Out of range access -> Failed" << RESET << std::endl;
	}

	std::cout << "*** Test copy constructor (copyArr[0] = 20):"<< std::endl;
	Array<int> copyArr(intArr);
	copyArr[0] = 20;
	if (intArr[0] != copyArr[0])
		std::cout << "original: " GREEN << intArr[0] << RESET ", copy: " GREEN << copyArr[0] << RESET << std::endl << std::endl;
	else
		std::cout << RED << "Failed, original and copy are the same" << RESET << std::endl;

	std::cout << "*** Test assignment operator (assArr[0] = 30):"<< std::endl;
	Array<int> assArr;
	assArr = copyArr;
	assArr[0] = 30;
	if (intArr[0] != assArr[0])
		std::cout << "original: " GREEN << intArr[0] << RESET ", copy: " GREEN << copyArr[0] << RESET ", assigned: " GREEN << assArr[0] << RESET << std::endl << std::endl;
	else
		std::cout << RED << "Failed, original and assigned are the same" << RESET << std::endl;
}

int main(int, char**)
{   
	std::cout << YELLOW "MAIN TEST" RESET << std::endl;

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//

	test2();
	return 0;
}