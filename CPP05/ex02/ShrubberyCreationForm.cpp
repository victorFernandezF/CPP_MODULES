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

/* ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy){
	if (this != &copy)
		this = AForm(copy);
	return (*this);
} */

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	int grade = executor.getGrade();
	if (this->getSigned() == 0)
		throw FormNotSignedException();
	std::cout<<grade<<"\n";
	if (grade > this->getGradeToExecute())
		throw GradeTooLowException();
	std::cout<<G<<this->_target<<" action for this functio"
	<<std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

