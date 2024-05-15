#ifndef  _EASYFIND_HPP
# define _EASYFIND_HPP

# include <iostream>
# include <exception>
# include <algorithm>
# include <vector>
# include <list>
# include <deque>

/******************************************************************************/
/*									DEFINES									  */
/******************************************************************************/

# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define CYAN    "\033[36m"
# define YELLOW  "\033[93m"

# define RESET   "\033[0m"
# define CLEAR	"\033[2J\033[1;1H"

/******************************************************************************/
/*									TEMPLATES								  */
/******************************************************************************/

/*Un itérateur est un objet qui fournit un moyen de parcourir séquentiellement les éléments d'une structure de données. 
Il sert à accéder aux éléments individuels d'une collection (comme un conteneur) et à effectuer des opérations telles que la lecture, 
l'écriture ou la suppression d'éléments. Un itérateur se comporte comme un pointeur dans le sens où il peut pointer vers 
un élément spécifique dans la séquence, mais il encapsule souvent des détails de la manière dont cet accès est implémenté 
(par exemple, un itérateur de liste doublement chaînée peut devoir effectuer des opérations de saut de nœud interne plutôt que 
d'incrémenter simplement une adresse mémoire. 

Un objet iterator n'est pas une classe en soi, mais plutôt un type défini par des classes ou 
des structures de données spécifiques. Chaque type de conteneur peut définir ses propres types d'itérateurs pour permettre 
l'itération à travers ses éléments. Ces types d'itérateurs peuvent être différents en fonction de la structure interne du conteneur et des 
opérations qu'il prend en charge (comme l'insertion, la suppression, etc.). 
Ainsi, chaque conteneur standard (comme std::vector, std::list, std::deque, etc.) fournit ses propres types d'itérateurs adaptés à ses besoins*/

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	if (container.empty())
		throw std::invalid_argument( RED "Container is empty" RESET );
// typename est nécessaire pour indiquer au compilateur que T::iterator est bien un type. le compilateur ne peut pas déterminer à la compilation si iterator est un type ou une valeur.
	typename T::iterator it = std::find(container.begin(), container.end(), value);
// find cherche et renvoie un iterateur sur la 1ere occurence de value ou sur end()
	if (it == container.end())
		throw std::out_of_range( RED "Value not found" RESET );
	return it;
}

#endif