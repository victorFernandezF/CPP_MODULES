/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:51:35 by victofer          #+#    #+#             */
/*   Updated: 2023/08/23 11:10:57 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <fstream>
#include "colours.h"

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
		
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat &name);
		Bureaucrat &operator=(const Bureaucrat &name);
		~Bureaucrat();
		std::string getName(void) const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		class GradeTooHighException;
		class GradeTooLowException;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);
#endif