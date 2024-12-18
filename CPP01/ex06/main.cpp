/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 21:09:09 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/26 15:10:45 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2 || !argv[1][0]) {
		std::cout << RED << "Usage:\t ./a.harlFilter <debug> <info> <warning> <error>" << RESET << std::endl;
		return (1);
	}
	Harl Haaaaarl;
	Haaaaarl.complain(argv[1]);
	return (0);
}
