/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:48:18 by victofer          #+#    #+#             */
/*   Updated: 2023/09/13 10:15:18 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <stdexcept>

template<class T>
class Array{
	private:
		T *_array;
		unsigned int _size;
		
	public:
		Array(void);
		Array(unsigned int n);
		Array (const Array<T> &copy);
		Array &operator=(const Array &copy);
		T &operator[](unsigned int index);
		~Array();	
		T size() const;
		void print(std::string name);
		void edit();
		class outOfBounds;
};

# include "Array.tpp"

#endif
