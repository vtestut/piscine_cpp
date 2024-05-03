#ifndef  _SCALARCONVERTER_HPP
# define _SCALARCONVERTER_HPP

# include <cmath>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <limits>
# include <sstream>
# include <string>
# include <vector>

/******************************************************************************/
/*									DEFINES									  */
/******************************************************************************/

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define CYAN	"\033[36m"
# define YELLOW	"\033[93m"

# define RESET	"\033[0m"
# define CLEAR	"\033[2J\033[1;1H"

# define NO "!!! NO !!!\n"

/******************************************************************************/
/*									STRUCT									  */
/******************************************************************************/

typedef struct s_num {
	char	c;
	bool	isValidChar;
	int		n;
	bool	isValidInt;
	double	d;
	bool	isValidDouble;
	float	f;
	bool	isValidFloat;
} t_num;

/******************************************************************************/
/*									CLASS									  */
/******************************************************************************/

class ScalarConverter {

private :

	ScalarConverter();
	ScalarConverter(const ScalarConverter& obj);
	ScalarConverter& operator=(const ScalarConverter& obj);

public :

	~ScalarConverter();

	static void convert(const std::string& input);
};

#endif