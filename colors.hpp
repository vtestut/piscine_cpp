#include <iostream>

#define RESET	"\033[0m"
#define CLEAR	"\033[2J\033[1;1H"

#define BLACK	"\033[30m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MGNTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"

// Couleurs de fond
#define BG_BLACK   "\033[40m"
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_WHITE   "\033[47m"

// Effets spéciaux
#define BLINK      "\033[5m"

// Autres contrôles de curseur
#define CURSOR_SAVE	"\033[s"  // Enregistrer la position du curseur
#define CURSOR_RSTR	"\033[u"  // Restaurer la position du curseur

// Déplacer le curseur
#define CURSOR_UP(n)	"\033[" #n "A" // Déplacer le curseur vers le haut de n lignes
#define CURSOR_DOWN(n)	"\033[" #n "B" // Déplacer le curseur vers le bas de n lignes
#define CURSOR_FRWRD(n) "\033[" #n "C" // Déplacer le curseur vers l'avant de n colonnes
#define CURSOR_BACK(n)	"\033[" #n "D" // Déplacer le curseur vers l'arrière de n colonnes

// Styles de texte
#define DOUBLE_UNDERLINE "\033[21m"
#define CROSSED_OUT	"\033[9m"
#define UNDERLINE	"\033[4m"
#define REVERSE	"\033[7m"
#define HIDDEN	"\033[8m"
#define BOLD	"\033[1m"

/*

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

*/