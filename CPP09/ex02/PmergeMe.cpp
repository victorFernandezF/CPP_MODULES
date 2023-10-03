/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:17:40 by victofer          #+#    #+#             */
/*   Updated: 2023/10/03 19:08:22 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
/* PmergeMe::PmergeMe(const PmergeMe &copy){}
PmergeMe &PmergeMe::operator=(const PmergeMe &copy){} */
PmergeMe::~PmergeMe(){}

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

void PmergeMe::sortVector(int nb, char **args){
	this->_checkCorrectArgs(nb, args);
	this->_checkDuplicated(nb, args);
	this->_checkInts(nb, args);
		
	if (!this->_error.empty()){
		std::cout<<BR<<"ERROR: "<<this->_error<<W<<"\n";
		return;
	}
}