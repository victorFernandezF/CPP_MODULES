/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:48:18 by victofer          #+#    #+#             */
/*   Updated: 2023/09/11 11:09:52 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <class T>
void swap(T &a, T &b){
	T aux = a;
	a = b;
	b = aux; 
}

template<class T>
void iter(T array[], int size, void (*swap)(T &a, T &b)){
	for(int i = 0; i < size - 1; i++)
		swap(array[i], array[i + 1]);
}

template<class T>
void printArray(T array[], int size, std::string status){
	std::cout<<Y<<"Printing array "<<status<<"\n";
	for(int i = 0; i < size; i++)
		std::cout<<C<<"array["<<W<<i<<C<<"] -> "<<W<<array[i]<<"\n";
}

#endif
