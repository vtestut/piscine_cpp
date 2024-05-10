#include "ScalarConverter.hpp"

/******************************************************************************/
/*								PRIVATE										  */
/******************************************************************************/

ScalarConverter::ScalarConverter(const ScalarConverter& obj) { 
  *this = obj; 
};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj) {
  (void)obj;
  return *this;
};

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void ScalarConverter::convert(const std::string& value) {
	std::string special;
	t_struct vals;

	if (printSpecials(value, special) || printChar(value, vals) || printNumber(value, vals))
		return;
	std::cout << RED "Impossible conversion" RESET << std::endl;
}

/******************************************************************************/
/*								UTILS										  */
/******************************************************************************/

bool printSpecials(const std::string& value, std::string& special) {
	if (trySpecialConversion(value, &special)) {
		std::cout << "  char: " << NON << std::endl;
		std::cout << "   int: " << NON << std::endl;
		std::cout << " float: " << special << 'f' << std::endl;
		std::cout << "double: " << special << std::endl;
		return true;
	}
	return false;
}

bool trySpecialConversion(const std::string& value, std::string* special) {
	bool isSpecialDouble = false;
	bool isSpecialFloat = false;

	if (value == "inf" || value == "-inf" || value == "+inf" || value == "nan")
		isSpecialDouble = true;
	if (value == "inff" || value == "-inff" || value == "+inff" || value == "nanf")
		isSpecialFloat = true;
	if (isSpecialDouble || isSpecialFloat) {
		*special = value;
		if (isSpecialFloat)
			(*special).resize(special->size() - 1);
		return true;
	}
	return false;
}

bool printChar(const std::string& value, t_struct& vals) {
	if (tryCharConversion(value, &vals)) {
		std::cout << "  char: " << vals.c << std::endl;
		std::cout << "   int: " << vals.n << std::endl;
		std::cout << " float: " << vals.f << ".0f" << std::endl;
		std::cout << "double: " << vals.d << ".0" << std::endl;
		return true;
	}
	return false;
}

bool tryCharConversion(const std::string& value, t_struct* vals) {
	if (value.size() == 3 && value[0] == '\'' && isPrintable(value[1]) && value[2] == '\'') {
		vals->c = value[1];
		vals->n = static_cast<int>(vals->c);
		vals->f = static_cast<float>(vals->c);
		vals->d = static_cast<double>(vals->c);
		return true;
	}
	return false;
}

bool printNumber(const std::string& value, t_struct& vals) {
	if (tryNumberConversion(value, &vals)) {
		std::cout << "  char: " << (vals.validChar ? charToString(vals.c) : NON) << std::endl;
		std::cout << "   int: " << (vals.validInt ? intToString(vals.n) : NON) << std::endl;
		std::cout << " float: " << (vals.validFloat ? numToString(vals.f) + 'f' : NON) << std::endl;
		std::cout << "double: " << numToString(vals.d) << std::endl;
		return true;
	}
	return false;
}

bool tryNumberConversion(const std::string& value, t_struct* vals) {
	std::string val = value;

	if (val.size() > 1 && val[val.size() - 1] == 'f')
		val = val.substr(0, val.size() - 1);
	if (val.empty() || val == "." || val == "-.")
		return false;

	double result = 0;
	bool dotFound = false;
	int sign = 1;
	size_t index = 0;

	while (index < val.length() && !isdigit(val[index])) {
		if (!parseSign(val, index, sign, dotFound))
			return false;
	}
	if (!parseAndConvert(val, index, result, dotFound))
		return false;
	doConversions(result, sign, vals);
	return true;
}

bool parseSign(const std::string& value, size_t& index, int& sign, bool& dotFound) {
	char c = value[index];

	if (c == '+') {
		if (index != 0) 
			return false;
	} 
	else if (c == '-') {
		if (index == 0) 
			sign = -1;
		else 
			return false;
	}
	else if (c == '.') {
		dotFound = true;
	}
	else
		return false;
	index++;
	return true;
}

bool parseAndConvert(const std::string& value, size_t index, double& result, bool& dotFound) {
	double decimal = 0.1;

	for (size_t i = index; i < value.length(); i++) 
	{
		char c = value[i];
		if (c == '.') {
			if (dotFound) 
				return false;
			dotFound = true;
		} 
		else if (isdigit(c)) {
			int digit = c - '0';
			if (dotFound) {
				result += decimal * digit;
				decimal *= 0.1;
			} 
			else 
				result = 10 * result + digit;
		} 
		else 
			return false;
	}
	return true;
}

void doConversions(double parsedValue, int sign, t_struct* vals) {
	vals->d = sign * parsedValue;
	vals->validInt = false;
	vals->validChar = false;
	vals->validFloat = false;

	if (std::isfinite(vals->d)) {
		if (std::numeric_limits<int>::min() <= vals->d && vals->d <= std::numeric_limits<int>::max()) {
			vals->n = static_cast<int>(vals->d);
			vals->validInt = true;
			if (vals->n >= std::numeric_limits<char>::min() && vals->n <= std::numeric_limits<char>::max() && isPrintable(static_cast<char>(vals->n))) {
				vals->c = static_cast<char>(vals->n);
				vals->validChar = true;
			}
		}
		if (-std::numeric_limits<float>::max() <= vals->d && vals->d <= std::numeric_limits<float>::max()) {
    		vals->f = static_cast<float>(vals->d);
    		if (std::isfinite(vals->f))
        		vals->validFloat = true;
		} 
	}
}

bool isPrintable(char c) {
	return 32 <= c && c <= 126;
}

std::string charToString(char c) {
	std::ostringstream ss;
	ss << c;
	return ss.str();
}

std::string intToString(int n) {
	std::ostringstream ss;
	ss << n;
	return ss.str();
}

std::string numToString(double d) {
	std::ostringstream ss;
	ss << std::fixed << std::setprecision(20) << d;

	std::string str = ss.str();
	size_t decimalPos = str.find('.');

	if (decimalPos != std::string::npos) {
		size_t lastNonZero = str.find_last_not_of('0');
		if (lastNonZero < str.size() - 1)
			str.erase(lastNonZero + 1);
		if (str[decimalPos] == '.') 
			str += '0';
	}
	return str;
}
