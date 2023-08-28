/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:10:28 by victofer          #+#    #+#             */
/*   Updated: 2023/08/28 19:01:41 by victofer         ###   ########.fr       */
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
	public:
		Intern();
		Intern(Intern const &copy);
		~Intern();
		Intern &operator=(Intern const &copy);
		AForm *makeShruberry(std::string target);
		AForm *makePresidential(std::string target);
		AForm *makeRobotomy(std::string target);
		
		AForm *makeForm(std::string formName, std::string target);
		class NoForm;
};
#endif
