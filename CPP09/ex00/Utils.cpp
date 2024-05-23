#include "Utils.hpp"

// Affiche un message d'erreur sur la sortie d'erreur standard et retourne false
bool complain(const std::string& message) {
	std::cerr << "Error: " << message << std::endl;
	return false;
}

// Parse une chaîne de caractères en double et stocke le résultat dans 'out'
// Retourne true si le parsing est réussi et false en cas d'échec
bool parseDouble(const std::string& s, double& out) {
	std::istringstream iss(s);
	iss >> out;
	return iss.eof() && !iss.fail();  // Vérifie qu'on a atteint la fin du stream sans erreur
}

// Affiche un message d'erreur spécifique à un fichier et retourne false
static bool fileError(const char* path, const std::string& message) {
	std::cerr << "Error: " << path << " " << message << "." << std::endl;
	return false;
}

// Lit le contenu d'un fichier et le stocke dans un stringstream 'content'
// Retourne true si la lecture est réussie, sinon retourne false et affiche une erreur
bool readFile(const char* path, std::stringstream& content) {
	struct stat sb;
	// Vérifie si le fichier existe
	if (stat(path, &sb) != 0)
		return fileError(path, "does not exist");
	// Vérifie si le chemin correspond à un fichier régulier
	if (!S_ISREG(sb.st_mode))
		return fileError(path, "is not a regular file");
	std::ifstream ifs(path);  // Ouvre le fichier en lecture
	if (!ifs.is_open())
		return fileError(path, "could not be opened");
	content << ifs.rdbuf();  // Lit le contenu du fichier dans le stringstream
	ifs.close();  // Ferme le fichier
	// Vérifie si le fichier est vide
	if (content.tellp() == 0)
		return fileError(path, "is empty");
	return true;
}

// Trim les espaces blancs en début et fin de chaîne et retourne le résultat
std::string strtrim(const std::string& s) {
	std::string result = s;
	// Trouve la position du premier caractère non espace
	std::string::size_type pos = result.find_first_not_of(SPACES);
	if (pos == std::string::npos)  // Si tous les caractères sont des espaces, retourne la chaîne originale
		return result;
	result.erase(0, pos);  // Supprime les espaces en début de chaîne
	pos = result.find_last_not_of(SPACES);  // Trouve la position du dernier caractère non espace
	result.erase(pos + 1);  // Supprime les espaces en fin de chaîne
	return result;
}
