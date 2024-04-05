#ifndef  _IMATERIASOURCE_HPP
# define _IMATERIASOURCE_HPP

# include "AMateria.hpp"
# include <string>

/*	classes purement abstraites = interface 
	-	Cela permet de spécifier un ensemble de méthodes que les classes dérivées doivent implémenter, 
		sans fournir d'implémentation par défaut. Cela favorise une conception par interface plutôt que 
		par implémentation, ce qui rend le code plus flexible et plus facile à maintenir.
	-	Forcer l'implémentation: force les classes dérivées à fournir une implémentation pour ces méthodes. 
		Si une classe dérivée ne fournit pas d'implémentation pour une méthode virtuelle pure, 
		elle restera également une classe abstraite et ne pourra pas être instanciée directement.
	-	Cela simplifie la manipulation d'objets polymorphiques, car vous pouvez travailler avec des 
		pointeurs ou des références de la classe de base sans vous soucier de l'implémentation spécifique 
		dans les classes dérivées. Vous pouvez donc manipuler un groupe d'objets de différentes 
		classes dérivées via un pointeur ou une référence de la classe de base, 
		en utilisant des méthodes virtuelles pour appeler le bon comportement spécifique à chaque classe dérivée*/

class IMateriaSource {

public :

	virtual ~IMateriaSource() {};

	/* Copie la Materia passée en paramètre et la stocke en mémoire afin de la cloner
plus tard. Tout comme le Character, la MateriaSource peut contenir 4 Materias
maximum. Ces dernières ne sont pas forcément uniques.*/
	virtual void		learnMateria(AMateria * m) = 0;

	/*Retourne une nouvelle Materia. Celle-ci est une copie de celle apprise précédem-
ment par la MateriaSource et dont le type est le même que celui passé en para-
mètre. Retourne 0 si le type est inconnu.*/
	virtual AMateria*	createMateria(std::string const & type) = 0;

};

#endif