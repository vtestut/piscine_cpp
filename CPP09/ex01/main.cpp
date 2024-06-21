#include "RPN.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << RED "Error: wrong usage : " 
                  << YELLOW << "./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" RESET << std::endl;
        return 1;
    }

    try {
        RPN rpn(argv[1]);
        rpn.run();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}