/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:28:30 by victofer          #+#    #+#             */
/*   Updated: 2023/10/25 10:34:37 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// C U S T O M   E X C E P T I O N S
class Span::OutOfRange : public std::exception{
	public: virtual char *what() const throw(){
		return ((char *)"Error: Not enough space in span to store more elements.");
	}
};
class Span::NotEnoughElements : public std::exception{
	public: virtual char *what() const throw(){
		return ((char *)"Error: There are not enough elements to do this action.");
	}
};

// C O N S T R U CT O R S   A N D   D E ST R U C T O R

// Default constructor.copy
Span::Span(){} 

// Constructor with parameter.
Span::Span(unsigned int N): _index(0), _size(N), _store(N) {}

// Copy constructor.
Span::Span(const Span &copy): _index(copy._index), _size(copy._size), _store(_size){
	for (size_t i = 0; i < _size; i++){
		this->_store[i] = copy._store[i];
	}
}	

// Assignment operator.
Span &Span::operator=(const Span &copy){
	this->_size = copy._size;
	this->_index = copy._index;
	this->_store = copy._store;
	for (size_t i = 0; i < _size; i++){
		this->_store[i] = copy._store[i];
	}
	return (*this);
}

// Destructor.
Span::~Span(){}

// M E M E B E R   F U N C T IO N S

// Add a single number to the store
void Span::addNumber(unsigned int nb){
	if (this->_index > this->_size - 1)
		throw OutOfRange();
	for (size_t i = 0; i < this->_size; i++){
		if (!this->_store[i]){
			this->_store[i] = nb;
			this->_index++;
			return;
		}
	}
}

// Add a range of numbers in a single call. (random numbers);
void Span::addManyNumbers(unsigned int nb){
	srand(time(NULL));
	if (this->_index > this->_size - 1)
		throw OutOfRange();
	std::vector<int> newVector(nb);
	std::generate(newVector.begin(), newVector.end(), rand);
	this->_store = newVector;
	this->_index = nb;	
}

// Calculate the shotest distance (span) between two elements.
int Span::shortestSpan(){
	int min;
	if (this->_size < 2)
		throw NotEnoughElements();
	std::vector<int> copy = this->_store;
	std::sort(copy.begin(), copy.end());
	min = copy[1] - copy[0];
	for(size_t i= 0; i< this->_size - 1; i++)
	{
		if ((copy[i + 1] - copy[i]) < min)
			min = copy[i + 1] - copy[i];
	}
	return (min);
}

// Calculate the longest distance (span) between two elements.
int Span::longestSpan(){
	if (this->_size < 2)
		throw NotEnoughElements();
	std::vector<int> copy = this->_store;
	std::sort(copy.begin(), copy.end());
	return (copy[this->_size - 1] - copy[0]);
}

// Print each element of the store.
void Span::print(){
	for (size_t i = 0; i < this->_size; i++)
		std::cout<<this->_store[i]<<"\n";
}