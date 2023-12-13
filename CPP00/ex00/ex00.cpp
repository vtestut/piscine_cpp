#include <iostream>
#include <cctype>


int main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		for (int i = 1; argv[i]; i++)
		{
    		std::string chaine = argv[i];
    		for (char &c : chaine)
        		c = std::toupper(c); 
    		std::cout << chaine;
			if (i == argc)
				std::cout << std::endl;
		}
	}
	else
		std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}