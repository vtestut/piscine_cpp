/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:47:32 by v                 #+#    #+#             */
/*   Updated: 2024/02/25 08:22:48 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NewClass.hpp"

int main(int argc, char* argv[])
{
    if (argc < 2 || argc > 3) {
        std::cerr << "Usage: " << argv[0] << " <classe name> \"make\"\n";
        return 1;
    }

    NewClass generator;
    if (argc == 3 && std::string(argv[2]) == "make")
        generator.generateFiles(argv[1], true);
    else
        generator.generateFiles(argv[1], false);

    return 0;
}
