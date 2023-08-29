/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:10:19 by victofer          #+#    #+#             */
/*   Updated: 2023/08/29 18:27:04 by victofer         ###   ########.fr       */
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
		int _plantShrubbery() const;
		void _seeShrubbery() const;
		
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm &name);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &name);
		~ShrubberyCreationForm();
		
		void setSigned(bool isSigned);
		void doAction(void) const; 
		void beSigned(Bureaucrat &buro);
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &obj);
#endif