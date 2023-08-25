/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:11:41 by victofer          #+#    #+#             */
/*   Updated: 2023/08/25 10:07:34 by victofer         ###   ########.fr       */
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

class PresidentialPardonForm::FormNotSignedException : public std::exception
{
	public: virtual char *what() const throw(){
		return ((char *)"Form is not signed");
	}
};

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 72, 45){}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 72, 45){
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) : AForm(copy){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy){
	(void)copy;
	return (*this);
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	int grade = executor.getGrade();
	if (this->getSigned() == 0)
		throw FormNotSignedException();
	if (grade > this->getGradeToExecute())
		throw GradeTooLowException();
	std::cout<<G<<this->_target<<" has been pardoned by Zaphod Beeblebrox"
	<<W<<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){}
