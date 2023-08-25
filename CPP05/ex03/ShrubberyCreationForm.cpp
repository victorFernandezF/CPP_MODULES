/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:43:43 by victofer          #+#    #+#             */
/*   Updated: 2023/08/24 10:43:55 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//E X C E P T O N S
class ShrubberyCreationForm::GradeTooHighException : public std::exception
{
	public: virtual char *what() const throw(){
		return ((char *)"Grade is too hight");
	}
};

class ShrubberyCreationForm::GradeTooLowException : public std::exception
{
	public: virtual char *what() const throw(){
		return ((char *)"Grade is too low");
	}
};

class ShrubberyCreationForm::FormNotSignedException : public std::exception
{
	public: virtual char *what() const throw(){
		return ((char *)"Grade is too low");
	}
};

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery", 145, 137){
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) : AForm(copy){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy){
	(void)copy;
	return (*this);
}

int ShrubberyCreationForm::_plantShrubbery() const{
	std::string		filename;
	std::ofstream	output;
	
	filename = this->_target + "_shrubbery";
	output.open(filename, std::ios::out);
	if (output.fail())
		return (std::cout<<BR<<"Sorry "<<this->_target<<" something were wrong\n"<<W, 1);
	output << "       _-_\n    /~~   ~~\\ \n /~~         ~~\\ \n"
	<<"{               }\n \\  _-     -_  /\n   ~  \\ //  ~\n       | |     \n"
	<<"       | |     \n______// \\\\______\n";
	return (0);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	int grade = executor.getGrade();
	if (this->getSigned() == 0)
		throw FormNotSignedException();
	if (grade > this->getGradeToExecute())
		throw GradeTooLowException();
	if (this->_plantShrubbery() == 0){
		std::cout<<W<<executor.getName()<<" executed "<<this->getName()<<"\n";
		std::cout<<G<<"Shruberry has been created succesfully in "
		<<this->_target<<"_shruberry\n"<<W;
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

