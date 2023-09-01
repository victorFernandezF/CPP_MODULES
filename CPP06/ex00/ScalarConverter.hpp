/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:45:31 by victofer          #+#    #+#             */
/*   Updated: 2023/09/01 10:39:13 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALARSCONVERTER_HPP
# define SCALARSCONVERTER_HPP
# include <iostream>
#include <limits>
#include <cfloat>
# include "colours.h"

class ScalarConverter{
	private:
		static char _char;
		static int	_int;
		static float _float;
		static double _double;
		static int _charError;
		static bool	_intError;
		static bool _floatError;
		static bool _doubleError;
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);
		~ScalarConverter();		
	
	public:	
		static void convert(std::string input);
		static char detectType(std::string str);
		static int	isChar(std::string str);
		static int	isInt(std::string str);
		static int isDouble(std::string str);
		static int isFloat(std::string str);
		static int	isAllDigit(std::string str);
		static void	printResult(std::string str, char type);
};

#endif