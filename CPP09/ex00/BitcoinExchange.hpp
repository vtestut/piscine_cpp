#ifndef  _BITCOINEXCHANGE_HPP
# define _BITCOINEXCHANGE_HPP

// # include <iostream>
// # include <iomanip>
// # include <sstream>
// # include <string>
// # include <map>

// # include "Utils.hpp"
// # include "Date.hpp"

/******************************************************************************/
/*									DEFINES									  */
/******************************************************************************/

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define CYAN	"\033[36m"
# define YELLOW	"\033[93m"

# define RESET	"\033[0m"
# define CLEAR	"\033[2J\033[1;1H"

/******************************************************************************/
/*									CLASS									  */
/******************************************************************************/

// class BitcoinExchange {

// private :

// 	BitcoinExchange& operator=(const BitcoinExchange& other);
// 	BitcoinExchange(const BitcoinExchange& other);

// 	std::map<Date, double> _data;

// public :

// 	BitcoinExchange();
// 	~BitcoinExchange();

// 	bool update(std::stringstream& dataStream);
// 	bool query(const std::string& line) const;

// };

// #endif

// #ifndef BITCOINEXCHANGE_HPP
// #define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <sys/stat.h>
#include <iomanip>
#include "Date.hpp"

class BitcoinExchange {
private :

	BitcoinExchange& operator=(const BitcoinExchange& other);
	BitcoinExchange(const BitcoinExchange& other);

    std::map<Date, double> _data;

public :
    BitcoinExchange();
    ~BitcoinExchange();

    bool update(std::stringstream& dataStream);
    bool query(const std::string& line) const;
};

/******************************************************************************/
/*									PROTOYPES								  */
/******************************************************************************/

// Déclarations des fonctions utilitaires
bool complain(const std::string& message);
bool parseDouble(const std::string& s, double& out);
bool readFile(const char* path, std::stringstream& content);
std::string strtrim(const std::string& s);

#endif // BITCOINEXCHANGE_HPP