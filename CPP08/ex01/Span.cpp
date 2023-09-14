/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:28:30 by victofer          #+#    #+#             */
/*   Updated: 2023/09/14 19:18:55 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

class Span::OutOfRange : public std::exception{
	public: virtual char *what() const throw(){
		return ((char *)"Impossible. Check the size of the Span.");
	}
};
class Span::NotEnoughElements : public std::exception{
	public: virtual char *what() const throw(){
		return ((char *)"There are not enough element to do this action");
	}
};

Span::Span(){}

Span::Span(unsigned int N): _index(0), _size(N), _array(N) {}

Span::Span(const Span &copy): _index(copy._index), _size(copy._size), _array(_size){
	for (size_t i = 0; i < _size; i++){
		this->_array[i] = copy._array[i];
	}
}	

Span &Span::operator=(const Span &copy){
	this->_size = copy._size;
	this->_index = copy._index;
	this->_array = copy._array;
	for (size_t i = 0; i < _size; i++){
		this->_array[i] = copy._array[i];
	}
	return (*this);
}

Span::~Span(){
	//std::cout<<Y<<"Destructor"<<W<<std::endl;
}
		
void Span::addNumber(unsigned int nb){
	if (this->_index > this->_size - 1)
		throw OutOfRange();
	for (size_t i = 0; i < this->_size; i++)
	{
		if (this->_array[i] == 0){
			this->_array[i] = nb;
			this->_index++;
			return;
		}
	}
}

void Span::addManyNumbers(unsigned int nb){
	srand(time(NULL));
	if (this->_index > this->_size - 1)
		throw OutOfRange();
	std::vector<int> newVector(nb);
	std::generate(newVector.begin(), newVector.begin() + nb, rand);
	this->_array = newVector;	
}

int Span::shortestSpan(){
	int min;
	if (this->_size < 2)
		throw NotEnoughElements();
	std::vector<int> copy = this->_array;
	std::sort(copy.begin(), copy.begin() + this->_size);
	min = copy[1] - copy[0];
	for(size_t i= 0; i< this->_size - 1; i++)
	{
		if ((copy[i + 1] - copy[i]) < min)
			min = copy[i + 1] - copy[i];
	}
	return (min);
}

int Span::longestSpan(){
	if (this->_size < 2)
		throw NotEnoughElements();
	std::vector<int> copy = this->_array;
	std::sort(copy.begin(), copy.begin() + this->_size);
	//std::cout<<copy[this->_size - 1]<<" - "<< copy[0]<<"\n";
	return (copy[this->_size - 1] - copy[0]);
}

void Span::print(){
	for (size_t i = 0; i < this->_size; i++)
		std::cout<<this->_array[i]<<"\n";
}