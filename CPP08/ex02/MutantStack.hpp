/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:48:18 by victofer          #+#    #+#             */
/*   Updated: 2023/09/18 18:28:20 by victofer         ###   ########.fr       */
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
	private:
		std::stack<T> stack;
	public:
		MutantStack(void);
		MutantStack(const MutantStack &copy);	
		~MutantStack(void);	
		MutantStack &operator=(const MutantStack &copy);	
		//Iterators();
};

#include "MutantStack.tpp"

#endif