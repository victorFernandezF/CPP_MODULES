/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:10:19 by victofer          #+#    #+#             */
/*   Updated: 2023/08/24 11:31:27 by victofer         ###   ########.fr       */
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
		virtual ~ShrubberyCreationForm() = 0;
		std::string getName(void) const;
		bool getSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;
		
		void setSigned(bool isSigned);
		
		void beSigned(Bureaucrat &buro);
		class GradeTooHighException;
		class GradeTooLowException; 
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &obj);
#endif