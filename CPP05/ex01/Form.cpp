/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:00:20 by victofer          #+#    #+#             */
/*   Updated: 2023/08/23 18:57:39 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//E X C E P T O N S
class Form::GradeTooHighException : public std::exception
{
	public: virtual char *what() const throw(){
		return ((char *)"Grade is too hight");
	}
};

class Form::GradeTooLowException : public std::exception
{
	public: virtual char *what() const throw(){
		return ((char *)"Grade is too low");
	}
};

Form::Form(): _name("default"), _gradeToSign(1), _gradeToExecute(1){}

Form::Form(std::string name, int sign, int exe): _name(name), _gradeToSign(sign), _gradeToExecute(exe){
	if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw GradeTooHighException();
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw GradeTooHighException();
}

Form::Form(Form &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute){
	if (this != &copy){
		this->_signed = copy._signed;
	}
}

Form &Form::operator=(const Form &copy){
	if (this != &copy)
		this->_signed = copy._signed;
	return (*this);
}

Form::~Form(){}

// G E T T E R S
std::string Form::getName(void) const {
	return (this->_name);
}
bool Form::getSigned(void) const {
	return (this->_signed);
}
int Form::getGradeToSign(void) const {
	return (this->_gradeToSign);
}
int Form::getGradeToExecute(void) const {
	return (this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat &buro){
	int gradeNeeded = this->getGradeToSign();
	if (buro.getGrade() > gradeNeeded)
		throw GradeTooLowException();
	this->_signed = 1;
}

// O U T P U T   O P E R A T O R 
std::ostream &operator<<(std::ostream &out, const Form &obj){
	out<<obj.getName()<<" -> signed: "<<obj.getSigned()
	<<" grade to sign: "<<obj.getGradeToSign()<<" grade to execute "
	<<obj.getGradeToExecute();
	return (out);
}
