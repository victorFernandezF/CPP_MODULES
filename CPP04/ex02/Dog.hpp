/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:37:03 by victofer          #+#    #+#             */
/*   Updated: 2023/09/04 13:34:09 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"


class Dog : public AAnimal{
	private:
		Brain *_brain;
		
	public:
		Dog();	
		Dog(std::string type);
		Dog(const Dog &copy);	
		Dog &operator=(const Dog &copy);	
		~Dog();
		
		void makeSound() const;
};

#endif