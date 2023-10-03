/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:14:23 by victofer          #+#    #+#             */
/*   Updated: 2023/10/03 19:21:25 by victofer         ###   ########.fr       */
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
		std::string _error;
		void	_checkCorrectArgs(int nb, char **args);
		void	_checkDuplicated(int nb, char **args);
		void	_isNumberInside(char **args, char *arg, int end);
		void 	_checkInts(int nb, char **args);
		void	_fillVector(int nb, char **args);



		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe();
		void sortVector(int arg, char **args);
		std::vector<int> getVector( void ) const;
		
};

#endif