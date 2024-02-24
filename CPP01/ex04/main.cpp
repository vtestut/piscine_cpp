#include "Filestream.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

/*
Concevez un programme prenant trois paramètres dans l’ordre suivant : 
un nom de fichier et deux strings, s1 et s2.

Le fichier <filename> sera ouvert et son contenu copié dans un nouveau fichier
<filename>.replace, où chaque occurrence de s1 sera remplacée par s2.

Avoir recours aux fonctions C de manipulation de fichiers est interdit

Toutes les fonctions membres de la classe std::string sont autorisées sauf 'replace'

Bien entendu, vous devez gérer les entrées inattendues et les erreurs possibles. 
	
Créez et rendez vos propres tests afin de prouver que votre programme fonctionne.
*/

int main(int argc, char **argv) 
{
	if (argc != 4 || !argv[1][0] || !argv[2][0])
		return (1);
	return (Filestream(argv[1]).ftReplace( argv[2] , argv[3] ));
}

/*
int	main(int ac, char **av)
{
	if (ac != 4 || !av[1][0])
		{
			std::cout << "Wrong arguments" << std::endl;
			return 0;
		}
	if(!av[2][0])
		return 0;

	return File(av[1]).replace(av[2], av[3]);
}
*/

/*
int main(int argc, char** argv) {
	if (argc != 4) {
		std::cerr << "Usage: ./sed " << argv[0] << " infile s1 s2\n";
		return EXIT_FAILURE;
	}
	std::string infile(argv[1]);
	std::ifstream ifs(infile.c_str());
	if (!ifs.good()) {
		std::cerr << "Cannot read from " << infile << "\n";
		return EXIT_FAILURE;
	}
	std::string outfile = infile + ".replace";
	std::ofstream ofs(outfile.c_str());
	if (!ofs.good()) {
		std::cerr << "Cannot write to " << outfile << "\n";
		return EXIT_FAILURE;
	}
	std::stringstream buffer;
	buffer << ifs.rdbuf();
	std::string content = buffer.str();
	std::string before(argv[2]);
	std::string after(argv[3]);
	size_t i = 0;
	while (i < content.size()) {
		if (content.substr(i, before.size()) == before) {
			ofs << after;
			i += before.size();
		} else {
			ofs << content[i];
			++i;
		}
	}
}
*/
