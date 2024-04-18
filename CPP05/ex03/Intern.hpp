#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"

class Intern {

public:
    Intern();
    Intern( const Intern& src );
    ~Intern();

    Intern& operator=( const Intern& rhs );

    Form*   makeForm( std::string name, std::string target );
};

#endif