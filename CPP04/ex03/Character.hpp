#ifndef  _CHARACTER_HPP
# define _CHARACTER_HPP

# include "AMateria.hpp"
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

/*Toute copie (avec le constructeur par recopie ou l’opérateur d’affectation) d’un Charac-
ter doit être profonde. Ainsi, lors d’une copie, les Materias du Character doivent être
delete avant que les nouvelles ne les remplacent dans l’inventaire. Bien évidemment, les
Materias doivent aussi être supprimées à la destruction d’un Character*/

class Character : public ICharacter {

private :

	std::string			_name;
	static int const	_inventorySize = 4;
	AMateria *			_inventory[_inventorySize];

	void	_initializeEmptyInventory(void);
	void	_deleteInventory(void);
	
public :

	Character(void);
	Character(Character const & src);
	Character(std::string const & name);
	~Character(void);
	Character &	operator=(Character const & src);

	std::string const &	getName(void) const;
	void				setName(std::string const & newName);
	
	void equip(AMateria * m);
	void unequip(int	idx);
	void use(int idx, ICharacter & target);
	void displayInventory(void) const;
};

#endif