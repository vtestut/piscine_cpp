#include "Date.hpp"

/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/

bool Date::isLeapYear() const {
	return _year % 4 == 0 && (_year % 400 == 0 || _year % 100 != 0);
}

bool Date::isValid() const {
	if (_year < 1900 || _day <= 0)
		return false;
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

std::string Date::toString() const {
	std::ostringstream os;
	os << std::setfill('0') << std::setw(4) << _year;
	os << '-';
	os << std::setfill('0') << std::setw(2) << _month;
	os << '-';
	os << std::setfill('0') << std::setw(2) << _day;
	return os.str();
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Date::Date() : _year(0), _month(0), _day(0) {}

Date::Date(const std::string& s) {
	if (s.size() == 10 && isdigit(s[0]) && isdigit(s[1]) && isdigit(s[2]) && isdigit(s[3]) &&
		s[4] == '-' && isdigit(s[5]) && isdigit(s[6]) && s[7] == '-' && isdigit(s[8]) &&
		isdigit(s[9])) {
		_year = std::atoi(s.c_str() + 0);
		_month = std::atoi(s.c_str() + 5);
		_day = std::atoi(s.c_str() + 8);
	} 
	else
		_year = _month = _day = 0;
}

Date::Date(const Date& obj) {
	*this = obj;
}

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

Date& Date::operator=(const Date& obj) {
	_year = obj.getYear();
	_month = obj.getMonth();
	_day = obj.getDay();
	return *this;
}

bool Date::operator==(const Date& obj) const {
	return _year == obj.getYear() && _month == obj.getMonth() && _day == obj.getDay();
}

bool Date::operator!=(const Date& obj) const {
	return !(*this == obj);
}

bool Date::operator>(const Date& obj) const {
	if (_year > obj.getYear())
		return true;
	if (_year < obj.getYear())
		return false;
	if (_month > obj.getMonth())
		return true;
	if (_month < obj.getMonth())
		return false;
	return _day > obj.getDay();
}

bool Date::operator>=(const Date& obj) const {
	return *this > obj || *this == obj;
}

bool Date::operator<(const Date& obj) const {
	return !(*this >= obj);
}

bool Date::operator<=(const Date& obj) const {
	return !(*this > obj);
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
	return os << date.toString();
}
