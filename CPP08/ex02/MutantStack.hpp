/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:48:18 by victofer          #+#    #+#             */
/*   Updated: 2023/09/19 19:09:54 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <algorithm>
# include <stack>
# include "colours.h"

template<class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void){};
		MutantStack(const MutantStack &copy){
			this = copy;
		};	
		~MutantStack(void){};	
		MutantStack &operator=(const MutantStack &copy){
			this = copy;
			return (*this);
		};	
		typedef typename std::deque<T>::iterator iterator;
		iterator begin(){ return std::stack<T>::c.begin(); };
		iterator end(){ return std::stack<T>::c.end(); };
};

#endif