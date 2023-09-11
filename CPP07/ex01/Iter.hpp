/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:48:18 by victofer          #+#    #+#             */
/*   Updated: 2023/09/11 18:20:06 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <class T>
void addition(T &a){
	a += 5; 
}

template <class T>
void substraction(T &a){
	a -= 10; 
}

template<class T>
void iter(T array[], int size, void (*func)(T &a)){
	for(int i = 0; i < size; i++)
		func(array[i]);
}

template<class T>
void printArray(T array[], int size, std::string status){
	std::cout<<Y<<"Printing array "<<status<<"\n";
	for(int i = 0; i < size; i++)
		std::cout<<C<<"array["<<W<<i<<C<<"] -> "<<W<<array[i]<<"\n";
}

#endif
