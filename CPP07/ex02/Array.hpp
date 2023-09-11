/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:48:18 by victofer          #+#    #+#             */
/*   Updated: 2023/09/11 18:57:40 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template<class T>
class Array{
	private:
		T _array[];
	public:
		Array();
		Array(unsigned int n){
			for(unsigned int i = 0; i < n; i++){
				this->_array[i] = 0;
			}
		};
		Array (const Array<T> &copy);
		T &operator=(const Array<T> &copy);
		~Array(){};	
		T size(){};
};

#endif
