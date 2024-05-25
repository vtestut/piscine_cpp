#include "RPN.hpp"

int main(int argc, char *argv[]) 
{
	if (argc != 2) 
	{
		std::cerr << RED "Errror: wrong usage : " 
		<< YELLOW << "./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" RESET << std::endl;
		return 1;
	}

	try 
	{
		RPN b = RPN(argv[1]); // Crée un objet RPN en utilisant l'argument passé en ligne de commande
		RPN b2 = b; // Utilise le constructeur de copie pour créer un deuxième objet RPN
		b2.run(); // Exécute la méthode run() de l'objet RPN pour afficher le résultat
	} 
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}