/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:11:41 by victofer          #+#    #+#             */
/*   Updated: 2023/08/25 10:07:34 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//E X C E P T O N S
class RobotomyRequestForm::GradeTooHighException : public std::exception
{
	public: virtual char *what() const throw(){
		return ((char *)"Grade is too hight");
	}
};

class RobotomyRequestForm::GradeTooLowException : public std::exception
{
	public: virtual char *what() const throw(){
		return ((char *)"Grade is too low");
	}
};

class RobotomyRequestForm::FormNotSignedException : public std::exception
{
	public: virtual char *what() const throw(){
		return ((char *)"Form is not signed");
	}
};

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyForm", 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyForm", 72, 45){
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy) : AForm(copy){}

/* RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy){
	if (this != &copy)
		this->setSigned(copy.getSigned());
	return (*this);
} */


void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	int grade = executor.getGrade();
	if (this->getSigned() == 0)
		throw FormNotSignedException();
	if (grade > this->getGradeToExecute())
		throw GradeTooLowException();
	std::cout<<G<<this->_target<<" action for this form"
	<<W<<std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){}
