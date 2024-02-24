/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:41:02 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/24 18:41:03 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 3;
	
	Zombie	*laHorde = zombieHorde(N, "Patrick");
	if (!laHorde)
		return (1);
	
	for (size_t i = 0; i < (size_t)N; i++) {
		std::cout << "zombie " << i+1 << " : ";
		laHorde[i].announce();
	}
	
	delete [] laHorde;
	
	return (0);
}