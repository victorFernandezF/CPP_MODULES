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
# include <iomanip>
#include <limits>
#include <cfloat>
# include "colours.h"

class ScalarConverter{
	private:
		static char _char;
		static long int	_int;
		static float _float;
		static double _double;
		
		static std::string _charError;
		static std::string	_intError;
		static std::string _floatError;
		static std::string _doubleError;
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);
		~ScalarConverter();
		static void _checkEachType(std::string input);
		static void	_printResult(std::string str, char type);
		static char _detectType(std::string str);
		static int	_isChar(std::string str);
		static int	_isInt(std::string str);
		static int _isDouble(std::string str);
		static int _isFloat(std::string str);
		static int	_isAllDigit(std::string str, size_t end);
		static int	_isAllDigitNotation(std::string str, size_t end);
	public:	
		static void convert(std::string input);

		
};

#endif