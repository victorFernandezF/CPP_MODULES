/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:11:41 by victofer          #+#    #+#             */
/*   Updated: 2023/08/29 18:23:53 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

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

void RobotomyRequestForm::doAction() const{
	int random = this->_getRandomNumber();
	std::cout<<Y<<"Brrrrrrr brrrr brrr ";
	if (random == 1)
		std::cout<<G<<this->_target<<" has been robotomized successfully\n"<<W;
	else
		std::cout<<BR<<this->_target<<"'s robotomy failed. XD\n"<<W;
}

RobotomyRequestForm::~RobotomyRequestForm(){}
