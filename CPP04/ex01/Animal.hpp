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
#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

# define R	"\x1B[31m"
# define GR	"\x1B[90m"
# define G	"\x1B[32m"
# define BG	"\x1B[92m"
# define BB	"\x1B[94m"
# define Y	"\x1B[33m"
# define B	"\x1B[36m"
# define W	"\x1B[0m"
# define BY	"\x1B[93m"
# define BM	"\x1B[95m"
# define BR	"\x1B[0;95m"

class Animal{
	protected:
		std::string _type;
	
	public:
		Animal();	
		Animal(std::string type);
		Animal(Animal &copy);	
		Animal &operator=(const Animal &copy);	
		virtual ~Animal();
		std::string getType(void) const;
		void setType(std::string type);
		virtual void makeSound() const;
};
#endif