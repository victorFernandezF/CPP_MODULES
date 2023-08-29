/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:15:25 by victofer          #+#    #+#             */
/*   Updated: 2023/08/29 13:05:48 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

class Intern::NoForm : public std::exception
{
	public: virtual char *what() const throw(){
		return ((char *)"No Form Found with that name");
	}
};

Intern::Intern(){}

Intern::Intern(Intern const &copy){
	*this = copy;
}

Intern::~Intern(){}

Intern & Intern::operator=(Intern const &copy){
	(void)copy;
	return (*this);
}

AForm *Intern::makeShruberry(std::string target){
	AForm *shru = new ShrubberyCreationForm(target);
	std::cout<<BC<<"Intern created Shrubbery Creation Form\n"<<W;
	return (shru);
}
AForm *Intern::makePresidential(std::string target){
	AForm *presi = new PresidentialPardonForm(target);
	std::cout<<BC<<"Intern created Presidential Pardon Form\n"<<W;
	return (presi);
}
AForm *Intern::makeRobotomy(std::string target){
	AForm *robot = new RobotomyRequestForm(target);
	std::cout<<BC<<"Intern created Robotomy Request Form\n"<<W;
	return (robot);
}

std::string Intern::_strToLower(std::string str){
	int i = -1;
	while (str[++i])
		str[i] = tolower(str[i]);
	return (str);
}

AForm *Intern::makeForm(std::string formName, std::string target){
	std::string functions[3] = {"shruberry creation", "presidential pardon", "robotomy request"};
	AForm *(Intern::*funcPtr[3])(std::string) = {&Intern::makeShruberry, &Intern::makePresidential, &Intern::makeRobotomy};
	std::string lowerName = this->_strToLower(formName);
	for (int i = 0; i < 3; i++)
		if (functions[i] == lowerName)
			return (this->*funcPtr[i])(target);
	throw NoForm();
}
