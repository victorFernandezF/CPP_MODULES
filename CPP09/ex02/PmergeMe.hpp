/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:14:23 by victofer          #+#    #+#             */
/*   Updated: 2023/11/06 12:43:44 by victofer         ###   ########.fr       */
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
		std::vector<std::pair<int, int> >_pair;
		std::vector<int>_main;
		std::vector<int>_pend;
		
		std::deque<int>_deque;
		std::deque<std::pair<int, int> >_depair;
		std::deque<int>_demain;
		std::deque<int>_depend;

		std::vector<int>_positions;
		std::vector<int>_jacobsthal;
		std::string _error;
		int	_size;
		
		// G E N E R A L
		int		_check_errors(int nb, char **args);
		void	_checkCorrectArgs(int nb, char **args);
		void 	_checkInts(int nb, char **args);
		void	_checkAlreadySorted(int nb, char **args);
		int		_getJacobsthal(int n);
		void	_printPairs(std::string deqVec);
		void	_getJacobsthalInsert(std::string cont);
		void	_printTime(std::clock_t s, std::clock_t e, char cont);
		
		// V E C T O R
		void	_vectorFill(int nb, char **args);
		void	_vectorGetPositions(void);
		void	_vectorCreatePairs(void);
		void	_vectorSortPairs(void);
		void	_vectorRecursiveSort(int n);
		void	_vectorCreateChains(void);
		int		_vectorBinarySearch(int tg, int begin, int end);	
		void	_vectorInsertion(void);
		int		_isVectorSorted(std::vector<int> vec);
		
		// D E Q U E
		void	_dequeFill(int nb, char **args);
		void	_dequeCreatePairs(void);
		void	_dequeSortPairs(void);
		void	_dequeRecursiveSort(int n);
		void	_dequeCreateChains(void);
		void	_dequeGetPositions(void);
		int		_dequeBinarySearch(int tg, int begin, int end);	
		void	_dequeInsertion(void);
		int		_isDequeSorted(std::deque<int> deq);
	
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe();
		
		void	sortVector(int arg, char **args);
		void	sortDeque(int arg, char **args);
		void	printVector(std::vector<int> vec, std::string msg);
		void	printDeque(std::deque<int> deq, std::string msg);
};

#endif