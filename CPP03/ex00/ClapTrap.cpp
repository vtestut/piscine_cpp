#include "ClapTrap.hpp"


/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/


void ClapTrap::attack(const std::string & target) {
	// cause the target to lose damage
	// need 1 nrj
	if (_nrj <= 0) {
		std::cout << "No energy points" << std::endl;
		return;
	} else 

}

void ClapTrap::takeDamage(int amount) {
	// take n damage 
}

void ClapTrap::beRepaired(int amount) {
	// win n hit
	// need 1 nrj
}


/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

ClapTrap::ClapTrap(void) {std::cout << "Default constructor called" << std::endl;}
ClapTrap::ClapTrap(std::string name_) : _name(name_) {std::cout << "ClapTrap constructor called with name " << this->_name << std::endl;}
ClapTrap::ClapTrap(ClapTrap const & src) {std::cout << "Copy constructor called" << std::endl; *this = src;}
ClapTrap::~ClapTrap(void) {std::cout << RED << "Destructor called" << RESET << std::endl;}

/******************************************************************************/
/*							GETTERS	& SETTERS								  */
/******************************************************************************/


int ClapTrap::_getHitPoints(void) const {return this->_hit;}
int ClapTrap::_getEnergyPoints(void) const {return this->_nrj;}
int ClapTrap::_getAttackPoints(void) const {return this->_atk;}
std::string ClapTrap::_getName(void) const {return this->_name;}

// void ClapTrap::setHitPoints(int const hit_) {this->_hit = hit_;}
// void ClapTrap::setEnergyPoints(int const nrj_) {this->_nrj = nrj_;}
// void ClapTrap::setAttackPoints(int const atk_) {this->_atk = atk_;}
// std::string ClapTrap::setName(std::string name_) {this->_name = name_;}


/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/


//	Assignation Operator
ClapTrap& ClapTrap::operator= (const ClapTrap & rhs) {
  std::cout << "ClapTrap " << std::setw(12) << std::left << rhs._name << " assignment operator" << std::endl;
  if (this != &rhs) {
    this->_name = rhs._name;
    this->_hit = rhs._hit;
    this->_nrj = rhs._nrj;
    this->_atk = rhs._atk;
  }
  return (*this);
};
