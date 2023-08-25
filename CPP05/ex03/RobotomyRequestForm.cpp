/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:11:41 by victofer          #+#    #+#             */
/*   Updated: 2023/08/25 13:38:04 by victofer         ###   ########.fr       */
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

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy){
	(void)copy;
	return (*this);
}

int RobotomyRequestForm::_getRandomNumber() const{
	int  random;
    srand(time(0));
    random = rand() % 2 + 1;
	return random;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	int grade = executor.getGrade();
	int random = this->_getRandomNumber();
	if (this->getSigned() == 0)
		throw FormNotSignedException();
	if (grade > this->getGradeToExecute())
		throw GradeTooLowException();
	std::cout<<W<<executor.getName()<<" executed "<<this->getName()<<"\n";
	std::cout<<Y<<"Brrrrrrr brrrr brrr ";
	if (random == 1)
		std::cout<<G<<this->_target<<" has been robotomized successfully\n"<<W;
	else
		std::cout<<BR<<this->_target<<"'s robotomy failed. XD\n"<<W;
}

RobotomyRequestForm::~RobotomyRequestForm(){}
