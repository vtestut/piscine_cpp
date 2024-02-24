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
	if (argc != 4 || !argv[1][0]) {
		std::cerr << "Usage : " << argv[0] << " <file> s1 s2" << std::endl;
		return (1);
	}
	if(!argv[2][0])
		return (1);

	return (Filestream(argv[1]).ftReplace( argv[2], argv[3] ));
}


// int main(int argc, char** argv) {
// 	std::string infile(argv[1]);
// 	std::ifstream ifs(infile.c_str());
// 	if (!ifs.good()) {
// 		std::cerr << "Cannot read from " << infile << "\n";
// 		return EXIT_FAILURE;
// 	}
// 	std::string outfile = infile + ".replace";
// 	std::ofstream ofs(outfile.c_str());
// 	if (!ofs.good()) {
// 		std::cerr << "Cannot write to " << outfile << "\n";
// 		return EXIT_FAILURE;
// 	}
// 	std::stringstream buffer;
// 	buffer << ifs.rdbuf();
// 	std::string content = buffer.str();
// 	std::string before(argv[2]);
// 	std::string after(argv[3]);
// 	size_t i = 0;
// 	while (i < content.size()) {
// 		if (content.substr(i, before.size()) == before) {
// 			ofs << after;
// 			i += before.size();
// 		} else {
// 			ofs << content[i];
// 			++i;
// 		}
// 	 }
// }



/*********************************************************/



// int Filestream::ftReplace(std::string s1, std::string s2) {
// 	std::ifstream in(this->_infile);
// 	std::string   in_file_string = this->_infile;
// 	std::ofstream out;
// 	std::string   content = "";
// 	std::string   line;
// 	std::size_t   pos;

// 	if (!in.is_open())
// 	{
// 		std::cerr << "can't open file " << this->_infile << std::endl;
// 		return 1;
// 	}

// 	out.open((in_file_string + ".replace").c_str());
// 	if (!out.is_open())
// 	{
// 		in.close();
// 		std::cerr << "can't open file " << (in_file_string + ".replace").c_str() << std::endl;
// 		return 1;
// 	}

// 	while (getline (in, line))
// 		content += line + "\n";
// 	in.close();

//  	for (int i = 0; 1; )
// 	{
// 		pos = content.find(s1, i);
// 		if (pos == std::string::npos)
// 			break ;
// 		content.erase(pos, s1.length()).insert(pos, s2);
// 		i = pos + s2.length();
// 	}

// 	out << content;
// 	out.close();

// 	return 0;
// };
