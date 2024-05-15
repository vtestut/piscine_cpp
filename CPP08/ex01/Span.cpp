#include "Span.hpp"

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void Span::addNumber(int number) {
	if (_container.size() >= _sizeMax) {
		throw std::out_of_range(RED "Can't add more numbers" RESET);
	}
	_container.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end) 
{
	// Calculer le nombre d'éléments entre les itérateurs start et end
	std::vector<int>::difference_type dist = std::distance(start, end);

	// Vérifier s'il y a assez de place dans le conteneur pour ajouter les nouveaux éléments
	if (dist > static_cast<std::vector<int>::difference_type>(_sizeMax - _container.size()))
		throw std::out_of_range(RED "Can't add more numbers" RESET);

	// Ajouter les éléments de la plage [start, end) à la fin du conteneur
	_container.insert(_container.end(), start, end);
}

int Span::shortestSpan() const {
	if (_container.size() < 2)
		throw std::logic_error(RED "Not enough numbers (short)" RESET);

	// Trie les nombres pour faciliter le calcul des écarts consécutifs
	std::vector<int> sortedNumbers = _container;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	// Initialise minSpan avec l'écart entre les deux premiers éléments triés
	int minSpan = sortedNumbers[1] - sortedNumbers[0];

	// Parcourt les éléments triés pour trouver le plus petit écart
	for (size_t i = 1; i < sortedNumbers.size() - 1; ++i) {
		int span = sortedNumbers[i + 1] - sortedNumbers[i];
		// Met à jour minSpan si un écart plus petit est trouvé
		if (span < minSpan) {
			minSpan = span;
		}
	}
	return minSpan;
}

/* template< class ForwardIt >
ForwardIt min_element( ForwardIt first, ForwardIt last );
retourne un itérateur pointant vers le plus petit élément
L'appel à std::min_element(_container.begin(), _container.end()) retourne un itérateur (disons it) 
pointant vers le plus petit élément de la plage spécifiée.
Cet itérateur est de type std::vector<int>::iterator si _container est un vecteur d'entiers.*/
int Span::longestSpan() const {
	if (_container.size() < 2) {
		throw std::logic_error(RED "Not enough numbers (long)" RESET);
	}

	int min = *std::min_element(_container.begin(), _container.end());
	int max = *std::max_element(_container.begin(), _container.end());

	return max - min;
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Span::Span(unsigned int n) : _sizeMax(n) {}

Span::Span(const Span& obj) : _container(obj._container), _sizeMax(obj._sizeMax) {}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

Span& Span::operator=(const Span& obj) {
	if (this != &obj) {
		_container = obj._container;
		_sizeMax = obj._sizeMax;
	}
	return *this;
}