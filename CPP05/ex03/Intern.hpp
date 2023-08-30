/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:10:28 by victofer          #+#    #+#             */
/*   Updated: 2023/08/30 13:36:32 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include <fstream>
#include "colours.h"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	private:
		std::string _strToLower(std::string str);
		int _Do(std::string lowerName);
		AForm *_makeshrubbery(std::string target);
		AForm *_makePresidential(std::string target);
		AForm *_makeRobotomy(std::string target);
	
	public:
		Intern();
		Intern(Intern const &copy);
		~Intern();
		Intern &operator=(Intern const &copy);
		AForm *makeForm(std::string formName, std::string target);
};
#endif
