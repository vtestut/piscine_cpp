#include "BitcoinExchange.hpp"

/******************************************************************************/
/*                                UTILS                                       */
/******************************************************************************/

bool printError(const std::string& message) {
	std::cerr << "Error: " << message << std::endl;
	return false;
}

bool parseDouble(const std::string& s, double& out) {
	std::istringstream iss(s);
	iss >> out; // tente de lire un nombre à virgule flottante depuis le flux iss et de le stocker dans la variable out. Si la chaîne commence par un nombre valide, cette opération réussit et le nombre est stocké.
	return iss.eof() && !iss.fail();
}

bool readFile(const char* path, std::stringstream& content) {
	struct stat statBuff; // structure définie dans la bibliothèque standard <sys/stat.h>
	if (stat(path, &statBuff) != 0) // sert à récupérer les informations sur l'état d'un fichier
		return printError("does not exist");
	if (!S_ISREG(statBuff.st_mode)) // utilise le macro S_ISREG (inclu dans sys/stat) pour vérifier si le fichier est un fichier régulier. st_mode : Indique les droits d'accès du fichier ainsi que le type de fichier (par exemple, fichier régulier, répertoire, lien symbolique, etc.).
		return printError("is not a regular file");
	std::ifstream ifs(path); // ifstream (input file stream) est une classe dérivée de istream spécifiquement conçue pour la lecture de fichiers, utiliser pour la lecture de donnes a partir de fichiers, elle herite de istream ce qui permet d'utiliser toutes les opérations de lecture standard disponibles pour les flux d'entrée mais ajoute également des fonctionnalités spécifiques à la gestion de fichiers, telles que l'ouverture et la fermeture de fichiers, la vérification de l'état du fichier (ouvert, fermé, fin de fichier atteinte, etc.).
	if (!ifs.is_open())
		return printError("could not be opened");
	content << ifs.rdbuf();
	ifs.close();
	if (content.tellp() == 0) // vérifie si le fichier était vide ou plus exactement vérifie si la position actuelle du pointeur d'écriture dans le flux de sortie content est à 0, c'est-à-dire au début du flux. Si c'est le cas, cela signifie que rien n'a encore été écrit dans le flux.
		return printError("is empty");
	return true;
}

std::string strtrim(const std::string& s) {
	std::string result = s;
	std::string::size_type pos = result.find_first_not_of(SPACES); // utilisé pour stocker la position du premier et du dernier caractère dans la chaîne result qui n'est pas un espace blanc
	if (pos == std::string::npos) // npos est une constante représentant une position invalide
		return result;
	result.erase(0, pos); // supprimer tous les espaces blancs au début de la chaîne.
	pos = result.find_last_not_of(SPACES);
	result.erase(pos + 1); // supprimer tous les espaces blancs à la fin de la chaîne.
	return result;
}

// Fonction statique pour parser une ligne et extraire la date et la valeur
// Retourne true si la ligne est valide, sinon affiche un message d'erreur et retourne false
static bool parseLine(const std::string& line, Date& date, double& value, double maxValue, char separator) {
	std::string dateStr, valueStr;
	std::istringstream iss(line);

	// Lit les parties de la ligne séparées par le séparateur spécifié
	if (!std::getline(iss, dateStr, separator) || !std::getline(iss, valueStr, separator) || !iss.eof())
		return printError("invalid line: " + line);

	// Trim les espaces blancs des chaînes de date et de valeur
	dateStr = strtrim(dateStr);
	valueStr = strtrim(valueStr);

	// Convertit la chaîne dateStr en un objet Date
	date = Date(dateStr);

	if (!date.isValid())
		return printError("invalid date: " + dateStr);
	if (!parseDouble(valueStr, value))
		return printError("invalid value: " + valueStr);
	if (value < 0)
		return printError("negative value: " + valueStr);
	if (value > maxValue)
		return printError("value too large: " + valueStr);
	return true;
}

/******************************************************************************/
/*                                PUBLIC                                      */
/******************************************************************************/

// Met à jour les données de l'échange à partir d'un flux de données
// Retourne true si la mise à jour est réussie, sinon affiche un message d'erreur et retourne false
bool BitcoinExchange::update(std::stringstream& dataStream) {
	_data.clear();

	std::string line;
	std::getline(dataStream, line); // lit jusqu'au premier \n, ne l'inclut pas, et ajoute un \0
	
	if (line != "date,exchange_rate")
		return printError("invalid data header: " + line);

	while (std::getline(dataStream, line)) {
		Date date;
		double value;
		
		// Parse chaque ligne pour extraire la date et la valeur
		if (!parseLine(line, date, value, 1000000000, ','))
			return false;
		
		// Vérifie les doublons de date
		if (_data.find(date) != _data.end())
			return printError("duplicate data date: " + date.toString());
		
		// Ajoute la date et la valeur dans la map _data
		_data[date] = value;
	}

	// Vérifie si des données ont été trouvées
	return _data.empty() ? printError("no data found in file") : true;
}

// Effectue une requête sur les données de l'échange avec une ligne d'entrée
// Retourne true si la requête est réussie, sinon affiche un message d'erreur et retourne false
bool BitcoinExchange::findValue(const std::string& line) const {
	Date date;
	double value;

	// Parse la ligne pour extraire la date et la valeur
	if (!parseLine(line, date, value, 1000, '|'))
		return false;

	// Trouve l'entrée dans la map qui correspond ou est superieur ou egale a la date donnée, sinon un ptr sur end()
	std::map<Date, double>::const_iterator it = _data.lower_bound(date); // etourne un itérateur pointant vers le premier élément qui n'est pas considéré comme inférieur à la clé donnée, c'est-à-dire le premier élément dont la clé est supérieure ou égale à la clé spécifiée. Si tous les éléments dans la map ont des clés inférieures à la clé spécifiée, lower_bound retournera un itérateur vers end().

	// Si la date exacte n'est pas trouvée, utilise la date précédente
	if (it->first != date) {
		if (it == _data.begin())
			return printError("date too old " + date.toString());
		--it;
	}

	std::cout << std::fixed << std::setprecision(2);
	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	return true;
}

/******************************************************************************/
/*                      CONSTRUCTORS & DESTRUCTORS                            */
/******************************************************************************/

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) : _data(obj._data) {}

BitcoinExchange::~BitcoinExchange() {}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj) {
	if (this != &obj)
		_data = obj._data;
	return *this;
}