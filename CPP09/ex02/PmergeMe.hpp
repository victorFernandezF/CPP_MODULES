/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:14:23 by victofer          #+#    #+#             */
/*   Updated: 2023/11/06 11:14:00 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <ctime>
# include <chrono>
# include <fstream>
# include <string>
# include <sstream>
# include <vector>
# include <deque>
# include <unistd.h>
# include "colours.h"

class PmergeMe{
	private:
		std::vector<int>_vector;
		std::deque<int>_deque;
		std::deque<std::pair<int, int> >_depair;
		std::deque<int>_demain;
		std::deque<int>_depend;
		std::deque<int>_dequePositions;
		
		std::vector<int>_main;
		std::vector<int>_pend;
		std::vector<int>_positions;
		std::vector<std::pair<int, int> >_pair;
		std::string _error;
		int	_size;
		
		//vector
		int		_check_errors(int nb, char **args);
		void	_checkCorrectArgs(int nb, char **args);
		void 	_checkInts(int nb, char **args);
		void	_checkAlreadySorted(int nb, char **args);
		std::vector<int> _getJacobsthalInsert(void);
		int		_getJacobsthal(int n);
		void	_getPositions(void);
		void	_printTime(std::clock_t f, std::clock_t l, std::string container);
		void	_printPairs(std::string deqVec);
		int		_notRepeat(std::vector<int> vec, int nb);
		
		// vector
		void	_fillVector(int nb, char **args);
		void	_createPairsVector(void);
		void	_sortPairsVector(void);
		void	_recursiveSortVector(std::vector<std::pair<int, int> > arr, int n);
		void	_createChainsVector(void);
		int		_isVectorSorted(std::vector<int> vec);
		int		_binarySearchVector(std::vector<int>vec, int tg, int begin, int end);	
		void	_insertionVector(void);
		
		// Deque
		void	_fillDeque(int nb, char **args);
		void	_createPairsDeque(void);
		void	_sortPairsDeque(void);
		void	_recursiveSortDeque(std::deque<std::pair<int, int> > arr, int n);
		void	_createChainsDeque(void);
		void	_getPositionsDeque(void);
		int		_binarySearchDeque(std::deque<int>deq, int tg, int begin, int end);	
		void	_insertionDeque(void);
		int		_isDequeSorted(std::deque<int> deq);
		std::vector<int> _getJacobsthalInsertDeque(void);
	
	
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe();
		
		void sortVector(int arg, char **args);
		void sortDeque(int arg, char **args);
		std::vector<int> getVector( void ) const;
		void printVector(std::vector<int> vec, std::string msg);
		void printDeque(std::deque<int> deq, std::string msg);
		void printVector(void);
};

#endif