#pragma once

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>


# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define CYAN	"\033[36m"
# define YELLOW	"\033[93m"

# define RESET	"\033[0m"
# define CLEAR	"\033[2J\033[1;1H"

# define NO "Non displayable\n"

typedef struct s_num {
	char c;
	bool isValidChar;
	int n;
	bool isValidInt;
	float f;
	bool isValidFloat;
	double d;
} t_num;

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& sc);
	ScalarConverter& operator=(const ScalarConverter& sc);

public:
	static void convert(const std::string& input);
	~ScalarConverter();
};