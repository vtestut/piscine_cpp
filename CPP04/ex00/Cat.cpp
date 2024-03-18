#include "Cat.hpp"

/******************************************************************************/
/*								PRIVATE										  */
/******************************************************************************/


// void Cat:: () {
// }


/******************************************************************************/
/*								PUBLIC										  */
/******************************************************************************/


// void Cat:: () {
// }


/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/


//	Default Constructor
Cat::Cat(void) {}

//	Parametric Constructor
Cat::Cat(int const p1) : _n(p1) {}

//	Copy constructor
Cat::Cat(Cat const & src) {
	*this = src;
}
	
//	Default Destructor
Cat::~Cat(void) {}


/******************************************************************************/
/*							GETTERS & SETTERS								  */
/******************************************************************************/


int Cat::_getValue(void) const {
	return this->_n;
}

void Cat::setValue(int const p1) {
	this->_n = p1;
}


/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/


//	Assignation Operator
Cat &   Cat::operator=(Cat const & rhs) {
	this->_n = rhs._getValue();
	return *this;
}

//	Addition Operator
Cat Cat::operator+(Cat const & rhs) const {
  return Cat( this->_n + rhs._getValue());
}

//	Stream Redirection Operator
// std::ostream &  operator<<(std::ostream & out, Cat const & rhs) {
//	out << rhs._getValue(); // passer getValue en public
//	return ( out );
//}
