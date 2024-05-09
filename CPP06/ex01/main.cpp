#include "Serializer.hpp"

int main() {
	Data* data = new Data();
	data->str = "THX";
	data->n = 1138;

	uintptr_t serializedPtr = Serializer::serialize(data);
	
	Data* deserializedPtr = Serializer::deserialize(serializedPtr);

	std::cout << YELLOW "Adresse de Data = " RESET << data << std::endl;
	std::cout << YELLOW "Valeur de serializedPtr = " RESET << serializedPtr << std::endl;
	std::cout << YELLOW "Adresse de deserializedPtr = " RESET << deserializedPtr << std::endl;
	std::cout << YELLOW "Valeur de n & str de deserializedPtr = " RESET << deserializedPtr->str << deserializedPtr->n << std::endl;

	delete data;

	return 0;
}

