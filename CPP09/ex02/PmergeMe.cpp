/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:17:40 by victofer          #+#    #+#             */
/*   Updated: 2023/10/02 19:31:34 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
/* PmergeMe::PmergeMe(const PmergeMe &copy){}
PmergeMe &PmergeMe::operator=(const PmergeMe &copy){} */
PmergeMe::~PmergeMe(){}

int PmergeMe::_checkCorrectArgs(int nb, char **args){
	int i = -1;
	int j;
	while (++i < nb){
		j = -1;
		while (args[i][++j])
			if (!(args[i][j] >= '0' && args[i][j] <= '9'))
				return (1);
	}
	return 0;
}

void PmergeMe::sortVector(int nb, char **args){
	if (this->_checkCorrectArgs(nb, args) != 0)
		std::cout<<"ERROR\n";
}