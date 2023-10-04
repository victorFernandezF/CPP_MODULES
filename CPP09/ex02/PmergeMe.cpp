/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:17:40 by victofer          #+#    #+#             */
/*   Updated: 2023/10/04 19:20:09 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): _size(0){}
/* PmergeMe::PmergeMe(const PmergeMe &copy){}
PmergeMe &PmergeMe::operator=(const PmergeMe &copy){} */
PmergeMe::~PmergeMe(){}


std::vector<int> PmergeMe::getVector( void ) const {
	return this->_vector;
}



void PmergeMe::_checkCorrectArgs(int nb, char **args){
	int i = 0;
	int j;
	while (++i < nb){
		j = -1;
		while (args[i][++j])
			if (!(args[i][j] >= '0' && args[i][j] <= '9'))
				this->_error = "Invalid input.";
	}
}


void PmergeMe::_isNumberInside(char **args, char *arg, int end){
	int i = 0;
	while (i < end){
		if (strtod(args[i], NULL) == strtod(arg, NULL))
			this->_error = "Duplicated numbers.";
		i++;
	}
}

void PmergeMe::_checkInts(int nb, char **args){
	int i = 0;
	double tmp;

	while (i < nb){
		tmp = strtod(args[i], NULL);
		if (tmp >= 2147483647 || tmp <= -2147483648)
			this->_error = "Out of the limits of integer.";
		i++;
	}
}

void PmergeMe::_checkDuplicated(int nb, char **args){
	int i = 0;
	while (++i < nb)
		 this->_isNumberInside(args, args[i], i);
}

void PmergeMe::_fillVector(int nb, char **args){
	int i = 1;
	int tmp;
	std::string stmp;
	while (i < nb){
		stmp = args[i];
		std::istringstream(stmp) >> tmp;
		this->_vector.push_back(tmp);
		this->_size++;
		i++;
	}
}

void PmergeMe::_createPairs(void){
	int i = 1;
	int size = this->_vector.size() / 2;
	
	while (size != 0){
		this->_pair.push_back(std::make_pair(this->_vector[i],
			this->_vector[i + 1]));
		i += 2;
		size--;
	}
}

void PmergeMe::printVector(){
	int i = -1;
	while (++i < this->_size)
		std::cout<<this->_vector[i]<<" ";
	std::cout<<"\n";
	
}

void PmergeMe::sortVector(int nb, char **args){
	this->_checkCorrectArgs(nb, args);
	this->_checkDuplicated(nb, args);
	this->_checkInts(nb, args);
	this->_fillVector(nb, args);
	this->_createPairs();
	
	std::cout<<BG<<"SIZE "<<this->_size<<W<<"\n";
	if (!this->_error.empty()){
		std::cout<<BR<<"ERROR: "<<this->_error<<W<<"\n";
		return;
	}
	
}