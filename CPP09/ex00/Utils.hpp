#ifndef  _UTILS_HPP
# define _UTILS_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <sys/stat.h>

/******************************************************************************/
/*									DEFINES									  */
/******************************************************************************/

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define CYAN	"\033[36m"
# define YELLOW	"\033[93m"

# define RESET	"\033[0m"
# define CLEAR	"\033[2J\033[1;1H"

# define SPACES " \f\n\r\t\v"

/******************************************************************************/
/*									PROTOYPES								  */
/******************************************************************************/

bool complain(const std::string& message);
bool parseDouble(const std::string& s, double& out);
bool readFile(const char* path, std::stringstream& content);
std::string strtrim(const std::string& s);

#endif
