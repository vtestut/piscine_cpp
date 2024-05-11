#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**) // ! SUBJECT TEST
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

// #include "Array.hpp"
// ! TEST PERSO
// int main() {
// 	Array<int> empty;
// 	std::cout << empty << std::endl;

// 	Array<int> ints(ARR_INT_SIZE);
// 	std::cout << ints << std::endl;
// 	std::srand(std::time(NULL));
// 	for (int i = 0; i < ARR_INT_SIZE; ++i)
// 		ints[i] = std::rand() % 10;
// 	std::cout << ints << std::endl;

// 	try {
// 		ints[-1] = 0;
// 	} catch (const std::exception& e) {
// 		std::cerr << e.what() << std::endl;
// 	}
// 	try {
// 		ints[ARR_INT_SIZE] = 0;
// 	} catch (const std::exception& e) {
// 		std::cerr << e.what() << std::endl;
// 	}

// 	Array<std::string> s1(3);
// 	std::cout << s1 << std::endl;
// 	s1[1] = "yolowesh";
// 	std::cout << s1 << std::endl;

// 	Array<std::string> s2 = s1;
// 	s2[0] = "Le temps est l'image mobile de la realite immobile.";
// 	s2[2] = "Pierre qui roule n'amasse pas mousse.";
// 	std::cout << s1 << std::endl;
// 	std::cout << s2 << std::endl;
// }