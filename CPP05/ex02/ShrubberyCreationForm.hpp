/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:10:19 by victofer          #+#    #+#             */
/*   Updated: 2023/08/24 19:13:02 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include <fstream>
#include "colours.h"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class ShrubberyCreationForm : public AForm{
	private:
		std::string _target;
		
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm &name);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &name);
		~ShrubberyCreationForm();
		std::string getName(void) const;
		
		void setSigned(bool isSigned);
		void execute(Bureaucrat const & executor) const;
		
		void beSigned(Bureaucrat &buro);
		class GradeTooHighException;
		class GradeTooLowException; 
		class FormNotSignedException; 
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &obj);
#endif