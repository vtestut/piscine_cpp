/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:47:32 by v                 #+#    #+#             */
/*   Updated: 2024/02/25 18:14:00 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NewClass.hpp"

int printUsage(std::string argv) {
        std::cerr << "Usage: " << argv << " <classeName> +\n"
        << "c\tpour créer un cpp" << std::endl
        << "h\tpour créer un hpp" << std::endl
        << "m\tpour créer un main" << std::endl
        << "make\tpour créer un makefille" << std::endl
        << "all\tpour créer les 4 fichiers" << std::endl;
        return (1);
}

int main(int argc, char* argv[])
{
    if (argc < 2 || argc > 3)
        return (printUsage(argv[0]));
    NewClass generator;
    if ((argc == 2) && std::string(argv[1]) != "make")
        return (printUsage(argv[0]));
    if ((argc == 2 || argc == 3) && std::string(argv[1]) == "make")
        generator.generateFiles(argv[1], MAKE);
    else if (argc == 3 && std::string(argv[2]) == "c")
        generator.generateFiles(argv[1], SRC);
    else if (argc == 3 && std::string(argv[2]) == "h")
        generator.generateFiles(argv[1], HEADR);
    else if (argc == 3 && std::string(argv[2]) == "m")
        generator.generateFiles(argv[1], MAIN);
    else if (argc == 3 && std::string(argv[2]) == "all")
        generator.generateFiles(argv[1], ALL);
    return 0;
}
