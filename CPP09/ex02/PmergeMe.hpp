/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:14:23 by victofer          #+#    #+#             */
/*   Updated: 2023/10/04 19:19:39 by victofer         ###   ########.fr       */
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
		std::vector<std::pair<int, int> >_pair;
		int	_size;
		std::string _error;
		
		void	_checkCorrectArgs(int nb, char **args);
		void	_checkDuplicated(int nb, char **args);
		void	_isNumberInside(char **args, char *arg, int end);
		void 	_checkInts(int nb, char **args);
		void	_fillVector(int nb, char **args);
		void	_createPairs(void);
		



		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe();
		void sortVector(int arg, char **args);
		std::vector<int> getVector( void ) const;
		void	printVector();
		
};

#endif