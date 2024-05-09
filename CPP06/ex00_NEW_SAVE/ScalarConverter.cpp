#include "ScalarConverter.hpp"

/******************************************************************************/
/*									PROTOYPES								  */
/******************************************************************************/

bool tryConvertSpecial(const std::string& input, std::string& special);
static bool convertSpecial(const std::string& input, std::string* special);
bool tryConvertChar(const std::string& input, t_num& num);
static bool convertChar(const std::string& input, t_num* num);
bool tryConvertNumber(const std::string& input, t_num& num);
static bool convertNum(const std::string& input, t_num* num);
static bool parseSignAndFormat(const std::string& input, size_t& index, int& sign, bool& dotFound);
static bool parseNumeric(const std::string& input, size_t start, double& result, bool& dotFound);
static void finalizeConversion(double parsedValue, int sign, t_num* num);
static std::string formatDouble(double d);
static bool isPrintable(char c);
std::string charToString(char c);
std::string intToString(int n);

//! type scalaire ?
//! static_cast
//! promotion / narrowing/ downgrade cast
//! reinterpret_cast
//! dynamic_cast
//! intra videos
//! diff virgule fixe / flottante 
//! utility ? : Compréhension Approfondie des Types de Données & Maîtrise des Conversions et de la Formattation

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

void ScalarConverter::convert(const std::string& input) {

	std::string special; //! evite de faire un copie, permet de conserver input et modifier special
	t_num num;

	if (tryConvertSpecial(input, special) || tryConvertChar(input, num) || tryConvertNumber(input, num))
		return;
	std::cout << RED "Invalid conversion" RESET << std::endl;
}
/*T_num stockera les valeurs converties ainsi que des indicateurs de validite pour chaque type
*/

/******************************************************************************/
/*								UTILS										  */
/******************************************************************************/

bool tryConvertSpecial(const std::string& input, std::string& special) {
	if (convertSpecial(input, &special)) {
		std::cout << "  char: " << NOT << std::endl;
		std::cout << "   int: " << NOT << std::endl;
		std::cout << " float: " << special << 'f' << std::endl;
		std::cout << "double: " << special << std::endl;
		return true;
	}
	return false;
}

static bool convertSpecial(const std::string& input, std::string* special) {
	bool isSpecialDouble = input == "inf" || input == "-inf" || input == "+inf" || input == "nan";
	bool isSpecialFloat = input == "inff" || input == "-inff" || input == "+inff" || input == "nanf";
	
	if (isSpecialDouble || isSpecialFloat) {
		*special = input; // ! derefence pour manipuler la string pointer par le pointeur
		if (isSpecialFloat) {
			// Supprimer le 'f' de la fin pour la représentation interne
			(*special).resize(special->size() - 1);
		}
		return true;
	}
	return false;
}

bool tryConvertChar(const std::string& input, t_num& num) {
	if (convertChar(input, &num)) {
		std::cout << "  char: " << num.c << std::endl;
		std::cout << "   int: " << num.n << std::endl;
		std::cout << " float: " << num.f << ".0f" << std::endl;
		std::cout << "double: " << num.d << ".0" << std::endl;
		return true;
	}
	return false;
}

// ! Convertir une chaîne qui contient potentiellement un littéral de caractère
static bool convertChar(const std::string& input, t_num* num) {
	if (input.size() == 3 && input[0] == '\'' && isPrintable(input[1]) && input[2] == '\'') {
		num->c = input[1];
		num->n = static_cast<int>(num->c);
		num->f = static_cast<float>(num->c);
		num->d = static_cast<double>(num->c);
		return true;
	}
	return false;
}

bool tryConvertNumber(const std::string& input, t_num& num) {
	if (convertNum(input, &num)) {
		std::cout << "  char: " << (num.validChar ? charToString(num.c) : NOT) << std::endl;
		std::cout << "   int: " << (num.validInt ? intToString(num.n) : NOT) << std::endl;
		std::cout << " float: " << (num.validFloat ? formatDouble(num.f) + 'f' : NOT) << std::endl;
		std::cout << "double: " << formatDouble(num.d) << std::endl;
		return true;
	}
	return false;
}

