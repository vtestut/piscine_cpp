#include "Base.hpp"

int main() {
    srand(time(NULL));
    Base* instances[3];

    for (int i = 0; i < 3; ++i) {
        instances[i] = generate();
        identify(instances[i]);
        identify(*instances[i]);
		std::cout << std::endl;
    }
    for (int i = 0; i < 3; ++i)
        delete instances[i];
    return 0;
}