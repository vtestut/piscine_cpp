/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newClass.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:47:32 by v                 #+#    #+#             */
/*   Updated: 2024/02/25 03:16:32 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "newClass.hpp"

/* ************************************************************************** */
/*									PUBBLIC									  */
/* ************************************************************************** */


void NewClass::generateFiles(const std::string& headerFile, const std::string& sourceFile, const std::string& makefile) 
{
	std::string headerPath = "srcs/header";
	std::string sourcePath = "srcs/source";
	std::string makefilePath = "srcs/Makefile";

	_generateHeader(headerPath, headerFile);
	_generateSource(sourcePath, sourceFile);
	_generateMakefile(makefilePath, makefile);
}

/* ************************************************************************** */
/*									PRIVATE									  */
/* ************************************************************************** */

void NewClass::_generateHeader(const std::string& path, const std::string& filename) 
{
	std::ifstream inputFile(path);
	std::ofstream outputFile(filename + ".hpp");
	outputFile << inputFile.rdbuf();
	std::cout << "Header file generated: " << filename << ".hpp\n";
}

void NewClass::_generateSource(const std::string& path, const std::string& filename) 
{
	std::ifstream inputFile(path);
	std::ofstream outputFile(filename + ".cpp");
	outputFile << inputFile.rdbuf();
	std::cout << "Source file generated: " << filename << ".cpp\n";
}

void NewClass::_generateMakefile(const std::string& path, const std::string& filename) 
{
	std::ifstream inputFile(path);
	std::ofstream outputFile(filename);
	outputFile << inputFile.rdbuf();
	std::cout << "Makefile generated: " << filename << "\n";
}