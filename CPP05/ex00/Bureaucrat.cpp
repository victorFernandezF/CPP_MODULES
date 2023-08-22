/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:00:20 by victofer          #+#    #+#             */
/*   Updated: 2023/08/22 12:57:36 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){}
Bureaucrat::Bureaucrat(std::string name, int grade): _name(name){
	try {		
		if (grade > 150 || grade < 1)
			throw (grade);
		this->setGrade(grade);
	}
	catch (int grade){
		if (grade > 150)
			this->_GradeTooLowException();
		else
			this->_GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat(Bureaucrat &copy) : _name(copy._name){
	if (this != &copy){
		this->_grade = copy._grade;
	}
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy){
	if (this != &copy)
		this->setGrade(copy._grade);
	return (*this);
}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName(void) const{
	return (this->_name);	
}

int Bureaucrat::getGrade() const{
	return (this->_grade);
}

void Bureaucrat::_GradeTooHighException(){
	std::cout<<"Grade Too High"<<std::endl;
}

void Bureaucrat::_GradeTooLowException(){
	std::cout<<"Grade Too Low"<<std::endl;
}

void Bureaucrat::setGrade(int grade){
	this->_grade = grade;
}
