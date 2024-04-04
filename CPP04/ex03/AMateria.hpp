#ifndef  _AMATERIA_HPP
# define _AMATERIA_HPP

# include "ICharacter.hpp"
# include <string>

/******************************************************************************/
/*									DEFINES									  */
/******************************************************************************/

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define CYAN	"\033[36m"
# define YELLOW	"\033[93m"

# define RESET	"\033[0m"
# define CLEAR	"\033[2J\033[1;1H"

/******************************************************************************/
/*									CLASS									  */
/******************************************************************************/

/*	Une classe abstraite est une classe qui ne peut pas être instanciée directement. 
	Elle sert de modèle à d'autres classes dérivées en définissant des méthodes virtuelles pures, 
	c'est-à-dire des méthodes qui n'ont pas de définition dans la classe abstraite elle-même et 
	qui doivent être implémentées par les classes dérivées.

	Une classe abstraite est déclarée en utilisant le mot-clé 'virtual' pour définir ses méthodes comme virtuelles et 
	en utilisant la syntaxe "= 0" pour indiquer qu'elles sont des méthodes virtuelles pures.

	Une "méthode pure" fait référence à une fonction membre virtuelle déclarée dans une classe de base mais 
	non implémentée dans cette classe de base.

	Une classe abstraite doit avoir au moins une méthode pure pour être considérée comme abstraite. 
*/

class ICharacter;

class AMateria {

protected :
	
	std::string	_type;
	
public :

	AMateria();
	AMateria(const AMateria & src);
	AMateria(const std::string & type);

	virtual ~AMateria();

	// std::string const & getType(void) const;
	std::string getType() const;
	
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter & target);

	AMateria &	operator=(AMateria const & src);
};

#endif