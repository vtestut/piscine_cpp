#ifndef  _SCALARCONVERTER_HPP
# define _SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <string> 
# include <cmath>
# include <cctype>
# include <limits>

/******************************************************************************/
/*									DEFINES									  */
/******************************************************************************/

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define CYAN	"\033[36m"
# define YELLOW	"\033[93m"

# define RESET	"\033[0m"
# define CLEAR	"\033[2J\033[1;1H"

# define NON RED "Non displayable" RESET

/******************************************************************************/
/*									STRUCT									  */
/******************************************************************************/

typedef struct s_num {
	char	c;
	int		n;
	float	f;
	double	d;
	bool	validChar, validInt, validFloat;
} t_struct;

/******************************************************************************/
/*									CLASS									  */
/******************************************************************************/

class ScalarConverter {

private :

	ScalarConverter();
	ScalarConverter(const ScalarConverter& obj);
	ScalarConverter& operator=(const ScalarConverter& obj);

public :

	static void convert(const std::string& value);
	~ScalarConverter() {};
};

/******************************************************************************/
/*									PROTOYPES								  */
/******************************************************************************/

bool printSpecials(const std::string& value, std::string& special);
bool trySpecialConversion(const std::string& value, std::string* special);
bool printChar(const std::string& value, t_struct& vals);
bool tryCharConversion(const std::string& value, t_struct* vals);
bool printNumber(const std::string& value, t_struct& vals);
bool tryNumberConversion(const std::string& value, t_struct* vals);
bool parseSign(const std::string& value, size_t& index, int& sign, bool& dotFound);
bool parseAndConvert(const std::string& value, size_t index, double& result, bool& dotFound);
void doConversions(double parsedValue, int sign, t_struct* vals);
bool isPrintable(char c);
std::string charToString(char c);
std::string intToString(int n);
std::string numToString(double d);

#endif
