/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:17:40 by victofer          #+#    #+#             */
/*   Updated: 2023/10/27 14:14:20 by victofer         ###   ########.fr       */
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
	std::vector<int> tmp;
	std::vector<int> tmp_2;
	for (size_t i = 0; i < this->_pair.size(); i++)
		if (this->_pair.at(i).first)
			this->_main.push_back(this->_pair.at(i).first);
	for (size_t i = 0; i < this->_pair.size(); i++)
		if (this->_pair.at(i).second)
			this->_pend.push_back(this->_pair.at(i).second);
 	if (this->_pend.at(0) < this->_main.at(0)){
		tmp.push_back(this->_pend.at(0));
		for (size_t i = 0; i < this->_main.size(); i++){
			tmp.push_back(this->_main.at(i));
		}
		this->_main = tmp;
		for (size_t i = 0; i < this->_pend.size() - 1; i++){
			tmp_2.push_back(this->_pend.at(i + 1));
		}
		_pend = tmp_2;
	}
}

int	PmergeMe::_notRepeat(std::vector<int> vec, int nb){
	for (size_t i = 0; i < vec.size(); i++)
		if (vec.at(i) == nb)
			return 1;
	return 0;
}

void	PmergeMe::_sortingVector(void){
	std::vector<int> order;
	std::vector<int> jacobo;
/* 	size_t	size;
	size_t	jindex;
	size_t	index;
	
	size = this->_pend.size();
	index = 3;
	jindex = this->_getJacobsthal(0);
	while (index <= size){
		order.push_back(jindex);
		jindex = this->_getJacobsthal(index);
		std::cout<<jindex<<"\n";
		index++;
	} */
	//std::vector<int> order;
	
	for (size_t i = 0; i < this->_pend.size(); i++)
		jacobo.push_back(this->_getJacobsthal(i));

	for (size_t i = 0; i < this->_pend.size(); i++){
		int j = _pend.size();
		order.push_back(jacobo.at(i));
		while (j != 0){
			if (j < jacobo.at(i) && !this->_notRepeat(order, j))
				order.push_back(j);
			j--;
		}
}
	std::cout<<"Jacobsthal sequence: \n";
	this->printVector(jacobo);
	std::cout<<"Order sequence: \n";
	this->printVector(order);
}

void PmergeMe::sortVector(int nb, char **args){
	//<std::vector<int>order;
	this->_checkCorrectArgs(nb, args);
	this->_checkDuplicated(nb, args);
	this->_checkInts(nb, args);
	this->_fillVector(nb, args);
	this->_createPairs();
	this->_sortPairs();
	this->_recursiveSort(0);
	this->_createChains();
	this->_sortingVector();
		std::cout<<"main chain:\n";
	this->printVector(this->_main);
		std::cout<<"pend chain:\n";
	this->printVector(this->_pend);
	
		
	//std::cout<<BG<<"SIZE "<<this->_size<<W<<"\n";
	if (!this->_error.empty()){
		std::cout<<BR<<"ERROR: "<<this->_error<<W<<"\n";
		return;
	}
	
}