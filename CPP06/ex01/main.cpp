#include "Serializer.hpp"
#include <iostream>

void test1() {
	std::cout << YELLOW "test 1 : " RESET << std::endl;
	Data originalData;
    originalData.n = 42;
    originalData.str = "Example";

    // Test de la sérialisation
    uintptr_t serialized = Serializer::serialize(&originalData);
    std::cout << "Serialized value: " << serialized << std::endl;

    // Test de la désérialisation
    Data* deserializedData = Serializer::deserialize(serialized);
    std::cout << "Deserialized Data content -> n: " << deserializedData->n << ", str: " << deserializedData->str << std::endl;

    // Comparaison des adresses pour vérifier si elles sont identiques
    if (&originalData == deserializedData) {
        std::cout << GREEN "Test Success: The deserialized object is the same as the original object." RESET << std::endl;
    } else {
        std::cout << RED "Test Failure: The deserialized object is not the same as the original object." RESET << std::endl;
    }
	std::cout << std::endl;
}

void test2() {
	std::cout << YELLOW "test 2 : " RESET << std::endl;
	Data* data1 = new Data;
	data1->n = 42;
	data1->str = "test 1 2 1 2 test test";
	Data* data2 = Serializer::deserialize(Serializer::serialize(data1));
	std::cout << data2->n << std::endl;
	std::cout << data2->str << std::endl;
	std::cout << Serializer::serialize(Serializer::deserialize(42)) << std::endl;
	std::cout << std::endl;
	delete data1;
}

int main() {
	test1();
	test2();
    return 0;
}
