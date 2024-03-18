#include "Dog.hpp"

/******************************************************************************/
/*								PRIVATE										  */
/******************************************************************************/


// void Dog:: () {
// }


/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/


// void Dog:: () {
// }


/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/


//	Default Constructor
Dog::Dog(void) {}

//	Parametric Constructor
Dog::Dog(int const p1) : _n(p1) {}

//	Copy constructor
Dog::Dog(Dog const & src) {
	*this = src;
}
	
//	Default Destructor
Dog::~Dog(void) {}


/******************************************************************************/
/*							GETTERS & SETTERS								  */
/******************************************************************************/


int Dog::_getValue(void) const {
	return this->_n;
}

void Dog::setValue(int const p1) {
	this->_n = p1;
}


/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/


//	Assignation Operator
Dog &   Dog::operator=(Dog const & rhs) {
	this->_n = rhs._getValue();
	return *this;
}

//	Addition Operator
Dog Dog::operator+(Dog const & rhs) const {
  return Dog( this->_n + rhs._getValue());
}

//	Stream Redirection Operator
// std::ostream &  operator<<(std::ostream & out, Dog const & rhs) {
//	out << rhs._getValue(); // passer getValue en public
//	return ( out );
//}
