/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:17:40 by victofer          #+#    #+#             */
/*   Updated: 2023/11/06 11:15:43 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): _size(0){}
PmergeMe::PmergeMe(const PmergeMe &copy){
	this->_vector = copy._vector;
	this->_main = copy._main;
	this->_pend = copy._pend;
	this->_pair = copy._pair;
	this->_size = copy._size;
	this->_error = copy._error;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy){
	this->_vector = copy._vector;
	this->_main = copy._main;
	this->_pend = copy._pend;
	this->_pair = copy._pair;
	this->_size = copy._size;
	this->_error = copy._error;
	return (*this);
}

PmergeMe::~PmergeMe(){}

std::vector<int> PmergeMe::getVector( void ) const {
	return this->_vector;

// P R E V I O U S   C H E C K S 
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

int PmergeMe::_isVectorSorted(std::vector<int> vec){
	std::vector<int> copy;
	for(size_t i = 0; i < vec.size(); i++){	
		copy.push_back(vec.at(i));
	}
	std::sort(copy.begin(), copy.end());
	if (copy == vec){
		std::cout<<G<<"SORTED\n";
		return 1;
	}
	std::cout<<BR<<"NOT SORTED.\n";
	return 0;
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

// V E C T O R   S T U F F 
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

void PmergeMe::_createPairsVector(void){
	int i = 0;
	int size = this->_vector.size() / 2;
	
	while (size != 0){
		this->_pair.push_back(std::make_pair(this->_vector[i],
			this->_vector[i + 1]));
		i += 2;
		size--;
	}
}

void PmergeMe::_sortPairsVector(void){
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
	std::cout<<BY<<"\n"<<msg<<W;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout<<vec[i]<<" ";
	std::cout<<"\n";
}

void	PmergeMe::_printPairs(std::string deqvec){
	if (deqvec == "vector"){
		for (size_t i = 0; i < this->_pair.size(); i++){
			std::cout<<"("<<this->_pair.at(i).first<<", "
			<<this->_pair.at(i).second<<") ";
		}
		std::cout<<std::endl;
	}
	if (deqvec == "deque"){
		for (size_t i = 0; i < this->_depair.size(); i++){
			std::cout<<"("<<this->_depair.at(i).first<<", "
			<<this->_depair.at(i).second<<") ";
		}
		std::cout<<std::endl;
	}
}

void	PmergeMe::_recursiveSortVector(std::vector<std::pair<int, int> > arr, int n){
    std::vector<std::pair<int, int> >tmp;
	(void)arr;
	if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++){
        tmp.push_back(_pair.at(i));
        tmp.push_back(_pair.at(i + 1));
		std::sort(tmp.begin(), tmp.end());
		_pair.at(i) = tmp.at(0);
		_pair.at(i + 1) = tmp.at(1);
		tmp.pop_back();
		tmp.pop_back();
	}
    _recursiveSortVector(_pair, n - 1);
}

void	PmergeMe::_createChainsVector(void){
	
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
	size_t i = 3;
	
	_positions.clear();
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
	this->_checkInts(nb, args);
	this->_checkAlreadySorted(nb, args);
	if (this->_error.empty())
		return 0;
	std::cout<<BR<<"ERROR: "<<this->_error<<W<<"\n";
	return 1;
}

int	PmergeMe::_binarySearchVector(std::vector<int>vec, int tg, int begin, int end){
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

void	PmergeMe::_insertionVector(void){
	std::vector<int>::iterator it;
	int tg;
	size_t endpos, added, pos;
	this->_getPositions();
	added = 0;
	for (it = _positions.begin(); it < _positions.end(); it++)
	{
		tg = _pend.at(*it - 1);
		endpos = *it + added;
		pos = _binarySearchVector(_main, tg, 0, endpos);
		_main.insert(_main.begin() + pos, tg);
		added++;
	}
	if (_vector.size() % 2 != 0){
		tg = _vector.at(_vector.size() - 1);
		pos = _binarySearchVector(_main, tg, 0, _main.size() - 1);
		_main.insert(_main.begin() + pos, tg);
	}
}

void PmergeMe::_printTime(std::clock_t s, std::clock_t e, std::string container){
	double milliseconds;
	milliseconds = 1000.0 * (e - s) / CLOCKS_PER_SEC;
	std::cout
		<<BY<<"\nTime to process a range of "<<BG<<this->_vector.size()
		<<BY<<" elements with "<<BM<<container<<" "<<W<<milliseconds<<" ms.\n";
}

void PmergeMe::sortVector(int nb, char **args){
	std::clock_t start;
	std::clock_t end;

	if (this->_check_errors(nb, args) != 0)
		return;
	std::cout<<BC<<"-------------- VECTOR -----------------"<<W;
	this->_fillVector(nb, args);
	this->_createPairsVector();
	this->printVector(this->_vector, "Before: ");
	start = std::clock();
	this->_sortPairsVector();
	this->_recursiveSortVector(_pair, _pair.size());
	this->_createChainsVector();
	this->_insertionVector();
	end = std::clock();
	this->printVector(this->_main, "After:  ");
	this->_printTime(start, end, "std::vector");
	std::cout<<BY<<"Status: "<<W;
	this->_isVectorSorted(_main);
	std::cout<<BC<<"--------------------------------------"<<W<<"\n\n";
}

//  DEQUE

void PmergeMe::_fillDeque(int nb, char **args){
	int i = 1;
	int tmp;
	std::string stmp;
	while (i < nb){
		stmp = args[i];
		std::istringstream(stmp) >> tmp;
		this->_deque.push_back(tmp);
		this->_size++;
		i++;
	}
}

void PmergeMe::printDeque(std::deque<int> deq, std::string msg){
	std::cout<<BY<<"\n"<<msg<<W;
	for (size_t i = 0; i < deq.size(); i++)
		std::cout<<deq.at(i)<<" ";
	std::cout<<"\n";
}

void PmergeMe::_createPairsDeque(void){
	int i = 0;
	int size = this->_deque.size() / 2;
	
	while (size != 0){
		this->_depair.push_back(std::make_pair(this->_deque.at(i),
			this->_deque.at(i + 1)));
		i += 2;
		size--;
	}
}

void PmergeMe::_sortPairsDeque(void){
	int tmp = this->_depair.at(0).first;
	
	for (size_t i = 0; i < this->_depair.size(); i++)
	{
		if (this->_depair.at(i).first < this->_depair.at(i).second){
			tmp = this->_depair.at(i).first;
			this->_depair.at(i).first = this->_depair.at(i).second;
			this->_depair.at(i).second = tmp;
		}
	}
}

void	PmergeMe::_recursiveSortDeque(std::deque<std::pair<int, int> > arr, int n){
    std::deque<std::pair<int, int> >tmp;
	(void)arr;
	if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++){
        tmp.push_back(_depair.at(i));
        tmp.push_back(_depair.at(i + 1));
		std::sort(tmp.begin(), tmp.end());
		_depair.at(i) = tmp.at(0);
		_depair.at(i + 1) = tmp.at(1);
		tmp.pop_back();
		tmp.pop_back();
	}
    _recursiveSortDeque(_depair, n - 1);
}

void	PmergeMe::_createChainsDeque(void){
	
	this->_demain.push_back(this->_depair.at(0).second);
	for (size_t i = 0; i < _depair.size(); i++){
		this->_demain.push_back(_depair.at(i).first);
		this->_depend.push_back(_depair.at(i).second);
	}
}

std::vector<int> PmergeMe::_getJacobsthalInsertDeque(void){
	std::vector<int> pos;
 	size_t	size;
	size_t	jindex;
	size_t	index;
	
	size = this->_depend.size();
	index = 3;
	jindex = this->_getJacobsthal(index);
	while (jindex < size - 1){
		pos.push_back(jindex);
		jindex = this->_getJacobsthal(index++);
	}
	return (pos);
}

void	PmergeMe::_getPositionsDeque(void){
	std::vector<int> jacobo;
	size_t val = 1;
	size_t last = 1;
	size_t pos;
	size_t i = 3;
	
	_positions.clear();
	if (_depend.size() == 0)
		return ;
	jacobo = this->_getJacobsthalInsertDeque();
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
	while (val++ < _depend.size()){
		_positions.push_back(val);
	}
}

int	PmergeMe::_binarySearchDeque(std::deque<int>deq, int tg, int begin, int end){
	int mid;
	while (begin <= end){
		mid = begin + (end - begin) / 2;
		if (tg == deq.at(mid))
			return mid;
		if (tg > deq.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (tg > deq.at(mid))
		return mid + 1;
	return mid;
}

void	PmergeMe::_insertionDeque(void){
	std::vector<int>::iterator it;
	int tg;
	size_t endpos, added, pos;
	this->_getPositionsDeque();
	added = 0;
	for (it = _positions.begin(); it < _positions.end(); it++)
	{
		tg = _depend.at(*it - 1);
		endpos = *it + added;
		pos = _binarySearchDeque(_demain, tg, 0, endpos);
		_demain.insert(_demain.begin() + pos, tg);
		added++;
	}
	if (_deque.size() % 2 != 0){
		tg = _deque.at(_deque.size() - 1);
		pos = _binarySearchDeque(_demain, tg, 0, _demain.size() - 1);
		_demain.insert(_demain.begin() + pos, tg);
	}
}

int PmergeMe::_isDequeSorted(std::deque<int> deq){
	std::deque<int> copy;
	for(size_t i = 0; i < deq.size(); i++){	
		copy.push_back(deq.at(i));
	}
	std::sort(copy.begin(), copy.end());
	if (copy == deq){
		std::cout<<G<<"SORTED\n";
		return 1;
	}
	std::cout<<BR<<"NOT SORTED.\n";
	return 0;
}

void PmergeMe::sortDeque(int nb, char **args){
	std::clock_t start;
	std::clock_t end;

	if (this->_check_errors(nb, args) != 0)
		return;
	std::cout<<BC<<"-------------- DEQUE -----------------"<<W;
 	this->_fillDeque(nb, args);
	this->_createPairsDeque();
	this->printDeque(this->_deque, "Before: ");
	start = std::clock();
	this->_sortPairsDeque();
	this->_recursiveSortDeque(_depair, _depair.size());
	this->_createChainsDeque();
	this->_insertionDeque();
	end = std::clock();
	this->printDeque(this->_demain, "After:  ");
	this->_printTime(start, end, "std::deque");
	std::cout<<BY<<"Status: "<<W;
	this->_isDequeSorted(_demain);
	std::cout<<BC<<"--------------------------------------"<<W<<"\n\n";
}
