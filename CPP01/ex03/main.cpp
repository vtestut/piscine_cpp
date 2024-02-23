#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main ()
{
	{
		Weapon club = Weapon("Boule Roc");
		HumanA bob("Racaillou", club);
		bob.attack();
		club.setType("Seisme !!!!!!!!!!!!");
		bob.attack();
	}
		std::cout << std::endl;
	{
		Weapon club = Weapon("Bulles d'O");
		HumanB jim("Magicarpe");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("Hydrocanon !!!!!!!!");
		jim.attack();
	}
	return 0;
}

/*
Dans quel cas pensez-vous plus judicieux d’utiliser un pointeur sur Weapon ? 

Il serait plus judicieux d'utiliser un pointeur sur Weapon lorsque la classe qui 
contient l'objet Weapon peut potentiellement ne pas avoir besoin d'une arme tout le temps, 
ou lorsque l'objet Weapon peut être créé dynamiquement ou détruit pendant le cycle de 
vie de l'objet parent. Par exemple, dans le cas de la classe HumanB où l'arme n'est 
pas toujours nécessaire, l'utilisation d'un pointeur sur Weapon permettrait de ne pas 
allouer de mémoire pour une arme si elle n'est pas utilisée.


Et une référence sur Weapon ? Pourquoi ? 

Il serait plus judicieux d'utiliser une référence sur Weapon lorsque l'objet parent doit 
toujours avoir une arme, et l'objet Weapon est créé une fois et ne change pas pendant le 
cycle de vie de l'objet parent. Par exemple, dans le cas de la classe HumanA où l'arme 
est obligatoire, l'utilisation d'une référence sur Weapon garantit qu'un objet Weapon valide est 
toujours associé à un objet HumanA et que l'objet Weapon ne peut pas être 
modifié ou supprimé en dehors du contrôle de HumanA.


En résumé, l'utilisation d'un pointeur sur Weapon est plus adaptée lorsque la présence 
de l'arme est facultative ou que l'objet Weapon peut être modifié ou supprimé pendant 
le cycle de vie de l'objet parent, 

tandis que l'utilisation d'une référence sur Weapon est plus adaptée lorsque l'arme est obligatoire 
et que l'objet Weapon ne change pas pendant le cycle de vie de l'objet parent.
*/