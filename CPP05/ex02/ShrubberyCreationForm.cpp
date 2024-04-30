#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

/******************************************************************************/
/*							PUBLIC											  */
/******************************************************************************/

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!this->getStatus())
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getExecGrade()) {
        throw AForm::GradeTooLowException();
    } else {
        // Correctly convert std::string to const char* before opening the file
        std::string filename = this->getName() + "_shrubbery";
        std::ofstream file(filename.c_str());
        if (!file) {
            throw std::runtime_error("Failed to create file");
        }
        file << "                      ___" << std::endl;
        file << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
        file << "             ,-'          __,,-- \\" << std::endl;
        file << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
        file << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
        file << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
        file << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
        file << "     (     ,-'                  `." << std::endl;
        file << "      `._,'     _   _             ;" << std::endl;
        file << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
        file << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
        file << "        `--\'   \"Hb  HH  dF\"" << std::endl;
        file << "                \"Hb HH dF" << std::endl;
        file << "                 \"HbHHdF" << std::endl;
        file << "                  |HHHF" << std::endl;
        file << "                  |HHH|" << std::endl;
        file << "                  |HHH|" << std::endl;
        file << "                  |HHH|" << std::endl;
        file << "                  |HHH|" << std::endl;
        file << "                  dHHHb" << std::endl;
        file << "                .dFd|bHb.               o" << std::endl;
        file << "      o       .dHFdH|HbTHb.          o /" << std::endl;
        file << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
        file << "##########################################" << std::endl;
        file.close();
    }
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ) 
    : AForm("Shrubbery_Form", 145, 137), _target( target ) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) 
    : AForm(obj), _target(obj._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& obj) {
    (void)obj;
    return *this;
}

