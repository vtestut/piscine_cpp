#include <iostream>
#include <string>

int main() {

	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << std::endl;
	std::cout << "L'adresse de 'str' en memoire\t  est (&str)\t   : " << &str << std::endl;
	std::cout << "L'adresse stockee dans stringPTR  est (stringPTR)  : " << stringPTR << std::endl;
	std::cout << "L'adresse stockee dans stringREF  est (&stringREF) : " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "La valeur de str\t\t  est (str)\t   : " << str << std::endl;
	std::cout << "La valeur pointee par stringSTR\t  est (*stringSTR) : " << *stringPTR << std::endl;
	std::cout << "La valeur pointee para stringREF  est (stringREF)  : " << stringREF << std::endl;
	std::cout << std::endl;

	return (0);
}