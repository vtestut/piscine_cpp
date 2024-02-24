/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:47:41 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/24 18:51:15 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/*
	l'utilisation d'une référence sur Weapon garantit qu'un objet Weapon valide 
	est toujours associé à un objet HumanA et que l'objet Weapon ne peut pas être 
	modifié ou supprimé en dehors du contrôle de HumanA. L'utilisation d'un pointeur sur Weapon est
	plus adaptée lorsque la présence de l'arme est facultative ou que l'objet Weapon peut être
	modifié ou supprimé pendant le cycle de vie de l'objet HumanB */
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
