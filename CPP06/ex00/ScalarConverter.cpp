/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:41:48 by victofer          #+#    #+#             */
/*   Updated: 2023/09/04 12:29:38 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char		ScalarConverter::_char = 0;
long int	ScalarConverter::_int = 0;
float		 ScalarConverter::_float = 0.0f;
double		ScalarConverter::_double = 0.0;
int			ScalarConverter::_charError = 0;
bool		ScalarConverter::_intError = 0;
bool		ScalarConverter::_floatError = 0;
bool		ScalarConverter::_doubleError = 0;

void ScalarConverter::_checkEachType(char type, std::string input){
	long int nb = 0;
	float nbf = 0;
	double nbd = 0;
	
	if (type == 'i'){
		nb = strtol(input.c_str(), NULL, 10);
		if (nb < INT_MIN || nb > INT_MAX){
			ScalarConverter::_intError = 1;
			ScalarConverter::_charError = 2;
		}
		else if (!(nb >= 32 && nb <= 126))
			ScalarConverter::_charError = 1;
	}
	if (type == 'f'){
		nbf = strtof(input.c_str(), NULL);
		if (nbf < FLT_MIN || nbf > FLT_MAX){
			ScalarConverter::_intError = 1;
			ScalarConverter::_charError = 2;
		}
		else if (input == "nanf" || input == "+inff" || input == "-inff"){
			ScalarConverter::_charError = 2;
			ScalarConverter::_intError = 1;
		}
		else if (!(nbf >= 32 && nbf <= 126))
			ScalarConverter::_charError = 1;
	}
	if (type == 'd'){
		nbd = strtod(input.c_str(), NULL);
		if (input == "nan" || input == "+inf" || input == "-inf"){
			ScalarConverter::_charError = 2;
			ScalarConverter::_intError = 1;
		}		else if (!(nbd >= 32 && nbd <= 126))
			ScalarConverter::_charError = 1;
	}
}

void ScalarConverter::convert(std::string input){
	char type = ScalarConverter::_detectType(input);
	std::string end = "nan";

	switch (type)
	{
	case 'c':
		ScalarConverter::_char = input[0];
		ScalarConverter::_int = static_cast<int>(ScalarConverter::_char);
		ScalarConverter::_float = static_cast<float>(ScalarConverter::_char);
		ScalarConverter::_double = static_cast<double>(ScalarConverter::_char);
		break;
	case 'i':
		ScalarConverter::_checkEachType('i', input);
		ScalarConverter::_int = strtol(input.c_str(), NULL, 10);
		ScalarConverter::_char = static_cast<char>(ScalarConverter::_int);
		ScalarConverter::_float = static_cast<float>(ScalarConverter::_int);
		ScalarConverter::_double = static_cast<double>(ScalarConverter::_int);
		break;
	case 'f':
		ScalarConverter::_checkEachType('f', input);
		ScalarConverter::_float = strtof(input.c_str(), NULL);
		ScalarConverter::_char = static_cast<char>(ScalarConverter::_float);
		ScalarConverter::_int = static_cast<int>(ScalarConverter::_float);
		ScalarConverter::_double = static_cast<double>(ScalarConverter::_float);
		break;
	case 'd':
		ScalarConverter::_checkEachType('d', input);
		ScalarConverter::_double = strtod(input.c_str(), NULL);
		ScalarConverter::_char = static_cast<char>(ScalarConverter::_double);
		ScalarConverter::_int = static_cast<int>(ScalarConverter::_double);
		ScalarConverter::_float = static_cast<float>(ScalarConverter::_double);
		break;	
	default:
		ScalarConverter::_charError = 2;
		ScalarConverter::_intError = 1;
		ScalarConverter::_floatError = 1;
		ScalarConverter::_doubleError = 1;
	}
	ScalarConverter::_printResult(input, type);
}

int	ScalarConverter::_isAllDigit(std::string str){
	size_t flag = 0;

	if (!(str[0] >= '0' && str[0] <= '9') && str[0] != '-' && str[0] != '+')
		return (0);
	for (size_t i = 1; i < str.length(); i++)
		if (str[i] >= '0' && str[i] <= '9')
			flag++;
	if (flag == str.length() -1)
		return 1;
	return (0);		
}

int ScalarConverter::_isFloat(std::string str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return 1;
	if (str[str.length() - 1] == 'f')
			return 1;
	return 0;
}

int ScalarConverter::_isDouble(std::string str)
{
	if (str == "-inf" || str == "+inf" || str == "nan")
		return 1;
	if (str.find('.') != std::string::npos || str.find(',') != std::string::npos)
	{
		if (str[str.length() - 1] != 'f')
			return 1;
	}
	return 0;
}

int	ScalarConverter::_isInt(std::string str){
	if (str.find('.') != std::string::npos || str.find(',') != std::string::npos)
		return 0;
	if (str == "-inf" || str == "+inf" || str == "nan"
		|| str == "-inff" || str == "+inff" || str == "nanf"
		|| str[str.length() - 1] == 'f' || !ScalarConverter::_isAllDigit(str))
		return 0;
	return 1;
}

int	ScalarConverter::_isChar(std::string str){
	if (str.length() == 1)
		if ((str[0] >= 26 && str[0] <= 126) && (!ScalarConverter::_isAllDigit(str)))
			return 1;
	return (0);		
}

char ScalarConverter::_detectType(std::string str){
	if (str.find(',') != std::string::npos)
			str[str.find(',')] = '.';
	if (ScalarConverter::_isChar(str))
		return CHAR;
	if (ScalarConverter::_isInt(str))
		return INT;
	if (ScalarConverter::_isFloat(str))
		return FLOAT;
	if (ScalarConverter::_isDouble(str))
		return DOUBLE;
	return (NAN);
}

void ScalarConverter::_printResult(std::string str, char type){
	if (type == 'e')
		return;
	std::cout<<BC<<" CONVERTING "<<str<<W<<std::endl;
	if (ScalarConverter::_charError == 1)
		std::cout<<G<<"Char:   "<<W<<"non displayable"<<std::endl;
	else if (ScalarConverter::_charError == 2)
		std::cout<<G<<"Char:   "<<W<<"impossible"<<std::endl;
	else
		std::cout<<G<<"Char:   "<<W<<ScalarConverter::_char<<std::endl;
	if (ScalarConverter::_intError)
		std::cout<<G<<"Int:    "<<W<<"impossible"<<std::endl;
	else
		std::cout<<G<<"Int:    "<<W<<ScalarConverter::_int<<std::endl;
	if (ScalarConverter::_floatError)
		std::cout<<G<<"Int:    "<<W<<"impossible"<<std::endl;
	else
		std::cout<<G<<"Float:  "<<W<<ScalarConverter::_float<<"f"<<std::endl;
	if (ScalarConverter::_doubleError)
		std::cout<<G<<"Int:    "<<W<<"impossible"<<std::endl;
	else
		std::cout<<G<<"Double: "<<W<<ScalarConverter::_double<<std::endl;
}