/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 21:09:09 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/25 01:45:20 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2 || !argv[1][0]) {
		std::cout << RED << "Usage:\t ./a.harlFilter <debug> <info> <warning> <error>" << std::endl;
		return (1);
	}
	Harl Haaaaarl;
	Haaaaarl.complain(argv[1]);
	return (0);
}
