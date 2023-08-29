/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:43:43 by victofer          #+#    #+#             */
/*   Updated: 2023/08/24 10:43:55 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery", 145, 137){
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) : AForm(copy){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy){
	(void)copy;
	return (*this);
}

void ShrubberyCreationForm::doAction() const{
	std::string		filename;
	std::ofstream	output;
	
	filename = this->_target + "_shrubbery";
	output.open(filename, std::ios::out);
	if (output.fail())
	{
		std::cout<<BR<<"Sorry "<<this->_target<<" something were wrong\n"<<W;
		return;
	}
	output << "       _-_\n    /~~   ~~\\ \n /~~         ~~\\ \n"
	<<"{               }\n \\  _-     -_  /\n   ~  \\ //  ~\n       | |     \n"
	<<"       | |     \n______// \\\\______\n";
	output.close();
	std::cout<<G<<"Shruberry has been created succesfully in "
	<<this->_target<<"_shruberry\n"<<W;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

