#ifndef  _SHRUBBERYCREATIONFORM_HPP
# define _SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

/******************************************************************************/
/*									CLASS									  */
/******************************************************************************/

class ShrubberyCreationForm : public AForm {

private :

    std::string   _target;

    ShrubberyCreationForm();

public :

    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& obj);
    ShrubberyCreationForm&  operator=(const ShrubberyCreationForm& obj);
    
    ~ShrubberyCreationForm();

    std::string getTarget() const;

    void        execute(const Bureaucrat& executor) const;
};

#endif
