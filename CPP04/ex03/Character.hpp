#ifndef  _CHARACTER_HPP
# define _CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

/*	Toute copie (avec le constructeur par recopie ou l’opérateur d’affectation) d’un Character 
	doit être profonde. Ainsi, lors d’une copie, les Materias du Character doivent être
	delete avant que les nouvelles ne les remplacent dans l’inventaire. Bien évidemment, les
	Materias doivent aussi être supprimées à la destruction d’un Character
*/

class Character : public ICharacter {

private :

	std::string			_name;
	static int const	_inventorySize = 4;
	AMateria *			_inventory[_inventorySize];

	void	_initializeEmptyInventory(void);
	void	_deleteInventory(void);
	
public :

	Character();
	Character(const Character & obj);
	Character(const std::string & name);

	~Character();

	std::string const &	getName() const;
	void		setName(const std::string & newName);
	
	void equip(AMateria * m);
	void unequip(int	idx);
	void use(int idx, ICharacter & target);
	void displayInventory(void) const;
	
	Character &	operator=(const Character & obj);
};

#endif