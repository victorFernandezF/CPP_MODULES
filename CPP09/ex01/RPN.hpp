/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:23:06 by victofer          #+#    #+#             */
/*   Updated: 2023/11/22 10:39:03 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
# define RPN_HPP_HPP
# include <iostream>
# include <fstream>
# include <stack>
# include "colours.h"

class Rpn{
	private:
		std::stack<int> _stack;
		
		int			_makeOperation(int nb1, int nb2, char sign);
		int			_isElementInt(char ele);
		int 		_isSign(char ele);
		std::string _checkStringErrors(std::string ogstring);
		std::string	_transformString(std::string str);
		
	public:
		Rpn();
		Rpn(const Rpn &copy);
		Rpn &operator=(const Rpn &copy);
		~Rpn();
		void rpn(std::string elements);
		std::stack<int> getStack();

		class BadInputException;
		class BadNbOfElementsEception;
		class NumberOverTheLimit;

};

#endif