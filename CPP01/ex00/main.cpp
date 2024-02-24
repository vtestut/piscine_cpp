/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:37:32 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/24 18:37:33 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) 
{
    Zombie Foo("Foo");
    Foo.announce();
    Foo.announce();
    Foo.announce();

    std::cout << std::endl;

    Zombie* zombie_ptr = newZombie("PTR");
    zombie_ptr->announce();
    zombie_ptr->announce();

    std::cout << std::endl;

    randomChump("CHUMP");

    std::cout << std::endl;

    delete zombie_ptr;
    return (0);
}