/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:47:32 by v                 #+#    #+#             */
/*   Updated: 2024/02/25 04:26:25 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NewClass.hpp"

int main(int argc, char* argv[])
{
    if (argc < 3 || argc > 4) {
        std::cerr << "Usage: " << argv[0] << " <header_filename> <source_filename> [make]\n";
        return 1;
    }

    NewClass generator;
    if (argc == 4 && std::string(argv[3]) == "make")
        generator.generateFiles(argv[1], argv[2], true);
    else
        generator.generateFiles(argv[1], argv[2], false);

    return 0;
}

/*
Dans ce code, j'ai utilisé la bibliothèque <filesystem> pour manipuler les chemins de fichiers de manière portable.
Le programme construit les chemins complets vers les fichiers "header", "source" et "Makefile" en ajoutant le préfixe "srcs/". 
Ensuite, il les utilise comme arguments pour les fonctions de génération de fichiers.
*/