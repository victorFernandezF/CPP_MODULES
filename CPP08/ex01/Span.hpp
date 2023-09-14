/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:48:18 by victofer          #+#    #+#             */
/*   Updated: 2023/09/14 10:55:09 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <algorithm>
# include <vector>
# include "colours.h"

class Span{
	private:
		unsigned int _index;
		unsigned int _size;
		std::vector<int> _array;
	public:
		Span();
		Span(unsigned int N);	
		Span(const Span &copy);	
		Span &operator=(const Span &copy);	
		~Span();
		
		void addNumber(unsigned int nb);
		int shortestSpan();
		int longestSpan();
		void print();
		void addManyNumbers(unsigned int nb);
		int incrementer();

		
		class OutOfRange;
		class NotEnoughElements;
};


#endif
