#include "ScalarConverter.hpp"

int main(int argc, char** argv) {

    if (argc == 1) {
        const std::string tests[] = {
            "0",
            "nan",
            "42.0f",
            "'*'",
            "-42",
            "56",
            "3.14159",
            "3.14159f",
            "-0",
            "inf",
            "+inf",
            "-inf",
            "nanf",
            "inff",
            "-inff",
            "+inff",
            "'a'",
            "'2'",
            "' '",
            "coucou",
            "-.578176",
            "1686468451514548498468465",
            "2147483647",
            "2147483648",
            "-2147483648",
            "-2147483649"
        };
        for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
            std::cout << YELLOW "Valeur = " << tests[i] << RESET << std::endl;
            ScalarConverter::convert(tests[i]);
            std::cout << GREEN "----------------------------------------" RESET << std::endl;
        }
        return 0;
    } 
    else if (argc == 2) {
		ScalarConverter::convert(argv[1]);
        return 0;
    } 
    else
        std::cout << "0 or 1 arg only" << std::endl;
    return 0;
}
