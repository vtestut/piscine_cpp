/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:47:32 by v                 #+#    #+#             */
/*   Updated: 2024/02/25 03:47:50 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "newClass.hpp"

/*
Dans ce code, j'ai utilisé la bibliothèque <filesystem> pour manipuler les chemins de fichiers de manière portable.
Le programme construit les chemins complets vers les fichiers "header", "source" et "Makefile" en ajoutant le préfixe "srcs/". 
Ensuite, il les utilise comme arguments pour les fonctions de génération de fichiers.
*/


int main(int argc, char* argv[]) 
{
    if (argc != 4) 
	{
        std::cerr << "Usage: " << argv[0] << " <header_filename> <source_filename> <makefile_filename>\n";
        return 1;
    }

    NewClass generator;
    generator.generateFiles(argv[1], argv[2], argv[3]);

    return 0;
}
