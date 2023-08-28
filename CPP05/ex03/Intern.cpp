/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:15:25 by victofer          #+#    #+#             */
/*   Updated: 2023/08/28 19:05:20 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

class Intern::NoForm : public std::exception
{
	public: virtual char *what() const throw(){
		return ((char *)"No Form Fountd");
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
	return (shru);
}
AForm *Intern::makePresidential(std::string target){
		AForm *presi = new PresidentialPardonForm(target);
	return (presi);
}
AForm *Intern::makeRobotomy(std::string target){
		AForm *robot = new RobotomyRequestForm(target);
	return (robot);
}

AForm *Intern::makeForm(std::string formName, std::string target){
	std::string functions[3] = {"shruberry creation", "Presidential Pardon", "Robotomy request"};
	AForm *(Intern::*funcPtr[3])(std::string) = {&Intern::makeShruberry, &Intern::makePresidential, &Intern::makeRobotomy};
		for (int i = 0; i < 3; i++)
			if (functions[i] == formName)
				return (this->*funcPtr[i])(target);
	return(nullptr);
}
