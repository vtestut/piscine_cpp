#ifndef FILESTREAM_HPP
# define FILESTREAM_HPP

# include <iostream>
# include <string>
# include <fstream>

class Filestream {

	public:

		Filestream(const char *p1);

		int myReplace(std::string s1, std::string s2);

	private:

		const char *_theFileName;

};

#endif
