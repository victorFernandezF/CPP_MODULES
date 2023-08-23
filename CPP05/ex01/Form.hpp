/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:51:35 by victofer          #+#    #+#             */
/*   Updated: 2023/08/23 12:35:38 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <fstream>
#include "colours.h"
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	
	public:
		Form();
		Form(std::string name, int sign, int exe);
		Form(Form &name);
		Form &operator=(const Form &name);
		~Form();
		std::string getName(void) const;
		bool getSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;
		void beSigned(Bureaucrat &buro);
		class GradeTooHighException;
		class GradeTooLowException; 
};

std::ostream &operator<<(std::ostream &out, const Form &obj);
#endif