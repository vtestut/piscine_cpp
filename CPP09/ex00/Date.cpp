#include "Date.hpp"

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

// Vérifie si l'année est bissextile
bool Date::isLeapYear() const {
	return _year % 4 == 0 && (_year % 400 == 0 || _year % 100 != 0);
}

// Vérifie si la date est valide
bool Date::isValid() const {
	// L'année doit être après 1900 et le jour doit être positif
	if (_year < 1900 || _day <= 0)
		return false;
	// Vérifie le nombre de jours en fonction du mois
	switch (_month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return _day <= 31;
		case 4: case 6: case 9: case 11:
			return _day <= 30;
		case 2:
			return _day <= (isLeapYear() ? 29 : 28);
		default:
			return false;
	}
}

// Convertit la date en chaîne de caractères au format "YYYY-MM-DD"
std::string Date::toString() const {
	std::ostringstream os;
	os << std::setfill('0') << std::setw(4) << _year; // Ajoute l'année avec 4 chiffres
	os << '-';
	os << std::setfill('0') << std::setw(2) << _month; // Ajoute le mois avec 2 chiffres
	os << '-';
	os << std::setfill('0') << std::setw(2) << _day; // Ajoute le jour avec 2 chiffres
	return os.str();
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

// Constructeur par défaut initialisant les valeurs à zéro
Date::Date() : _year(0), _month(0), _day(0) {}

// Constructeur à partir d'une chaîne de caractères au format "YYYY-MM-DD"
Date::Date(const std::string& s) {
	// Vérifie si la chaîne est au bon format
	if (s.size() == 10 && isdigit(s[0]) && isdigit(s[1]) && isdigit(s[2]) && isdigit(s[3]) &&
		s[4] == '-' && isdigit(s[5]) && isdigit(s[6]) && s[7] == '-' && isdigit(s[8]) &&
		isdigit(s[9])) {
		// Convertit les sous-chaînes en entiers
		_year = std::atoi(s.c_str() + 0);
		_month = std::atoi(s.c_str() + 5);
		_day = std::atoi(s.c_str() + 8);
	} else {
		// Initialise à zéro si le format est incorrect
		_year = _month = _day = 0;
	}
}

// Constructeur de copie
Date::Date(const Date& other) {
	*this = other;
}

// Destructeur
Date::~Date() {}

/******************************************************************************/
/*							GETTERS & SETTERS								  */
/******************************************************************************/

int Date::getYear() const {
	return _year;
}

int Date::getMonth() const {
	return _month;
}

int Date::getDay() const {
	return _day;
}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

// Opérateur d'affectation
Date& Date::operator=(const Date& other) {
	_year = other.getYear();
	_month = other.getMonth();
	_day = other.getDay();
	return *this;
}

// Opérateur de comparaison d'égalité
bool Date::operator==(const Date& other) const {
	return _year == other.getYear() && _month == other.getMonth() && _day == other.getDay();
}

// Opérateur de comparaison de différence
bool Date::operator!=(const Date& other) const {
	return !(*this == other);
}

// Opérateur de comparaison supérieur
bool Date::operator>(const Date& other) const {
	if (_year > other.getYear())
		return true;
	if (_year < other.getYear())
		return false;
	if (_month > other.getMonth())
		return true;
	if (_month < other.getMonth())
		return false;
	return _day > other.getDay();
}

// Opérateur de comparaison supérieur ou égal
bool Date::operator>=(const Date& other) const {
	return *this > other || *this == other;
}

// Opérateur de comparaison inférieur
bool Date::operator<(const Date& other) const {
	return !(*this >= other);
}

// Opérateur de comparaison inférieur ou égal
bool Date::operator<=(const Date& other) const {
	return !(*this > other);
}

// Surcharge de l'opérateur << pour afficher une date
std::ostream& operator<<(std::ostream& os, const Date& date) {
	return os << date.toString();
}
