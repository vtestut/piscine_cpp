/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:37:44 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/24 18:53:18 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//  Les constructeurs et destructeurs n'ont pas de type de retour

/*	Initialization list
	Pour initaliser des attributs lors de la creation de l'instance,
	ajouter ' : ' apres les parametres puis preciser l'attribut a initialiser
	suivi du parametre passee au constructeur entre parenthese */
Zombie::Zombie(std::string p1) : _name(p1) {
    std::cout << this->_name << "\t: Constructed" << std::endl;
}

Zombie::~Zombie(void) {
    std::cout << this->_name << "\t: Destructed" << std::endl;
}

void Zombie::announce(void) {
    std::cout << this->_name << "\t: BraiiiiiiinnnzzzZ..." << std::endl;
    return;
}
