/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filestream.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:53:39 by vtestut           #+#    #+#             */
/*   Updated: 2024/02/24 18:53:40 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filestream.hpp"

Filestream::Filestream(const char *p1) : _name(p1) {}


int Filestream::replace(std::string s1, std::string s2) 
{	
	
	std::string		infile(this->_name);
	std::ifstream	ifs(infile.c_str());
	if (!ifs.good()) {
		std::cerr << "Can't read from " << infile << "\n";
		return (1);
	}

	std::string outfile = infile + ".replace";
	std::ofstream ofs(outfile.c_str());
	if (!ofs.good()) {
		std::cerr << "Can't write to " << outfile << "\n";
		return (1);
	}

	std::stringstream buffer;
	buffer << ifs.rdbuf();
	std::string content = buffer.str();

	size_t i = 0;
	while (i < content.size()) {
		if (content.substr(i, s1.size()) == s1) {
			ofs << s2;
			i += s1.size();
		} else
			ofs << content[i++];
	}
	return (0);
}