// ! Fonction ajustée pour gérer la notation flottante avec 'f'
static bool convertNum(const std::string& input, t_num* num) {
	std::string numPart = input;
	// ! Gérer la notation flottante
	if (numPart.size() > 1 && numPart[numPart.size() - 1] == 'f') { 
		numPart = numPart.substr(0, numPart.size() - 1); // ! enleve le f pour préparer la chaîne pour une conversion standard en double ou int
	}

	if (numPart.empty() || numPart == "." || numPart == "-.")
		return false;

	double result = 0; // ! servira a stocker la valeur numérique convertie à partir de la chaîne.
	bool dotFound = false;
	int sign = 1; // !  Assume que le nombre est positif à moins qu'un signe négatif soit trouver
	size_t index = 0; // ! Un index pour parcourir la chaîne caractère par caractère.

	while (index < numPart.length() && !isdigit(numPart[index])) { // ! tant qu'il reste des caractères et que le caractère courant n'est PAS un chiffre.
		if (!parseSignAndFormat(numPart, index, sign, dotFound)) // ! pour chaque caractère jusqu'à ce qu'un chiffre soit rencontré
			return false;
	}
	if (!parseNumeric(numPart, index, result, dotFound)) // ! result = 0 / index = start
		return false;
	finalizeConversion(result, sign, num);
	//!return std::isfinite(num->d);
	return true;
}

// Parse the initial characters for sign and format validation
// ! Analyser les caractères initiaux pour la validation du signe et du format
static bool parseSignAndFormat(const std::string& input, size_t& index, int& sign, bool& dotFound) {
	char c = input[index];
	if (c == '+') {
		if (index != 0) return false;
	} else if (c == '-') {
		if (index == 0) sign = -1;
		else return false;
	} else if (c == '.') { // ! -.5 is valid number (=-0.5)
		dotFound = true;
	} else {
		return false;
	}
	index++;
	return true;
}

// Parse the numeric part of the string
// ! Analyser la partie numérique de la chaîne
// ! convertie la chaine en double
/*double offre une précision plus élevée que float. 
Un double utilise typiquement 64 bits de stockage, tandis qu'un float utilise 32 bits.*/
static bool parseNumeric(const std::string& input, size_t start, double& result, bool& dotFound) {
	double decimalFactor = 0.1; // ! utilisée pour correctement positionner les chiffres après le point décimal pendant la conversion de la chaîne en nombre.
	for (size_t i = start; i < input.length(); i++) 
	{ //! start = index
		char c = input[i];
		if (c == '.') 
		{
			if (dotFound) 
				return false; // ! Multiple dots not allowed
			dotFound = true;
		} 
		else if (isdigit(c)) 
		{
			int digit = c - '0'; // ! convertie le char en int
			if (dotFound) 
			{
				result += decimalFactor * digit; // ! Ajoute le chiffre à la place décimale correcte
				decimalFactor *= 0.1; // ! 0.1*0.1 = 0.01*0.1 = 0.001 
			} 
			else 
			{
				result = 10 * result + digit; /*Si aucun point décimal n'a été trouvé, chaque nouveau chiffre décale le nombre actuel d'un ordre de 
				grandeur (multiplication par 10) et ajoute le chiffre à l'unité. Cela construit progressivement le nombre de gauche à droite.*/
			}
		} 
		else 
		{
			return false;
		}
	}
	return true;
}

// Final conversion and validation
// ! Conversion finale et validation
/*utilisée pour finaliser la conversion de la valeur numérique après qu'elle a été analysée et construite à partir de la chaîne. 
Elle applique le signe correct à la valeur, vérifie la validité des conversions aux différents types de données scalaires, 
et met à jour la structure t_num avec ces valeurs et leurs validités.*/
static void finalizeConversion(double parsedValue, int sign, t_num* num) {
	num->d = sign * parsedValue; // ! applique le signe à la valeur parsée
	num->validInt = false; // ! initialise tous les indicateurs de validité à false
	num->validChar = false;
	num->validFloat = false;

	if (std::isfinite(num->d)) { // ! vérifie si la valeur double num->d est finie (ni infinie, ni NaN)  aide à identifier les valeurs numériques valides.
		if (std::numeric_limits<int>::min() <= num->d && num->d <= std::numeric_limits<int>::max()) { // ! veirifie int max / min
			num->n = static_cast<int>(num->d);
			num->validInt = true;
			//if (isPrintable(num->n)) { // ! implicite cast MODIF A VERIFIER !
			if (num->n >= std::numeric_limits<char>::min() && num->n <= std::numeric_limits<char>::max() && isPrintable(static_cast<char>(num->n))) {
				num->c = static_cast<char>(num->n);
				num->validChar = true;
			}
		}
		// num->f = static_cast<float>(num->d);
		// if (std::isfinite(num->f)) num->validFloat = true;
		if (-std::numeric_limits<float>::max() <= num->d && num->d <= std::numeric_limits<float>::max()) {
    		num->f = static_cast<float>(num->d);
    		if (std::isfinite(num->f)) {
        		num->validFloat = true;
   			}
		} 
		// else {
    	// 	// Gérer le cas où le double est en dehors de la plage de float
    	// 	num->validFloat = false;
		// }
	}
}

