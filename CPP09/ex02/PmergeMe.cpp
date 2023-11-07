/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:17:40 by victofer          #+#    #+#             */
/*   Updated: 2023/11/07 10:49:27 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

class PmergeMe::InvalidException: public std::exception{
	public: virtual char *what() const throw(){
		return ((char *)"Invalid input. (Only positive integers allowed).");
	}
};
class PmergeMe::BadCantArguments: public std::exception{
	public: virtual char *what() const throw(){
		return ((char *)"Incorrect number of arguments. (At least two needed)");
	}
};

class PmergeMe::OutOfIntLimits: public std::exception{
	public: virtual char *what() const throw(){
		return ((char *)"Some input is out of the integer's limits. (-2147483648, 2147483647)");
	}
};

class PmergeMe::AlreadySorted: public std::exception{
	public: virtual char *what() const throw(){
		return ((char *)"Input is already sorted.");
	}
};

// C O N S T R U C T O R S
PmergeMe::PmergeMe(): _vecSize(0), _deqSize(0){}
PmergeMe::PmergeMe(const PmergeMe &copy){
	this->_vector = copy._vector;
	this->_vecPair = copy._vecPair;
	this->_vectorMain = copy._vectorMain;
	this->_vectorPend = copy._vectorPend;
	this->_jacobsthal = copy._jacobsthal;
	this->_deque = copy._deque;
	this->_deqPair = copy._deqPair;
	this->_dequeMain = copy._dequeMain;
	this->_dequePend = copy._dequePend;
	this->_vecSize = copy._vecSize;
	this->_deqSize = copy._deqSize;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy){
	this->_vector = copy._vector;
	this->_vecPair = copy._vecPair;
	this->_vectorMain = copy._vectorMain;
	this->_vectorPend = copy._vectorPend;
	this->_jacobsthal = copy._jacobsthal;
	this->_deque = copy._deque;
	this->_deqPair = copy._deqPair;
	this->_dequeMain = copy._dequeMain;
	this->_dequePend = copy._dequePend;
	this->_vecSize = copy._vecSize;
	this->_deqSize = copy._deqSize;
	return (*this);
}

PmergeMe::~PmergeMe(){}

// P R E V I O U S   C H E C K S 
void PmergeMe::_checkCorrectArgs(int nb, char **args){
	int i = 0;
	int j;
	while (++i < nb){
		j = -1;
		while (args[i][++j])
			if (!(args[i][j] >= '0' && args[i][j] <= '9'))
				throw InvalidException();
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
	int			i = 0;
	double		tmp;
	std::string	string;

	while (++i < nb){
		string = args[i];
		std::istringstream(string) >> tmp;
		if (tmp >= 2147483647 || tmp <= -2147483648)
			throw OutOfIntLimits();
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
		throw AlreadySorted();
}


// ----- V E C T O R   S T U F F ----- 
void PmergeMe::_vectorFill(int nb, char **args){
	int i = 1;
	int tmp;
	std::string stmp;
	while (i < nb){
		stmp = args[i];
		std::istringstream(stmp) >> tmp;
		this->_vector.push_back(tmp);
		this->_vecSize++;
		i++;
	}
}

void PmergeMe::_vectorCreatePairs(void){
	int i = 0;
	int size = this->_vector.size() / 2;
	
	while (size != 0){
		this->_vecPair.push_back(std::make_pair(this->_vector.at(i),
			this->_vector[i + 1]));
		i += 2;
		size--;
	}
}

void PmergeMe::_vectorSortPairs(void){
	int tmp = this->_vecPair.at(0).first;
	
	for (size_t i = 0; i < this->_vecPair.size(); i++)
	{
		if (this->_vecPair.at(i).first < this->_vecPair.at(i).second){
			tmp = this->_vecPair.at(i).first;
			this->_vecPair.at(i).first = this->_vecPair.at(i).second;
			this->_vecPair.at(i).second = tmp;
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

void PmergeMe::printVector(std::vector<int> vec, std::string msg){
	std::cout<<BY<<"\n"<<msg<<W;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout<<vec.at(i)<<" ";
	std::cout<<"\n";
}

void	PmergeMe::_printPairs(std::string deqvec){
	if (deqvec == "vector"){
		for (size_t i = 0; i < this->_vecPair.size(); i++){
			std::cout<<"("<<this->_vecPair.at(i).first<<", "
			<<this->_vecPair.at(i).second<<") ";
		}
		std::cout<<std::endl;
	}
	if (deqvec == "deque"){
		for (size_t i = 0; i < this->_deqPair.size(); i++){
			std::cout<<"("<<this->_deqPair.at(i).first<<", "
			<<this->_deqPair.at(i).second<<") ";
		}
		std::cout<<std::endl;
	}
}

void	PmergeMe::_vectorRecursiveSort(int n){
    std::vector<std::pair<int, int> >tmp;
	if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++){
        tmp.push_back(_vecPair.at(i));
        tmp.push_back(_vecPair.at(i + 1));
		std::sort(tmp.begin(), tmp.end());
		_vecPair.at(i) = tmp.at(0);
		_vecPair.at(i + 1) = tmp.at(1);
		tmp.pop_back();
		tmp.pop_back();
	}
    this->_vectorRecursiveSort(n - 1);
}

void	PmergeMe::_vectorCreateChains(void){
	
	this->_vectorMain.push_back(this->_vecPair.at(0).second);
	for (size_t i = 0; i < this->_vecPair.size(); i++){
		this->_vectorMain.push_back(_vecPair.at(i).first);
		this->_vectorPend.push_back(_vecPair.at(i).second);
	}
}

void PmergeMe::_getJacobsthalInsert(std::string cont){
 	size_t	size;
	size_t	jindex;
	size_t	index;
	
	this->_jacobsthal.clear();	
	size = this->_vectorPend.size();
	if (cont == "deque")
		size = this->_dequePend.size();
	index = 3;
	jindex = this->_getJacobsthal(index);
	while (jindex < size - 1){
		this->_jacobsthal.push_back(jindex);
		jindex = this->_getJacobsthal(index++);
	}
}

void	PmergeMe::_vectorGetPositions(void){
	size_t val = 1;
	size_t last = 1;
	size_t pos;
	size_t i = 3;
	
	_positions.clear();
	if (_vectorPend.size() == 0)
		return ;
	this->_getJacobsthalInsert("vector");
	while (i < this->_jacobsthal.size())
	{
		val = this->_jacobsthal.at(i);
		_positions.push_back(val);
		pos = val -1;
		while (pos > last){
			_positions.push_back(pos);
			pos--;
		}
		last = val; 
		i++;
	}
	while (val++ < this->_vectorPend.size()){
		_positions.push_back(val);
	}
}

void PmergeMe::_check_errors(int nb, char **args){
	if (nb < 3)
		throw BadCantArguments();
	this->_checkCorrectArgs(nb, args);
	this->_checkInts(nb, args);
	this->_checkAlreadySorted(nb, args);
}

int	PmergeMe::_vectorBinarySearch(int tg, int begin, int end){
	int mid;
	while (begin <= end){
		mid = begin + (end - begin) / 2;
		if (tg == this->_vectorMain.at(mid))
			return mid;
		if (tg > this->_vectorMain.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (tg > this->_vectorMain.at(mid))
		return mid + 1;
	return mid;
}

void	PmergeMe::_vectorInsertion(void){
	std::vector<int>::iterator it;
	int tg;
	size_t endpos, added, pos;
	this->_vectorGetPositions();
	added = 0;
	for (it = this->_positions.begin(); it < this->_positions.end(); it++)
	{
		tg = this->_vectorPend.at(*it - 1);
		endpos = *it + added;
		pos = this->_vectorBinarySearch(tg, 0, endpos);
		this->_vectorMain.insert(this->_vectorMain.begin() + pos, tg);
		added++;
	}
	if (_vector.size() % 2 != 0){
		tg = this->_vector.at(this->_vector.size() - 1);
		pos = this->_vectorBinarySearch(tg, 0, this->_vectorMain.size() - 1);
		this->_vectorMain.insert(this->_vectorMain.begin() + pos, tg);
	}
}

void PmergeMe::_printTime(std::clock_t s, std::clock_t e, char cont){
	double		milliseconds;
	int			size;
	std::string	container;
	
	size = this->_vecSize;
	container = "std::vector ";
	if (cont == 'D'){
		container = "std::deque ";
		size = this->_deqSize;
	}
	milliseconds = 1000.0 * (e - s) / CLOCKS_PER_SEC;
	std::cout
		<<BY<<"\nTime to process a range of "<<BG<<size
		<<BY<<" elements with "<<BM<<container<<W<<milliseconds<<" ms.\n";
}

void PmergeMe::sortVector(int nb, char **args){
	std::clock_t start;
	std::clock_t end;

	this->_check_errors(nb, args);
	this->_clearDatas();
	std::cout<<BC<<"-------------- VECTOR -----------------"<<W;
	this->_vectorFill(nb, args);
	this->_vectorCreatePairs();
	this->printVector(this->_vector, "Before: ");
	start = std::clock();
	this->_vectorSortPairs();
	this->_vectorRecursiveSort(_vecPair.size());
	this->_vectorCreateChains();
	this->_vectorInsertion();
	end = std::clock();
	this->printVector(this->_vectorMain, "After:  ");
	this->_printTime(start, end, 'V');
	std::cout<<BY<<"Status: "<<W;
	this->_isVectorSorted(_vectorMain);
	std::cout<<BC<<"--------------------------------------"<<W<<"\n\n";
}

// ----- D E Q U E   S T U F F  -----

void PmergeMe::_dequeFill(int nb, char **args){
	int i = 1;
	int tmp;
	std::string stmp;
	while (i < nb){
		stmp = args[i];
		std::istringstream(stmp) >> tmp;
		this->_deque.push_back(tmp);
		this->_deqSize++;
		i++;
	}
}

void PmergeMe::printDeque(std::deque<int> deq, std::string msg){
	std::cout<<BY<<"\n"<<msg<<W;
	for (size_t i = 0; i < deq.size(); i++)
		std::cout<<deq.at(i)<<" ";
	std::cout<<"\n";
}

void PmergeMe::_dequeCreatePairs(void){
	int i = 0;
	int size = this->_deque.size() / 2;
	
	while (size != 0){
		this->_deqPair.push_back(std::make_pair(this->_deque.at(i),
			this->_deque.at(i + 1)));
		i += 2;
		size--;
	}
}

void PmergeMe::_dequeSortPairs(void){
	int tmp = this->_deqPair.at(0).first;
	
	for (size_t i = 0; i < this->_deqPair.size(); i++)
	{
		if (this->_deqPair.at(i).first < this->_deqPair.at(i).second){
			tmp = this->_deqPair.at(i).first;
			this->_deqPair.at(i).first = this->_deqPair.at(i).second;
			this->_deqPair.at(i).second = tmp;
		}
	}
}

void	PmergeMe::_dequeRecursiveSort(int n){
    std::deque<std::pair<int, int> >tmp;
	if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++){
        tmp.push_back(_deqPair.at(i));
        tmp.push_back(_deqPair.at(i + 1));
		std::sort(tmp.begin(), tmp.end());
		_deqPair.at(i) = tmp.at(0);
		_deqPair.at(i + 1) = tmp.at(1);
		tmp.pop_back();
		tmp.pop_back();
	}
    this->_dequeRecursiveSort(n - 1);
}

void	PmergeMe::_dequeCreateChains(void){
	
	this->_dequeMain.push_back(this->_deqPair.at(0).second);
	for (size_t i = 0; i < this->_deqPair.size(); i++){
		this->_dequeMain.push_back(this->_deqPair.at(i).first);
		this->_dequePend.push_back(this->_deqPair.at(i).second);
	}
}

void	PmergeMe::_dequeGetPositions(void){
	size_t val = 1;
	size_t last = 1;
	size_t pos;
	size_t i = 3;
	
	this->_positions.clear();
	if (this->_dequePend.size() == 0)
		return ;
	this->_getJacobsthalInsert("deque");
	while (i < this->_jacobsthal.size())
	{
		val = this->_jacobsthal.at(i);
		this->_positions.push_back(val);
		pos = val -1;
		while (pos > last){
			this->_positions.push_back(pos);
			pos--;
		}
		last = val; 
		i++;
	}
	while (val++ < this->_dequePend.size()){
		this->_positions.push_back(val);
	}
}

int	PmergeMe::_dequeBinarySearch(int tg, int begin, int end){
	int mid;
	while (begin <= end){
		mid = begin + (end - begin) / 2;
		if (tg == this->_dequeMain.at(mid))
			return mid;
		if (tg > this->_dequeMain.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (tg > this->_dequeMain.at(mid))
		return mid + 1;
	return mid;
}

void	PmergeMe::_dequeInsertion(void){
	std::vector<int>::iterator it;
	int tg;
	size_t endpos, added, pos;
	this->_dequeGetPositions();
	added = 0;
	for (it = this->_positions.begin(); it < this->_positions.end(); it++)
	{
		tg = this->_dequePend.at(*it - 1);
		endpos = *it + added;
		pos = this->_dequeBinarySearch(tg, 0, endpos);
		this->_dequeMain.insert(this->_dequeMain.begin() + pos, tg);
		added++;
	}
	if (this->_deque.size() % 2 != 0){
		tg =this->_deque.at(_deque.size() - 1);
		pos = this->_dequeBinarySearch(tg, 0, this->_dequeMain.size() - 1);
		this->_dequeMain.insert(this->_dequeMain.begin() + pos, tg);
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

void PmergeMe::_clearDatas(){
	this->_positions.clear();
	this->_jacobsthal.clear();
	this->_vector.clear();
	this->_vecPair.clear();
	this->_vectorMain.clear();
	this->_vectorPend.clear();
	this->_deque.clear();
	this->_deqPair.clear();
	this->_dequeMain.clear();
	this->_dequePend.clear();
	this->_vecSize = 0;
	this->_deqSize = 0;
}

void PmergeMe::sortDeque(int nb, char **args){
	std::clock_t start;
	std::clock_t end;

	this->_check_errors(nb, args);
	std::cout<<BC<<"-------------- DEQUE -----------------"<<W;
	this->_clearDatas();
	this->_dequeFill(nb, args);
	this->_dequeCreatePairs();
	this->printDeque(this->_deque, "Before: ");
	start = std::clock();
	this->_dequeSortPairs();
	this->_dequeRecursiveSort(_deqPair.size());
	this->_dequeCreateChains();
	this->_dequeInsertion();
	end = std::clock();
	this->printDeque(this->_dequeMain, "After:  ");
	this->_printTime(start, end, 'D');
	std::cout<<BY<<"Status: "<<W;
	this->_isDequeSorted(_dequeMain);
	std::cout<<BC<<"--------------------------------------"<<W<<"\n\n";
}
