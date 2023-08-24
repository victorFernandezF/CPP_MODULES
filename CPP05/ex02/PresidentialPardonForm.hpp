/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:11:30 by victofer          #+#    #+#             */
/*   Updated: 2023/08/24 11:21:54 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include <fstream>
#include "colours.h"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class PresidentialPardonForm : public AForm{
	private:
		std::string _target;
	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &name);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &name);
		virtual ~PresidentialPardonForm() = 0;
		std::string getName(void) const;
		bool getSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;
		
		void setSigned(bool isSigned);
		void execute(Bureaucrat const & executor) const;
		
		void beSigned(Bureaucrat &buro);
		class GradeTooHighException;
		class GradeTooLowException; 
};

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &obj);
#endif