static bool isPrintable(char c) {
	return 32 <= c && c <= 126;
}

std::string charToString(char c) {
	// ! std::stringstream ss;
	std::ostringstream ss;
	ss << c;
	return ss.str();
}

std::string intToString(int n) {
	// ! std::stringstream ss;
	std::ostringstream ss;
	ss << n;
	return ss.str();
}

// Function to format double values into a string with trimmed trailing zeros
// ! Fonction pour formater les valeurs double en une chaîne avec des zéros finaux supprimés
static std::string formatDouble(double d) {
	std::ostringstream ss; //!  crée un flux de sortie en chaîne pour accumuler des données.
	ss << std::fixed << std::setprecision(20) << d; // !std::fixed garantit que le nombre est représenté avec des chiffres après le point décimal même si c'est un entier
	// ! std::setprecision spécifie le nombre maximum de décimales à afficher
	// ! fixed evite cette notation 1.23e+3
	std::string str = ss.str();
	size_t decimalPos = str.find('.'); // ! Si la recherche échoue à localiser le sous-chaîne ou le caractère recherché, cette methode renvoie std::string::npos
	if (decimalPos != std::string::npos) { // ! npos est une constante statique membre de std::string qui représente une position non trouvée.  elle est typiquement utilisée pour indiquer qu'une recherche dans une chaîne n'a pas réussi à trouver le sous-chaîne ou le caractère spécifié.
		// ! on rentre dans le if si on a trouver un '.'
		size_t lastNonZero = str.find_last_not_of('0'); // ! parcourt la chaîne en partant de la fin jusqu'à ce qu'elle trouve un caractère qui n'est pas un '0'
		if (lastNonZero < str.size() - 1) // ! vérifie si le dernier caractère non-zéro n'est pas le dernier caractère de la chaîne
			str.erase(lastNonZero + 1); // ! efface tout dans la chaîne à partir de l'indice juste après le dernier caractère non-zéro (+1)
		if (str[decimalPos] == '.') 
			str += '0'; // ! ajoute un 0 pour le format double
	}
	return str;
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!11
/*La fonction std::fixed en C++ est utilisée avec les flux de sortie pour contrôler le formatage des nombres à virgule flottante. 
Lorsque vous appliquez std::fixed à un flux de sortie, cela modifie la façon dont les nombres flottants sont affichés. 
Voici une explication détaillée de ce que fait std::fixed et comment il est utilisé :
Fonctionnalité de std::fixed

    Formatage à Virgule Fixe :
        Lorsque std::fixed est utilisé avec un flux de sortie, cela force le flux à utiliser une notation à virgule fixe pour 
		les nombres à virgule flottante. Cela signifie que les nombres seront toujours affichés avec un point décimal et 
		un nombre de chiffres décimaux spécifique (ou par défaut, si non spécifié autrement).

        En absence de std::fixed, le flux pourrait choisir d'utiliser une notation scientifique (e.g., 1.23e+3) 
		pour les grands ou petits nombres, ce qui n'est pas toujours désirable pour des affichages où la constance du format est préférée.

    Combinaison avec std::setprecision :
        std::fixed est souvent utilisé en combinaison avec std::setprecision, qui définit le nombre de chiffres après le point décimal à afficher.
        Par exemple, si vous configurez un flux avec std::fixed et std::setprecision(2), 
		tous les nombres à virgule flottante seront affichés avec exactement deux chiffres après la virgule, comme 123.45, 67.00, ou 0.10. 


std::ostringstream est une classe spécialisée. permet la manipulation de chaînes de caractères comme des flux de données, 
similairement aux flux d'entrée/sortie standard . permet de "écrire" des données dans une chaîne de caractères, 
qui peut ensuite être récupérée sous forme de std::string.
Permet de construire dynamiquement des chaînes de caractères en insérant divers types de données (nombres, textes, etc.) 
via des opérateurs de flux (comme <<), qui convertissent et formatent automatiquement les données en texte.
Gère automatiquement la mémoire associée à la chaîne sous-jacente
la chaîne résultante peut être extraite en utilisant la méthode str()

*/
/******************************************************************************/
/*								PRIVATE										  */
/******************************************************************************/

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter &obj) { 
  *this = obj; 
};

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &obj) {
  (void)obj;
  return *this;
};