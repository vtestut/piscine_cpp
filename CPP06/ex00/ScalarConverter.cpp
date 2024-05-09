#include "ScalarConverter.hpp"

/******************************************************************************/
/*									PROTOYPES								  */
/******************************************************************************/

bool tryConvertSpecial(const std::string& value, std::string& special);
static bool convertSpecial(const std::string& value, std::string* special);
bool tryConvertChar(const std::string& value, t_num& num);
static bool convertChar(const std::string& value, t_num* num);
bool tryConvertNumber(const std::string& value, t_num& num);
static bool convertNum(const std::string& value, t_num* num);
static bool parseSignAndFormat(const std::string& value, size_t& index, int& sign, bool& dotFound);
static bool parseNumeric(const std::string& value, size_t start, double& result, bool& dotFound);
static void finalizeConversion(double parsedValue, int sign, t_num* num);
static std::string formatDouble(double d);
static bool isPrintable(char c);
std::string charToString(char c);
std::string intToString(int n);

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void ScalarConverter::convert(const std::string& value) {

	std::string special;
	t_num num;

	if (tryConvertSpecial(value, special) || tryConvertChar(value, num) || tryConvertNumber(value, num))
		return;
	std::cout << RED "Impossible conversion" RESET << std::endl;
}

/******************************************************************************/
/*								UTILS										  */
/******************************************************************************/

bool tryConvertSpecial(const std::string& value, std::string& special) {
	if (convertSpecial(value, &special)) {
		std::cout << "  char: " << NON << std::endl;
		std::cout << "   int: " << NON << std::endl;
		std::cout << " float: " << special << 'f' << std::endl;
		std::cout << "double: " << special << std::endl;
		return true;
	}
	return false;
}

static bool convertSpecial(const std::string& value, std::string* special) {
	bool isSpecialDouble = value == "inf" || value == "-inf" || value == "+inf" || value == "nan";
	bool isSpecialFloat = value == "inff" || value == "-inff" || value == "+inff" || value == "nanf";
	
	if (isSpecialDouble || isSpecialFloat) {
		*special = value;
		if (isSpecialFloat) {
			(*special).resize(special->size() - 1);
		}
		return true;
	}
	return false;
}

bool tryConvertChar(const std::string& value, t_num& num) {
	if (convertChar(value, &num)) {
		std::cout << "  char: " << num.c << std::endl;
		std::cout << "   int: " << num.n << std::endl;
		std::cout << " float: " << num.f << ".0f" << std::endl;
		std::cout << "double: " << num.d << ".0" << std::endl;
		return true;
	}
	return false;
}

static bool convertChar(const std::string& value, t_num* num) {
	if (value.size() == 3 && value[0] == '\'' && isPrintable(value[1]) && value[2] == '\'') {
		num->c = value[1];
		num->n = static_cast<int>(num->c);
		num->f = static_cast<float>(num->c);
		num->d = static_cast<double>(num->c);
		return true;
	}
	return false;
}

bool tryConvertNumber(const std::string& value, t_num& num) {
	if (convertNum(value, &num)) {
		std::cout << "  char: " << (num.validChar ? charToString(num.c) : NON) << std::endl;
		std::cout << "   int: " << (num.validInt ? intToString(num.n) : NON) << std::endl;
		std::cout << " float: " << (num.validFloat ? formatDouble(num.f) + 'f' : NON) << std::endl;
		std::cout << "double: " << formatDouble(num.d) << std::endl;
		return true;
	}
	return false;
}

static bool convertNum(const std::string& value, t_num* num) {
	std::string numPart = value;
	if (numPart.size() > 1 && numPart[numPart.size() - 1] == 'f') { 
		numPart = numPart.substr(0, numPart.size() - 1);
	}
	if (numPart.empty() || numPart == "." || numPart == "-.")
		return false;

	double result = 0;
	bool dotFound = false;
	int sign = 1;
	size_t index = 0;

	while (index < numPart.length() && !isdigit(numPart[index])) {
		if (!parseSignAndFormat(numPart, index, sign, dotFound))
			return false;
	}
	if (!parseNumeric(numPart, index, result, dotFound))
		return false;
	finalizeConversion(result, sign, num);
	return true;
}

static bool parseSignAndFormat(const std::string& value, size_t& index, int& sign, bool& dotFound) {
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

static bool parseNumeric(const std::string& value, size_t start, double& result, bool& dotFound) {
	double decimalFactor = 0.1;
	for (size_t i = start; i < value.length(); i++) 
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
				result += decimalFactor * digit;
				decimalFactor *= 0.1;
			} 
			else 
				result = 10 * result + digit;
		} 
		else 
			return false;
	}
	return true;
}

static void finalizeConversion(double parsedValue, int sign, t_num* num) {
	num->d = sign * parsedValue;
	num->validInt = false;
	num->validChar = false;
	num->validFloat = false;

	if (std::isfinite(num->d)) {
		if (std::numeric_limits<int>::min() <= num->d && num->d <= std::numeric_limits<int>::max()) {
			num->n = static_cast<int>(num->d);
			num->validInt = true;
			if (num->n >= std::numeric_limits<char>::min() && num->n <= std::numeric_limits<char>::max() && isPrintable(static_cast<char>(num->n))) {
				num->c = static_cast<char>(num->n);
				num->validChar = true;
			}
		}
		if (-std::numeric_limits<float>::max() <= num->d && num->d <= std::numeric_limits<float>::max()) {
    		num->f = static_cast<float>(num->d);
    		if (std::isfinite(num->f))
        		num->validFloat = true;
		} 
	}
}

static bool isPrintable(char c) {
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

static std::string formatDouble(double d) {
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

/******************************************************************************/
/*								PRIVATE										  */
/******************************************************************************/

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter &obj) { 
  *this = obj; 
};

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &obj) {
  (void)obj;
  return *this;
};