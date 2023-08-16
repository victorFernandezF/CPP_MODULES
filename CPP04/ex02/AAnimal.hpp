/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:52:51 by victofer          #+#    #+#             */
/*   Updated: 2023/08/09 12:39:45 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <iostream>
# include "colours.h"

class Animal{
	protected:
		std::string _type;
	
	public:
		Animal();	
		Animal(std::string type);
		Animal(Animal &copy);	
		Animal &operator=(const Animal &copy);	
		virtual ~Animal() = 0;
};
#endif