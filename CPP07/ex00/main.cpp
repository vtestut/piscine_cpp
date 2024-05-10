#include "Whatever.hpp"

void test2() {
	std::cout << std::endl << YELLOW "MORE TESTS" RESET << std::endl;
	char char1 = 'a';
	char char2 = 'z';
	std::cout << std::endl << YELLOW "CHAR TESTS: char1 = " << char1 << ", char2 = " << char2 << RESET << std::endl;
	swap(char1, char2);
	std::cout << "swap: char1 = " << char1 << ", char2 = " << char2 << std::endl;
	std::cout << "min() = " << min(char1, char2) << std::endl;
	std::cout << "max() = " << max(char1, char2) << std::endl;

	int int1 = 2;
	int int2 = 3;
	std::cout << std::endl << YELLOW "INT TESTS: int1 = " << int1 << ", int2 = " << int2 << RESET << std::endl;
	swap(int1, int2);
	std::cout << "swap: int1 = " << int1 << ", int2 = " << int2 << RESET << std::endl;
	std::cout << "min() = " << min(int1, int2) << RESET << std::endl;
	std::cout << "max() = " << max(int1, int2) << RESET << std::endl;

	float float1 = 1.001f;
	float float2 = 1.002f;
	std::cout << std::endl << YELLOW "FLOAT TESTS: float1 = " << float1 << ", float2 = " << float2 << RESET << std::endl;
	swap(float1, float2);
	std::cout << "swap: float1 = " << float1 << ", float2 = " << float2 << RESET << std::endl;
	std::cout << "min() = " << min(float1, float2) << RESET << std::endl;
	std::cout << "max() = " << max(float1, float2) << RESET << std::endl;

	double double1 = 1.1;
	double double2 = 1.2;
	std::cout << std::endl << YELLOW "DOUBLE TESTS: double1 = " << double1 << ", double2 = " << double2 << RESET << std::endl;
	swap(double1, double2);
	std::cout << "swap: double1 = " << double1 << ", double2 = " << double2 << RESET << std::endl;
	std::cout << "min() = " << min(double1, double2) << RESET << std::endl;
	std::cout << "max() = " << max(double1, double2) << RESET << std::endl;


	std::string str1 = "Apple", str2 = "Banana";
	std::cout << std::endl << YELLOW "STRING TESTS: str1 = " << str1 << ", str2 = " << str2 << RESET << std::endl;
	swap(str1, str2);
	std::cout << "swap: str1 = " << str1 << ", str2 = " << str2 << RESET << std::endl;
	std::cout << "min() = " << min(str1, str2) << RESET << std::endl;
	std::cout << "max() = " << max(str1, str2) << RESET << std::endl;
}

int main( void ) {
	int a = 2;
	int b = 3;
	std::cout << std::endl << YELLOW "MAIN TEST" RESET << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	test2();
	return 0;
}