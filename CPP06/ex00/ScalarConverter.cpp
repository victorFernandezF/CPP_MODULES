/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:41:48 by victofer          #+#    #+#             */
/*   Updated: 2023/09/01 13:50:53 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char	ScalarConverter::_char = 0;
int		ScalarConverter::_int = 0;
float	ScalarConverter::_float = 0.0f;
double	ScalarConverter::_double = 0.0;
int	ScalarConverter::_charError = 0;
bool	ScalarConverter::_intError = 0;
bool	ScalarConverter::_floatError = 0;
bool	ScalarConverter::_doubleError = 0;

void ScalarConverter::convert(std::string input){
	char type = ScalarConverter::detectType(input);
	long int nb;
	std::string end = "nan";
	float nbf;
	float nbd;
	switch (type)
	{
	case 'n':
		nbf = strtof(end.c_str(), NULL);
		ScalarConverter::_charError = 2;
		ScalarConverter::_intError = 1;
		ScalarConverter::_float = static_cast<float>(nbf);
		ScalarConverter::_double = static_cast<double>(nbf);
		break;
	case 'i':
		nb = strtol(input.c_str(), NULL, 10);
		if (nb < INT_MIN || nb > INT_MAX){
			ScalarConverter::_intError = 1;
			ScalarConverter::_charError = 2;
		}
		else if (!(nb >= 32 && nb <= 126))
			ScalarConverter::_charError = 1;
		ScalarConverter::_char = static_cast<char>(nb);
		ScalarConverter::_int = static_cast<int>(nb);
		ScalarConverter::_float = static_cast<float>(nb);
		ScalarConverter::_double = static_cast<double>(nb);
		break;
	case 'f':
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
		ScalarConverter::_char = static_cast<char>(nbf);
		ScalarConverter::_int = static_cast<int>(nbf);
		ScalarConverter::_float = static_cast<float>(nbf);
		ScalarConverter::_double = static_cast<double>(nbf);
		break;
	case 'd':
		nbd = strtod(input.c_str(), NULL);
		if (input == "nan" || input == "+inf" || input == "-inf"){
			ScalarConverter::_charError = 2;
			ScalarConverter::_intError = 1;
		}
		else if (!(nbd >= 32 && nbd <= 126))
			ScalarConverter::_charError = 1;
		ScalarConverter::_char = static_cast<char>(nbd);
		ScalarConverter::_int = static_cast<int>(nbd);
		ScalarConverter::_float = static_cast<float>(nbd);
		ScalarConverter::_double = static_cast<double>(nbd);
		break;	
	default:
		break;
	}
	ScalarConverter::printResult(input, type);
}

int	ScalarConverter::isAllDigit(std::string str){
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

int ScalarConverter::isFloat(std::string str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return 1;
	if (str.find('.') != std::string::npos || str.find(',') != std::string::npos)
		if (str[str.length() - 1] == 'f')
			return 1;
	return 0;
}

int ScalarConverter::isDouble(std::string str)
{
	if (str == "-inf" || str == "+inf" || str == "nan")
		return 1;
	if (str.find('.') != std::string::npos || str.find(',') != std::string::npos)
		if (str[str.length() - 1] != 'f')
			return 1;
	return 0;
}

int	ScalarConverter::isInt(std::string str){
	if (str.find('.') != std::string::npos || str.find(',') != std::string::npos)
		return 0;
	if (str == "-inf" || str == "+inf" || str == "nan"
		|| str == "-inff" || str == "+inff" || str == "nanf"
		|| str[str.length() - 1] == 'f' || !ScalarConverter::isAllDigit(str))
		return 0;
	return 1;
}

int	ScalarConverter::isChar(std::string str){
	if (str.length() == 1)
		if ((str[0] >= 26 && str[0] <= 126) && (!ScalarConverter::isAllDigit(str)))
			return 1;
	return (0);		
}

char ScalarConverter::detectType(std::string str){
	if (ScalarConverter::isChar(str))
		return CHAR;
	if (ScalarConverter::isInt(str))
		return INT;
	if (ScalarConverter::isFloat(str))
		return FLOAT;
	if (ScalarConverter::isDouble(str))
		return DOUBLE;
	return (NAN);
}

void ScalarConverter::printResult(std::string str, char type){
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
	std::cout<<G<<"Float:  "<<W<<ScalarConverter::_float<<"f"<<std::endl;
	std::cout<<G<<"Double: "<<W<<ScalarConverter::_double<<std::endl;
}