#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

void test2() 
{
    // Test: Construction d'un tableau vide
    Array<int> emptyArray;
    std::cout << GREEN << "Test: Construct empty array -> Passed, size: " << emptyArray.size() << RESET << std::endl;

    // Test: Construction avec taille spécifique
    Array<int> sizedArray(5);
    std::cout << GREEN << "Test: Construct array of specific size -> Passed, size: " << sizedArray.size() << RESET << std::endl;

    // Test: Accès en lecture et écriture
    try {
        sizedArray[0] = 10;
        std::cout << GREEN << "Test: Write access using [] -> Passed, first element: " << sizedArray[0] << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "Test: Write access using [] -> Failed, " << e.what() << RESET << std::endl;
    }

    // Test: Accès hors limite
    try {
        sizedArray[10] = 100;  // Intentionally out of range
    } catch (const std::out_of_range& e) {
        std::cout << GREEN << "Test: Out of range access -> Passed, caught: " << e.what() << RESET << std::endl;
    } catch (...) {
        std::cout << RED << "Test: Out of range access -> Failed" << RESET << std::endl;
    }

    // Test: Copie et indépendance de la copie
    Array<int> copyArray = sizedArray;
    copyArray[0] = 20;
    if (sizedArray[0] != copyArray[0]) {
        std::cout << GREEN << "Test: Copy independence -> Passed, original: " << sizedArray[0] << ", copy: " << copyArray[0] << RESET << std::endl;
    } else {
        std::cout << RED << "Test: Copy independence -> Failed, original and copy are the same" << RESET << std::endl;
    }

    // Test: Opérateur d'assignation et indépendance
    Array<int> assignedArray;
    assignedArray = sizedArray;
    assignedArray[0] = 30;
    if (sizedArray[0] != assignedArray[0]) {
        std::cout << GREEN << "Test: Assignment independence -> Passed, original: " << sizedArray[0] << ", assigned: " << assignedArray[0] << RESET << std::endl;
    } else {
        std::cout << RED << "Test: Assignment independence -> Failed, original and assigned are the same" << RESET << std::endl;
    }

    // Test: Affichage d'un tableau
    std::cout << CYAN << "Displaying array content: " << sizedArray << RESET << std::endl;

    // Fin des tests
    std::cout << YELLOW << "All tests completed." << RESET << std::endl;
}

int main(int, char**)
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

    test2();
    return 0;
}