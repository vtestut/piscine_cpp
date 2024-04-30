#ifndef  _SHRUBBERYCREATIONFORM_HPP
# define _SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

/******************************************************************************/
/*									CLASS									  */
/******************************************************************************/

class ShrubberyCreationForm : public AForm {

private :

    const std::string   _target;

    ShrubberyCreationForm();

public :

    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& obj);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm&  operator=(ShrubberyCreationForm& obj);

    void        execute(const Bureaucrat& executor) const;
};

#endif
