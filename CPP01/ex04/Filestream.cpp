#include "Filestream.hpp"

Filestream::Filestream(const char *p1) : _name(p1) {}


int Filestream::ftReplace(std::string s1, std::string s2) 
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

	// std::ifstream in(this->in_file);
	// std::string   in_file_string = this->in_file;
	// std::ofstream out;
	// std::string   content = "";
	// std::string   line;
	// std::size_t   pos;

	// if (!in.is_open())
	// {
	// 	std::cerr << "can't open file " << this->in_file << std::endl;
	// 	return 1;
	// }

	// out.open((in_file_string + ".replace").c_str());
	// if (!out.is_open())
	// {
	// 	in.close();
	// 	std::cerr << "can't open file " << (in_file_string + ".replace").c_str() << std::endl;
	// 	return 1;
	// }

	// while (getline (in, line))
	// 	content += line + "\n";
	// in.close();

 	// for (int i = 0; 1; )
	// {
	// 	pos = content.find(s1, i);
	// 	if (pos == std::string::npos)
	// 		break ;
	// 	content.erase(pos, s1.length()).insert(pos, s2);
	// 	i = pos + s2.length();
	// }

	// out << content;
	// out.close();

	// return 0;

