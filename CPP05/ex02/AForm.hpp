/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:51:35 by victofer          #+#    #+#             */
/*   Updated: 2023/08/24 10:41:49 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <fstream>
#include "colours.h"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	
	public:
		AForm();
		AForm(std::string name, int sign, int exe);
		AForm(AForm &name);
		AForm &operator=(const AForm &name);
		virtual ~AForm() = 0;
		std::string getName(void) const;
		bool getSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;
		
		void setSigned(bool isSigned);
		void setGradeSign(int sign);
		void setGradeExe(int exe);
		
		void beSigned(Bureaucrat &buro);
		void execute(Bureaucrat const & executor) const;
		virtual void doAction(void) const = 0;
		
		class GradeTooHighException;
		class GradeTooLowException; 
		class FormNotSignedException; 
};

std::ostream &operator<<(std::ostream &out, const AForm &obj);
#endif