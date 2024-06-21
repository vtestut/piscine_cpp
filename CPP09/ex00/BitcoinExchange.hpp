#ifndef  _BITCOINEXCHANGE_HPP
# define _BITCOINEXCHANGE_HPP

# include <sys/stat.h>
# include <iostream>
# include <fstream>
# include <sstream>
# include <iomanip>
# include <string>
# include <map>

# include "Date.hpp"

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
/*									CLASS									  */
/******************************************************************************/

class BitcoinExchange {

	private :

	std::map<Date, double> _data;

	BitcoinExchange(const BitcoinExchange & obj);
	BitcoinExchange& operator=(const BitcoinExchange & obj);

	public :

	BitcoinExchange();
	
	~BitcoinExchange();

	bool update(std::stringstream & dataStream);
	bool findValue(const std::string & line) const;
};

/******************************************************************************/
/*									PROTOYPES								  */
/******************************************************************************/

bool printError(const std::string & message);
bool parseDouble(const std::string & s, double& out);
bool readFile(const char * path, std::stringstream & content);
std::string strtrim(const std::string & s);

#endif