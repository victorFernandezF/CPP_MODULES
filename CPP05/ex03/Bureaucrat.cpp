/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:00:20 by victofer          #+#    #+#             */
/*   Updated: 2023/08/30 13:31:48 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//E X C E P T O N S
class Bureaucrat::GradeTooHighException : public std::exception
{
	public: virtual char *what() const throw(){
		return ((char *)"Grade is too hight");
	}
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	public: virtual char *what() const throw(){
		return ((char *)"Grade is too low");
	}
};

Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade){
	if (this->_grade > 150)
		throw GradeTooLowException();
	if (this->_grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat &copy) : _name(copy._name){
	if (this != &copy){
		this->_grade = copy._grade;
	}
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy){
	if (this != &copy)
		this->_grade = copy._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName(void) const{
	return (this->_name);	
}

int Bureaucrat::getGrade() const{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(){
	if ((this->getGrade() - 1) < 1)
		throw GradeTooHighException();
	this->_grade -= 1;
}

void Bureaucrat::decrementGrade(){
	if ((this->getGrade() + 1) > 150)
		throw GradeTooLowException();
	this->_grade += 1;
}

void Bureaucrat::signForm(AForm &form){
	try{
		form.beSigned(*this);
		std::cout<<G<<this->getName()<<" signed "<<form.getName()
		<<W<<std::endl;
	}catch (std::exception &e){
		std::cout<<BR<<this->getName()<<" couldn't sign "
		<<form.getName()<<" because "<<e.what()<<W<<std::endl;	
	}
}

void Bureaucrat::executeForm(AForm const & form){
	try{
		form.execute(*this);
	}catch(std::exception &e){
		std::cout<<BR<<this->getName()<<" couldn't execute "
		<<form.getName()<<" because "<<e.what()<<W<<std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj){
	out<<obj.getName()<<", bureaucrat grade: "<<obj.getGrade();
	return (out);
}
