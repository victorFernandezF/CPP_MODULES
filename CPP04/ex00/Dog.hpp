/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:37:03 by victofer          #+#    #+#             */
/*   Updated: 2023/08/30 13:39:54 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
# include "Animal.hpp"


class Dog : public Animal{
	public:
		Dog();	
		Dog(std::string type);
		Dog(Dog &copy);	
		Dog &operator=(const Dog &copy);	
		~Dog();
		
		void makeSound() const;
};

#endif