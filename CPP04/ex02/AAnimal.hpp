#ifndef  _AANIMAL_HPP
# define _AANIMAL_HPP

# include <iostream>
# include <stdexcept>
# include <string>

# include "Brain.hpp"

/*	une "méthode pure" fait référence à une fonction membre virtuelle déclarée dans une classe de base mais non implémentée dans cette classe de base
	Une classe abstraite doit avoir au moins une méthode pure pour être considérée comme telle
	Si une classe contient au moins une méthode pure, elle est une classe abstraite et ne peut pas être instanciée directement.*/

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

