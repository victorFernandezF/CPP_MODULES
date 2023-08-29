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

// Default constructor
PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 72, 45){}

// Constructor with parameters
PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 72, 45){
	this->_target = target;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) : AForm(copy){}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm(){}

// Asignment operator
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy){
	(void)copy;
	return (*this);
}

// Execute function
void PresidentialPardonForm::doAction() const{
	std::cout<<G<<this->_target<<" has been pardoned by Zaphod Beeblebrox"
	<<W<<std::endl;
}
