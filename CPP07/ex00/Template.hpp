/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:48:18 by victofer          #+#    #+#             */
/*   Updated: 2023/09/07 19:10:39 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <class T>
void swap(T &a, T &b){
	T aux = a;
	a = b;
	b = aux; 
}

template <class T>
T max(T a, T b){
	if (a > b)
		return a;
	return b;
}

template <class T>
T min(T a, T b){
	if (a < b)
		return a;
	return b;
}
