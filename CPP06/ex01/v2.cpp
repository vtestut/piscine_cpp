#pragma once

#include <cmath>
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

// Define constants for special outputs and color codes
constexpr char NO[] = "❌❌❌\n";
constexpr char RESET[] = "\033[0m";
constexpr char BOLDBLUE[] = "\033[1m\033[34m";
constexpr char GREEN[] = "\033[32m";

struct Num {
    char c{};
    bool isValidChar = false;
    int n = 0;
    bool isValidInt = false;
    float f = 0.0f;
    bool isValidFloat = false;
    double d = 0.0;
};

class ScalarConverter {
public:
    static void convert(const std::string& input);
private:
    ScalarConverter() = delete;
    ScalarConverter(const ScalarConverter& sc) = delete;
    ScalarConverter& operator=(const ScalarConverter& sc) = delete;
    ~ScalarConverter() = default;

    static bool isPrintable(char c);
    static bool convertSpecial(const std::string& input, std::string& special);
    static bool convertChar(const std::string& input, Num& num);
    static bool convertNum(const std::string& input, Num& num);
    static std::string formatDouble(double d);
};

bool ScalarConverter::isPrintable(char c) {
    return std::isprint(c);
}

bool ScalarConverter::convertSpecial(const std::string& input, std::string& special) {
    if (input == "inf" || input == "-inf" || input == "+inf" || input == "nan" ||
        input == "inff" || input == "-inff" || input == "+inff" || input == "nanf") {
        special = input.substr(0, input.size() - (input.back() == 'f' ? 1 : 0));
        return true;
    }
    return false;
}

bool ScalarConverter::convertChar(const std::string& input, Num& num) {
    if (input.size() == 3 && input[0] == '\'' && isPrintable(input[1]) && input[2] == '\'') {
        num.c = input[1];
        num.n = static_cast<int>(num.c);
        num.f = static_cast<float>(num.c);
        num.d = static_cast<double>(num.c);
        num.isValidChar = true;
        return true;
    }
    return false;
}

bool ScalarConverter::convertNum(const std::string& input, Num& num) {
    if (input.empty() || input == "." || input == ".f" || input == "-." || input == "-.f") {
        return false;
    }
    size_t i = 0;
    double decimal = 0.1;
    bool dotFound = false;

    // Handle sign
    if (input[i] == '+' || input[i] == '-') {
        num.d = (input[i++] == '-') ? -num.d : num.d;
    }

    for (; i < input.size(); ++i) {
        char c = input[i];
        if (c == '.') {
            if (dotFound) return false;
            dotFound = true;
        } else if (isdigit(c)) {
            int digit = c - '0';
            if (dotFound) {
                num.d += decimal * digit;
                decimal *= 0.1;
            } else {
                num.d = 10 * num.d + digit;
            }
        } else if (c == 'f' && i == input.size() - 1) {
            continue; // Handle 'f' at the end for float literals
        } else {
            return false;
        }
    }

    num.d *= (input[0] == '-') ? -1 : 1;

    // Determine the valid types
    num.isValidChar = num.isValidInt = num.isValidFloat = false;
    if (std::isfinite(num.d)) {
        if (num.d >= std::numeric_limits<int>::min() && num.d <= std::numeric_limits<int>::max() && std::floor(num.d) == num.d) {
            num.n = static_cast<int>(num.d);
            num.isValidInt = true;
            num.isValidChar = isPrintable(num.n);
        }
        num.f = static_cast<float>(num.d);
        num.isValidFloat = std::isfinite(num.f);
    }
    return true;
}

std::string ScalarConverter::formatDouble(double d) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(999) << d;
    std::string str = ss.str();
    size_t last = str.find_last_not_of('0');
    if (str[last] == '.') {
        ++last; // Keep the decimal point
    }
    return str.substr(0, last + 1);
}

void ScalarConverter::convert(const std::string& input) {
    std::string special;
    Num num;

    if (convertSpecial(input, special)) {
        std::cout << "  char: " << NO;
        std::cout << "   int: " << NO;
        std::cout << " float: " << special << 'f' << std::endl;
        std::cout << "double: " << special << std::endl;
    } else if (convertChar(input, num)) {
        std::cout << "  char: " << num.c << std::endl;
        std::cout << "   int: " << num.n << std::endl;
        std::cout << " float: " << num.f << ".0f" << std::endl;
        std::cout << "double: " << num.d << ".0" << std::endl;
    } else if (convertNum(input, num)) {
        std::cout << "  char: " << (num.isValidChar ? std::string(1, num.c) : NO);
        std::cout << "   int: " << (num.isValidInt ? std::to_string(num.n) : NO);
        std::cout << " float: " << (num.isValidFloat ? formatDouble(num.f) + "f" : NO);
        std::cout << "double: " << formatDouble(num.d) << std::endl;
    } else {
        std::cout << "Invalid conversion" << std::endl;
    }
}
