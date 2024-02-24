#include "Filestream.hpp"

Filestream::Filestream(const char *p1) : _infile(p1) {}

int Filestream::ftReplace(std::string s1, std::string s2) {
	std::string		str_infile(this->_infile);
	std::ifstream	ifs(str_infile.c_str());
	if (!ifs.good()) {
		std::cerr << "Cannot read from " << str_infile << std::endl;
		return (EXIT_FAILURE);
	} if (ifs) {
		std::string tmp;
		while (std::getline(ifs, tmp)) 
			std::cout << tmp << std::endl;
	} else {
		std::cout << "Unable to open file" << std::endl;
	}
	std::cout << s1 << s2;

	return (EXIT_SUCCESS);
}
