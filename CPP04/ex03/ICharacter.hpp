#ifndef  _ICHARACTER_HPP
# define _ICHARACTER_HPP

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

class AMateria;

class ICharacter {

public :

	virtual ~ICharacter(void) {}

	virtual std::string const & getName(void) const = 0;
	
	virtual void equip(AMateria * m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;

};

#endif