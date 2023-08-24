/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:11:30 by victofer          #+#    #+#             */
/*   Updated: 2023/08/24 19:12:47 by victofer         ###   ########.fr       */
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
		~RobotomyRequestForm();
		std::string getName(void) const;
		
		void setSigned(bool isSigned);
		void execute(Bureaucrat const & executor) const;

		void beSigned(Bureaucrat &buro);
		class GradeTooHighException;
		class GradeTooLowException;
		class FormNotSignedException;
};

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &obj);
#endif