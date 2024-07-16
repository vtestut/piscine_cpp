#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		// std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
		// std::cerr << "date | value" << std::endl;
		// std::cerr << "2020-10-04 | 30" << std::endl;
		return 1;
	}

	std::stringstream dataStream;
	std::stringstream inputStream;
	if (!readFile("files/data.csv", dataStream) || !readFile(argv[1], inputStream))
		return 1;

	BitcoinExchange bitcoinExchange;
	if (!bitcoinExchange.update(dataStream)) {
		std::cerr << "Failed to parse " << "files/data.csv." << std::endl;
		return 1;
	}

	std::string line;
	std::getline(inputStream, line);
	if (line != "date | value")
		printError("invalid data header: " + line);

	while (std::getline(inputStream, line))
		bitcoinExchange.findValue(line);
	return 0;
}
