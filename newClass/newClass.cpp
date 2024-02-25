/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newClass.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:47:32 by v                 #+#    #+#             */
/*   Updated: 2024/02/25 04:35:51 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NewClass.hpp"

/* ************************************************************************** */
/*									PUBBLIC									  */
/* ************************************************************************** */


void NewClass::generateFiles(const std::string& headerFile, const std::string& sourceFile, bool do_makefile) {
	std::string headerPath = "srcs/header";
	std::string sourcePath = "srcs/source";
	std::string makefilePath = "srcs/Makefile";

	_generateHeader(headerPath, headerFile);
	_generateSource(sourcePath, sourceFile);
	
    if (!std::filesystem::exists("CLASS")) {
        if (!std::filesystem::create_directory("CLASS")) {
            std::cerr << "Error: Unable to create directory 'CLASS'\n";
            return;
        }
    }

    if (!std::filesystem::exists(headerPath)) {
        std::cerr << "Error: Header directory '" << headerPath << "' does not exist\n";
        return;
    }

    if (!std::filesystem::exists(sourcePath)) {
        std::cerr << "Error: Source directory '" << sourcePath << "' does not exist\n";
        return;
    }

	if (do_makefile == true)
		_generateMakefile(makefilePath);
}


/* ************************************************************************** */
/*									PRIVATE									  */
/* ************************************************************************** */


void NewClass::_generateHeader(const std::string& path, const std::string& filename) {
	std::ifstream inputFile(path);
	std::ofstream outputFile("CLASS/" + filename + ".hpp");
	outputFile << inputFile.rdbuf();
	std::cout << "Header file generated: " << filename << ".hpp" << std::endl;
}

void NewClass::_generateSource(const std::string& path, const std::string& filename) {
	std::ifstream inputFile(path);
	std::ofstream outputFile("CLASS/" + filename + ".cpp");
	outputFile << inputFile.rdbuf();
	std::cout << "Source file generated: " << filename << ".cpp" << std::endl;
}

void NewClass::_generateMakefile(const std::string& path) {
	std::ifstream inputFile(path);
	std::ofstream outputFile("CLASS/Makefile");
	outputFile << inputFile.rdbuf();
	std::cout << "Makefile generated" << std::endl;
}
