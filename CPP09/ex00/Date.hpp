#ifndef  _DATE_HPP
# define _DATE_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include <cstdlib>

/******************************************************************************/
/*									DEFINES									  */
/******************************************************************************/

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define CYAN	"\033[36m"
# define YELLOW	"\033[93m"

# define RESET	"\033[0m"
# define CLEAR	"\033[2J\033[1;1H"

/******************************************************************************/
/*									CLASS									  */
/******************************************************************************/

class Date {

private :

	int _year;
	int _month;
	int _day;

public :

	Date();
	explicit Date(const std::string& s);
	Date& operator=(const Date& other);
	Date(const Date& other);
	~Date();

	bool operator==(const Date& other) const;
	bool operator!=(const Date& other) const;
	bool operator>(const Date& other) const;
	bool operator>=(const Date& other) const;
	bool operator<(const Date& other) const;
	bool operator<=(const Date& other) const;

	int getYear() const;
	int getMonth() const;
	int getDay() const;

	bool isLeapYear() const; // Vérifie si l'année est bissextile
	bool isValid() const;

	std::string toString() const;

};

/******************************************************************************/
/*									PROTOYPES								  */
/******************************************************************************/

std::ostream& operator<<(std::ostream& os, const Date& date);

#endif
