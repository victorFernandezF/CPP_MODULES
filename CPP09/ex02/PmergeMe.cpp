/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:17:40 by victofer          #+#    #+#             */
/*   Updated: 2023/10/26 19:19:08 by victofer         ###   ########.fr       */
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
	int i = 0;
	int size = this->_vector.size() / 2;
	
	while (size != 0){
		this->_pair.push_back(std::make_pair(this->_vector[i],
			this->_vector[i + 1]));
		i += 2;
		size--;
	}
}

void PmergeMe::_sortPairs(void){
	int tmp = this->_pair.at(0).first;
	
	for (size_t i = 0; i < this->_pair.size(); i++)
	{
		if (this->_pair.at(i).first < this->_pair.at(i).second){
			tmp = this->_pair.at(i).first;
			this->_pair.at(i).first = this->_pair.at(i).second;
			this->_pair.at(i).second = tmp;
		}
	}
}

int PmergeMe::_getJacobsthal(int n){
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return (this->_getJacobsthal(n - 1) + 2 * this->_getJacobsthal(n - 2));
}

void PmergeMe::printVector(std::vector<int> vec){
	for (size_t i = 0; i < vec.size(); i++)
		std::cout<<vec[i]<<" ";
	std::cout<<"\n\n";
}


void	PmergeMe::_printPairs(){
		for (size_t i = 0; i < this->_pair.size(); i++){
		std::cout<<"("<<this->_pair.at(i).first<<", "
		<<this->_pair.at(i).second<<") \n";
	}
}

void	PmergeMe::_recursiveSort(size_t it){
	std::pair<int, int> tmp = this->_pair.at(it);
	this->_pair.at(it) = this->_pair.at(it + 1);
	this->_pair.at(it + 1) = tmp;
	if (it == this->_pair.size())
		return;
	for (size_t i = 0; i < this->_pair.size() - 1; i++){
		if (this->_pair.at(i).first > this->_pair.at(i + 1).first)
			this->_recursiveSort(i);
	}

}
void	PmergeMe::_createChains(void){
	int i = 0;
	for (size_t i = 0; i < this->_pair.size(); i++)
		if (this->_pair.at(i).first)
			this->_main.push_back(this->_pair.at(i).first);
	for (size_t i = 0; i < this->_pair.size(); i++)
		if (this->_pair.at(i).second)
			this->_pend.push_back(this->_pair.at(i).second);
}

void PmergeMe::sortVector(int nb, char **args){
	this->_checkCorrectArgs(nb, args);
	this->_checkDuplicated(nb, args);
	this->_checkInts(nb, args);
	this->_fillVector(nb, args);
	this->_createPairs();
	this->_sortPairs();
	this->_recursiveSort(0);
	this->_createChains();
	this->printVector(this->_main);
	this->printVector(this->_pend);
	
		
	//std::cout<<BG<<"SIZE "<<this->_size<<W<<"\n";
	if (!this->_error.empty()){
		std::cout<<BR<<"ERROR: "<<this->_error<<W<<"\n";
		return;
	}
	
}