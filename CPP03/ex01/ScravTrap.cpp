#include "ScravTrap.hpp"

/******************************************************************************/
/*								PRIVATE										  */
/******************************************************************************/


// void ScravTrap:: () {
// }


/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/


// void ScravTrap:: () {
// }


/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/


//	Default Constructor
ScravTrap::ScravTrap(void) {}

//	Parametric Constructor
ScravTrap::ScravTrap(int const p1) : _n(p1) {}

//	Copy constructor
ScravTrap::ScravTrap(ScravTrap const & src) {
	*this = src;
}
	
//	Default Destructor
ScravTrap::~ScravTrap(void) {}


/******************************************************************************/
/*							GETTERS & SETTERS								  */
/******************************************************************************/


int ScravTrap::_getValue(void) const {
	return this->_n;
}

void ScravTrap::setValue(int const p1) {
	this->_n = p1;
}


/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/


//	Assignation Operator
ScravTrap &   ScravTrap::operator=(ScravTrap const & rhs) {
	this->_n = rhs._getValue();
	return *this;
}

//	Addition Operator
ScravTrap ScravTrap::operator+(ScravTrap const & rhs) const {
  return ScravTrap( this->_n + rhs._getValue());
}

//	Stream Redirection Operator
// std::ostream &  operator<<(std::ostream & out, ScravTrap const & rhs) {
//	out << rhs._getValue(); // passer getValue en public
//	return ( out );
//}
