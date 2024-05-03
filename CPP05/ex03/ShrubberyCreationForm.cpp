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
		std::string filename = this->_target + "_shrubbery";
		std::ofstream file(filename.c_str());
		if (!file) {
			throw std::runtime_error("Failed to create file");
		}
		file << "                                                         ." << std::endl;
		file << "                                              .         ;  " << std::endl;
		file << "                 .              .              ;%     ;;   " << std::endl;
		file << "                   ,           ,                :;%  %;   " << std::endl;
		file << "                    :         ;                   :;%;'     .,   " << std::endl;
		file << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
		file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
		file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
		file << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
		file << "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
		file << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
		file << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
		file << "                      `@%:.  :;%.         ;@@%;'   " << std::endl;
		file << "                        `@%.  `;@%.      ;@@%;         " << std::endl;
		file << "                          `@%%. `@%%    ;@@%;        " << std::endl;
		file << "                            ;@%. :@%%  %@@%;       " << std::endl;
		file << "                              %@bd%%%bd%%:;     " << std::endl;
		file << "                                #@%%%%%:;;" << std::endl;
		file << "                                %@@%%%::;" << std::endl;
		file << "                                %@@@%(o);  . '         " << std::endl;
		file << "                                %@@@o%;:(.,'         " << std::endl;
		file << "                            `.. %@@@o%::;         " << std::endl;
		file << "                               `)@@@o%::;         " << std::endl;
		file << "                                %@@(o)::;        " << std::endl;
		file << "                               .%@@@@%::;         " << std::endl;
		file << "                               ;%@@@@%::;.          " << std::endl;
		file << "                              ;%@@@@%%:;;;. " << std::endl;
		file << "                          ...;%@@@@@%%:;;;;,..    Gilo97" << std::endl;
		file.close();
	}
}

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ) 
	: AForm(GREEN "shrubbery creation" RESET, 145, 137), _target( target ) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) 
	: AForm(obj), _target(obj._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/******************************************************************************/
/*							OPERATOR OVERLOAD								  */
/******************************************************************************/

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
	this->_target = obj._target;
	return *this;
}
