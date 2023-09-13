/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:48:18 by victofer          #+#    #+#             */
/*   Updated: 2023/09/13 13:49:20 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <algorithm>
# include <vector>
# include <array>

class NoOcurrenceFound: public std::exception{
	public: virtual char *what() const throw(){
		return ((char *)"Number not found in the container.");
	}
};

template<typename T>
void easyFind(T container, int nb){
	typename T::iterator it;
	it = std::find(container.begin(), container.end() , nb);
	if (it == container.end())
		throw NoOcurrenceFound();
	std::cout<<"First occurrence found "<<*it<<"\n";
}


#endif
