/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:23:06 by victofer          #+#    #+#             */
/*   Updated: 2023/10/02 18:32:44 by victofer         ###   ########.fr       */
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
		std::stack<int>_stack;
		int	_makeOperation(int nb1, int nb2, char sign);
		int	_isElementInt(char ele);
		int _isSign(char ele);
		int _checkStringErrors(std::string str);
		std::string _transformString(std::string str);
	public:
		Rpn();
		Rpn(const Rpn &copy);
		Rpn &operator=(const Rpn &copy);
		~Rpn();
		void rpn(std::string elements);
		std::stack<int> getStack();
};

#endif