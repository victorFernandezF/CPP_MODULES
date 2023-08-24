/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:00:20 by victofer          #+#    #+#             */
/*   Updated: 2023/08/24 10:35:41 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//E X C E P T O N S
class AForm::GradeTooHighException : public std::exception
{
	public: virtual char *what() const throw(){
		return ((char *)"Grade is too hight");
	}
};

class AForm::GradeTooLowException : public std::exception
{
	public: virtual char *what() const throw(){
		return ((char *)"Grade is too low");
	}
};

class AForm::FormIsNotSignedException : public std::exception
{
	public: virtual char *what() const throw(){
		return ((char *)"Form is not signed.");
	}
};

AForm::AForm(): _name("default"), _gradeToSign(1), _gradeToExecute(1){}

AForm::AForm(std::string name, int sign, int exe): _name(name), _gradeToSign(sign), _gradeToExecute(exe){
	if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw GradeTooHighException();
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw GradeTooHighException();
}

AForm::AForm(AForm &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute){
	if (this != &copy){
		this->_signed = copy._signed;
	}
}

AForm &AForm::operator=(const AForm &copy){
	if (this != &copy)
		this->_signed = copy._signed;
	return (*this);
}

AForm::~AForm(){}

// G E T T E R S
std::string AForm::getName(void) const {
	return (this->_name);
}
bool AForm::getSigned(void) const {
	return (this->_signed);
}
int AForm::getGradeToSign(void) const {
	return (this->_gradeToSign);
}
int AForm::getGradeToExecute(void) const {
	return (this->_gradeToExecute);
}

void AForm::setSigned(bool isSigned){
	this->_signed = isSigned;
}


void AForm::beSigned(Bureaucrat &buro){
	int gradeNeeded = this->getGradeToSign();
	if (buro.getGrade() > gradeNeeded)
		throw GradeTooLowException();
	this->_signed = 1;
}

void AForm::execute(Bureaucrat const & executor) const{
	if (this->_signed == 0)
		throw FormIsNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::cout<<B<<" "<<W<<std::endl;
}

// O U T P U T   O P E R A T O R 
std::ostream &operator<<(std::ostream &out, const AForm &obj){
	out<<obj.getName()<<" -> signed: "<<obj.getSigned()
	<<" grade to sign: "<<obj.getGradeToSign()<<" grade to execute "
	<<obj.getGradeToExecute();
	return (out);
}
