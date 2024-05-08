#ifndef  _SCALARCONVERTER_HPP
# define _SCALARCONVERTER_HPP

# include <cmath>
# include <string>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <limits>
# include <sstream>
# include <string>
# include <cctype>

/******************************************************************************/
/*									DEFINES									  */
/******************************************************************************/

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define CYAN	"\033[36m"
# define YELLOW	"\033[93m"

# define RESET	"\033[0m"
# define CLEAR	"\033[2J\033[1;1H"

# define NO "Non displayable"

/******************************************************************************/
/*									STRUCT									  */
/******************************************************************************/

typedef struct s_num {
	char	c;
	int		n;
	float	f;
	double	d;
	bool	validChar, validInt, validFloat;
} t_num;

/******************************************************************************/
/*									CLASS									  */
/******************************************************************************/

class ScalarConverter {

private : // ! operato = & contructeur copy

	ScalarConverter();
	ScalarConverter(const ScalarConverter& obj);
	ScalarConverter& operator=(const ScalarConverter& obj);

public :

	static void convert(const std::string& input);
	~ScalarConverter() {};

};

#endif