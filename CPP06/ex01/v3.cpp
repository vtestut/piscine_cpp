#pragma once

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

#define NO "❌❌❌\n"
#define RESET "\033[0m"
#define BOLDBLUE "\033[1m\033[34m"
#define GREEN "\033[32m"

struct NumericValue {
    char character;
    bool isValidChar;
    int integer;
    bool isValidInt;
    float floating;
    bool isValidFloat;
    double doublePrecision;
};

class ScalarConverter {
public:
    static void convert(const std::string& input);
    ~ScalarConverter() {}

private:
    ScalarConverter() {}
    ScalarConverter(const ScalarConverter& sc) {}
    ScalarConverter& operator=(const ScalarConverter& sc) {}

    static bool isPrintable(char c);
    static bool convertSpecial(const std::string& input, std::string& special);
    static bool convertChar(const std::string& input, NumericValue& numValue);
    static bool convertNum(const std::string& input, NumericValue& numValue);
    static std::string formatDouble(double value);
};

bool ScalarConverter::isPrintable(char c) {
    return 32 <= c && c <= 126;
}

bool ScalarConverter::convertSpecial(const std::string& input, std::string& special) {
    bool isSpecialDouble = input == "inf" || input == "-inf" || input == "+inf" || input == "nan";
    bool isSpecialFloat = input == "inff" || input == "-inff" || input == "+inff" || input == "nanf";

    if (isSpecialDouble || isSpecialFloat) {
        special = input;
        if (isSpecialFloat) {
            special.pop_back();
        }
        return true;
    }
    return false;
}

bool ScalarConverter::convertChar(const std::string& input, NumericValue& numValue) {
    if (input.size() == 3 && input[0] == '\'' && isPrintable(input[1]) && input[2] == '\'') {
        numValue.character = input[1];
        numValue.integer = static_cast<int>(numValue.character);
        numValue.floating = static_cast<float>(numValue.character);
        numValue.doublePrecision = static_cast<double>(numValue.character);
        return true;
    }
    return false;
}

bool ScalarConverter::convertNum(const std::string& input, NumericValue& numValue) {
    if (input == "." || input == ".f" || input == "-." || input == "-.f")
        return false;

    bool dotFound = false;
    double decimalFactor = 0.1;
    numValue.doublePrecision = 0;
    int sign = 1;

    for (size_t i = 0; i < input.size(); ++i) {
        char c = input[i];
        if (c == '.') {
            if (dotFound) return false;
            dotFound = true;
        } else if (c == '-' && i == 0) {
            sign = -1;
        } else if (c == '+' && i != 0) {
            return false;
        } else if (c == 'f' && i == input.size() - 1) {
            numValue.doublePrecision = static_cast<float>(numValue.doublePrecision);
        } else if (isdigit(c)) {
            int digit = c - '0';
            if (dotFound) {
                numValue.doublePrecision += decimalFactor * digit;
                decimalFactor *= 0.1;
            } else {
                numValue.doublePrecision = 10 * numValue.doublePrecision + digit;
            }
        } else {
            return false;
        }
    }

    numValue.doublePrecision *= sign;

    numValue.isValidFloat = numValue.isValidInt = std::isfinite(numValue.doublePrecision);
    if (numValue.isValidInt) {
        numValue.integer = static_cast<int>(numValue.doublePrecision);
        numValue.isValidChar = isPrintable(numValue.integer);
        numValue.character = static_cast<char>(numValue.integer);
    } else {
        numValue.isValidChar = numValue.isValidInt = false;
    }

    numValue.floating = static_cast<float>(numValue.doublePrecision);
    return true;
}

std::string ScalarConverter::formatDouble(double value) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(999) << value;
    std::string str = ss.str();
    size_t dotPos = str.find('.');
    if (dotPos != std::string::npos) {
        size_t lastNonZero = str.find_last_not_of('0');
        if (lastNonZero == dotPos) str += '0';
        else str.erase(lastNonZero + 1);
    }
    return str;
}

void ScalarConverter::convert(const std::string& input) {
    std::string special;
    NumericValue numValue;

    if (convertSpecial(input, special)) {
        std::cout << "  char: " << NO;
        std::cout << "   int: " << NO;
        std::cout << " float: " << special << 'f' << std::endl;
        std::cout << "double: " << special << std::endl;
    } else if (convertChar(input, numValue)) {
        std::cout << "  char: " << numValue.character << std::endl;
        std::cout << "   int: " << numValue.integer << std::endl;
        std::cout << " float: " << numValue.floating << ".0f" << std::endl;
        std::cout << "double: " << numValue.doublePrecision << ".0" << std::endl;
    } else if (convertNum(input, numValue)) {
        if (numValue.isValidChar)
            std::cout << "  char: " << numValue.character << std::endl;
        else
            std::cout << "  char: " << NO;
        if (numValue.isValidInt)
            std::cout << "   int: " << numValue.integer << std::endl;
        else
            std::cout << "   int: " << NO;
        if (numValue.isValidFloat)
            std::cout << " float: " << formatDouble(numValue.floating) << 'f' << std::endl;
        else
            std::cout << " float: " << NO;
        std::cout << "double: " << formatDouble(numValue.doublePrecision) << std::endl;
    } else {
        std::cout << "Invalid conversion" << std::endl;
    }
}
