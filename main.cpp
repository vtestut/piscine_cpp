#include "colors.hpp"

int main() 
{
    std::cout << BLACK << "Texte souligné." << RESET << std::endl;
    std::cout << RED << "Texte souligné." << RESET << std::endl;
    std::cout << GREEN << "Texte souligné." << RESET << std::endl;
    std::cout << YELLOW << "Texte souligné." << RESET << std::endl;
    std::cout << BLUE << "Texte souligné." << RESET << std::endl;
    std::cout << MGNTA << "Texte souligné." << RESET << std::endl;
    std::cout << CYAN << "Texte souligné." << std::endl;
    std::cout << WHITE << "Texte souligné." << RESET << std::endl;
    std::cout << "Texte sans rien" << std::endl;

    return 0;
}