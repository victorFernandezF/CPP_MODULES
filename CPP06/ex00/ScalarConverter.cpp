/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:41:48 by victofer          #+#    #+#             */
/*   Updated: 2023/09/04 18:59:32 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char		ScalarConverter::_char = 0;
long int	ScalarConverter::_int = 0;
float		 ScalarConverter::_float = 0.0f;
double		ScalarConverter::_double = 0.0;

std::string	ScalarConverter::_charError = "";
std::string	ScalarConverter::_intError = "";
std::string	ScalarConverter::_floatError = "";
std::string	ScalarConverter::_doubleError = "";

void ScalarConverter::_checkEachType(char type, std::string input){
	long int nb = 0;
	float nbf = 0;
	double nbd = 0;
	
	if (type == 'i'){
		nb = strtol(input.c_str(), NULL, 10);
		if (nb < INT_MIN || nb > INT_MAX){
			ScalarConverter::_intError = "impossible";
			ScalarConverter::_charError = "impossible";
		}
		else if (!(nb >= 32 && nb <= 126))
			ScalarConverter::_charError = "no displayable";
	}
	if (type == 'f'){
		nbf = strtof(input.c_str(), NULL);
		if (nbf < FLT_MIN || nbf > FLT_MAX){
			ScalarConverter::_intError = "impossible";
			ScalarConverter::_charError = "impossible";
		}
		else if (input == "nanf" || input == "+inff" || input == "-inff"){
			ScalarConverter::_charError = "impossible";
			ScalarConverter::_intError = "impossible";
		}
		else if (!(nbf >= 32 && nbf <= 126))
			ScalarConverter::_charError = "no displayable";
	}
	if (type == 'd'){
		nbd = strtod(input.c_str(), NULL);
		if (input == "nan" || input == "+inf" || input == "-inf"){
			ScalarConverter::_charError = "impossible";
			ScalarConverter::_intError = "impossible";
		}		else if (!(nbd >= 32 && nbd <= 126))
			ScalarConverter::_charError = "no displayable";
	}
}

void ScalarConverter::convert(std::string input){
	char type = ScalarConverter::_detectType(input);

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
		ScalarConverter::_charError = "imposible";
		ScalarConverter::_intError = "imposible";
		ScalarConverter::_floatError = "imposible";
		ScalarConverter::_doubleError = "imposible";
	}
	ScalarConverter::_printResult(input, type);
}

int	ScalarConverter::_isAllDigit(std::string str, size_t end){
	if (!end)
		end = str.length();
	if (!(str[0] >= '0' && str[0] <= '9') && str[0] != '-' && str[0] != '.' )
		return (0);
	for (size_t i = 1; i < end; i++)
		if (!(str[i] >= '0' && str[i] <= '9'))
			return 0;
	return 1;		
}

int ScalarConverter::_isFloat(std::string str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return 1;
	if ((ScalarConverter::_isAllDigit(str, str.length() -1))
		&& (str[str.length() - 1] == 'f'))
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
		|| str[str.length() - 1] == 'f' || !ScalarConverter::_isAllDigit(str, 0))
		return 0;
	return 1;
}

int	ScalarConverter::_isChar(std::string str){
	if (str.length() == 1)
		if ((str[0] >= 26 && str[0] <= 126) && (!ScalarConverter::_isAllDigit(str, 0)))
			return 1;
	return (0);		
}

char ScalarConverter::_detectType(std::string str){
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
	std::cout<<BC<<" CONVERTING \""<<str<<"\"\n"<<W<<std::endl;
	
	// PRINT CHAR
	std::cout<<G<<" ◉ CHAR:    "<<W;
	if (ScalarConverter::_charError.empty())
		std::cout<<ScalarConverter::_char<<std::endl;
	else
		std::cout<<ScalarConverter::_charError<<std::endl;

	// PRINT INT
	std::cout<<G<<" ◉ INT:     "<<W;
	if (ScalarConverter::_intError.empty())
		std::cout<<W<<ScalarConverter::_int<<std::endl;
	else
		std::cout<<ScalarConverter::_intError<<std::endl;
		
	// PRINT FLOAT
	std::cout<<G<<" ◉ FLOAT:   "<<W;
	if (ScalarConverter::_floatError.empty()){
		if (ScalarConverter::_float - ScalarConverter::_int == 0)
			std::cout<<ScalarConverter::_double<<".0f"<<std::endl;
		else
			std::cout<<W<<ScalarConverter::_float<<"f"<<std::endl;
	}else	
		std::cout<<ScalarConverter::_floatError<<std::endl;

	// PRINT DOUBLE
	std::cout<<G<<" ◉ DOUBLE:  "<<W;
	if (ScalarConverter::_doubleError.empty()){
		if (ScalarConverter::_double - ScalarConverter::_int == 0)
			std::cout<<ScalarConverter::_double<<".0"<<std::endl;
		else
			std::cout<<ScalarConverter::_double<<std::endl;
	}else
		std::cout<<ScalarConverter::_doubleError<<std::endl;
}