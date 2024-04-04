#ifndef  _AANIMAL_HPP
# define _AANIMAL_HPP

# include <iostream>
# include <stdexcept>
# include <string>

# include "Brain.hpp"

/*	une classe abstraite est une classe qui ne peut pas être instanciée directement. 
	Elle sert de modèle à d'autres classes dérivées en définissant des méthodes virtuelles pures, 
	c'est-à-dire des méthodes qui n'ont pas de définition dans la classe abstraite elle-même et 
	qui doivent être implémentées par les classes dérivées.

	Une classe abstraite est déclarée en utilisant le mot-clé 'virtual' pour définir ses méthodes comme virtuelles et 
	en utilisant la syntaxe "= 0" pour indiquer qu'elles sont des méthodes virtuelles pures.

	une "méthode pure" fait référence à une fonction membre virtuelle déclarée dans une classe de base mais 
	non implémentée dans cette classe de base.

	Une classe abstraite doit avoir au moins une méthode pure pour être considérée comme abstraite.
	classe abstraites / classes concrètes */

class AAnimal {

protected :

	std::string _type;

public :

	AAnimal();
	AAnimal(const AAnimal & obj);

	virtual ~AAnimal();

	std::string getType() const;

	virtual void makeSound() const = 0;

	AAnimal & operator=(const AAnimal & obj);
};

#endif