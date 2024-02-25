/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:44:45 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/24 23:59:58 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/*
	Une référence est un pointeur constant et toujours déréférencé qui est 
	initialisé à sa déclaration. (Jamais NULL)	*/
int main() {

	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << std::endl;
	std::cout << "L'adresse de 'str' en memoire\t  est (&str)\t   : " << &str << std::endl;
	std::cout << "L'adresse stockee dans stringPTR  est (stringPTR)  : " << stringPTR << std::endl;
	std::cout << "L'adresse stockee dans stringREF  est (&stringREF) : " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "La valeur de str\t\t  est (str)\t   : " << str << std::endl;
	std::cout << "La valeur pointee par stringSTR\t  est (*stringSTR) : " << *stringPTR << std::endl;
	std::cout << "La valeur pointee para stringREF  est (stringREF)  : " << stringREF << std::endl;
	std::cout << std::endl;

	return (0);
}