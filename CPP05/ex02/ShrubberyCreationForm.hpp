#ifndef  _SHRUBBERYCREATIONFORM_HPP
# define _SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>
# include <cstring>

class ShrubberyCreationForm : public AForm {

private:
    const std::string   _target;

    ShrubberyCreationForm();

public:
    ShrubberyCreationForm( const std::string& target );
    ShrubberyCreationForm( const ShrubberyCreationForm& src );
    ~ShrubberyCreationForm();

    ShrubberyCreationForm&  operator=( ShrubberyCreationForm& rhs );

    void        execute( const Bureaucrat& executor ) const;

};

#endif
