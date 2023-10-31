/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:17:40 by victofer          #+#    #+#             */
/*   Updated: 2023/10/31 19:01:33 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): _size(0){}
//PmergeMe::PmergeMe(const PmergeMe &copy){}
//PmergeMe &PmergeMe::operator=(const PmergeMe &copy){}
PmergeMe::~PmergeMe(){}

std::vector<int> PmergeMe::getVector( void ) const {
	return this->_vector;
}

void PmergeMe::_checkCorrectArgs(int nb, char **args){
	int i = 0;
	int j;
	if (nb < 2)
		this->_error = "Too few arguments.";
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

void PmergeMe::_checkAlreadySorted(int nb, char **args){
	int i = 1;
	int tmp;
	int size;
	size = 0;
	std::vector<int> vec;
	std::vector<int> copy;
	std::string stmp;
	while (i < nb){
		stmp = args[i];
		std::istringstream(stmp) >> tmp;
		vec.push_back(tmp);
		size++;
		i++;
	}
	copy = vec;
	std::sort(copy.begin(), copy.end());
	if (copy == vec)
		this->_error = "Already sorted.";
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

void PmergeMe::printVector(void){
	for (size_t i = 0; i < this->_vector.size(); i++)
		std::cout<<this->_vector.at(i)<<" ";
	std::cout<<"\n\n";
}

void PmergeMe::printVector(std::vector<int> vec, std::string msg){
	std::cout<<msg;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout<<vec[i]<<" ";
	std::cout<<"\n";
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
	
	this->_main.push_back(this->_pair.at(0).second);
	for (size_t i = 0; i < _pair.size(); i++){
		this->_main.push_back(_pair.at(i).first);
		this->_pend.push_back(_pair.at(i).second);
	}
}

int	PmergeMe::_notRepeat(std::vector<int> vec, int nb){
	for (size_t i = 0; i < vec.size(); i++)
		if (vec.at(i) == nb)
			return 1;
	return 0;
}

std::vector<int> PmergeMe::_getJacobsthalInsert(void){
	std::vector<int> pos;
 	size_t	size;
	size_t	jindex;
	size_t	index;
	
	size = this->_pend.size();
	index = 3;
	jindex = this->_getJacobsthal(index);
	while (jindex < size - 1){
		pos.push_back(jindex);
		jindex = this->_getJacobsthal(index++);
	}
	return (pos);
}

void	PmergeMe::_getPositions(void){
	std::vector<int> jacobo;
	size_t val = 1;
	size_t last = 1;
	size_t pos;
	size_t i = 0;
	
	if (_pend.size() == 0)
		return ;
	jacobo = this->_getJacobsthalInsert();
	while (i < jacobo.size())
	{
		val = jacobo.at(i);
		_positions.push_back(val);
		pos = val -1;
		while (pos > last){
			_positions.push_back(pos);
			pos--;
		}
		last = val; 
		i++;
	}
	while (val++ < _pend.size()){
		_positions.push_back(val);
	}
}


int PmergeMe::_check_errors(int nb, char **args){
	this->_checkCorrectArgs(nb, args);
	this->_checkDuplicated(nb, args);
	this->_checkInts(nb, args);
	this->_checkAlreadySorted(nb, args);
	if (this->_error.empty())
		return 0;
	std::cout<<BR<<"ERROR: "<<this->_error<<W<<"\n";
	return 1;
}

int	PmergeMe::_binarySearch(std::vector<int>vec, int tg, int begin, int end){
	int mid;
	while (begin <= end){
		mid = begin + (end - begin) / 2;
		if (tg == vec.at(mid))
			return mid;
		if (tg > vec.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (tg > vec.at(mid))
		return mid + 1;
	return mid;
}

void	PmergeMe::_insertion(void){
	std::vector<int>::iterator it;
	int tg;
	size_t endpos, added, pos;
	this->_getPositions();
	added = 0;
	for (it = _positions.begin(); it < _positions.end(); it++)
	{
		tg = _pend.at(*it - 1);
		endpos = *it + added;
		pos = _binarySearch(_main, tg, 0, endpos);
		_main.insert(_main.begin() + pos, tg);
		added++;
	}
	if (_vector.size() % 2 != 0){
		tg = _vector.at(_vector.size() - 1);
		pos = _binarySearch(_main, tg, 0, _main.size() - 1);
		_main.insert(_main.begin() + pos, tg);
	}
}

void PmergeMe::sortVector(int nb, char **args){
	std::clock_t first;
	std::clock_t last;
	double milliseconds;
	if (this->_check_errors(nb, args) != 0)
		return;
	this->_fillVector(nb, args);
	this->_createPairs();
	this->printVector(this->_vector, "Before: ");
	first = std::clock();
	this->_sortPairs();
	this->_recursiveSort(0);
	this->_createChains();
	this->_insertion();
	last = std::clock();
	milliseconds = 1000.0 * (last - first) / CLOCKS_PER_SEC;
	this->printVector(this->_main, "After: ");
	std::cout
		<<"Time to process a range of "<<this->_vector.size()
		<<" elements with std::vector: "<<milliseconds<<" ms.\n";
}