/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:28:30 by victofer          #+#    #+#             */
/*   Updated: 2023/09/13 19:14:30 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

class Span::OutOfRange : public std::exception{
	public: virtual char *what() const throw(){
		return ((char *)"Out of Range");
	}
};

Span::Span(){}

Span::Span(unsigned int N): _index(0), _size(N), _array(N) {
	std::cout<<Y<<"Constructor"<<W<<std::endl;
}	

//Span::Span(const Span &copy){}	

//Span &Span::operator=(const Span &copy){}	

Span::~Span(){
	std::cout<<Y<<"Destructor"<<W<<std::endl;
}
		
void Span::addNumber(unsigned int nb){
	if (this->_index >= this->_size - 1)
		throw OutOfRange();
	for (size_t i = 0; i < this->_size; i++)
	{
		if (this->_array[i] == 0){
			this->_array[i] = nb;
			this->_index = i;
			return;
		}
	}
	
}

int Span::shortestSpan(){
	std::vector<int> copy = this->_array;
	std::sort(copy.begin(), copy.begin() + this->_size);
	return (copy[1] - copy[0]);
}

void Span::print(){
	for (size_t i = 0; i < this->_size; i++)
		std::cout<<this->_array[i]<<"\n";
}