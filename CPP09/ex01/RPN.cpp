#include "RPN.hpp"

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

// Méthode pour exécuter l'évaluation et afficher le résultat
void RPN::run() {
	std::cout << this->top() << std::endl; // Affiche le sommet de la pile
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

RPN::RPN(std::string arg) : std::stack<float>() 
{
	arg.erase(std::remove_if(arg.begin(), arg.end(), isspace), arg.end()); // remove spaces
	
	// Parcourt chaque caractère de la chaîne
	for(std::string::iterator it = arg.begin(); it != arg.end(); ++it)
	{
		if (*it >= '0' && *it <= '9') // Si le caractère est un chiffre, le pousse sur la pile
			this->push(*it - '0');
		// Si le caractère est un opérateur et qu'il y a au moins deux opérandes sur la pile
		else if ((*it == '+' || *it == '-' || *it == '*' || *it == '/') && this->size() >= 2)
		{
			float b = this->top(); // Récupère et retire le premier opérande
			this->pop();
			float a = this->top(); // Récupère et retire le second opérande
			this->pop();
			// Applique l'opérateur et pousse le résultat sur la pile
			if (*it == '+')
				this->push(a + b);
			if (*it == '-')
				this->push(a - b);
			if (*it == '*')
				this->push(a * b);
			if (*it == '/') {
				if (b == 0.0)
					throw std::invalid_argument( RED "Error: Division by zero" RESET );
				this->push(a / b);
			}
		}
		// Si le caractère n'est ni un opérande ni un opérateur valide, lève une exception
		else
	  		throw std::invalid_argument( RED "Error: wrong args" RESET );
	}
	// Vérifie qu'il reste exactement un élément sur la pile, sinon lève une exception
	if (this->size() != 1)
		throw std::invalid_argument( RED "Error: too many digits in the stack" RESET);
}

RPN::RPN() : std::stack<float>() {}

RPN::~RPN() {}

RPN::RPN(const RPN& o) : std::stack<float>() { *this = o; }

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

RPN& RPN::operator=(const RPN& o) {
	// Copie le conteneur sous-jacent de la pile
	std::stack<float>::container_type underliyng_cont_o    = o.c;
	this->c = underliyng_cont_o;
	return *this;
}
