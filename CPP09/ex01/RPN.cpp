#include "RPN.hpp"

// Exécute le calculateur RPN en affichant le résultat final s'il existe.
void RPN::run() {
    // Vérifie si la deque n'est pas vide avant d'accéder au dernier élément.
    if (!deque.empty()) {
        // Affiche le résultat final qui est le dernier élément de la deque.
        std::cout << deque.back() << std::endl;
    }
}

// Constructeur qui prend une chaîne représentant les opérations et les nombres.
RPN::RPN(std::string arg) {
    // Supprime tous les espaces de la chaîne pour simplifier le traitement.
    arg.erase(std::remove_if(arg.begin(), arg.end(), ::isspace), arg.end());

    // Itère sur chaque caractère de la chaîne.
    for (std::string::iterator it = arg.begin(); it != arg.end(); ++it) {
        // Vérifie si le caractère est un chiffre.
        if (*it >= '0' && *it <= '9') {
            // Convertit le caractère en float et l'ajoute à la fin de la deque.
            deque.push_back(*it - '0');
        } else if ((*it == '+' || *it == '-' || *it == '*' || *it == '/') && deque.size() >= 2) {
            // Prend les deux derniers éléments pour l'opération.
            float b = deque.back(); deque.pop_back();
            float a = deque.back(); deque.pop_back();

            // Effectue l'opération en fonction du caractère et ajoute le résultat.
            switch (*it) {
                case '+': deque.push_back(a + b); break;
                case '-': deque.push_back(a - b); break;
                case '*': deque.push_back(a * b); break;
                case '/':
                    if (b == 0.0) // Vérifie la division par zéro.
                        throw std::invalid_argument(RED "Error: Division by zero" RESET);
                    deque.push_back(a / b);
                    break;
            }
        } else {
            // Gère les erreurs pour les caractères non valides ou manque d'opérandes.
            throw std::invalid_argument(RED "Error: wrong args" RESET);
        }
    }
    // Vérifie si un seul élément reste dans la deque, sinon erreur.
    if (deque.size() != 1)
        throw std::invalid_argument(RED "Error: too many digits in the deque" RESET);
}

// Constructeur par défaut, sans opérations spécifiques.
RPN::RPN() {}

// Destructeur.
RPN::~RPN() {}

// Constructeur de copie.
RPN::RPN(const RPN& other) : deque(other.deque) {}

// Opérateur d'affectation.
RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        deque = other.deque; // Copie la deque de l'autre instance.
    }
    return *this;
}
