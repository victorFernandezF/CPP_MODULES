/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:11:30 by victofer          #+#    #+#             */
/*   Updated: 2023/08/29 18:24:01 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "colours.h"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class RobotomyRequestForm : public AForm{
	private:
		std::string _target;
		int _getRandomNumber() const;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &name);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &name);
		~RobotomyRequestForm();
		
		void setSigned(bool isSigned);
		void doAction(void) const;
		void beSigned(Bureaucrat &buro);
};

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &obj);
#endif