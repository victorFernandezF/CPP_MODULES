/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:48:18 by victofer          #+#    #+#             */
/*   Updated: 2023/10/02 10:19:25 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

template <typename T>
void swap(T &a, T &b){
	T aux = a;
	a = b;
	b = aux; 
}

template <typename T>
T max(T a, T b){
	if (a > b)
		return a;
	return b;
}

template <typename T>
T min(T a, T b){
	if (a < b)
		return a;
	return b;
}
#endif
