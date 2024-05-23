#include "BitcoinExchange.hpp"

/******************************************************************************/
/*                                UTILS                                       */
/******************************************************************************/

bool complain(const std::string& message) {
    std::cerr << "Error: " << message << std::endl;
    return false;
}

bool parseDouble(const std::string& s, double& out) {
    std::istringstream iss(s);
    iss >> out;
    return iss.eof() && !iss.fail();
}

bool readFile(const char* path, std::stringstream& content) {
    struct stat sb;
    if (stat(path, &sb) != 0)
        return complain("does not exist");
    if (!S_ISREG(sb.st_mode))
        return complain("is not a regular file");
    std::ifstream ifs(path);
    if (!ifs.is_open())
        return complain("could not be opened");
    content << ifs.rdbuf();
    ifs.close();
    if (content.tellp() == 0)
        return complain("is empty");
    return true;
}

std::string strtrim(const std::string& s) {
    std::string result = s;
    std::string::size_type pos = result.find_first_not_of(SPACES);
    if (pos == std::string::npos)
        return result;
    result.erase(0, pos);
    pos = result.find_last_not_of(SPACES);
    result.erase(pos + 1);
    return result;
}

/******************************************************************************/
/*                                PUBLIC                                      */
/******************************************************************************/

bool BitcoinExchange::update(std::stringstream& dataStream) {
    _data.clear();
    std::string line;
    std::getline(dataStream, line);
    if (line != "date,exchange_rate")
        return complain("invalid data header: " + line);
    while (std::getline(dataStream, line)) {
        Date date;
        double value;
        if (!parseLine(line, date, value, 1000000000, ','))
            return false;
        if (_data.find(date) != _data.end())
            return complain("duplicate data date: " + date.toString());
        _data[date] = value;
    }
    return _data.empty() ? complain("no data found in file") : true;
}

bool BitcoinExchange::query(const std::string& line) const {
    Date date;
    double value;
    if (!parseLine(line, date, value, 1000, '|'))
        return false;
    std::map<Date, double>::const_iterator it = _data.lower_bound(date);
    if (it->first != date) {
        if (it == _data.begin())
            return complain("date too old " + date.toString());
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

BitcoinExchange::~BitcoinExchange() {}


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1

// #include "BitcoinExchange.hpp"

// /******************************************************************************/
// /*								UTILS										  */
// /******************************************************************************/

// // Fonction statique pour parser une ligne et extraire la date et la valeur
// // Retourne true si la ligne est valide, sinon affiche un message d'erreur et retourne false
// static bool parseLine(const std::string& line, Date& date, double& value, double maxValue, char separator) {
// 	std::string dateStr, valueStr;
// 	std::istringstream iss(line); // Crée un stream à partir de la ligne

// 	// Lit les parties de la ligne séparées par le séparateur spécifié
// 	if (!std::getline(iss, dateStr, separator) || !std::getline(iss, valueStr, separator) || !iss.eof())
// 		return complain("invalid line: " + line);

// 	// Trim les espaces blancs des chaînes de date et de valeur
// 	dateStr = strtrim(dateStr);
// 	valueStr = strtrim(valueStr);

// 	// Convertit la chaîne dateStr en un objet Date
// 	date = Date(dateStr);

// 	// Vérifie si la date est valide
// 	if (!date.isValid())
// 		return complain("invalid date: " + dateStr);

// 	// Parse la chaîne valueStr en double
// 	if (!parseDouble(valueStr, value))
// 		return complain("invalid value: " + valueStr);

// 	// Vérifie si la valeur est négative
// 	if (value < 0)
// 		return complain("negative value: " + valueStr);

// 	// Vérifie si la valeur dépasse la valeur maximale autorisée
// 	if (value > maxValue)
// 		return complain("value too large: " + valueStr);

// 	return true; // Si toutes les vérifications sont passées, retourne true
// }

// /******************************************************************************/
// /*								PUBLIC										  */
// /******************************************************************************/

// // Met à jour les données de l'échange à partir d'un flux de données
// // Retourne true si la mise à jour est réussie, sinon affiche un message d'erreur et retourne false
// bool BitcoinExchange::update(std::stringstream& dataStream) {
// 	_data.clear(); // Vide les anciennes données

// 	std::string line;
// 	std::getline(dataStream, line); // Lit la première ligne (header)
	
// 	// Vérifie si le header est valide
// 	if (line != "date,exchange_rate")
// 		return complain("invalid data header: " + line);

// 	// Lit les lignes suivantes contenant les données
// 	while (std::getline(dataStream, line)) {
// 		Date date;
// 		double value;
		
// 		// Parse chaque ligne pour extraire la date et la valeur
// 		if (!parseLine(line, date, value, 1000000000, ','))
// 			return false;
		
// 		// Vérifie les doublons de date
// 		if (_data.find(date) != _data.end())
// 			return complain("duplicate data date: " + date.toString());
		
// 		// Ajoute la date et la valeur dans la map _data
// 		_data[date] = value;
// 	}

// 	// Vérifie si des données ont été trouvées
// 	return _data.empty() ? complain("no data found in file") : true;
// }

// // Effectue une requête sur les données de l'échange avec une ligne d'entrée
// // Retourne true si la requête est réussie, sinon affiche un message d'erreur et retourne false
// bool BitcoinExchange::query(const std::string& line) const {
// 	Date date;
// 	double value;

// 	// Parse la ligne pour extraire la date et la valeur
// 	if (!parseLine(line, date, value, 1000, '|'))
// 		return false;

// 	// Trouve l'entrée dans la map qui correspond ou est juste avant la date donnée
// 	std::map<Date, double>::const_iterator it = _data.lower_bound(date);

// 	// Si la date exacte n'est pas trouvée, utilise la date précédente
// 	if (it->first != date) {
// 		if (it == _data.begin())
// 			return complain("date too old " + date.toString());
// 		--it;
// 	}

// 	// Affiche le résultat du calcul
// 	std::cout << std::fixed << std::setprecision(2);
// 	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
// 	return true;
// }

// /******************************************************************************/
// /*						CONSTRUCTORS & DESTRUCTORS							  */
// /******************************************************************************/

// // Constructeur par défaut
// BitcoinExchange::BitcoinExchange() {}

// // Destructeur
// BitcoinExchange::~BitcoinExchange() {}
