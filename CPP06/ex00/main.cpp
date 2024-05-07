#include "ScalarConverter.hpp"

int main(int argc, char** argv) {

    if (argc == 1) {
        const std::string tests[] = {
            "42",
            "-42",
            "56",
            "3.14159",
            "3.14159f",
            "0",
            "-0",
            "nan",
            "inf",
            "+inf",
            "-inf",
            "nanf",
            "inff",
            "-inff",
            "+inff",
            "'a'",
            "' '",
            "hello",
            "1686468451514548498468465",
            "2.5e10",
            "2.5e-10",
            "-2.5e-10",
            "2147483647",
            "2147483648",
            "-2147483648",
            "-2147483649",
            "+2.5e10f"
        };
        for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
            std::cout << CYAN "Test input: " << tests[i] << RESET << std::endl;
            ScalarConverter::convert(tests[i]);
            std::cout << GREEN "----------------------------------------" RESET << std::endl;
        }
        return 0;
    } else if (argc == 2) {
		ScalarConverter::convert(argv[1]);
        return 0;
    } else {
        std::cout << "0 or 1 arg only" << std::endl;
    } return 0;
}
