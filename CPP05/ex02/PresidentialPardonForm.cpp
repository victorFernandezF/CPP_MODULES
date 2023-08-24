/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:11:41 by victofer          #+#    #+#             */
/*   Updated: 2023/08/24 11:20:55 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//E X C E P T O N S
class PresidentialPardonForm::GradeTooHighException : public std::exception
{
	public: virtual char *what() const throw(){
		return ((char *)"Grade is too hight");
	}
};

class PresidentialPardonForm::GradeTooLowException : public std::exception
{
	public: virtual char *what() const throw(){
		return ((char *)"Grade is too low");
	}
};

PresidentialPardonForm::PresidentialPardonForm(): AForm("Shrubbery", 25, 5){}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Shrubbery", 25, 5){
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) : AForm(copy){}

/* PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy){
	if (this != &copy)
		this->setSigned(copy.getSigned());
	return (*this);
} */

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (this->_signed == 0)
		throw FormIsNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::cout<<B<<this->_target<<" has been pardoned by Zaphod Beeblebrox."<<W<<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){}
