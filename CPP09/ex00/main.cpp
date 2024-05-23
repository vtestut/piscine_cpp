#include "BitcoinExchange.hpp"

#define DATA_PATH "files/data.csv"

int main(int argc, char** argv) {
	// Vérifie que le nombre d'arguments est correct
	if (argc != 2) {
		// Affiche le message d'utilisation en cas d'erreur dans le nombre d'arguments
		std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
		std::cerr << "Example:" << std::endl;
		std::cerr << "date | value" << std::endl;
		std::cerr << "2011-01-03 | 2" << std::endl;
		std::cerr << "2011-01-03 | 1.2" << std::endl;
		std::cerr << "2011-01-09 | 3" << std::endl;
		return EXIT_FAILURE; // Retourne un échec
	}

	std::stringstream dataStream, inputStream; // Déclare les stringstreams pour les données et les entrées utilisateur

	// Lit le fichier de données et le fichier d'entrée utilisateur, retourne un échec en cas d'erreur
	if (!readFile(DATA_PATH, dataStream) || !readFile(argv[1], inputStream))
		return EXIT_FAILURE;

	BitcoinExchange bitcoinExchange; // Crée une instance de BitcoinExchange

	// Met à jour les données de BitcoinExchange à partir du dataStream, retourne un échec en cas d'erreur
	if (!bitcoinExchange.update(dataStream)) {
		std::cerr << "Failed to parse " << DATA_PATH << "." << std::endl;
		return EXIT_FAILURE;
	}

	std::string line;
	std::getline(inputStream, line); // Lit la première ligne du fichier d'entrée

	// Vérifie que le header du fichier d'entrée est correct
	if (line != "date | value")
		complain("invalid data header: " + line);

	// Parcourt toutes les lignes restantes du fichier d'entrée et effectue des requêtes pour chaque ligne
	while (std::getline(inputStream, line))
		bitcoinExchange.query(line);

	return EXIT_SUCCESS; // Retourne une réussite
}
