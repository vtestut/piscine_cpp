#include "ScalarConverter.hpp"



int main() {
    // Array of test inputs
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
        "16864684515145484984684656146841664",  // Very large number
        "2.5e10",
        "2.5e-10",
        "-2.5e-10",
        "+2.5e10f"
        "2147483647",
        "2147483648",
        "-2147483648",
        "-2147483649",
    };

    // Run tests
    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        std::cout << CYAN "Test input: " << tests[i] << RESET << std::endl;
        ScalarConverter::convert(tests[i]);
        std::cout << GREEN "----------------------------------------" RESET << std::endl;
    }

    return 0;
}