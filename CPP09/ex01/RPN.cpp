/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:23:03 by victofer          #+#    #+#             */
/*   Updated: 2023/11/22 11:01:04 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// E X C E P T I O N S
class Rpn::BadInputException : public std::exception{
	public: virtual char *what() const throw(){
		return ((char *)"Invalid input. (Only integers and signs [+ - * /] allowed)\
		\n \x1B[33m Correct input example: '2 5 * 2 - 4 /'");
	}	
};

class Rpn::BadNbOfElementsEception : public std::exception{
	public: virtual char *what() const throw(){
		return ((char *)"Incorrect amount of numbres or signs \
		\n \x1B[33m Correct input example: '3 2 + 3 -'");
	}	
};

class Rpn::NumberOverTheLimit : public std::exception{
	public: virtual char *what() const throw(){
		return ((char *)"Incorrect input. numbers must be less than 10. \
		\n \x1B[33m Correct input example: '5 3 - 2 *'");
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
int	Rpn::_isElementInt(char element){
	return element >= '0' && element <= '9';
}

int Rpn::_isSign(char element){
	return element == '+' || element <= '-' || element == '*' || element == '/';
}

std::string Rpn::_deleteWhitespacesFromString(std::string str){
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
	std::string noSpaces;
	
	noSpaces = this->_deleteWhitespacesFromString(ogstring);
	for (size_t i = 0; i < ogstring.size(); i++)
		if (this->_isElementInt(ogstring[i]) && this->_isElementInt(ogstring[i + 1]))
			throw NumberOverTheLimit();
	for (size_t i = 0; i < noSpaces.size(); i++)
		if (!(this->_isElementInt(noSpaces[i]) || (this->_isSign(noSpaces[i]))))
			throw BadInputException();
	for (size_t i = 0; i < noSpaces.size(); i++){
		if (this->_isElementInt(noSpaces[i]))
			nb++;
		if (this->_isSign(noSpaces[i]))
			op++;
	}
	if (nb - op >= 2 || nb - op <= 0)
		throw BadNbOfElementsEception();
	return (noSpaces);
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
