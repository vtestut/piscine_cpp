#ifndef FILESTREAM_HPP
# define FILESTREAM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>

class Filestream {

	public:

		Filestream(const char *p1);

		int ftReplace(std::string s1, std::string s2);

	private:

		const char *_name;

};

#endif
