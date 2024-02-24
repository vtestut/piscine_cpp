/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:42:08 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/24 18:42:24 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	
	Zombie* laHorde;

	if (N <= 0)
		return (NULL);
		
	/*	en declarant un array de cette facon on ne peut pas initaliser 
		d'attributs via constructeur */
	laHorde = new Zombie[N]; 
  	if (!laHorde)
		return (NULL);

	for (int i = 0; i < N; i++)
		laHorde[i].setName(name);
		
	return (laHorde);
}