#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        for (int i = 1; i < argc; i++)
        {
            std::string chaine = argv[i];
            for (size_t j = 0; j < chaine.length(); j++)
                chaine[j] = std::toupper(chaine[j]);

            std::cout << chaine;
            if (i == argc - 1)
                std::cout << std::endl;
        }
    }
    else
        std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}
