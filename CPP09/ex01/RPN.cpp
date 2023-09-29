/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:23:03 by victofer          #+#    #+#             */
/*   Updated: 2023/09/29 13:51:40 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Rpn::Rpn(){}

/* Rpn::Rpn(const Rpn &copy){}

Rpn &Rpn::operator=(const Rpn &copy){} */

Rpn::~Rpn(){}

int	Rpn::_isElementInt(char ele){
	return ele >= '0' && ele <= '9';
}

int Rpn::_isSign(char ele){
	return ele == '+' || ele <= '-' || ele == '*' || ele == '/';
}

std::string Rpn::_transformString(std::string str){
	std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
	str.erase(end_pos, str.end());
	return str;
}

int	Rpn::_makeOperation(int nb1, int nb2, char sign){
	switch (sign)
	{
	case '+':
		return nb1 + nb2;
	case '-':
		return nb1 - nb2;
	case '*':
		return nb1 * nb2;
	case '/':
		return nb1 / nb2;
	}
	return 0;
}

int Rpn::_checkStringErrors(std::string str){
	std::string error = "";
	int nb = 0;
	int op = 0;
	for (size_t i = 0; i < str.size(); i++)
		if (!((str[i] >= '0' && str[i] <= '9') || (this->_isSign(str[i]))))
			error = "Error, Bad input characters";
	for (size_t i = 0; i < str.size(); i++){
		if (this->_isElementInt(str[i]))
			nb++;
		if (this->_isSign(str[i]))
			op++;
	}
	if (nb - op == 2 || nb - op <= 0)
		error = "Error Bad nimber of signs or elements.";
	if (!error.empty()){
		std::cout<<BR<<error<<W<<std::endl;
		return 1;
	}
	return 0;
}

void Rpn::rpn(std::string elements){
	std::string operation = this->_transformString(elements);
	if (this->_checkStringErrors(operation))
		return;
	if (this->_isElementInt(operation[0]))
			this->_stack.push(operation[0] - '0');
	for (size_t i = 1; i < operation.size(); i++)
	{
		if (this->_isElementInt(operation[i]))
			this->_stack.push(operation[i] - '0');
		if (this->_isSign(operation[i]))
		{
			int nb_2 = this->_stack.top();		
			this->_stack.pop();		
			int nb_1= this->_stack.top();
			this->_stack.pop();
			this->_stack.push(this->_makeOperation(nb_1, nb_2, operation[i]));					
		}
	}
	std::cout<<"\nResult: "<<this->_stack.top()<<std::endl;
}