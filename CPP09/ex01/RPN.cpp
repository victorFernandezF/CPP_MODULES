/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:23:03 by victofer          #+#    #+#             */
/*   Updated: 2023/11/22 10:39:32 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// E X C E P T I O N S
class Rpn::BadInputException : public std::exception{
	public: virtual char *what() const throw(){
		return ((char *)"Invalid input. (Only integers and signs [+ - * /] allowed)");
	}	
};

class Rpn::BadNbOfElementsEception : public std::exception{
	public: virtual char *what() const throw(){
		return ((char *)"Incorrect number of signs or elements.");
	}	
};

class Rpn::NumberOverTheLimit : public std::exception{
	public: virtual char *what() const throw(){
		return ((char *)"Incorrect input. numbers must be less than 10.");
	}	
};

// C O N S T R U C T O R S
Rpn::Rpn(){}

Rpn::Rpn(const Rpn &copy){
	this->_stack = copy._stack;
}

Rpn &Rpn::operator=(const Rpn &copy){
	this->_stack = copy._stack;
	return (*this);
}

Rpn::~Rpn(){}

// R P N   F U N C T I O N S
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

std::string Rpn::_checkStringErrors(std::string ogstring){
	int nb = 0;
	int op = 0;
	std::string str;
	
	str = this->_transformString(ogstring);
	for (size_t i = 0; i < ogstring.size(); i++)
		if (this->_isElementInt(ogstring[i]) && this->_isElementInt(ogstring[i + 1]))
			throw NumberOverTheLimit();
	for (size_t i = 0; i < str.size(); i++)
		if (!(this->_isElementInt(str[i]) || (this->_isSign(str[i]))))
			throw BadInputException();
	for (size_t i = 0; i < str.size(); i++){
		if (this->_isElementInt(str[i]))
			nb++;
		if (this->_isSign(str[i]))
			op++;
	}
	if (nb - op >= 2 || nb - op <= 0)
		throw BadNbOfElementsEception();
	return (str);
}

void Rpn::rpn(std::string elements){
	std::string operation;
	operation = this->_checkStringErrors(elements);
	this->_stack.push(operation.at(0) - '0');
	for (size_t i = 1; i < operation.size(); i++)
	{
		if (this->_isElementInt(operation.at(i)))
			this->_stack.push(operation.at(i) - '0');
		if (this->_isSign(operation.at(i)))
		{
			int nb_2 = this->_stack.top();		
			this->_stack.pop();		
			int nb_1= this->_stack.top();
			this->_stack.pop();
			this->_stack.push(this->_makeOperation(nb_1, nb_2, operation.at(i)));					
		}
	}
	std::cout<<"\nResult: "<<this->_stack.top()<<std::endl;
}

std::stack<int> Rpn::getStack(){
	return this->_stack;
}