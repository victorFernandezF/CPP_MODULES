/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:14:23 by victofer          #+#    #+#             */
/*   Updated: 2023/10/30 18:22:31 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <fstream>
# include <string>
# include <sstream>
# include <vector>
# include "colours.h"

class PmergeMe{
	private:
		std::vector<int>_vector;
		std::vector<int>_main;
		std::vector<int>_pend;
		std::vector<int>_positions;
		std::vector<std::pair<int, int> >_pair;
		std::string _error;
		int	_size;
		
		int		_check_errors(int nb, char **args);
		void	_checkCorrectArgs(int nb, char **args);
		void	_checkDuplicated(int nb, char **args);
		void	_isNumberInside(char **args, char *arg, int end);
		void 	_checkInts(int nb, char **args);
		void	_checkAlreadySorted(int nb, char **args);
		void	_fillVector(int nb, char **args);
		void	_createPairs(void);
		void	_sortPairs(void);
		int		_getJacobsthal(int n);
		void	_printPairs(void);
		void	_recursiveSort(size_t i);
		void	_merge(std::vector <std::pair<int, int> > &arr, int begin, int mid, int end);
		void	_createChains(void);
		void	_getPositions(void);
		std::vector<int> _getJacobsthalInsert(void);
		int		_notRepeat(std::vector<int> vec, int nb);
		int		_binarySearch(std::vector<int>vec, int tg, int begin, int end);	
		void	_insertion(void);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe();
		void sortVector(int arg, char **args);
		std::vector<int> getVector( void ) const;
		void printVector(std::vector<int> vec);
		
};

#endif