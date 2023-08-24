/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:11:30 by victofer          #+#    #+#             */
/*   Updated: 2023/08/24 11:34:47 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include <fstream>
#include "colours.h"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class RobotomyRequestForm : public AForm{
	private:
		std::string _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &name);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &name);
		virtual ~RobotomyRequestForm() = 0;
		std::string getName(void) const;
		bool getSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;
		
		void setSigned(bool isSigned);
		
		void beSigned(Bureaucrat &buro);
		class GradeTooHighException;
		class GradeTooLowException; 
};

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &obj);
#endif