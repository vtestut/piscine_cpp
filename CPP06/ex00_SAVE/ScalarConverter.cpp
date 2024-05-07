#include "ScalarConverter.hpp"

/******************************************************************************/
/*									PROTOYPES								  */
/******************************************************************************/

bool tryConvertSpecial(const std::string& input, std::string& special);
bool tryConvertChar(const std::string& input, t_num& num);
bool tryConvertNumber(const std::string& input, t_num& num);
static bool convertSpecial(const std::string& input, std::string* special);
static bool convertChar(const std::string& input, t_num* num);
static bool convertNum(const std::string& input, t_num* num);
static bool parseSignAndFormat(const std::string& input, size_t& index, int& sign, bool& dotFound);
static bool parseNumeric(const std::string& input, size_t start, double& result, bool& dotFound);
static void finalizeConversion(double parsedValue, int sign, t_num* num);
static std::string formatDouble(double d);
static bool isPrintable(char c);
std::string charToString(char c);
std::string intToString(int n);

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void ScalarConverter::convert(const std::string& input) {

	std::string special;
	t_num num;

	if (tryConvertSpecial(input, special) || tryConvertChar(input, num) || tryConvertNumber(input, num))
		return;
	std::cout << "Invalid conversion" << std::endl;
}

/******************************************************************************/
/*								UTILS										  */
/******************************************************************************/

static bool isPrintable(char c) {
	return 32 <= c && c <= 126;
}

static bool convertSpecial(const std::string& input, std::string* special) {
	bool isSpecialDouble = input == "inf" || input == "-inf" || input == "+inf" || input == "nan";
	bool isSpecialFloat = input == "inff" || input == "-inff" || input == "+inff" || input == "nanf";
	
	if (isSpecialDouble || isSpecialFloat) {
		*special = input;
		if (isSpecialFloat) {
			// Supprimer le 'f' de la fin pour la représentation interne
			(*special).resize(special->size() - 1);
		}
		return true;
	}
	return false;
}

// Convert a string that potentially holds a character literal
// ! Convertir une chaîne qui contient potentiellement un littéral de caractère
static bool convertChar(const std::string& input, t_num* num) {
	if (input.size() == 3 && input[0] == '\'' && isPrintable(input[1]) && input[2] == '\'') {
		num->c = input[1];
		num->n = static_cast<int>(num->c);
		num->f = static_cast<float>(num->c);
		num->d = static_cast<double>(num->c);
		return true;
	}
	return false;
}

// Parse the initial characters for sign and format validation
// ! Analyser les caractères initiaux pour la validation du signe et du format
static bool parseSignAndFormat(const std::string& input, size_t& index, int& sign, bool& dotFound) {
	char c = input[index];
	if (c == '+') {
		if (index != 0) return false;
	} else if (c == '-') {
		if (index == 0) sign = -1;
		else return false;
	} else if (c == '.') {
		dotFound = true;
	} else {
		return false;
	}
	index++;
	return true;
}

// Parse the numeric part of the string
// ! Analyser la partie numérique de la chaîne
static bool parseNumeric(const std::string& input, size_t start, double& result, bool& dotFound) {
	double decimalFactor = 0.1;
	for (size_t i = start; i < input.length(); i++) {
		char c = input[i];
		if (c == '.') {
			if (dotFound) return false; // ! Multiple dots not allowed
			dotFound = true;
		} else if (isdigit(c)) {
			int digit = c - '0';
			if (dotFound) {
				result += decimalFactor * digit;
				decimalFactor *= 0.1;
			} else {
				result = 10 * result + digit;
			}
		} else {
			return false;
		}
	}
	return true;
}

// Final conversion and validation
// ! Conversion finale et validation
static void finalizeConversion(double parsedValue, int sign, t_num* num) {
	num->d = sign * parsedValue;
	num->validInt = num->validChar = num->validFloat = false;

	if (std::isfinite(num->d)) {
		if (std::numeric_limits<int>::min() <= num->d && num->d <= std::numeric_limits<int>::max()) {
			num->n = static_cast<int>(num->d);
			num->validInt = true;
			if (isPrintable(num->n)) {
				num->c = static_cast<char>(num->n);
				num->validChar = true;
			}
		}
		num->f = static_cast<float>(num->d);
		if (std::isfinite(num->f)) num->validFloat = true;
	}
}

// Adjusted function to handle float notation with 'f'
// ! Fonction ajustée pour gérer la notation flottante avec 'f'
static bool convertNum(const std::string& input, t_num* num) {
	std::string numPart = input;
	// Handle float notation
	// ! Gérer la notation flottante
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
	return std::isfinite(num->d);
}

// Function to format double values into a string with trimmed trailing zeros
// ! Fonction pour formater les valeurs double en une chaîne avec des zéros finaux supprimés
static std::string formatDouble(double d) {
	std::ostringstream ss;
	ss << std::fixed << std::setprecision(999) << d;
	std::string str = ss.str();
	size_t decimalPos = str.find('.');
	if (decimalPos != std::string::npos) {
		size_t lastNonZero = str.find_last_not_of('0');
		if (lastNonZero < str.size() - 1) str.erase(lastNonZero + 1);
		if (str[decimalPos] == '.') str += '0';
	}
	return str;
}

bool tryConvertSpecial(const std::string& input, std::string& special) {
	if (convertSpecial(input, &special)) {
		std::cout << "  char: " << NO << std::endl;
		std::cout << "   int: " << NO << std::endl;
		std::cout << " float: " << special << 'f' << std::endl;
		std::cout << "double: " << special << std::endl;
		return true;
	}
	return false;
}

bool tryConvertChar(const std::string& input, t_num& num) {
	if (convertChar(input, &num)) {
		std::cout << "  char: " << num.c << std::endl;
		std::cout << "   int: " << num.n << std::endl;
		std::cout << " float: " << num.f << ".0f" << std::endl;
		std::cout << "double: " << num.d << ".0" << std::endl;
		return true;
	}
	return false;
}

std::string charToString(char c) {
	std::stringstream ss;
	ss << c;
	return ss.str();
}

std::string intToString(int n) {
	std::stringstream ss;
	ss << n;
	return ss.str();
}

bool tryConvertNumber(const std::string& input, t_num& num) {
	if (convertNum(input, &num)) {
		std::cout << "  char: " << (num.validChar ? charToString(num.c) : NO) << std::endl;
		std::cout << "   int: " << (num.validInt ? intToString(num.n) : NO) << std::endl;
		std::cout << " float: " << (num.validFloat ? formatDouble(num.f) + 'f' : NO) << std::endl;
		std::cout << "double: " << formatDouble(num.d) << std::endl;
		return true;
	}
	return false;
}
