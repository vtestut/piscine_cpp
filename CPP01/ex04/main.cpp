#include "Filestream.hpp"

int main(int argc, char **argv) 
{
	if (argc != 4 || !argv[1][0] || !argv[2][0]) {
		std::cout << "usage: ./a.filstream <infile> s1 s2" << std::endl;
		return (1);
	}
	return (Filestream(argv[1]).replace( argv[2] , argv[3] ));
}
