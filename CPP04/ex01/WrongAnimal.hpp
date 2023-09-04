/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:52:51 by victofer          #+#    #+#             */
/*   Updated: 2023/08/09 12:39:45 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>
# include "colours.h"

class WrongAnimal{
	protected:
		std::string _type;

	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal &copy);
		WrongAnimal(std::string type);
		WrongAnimal &operator=(const WrongAnimal &copy);
		virtual ~WrongAnimal();
		
		std::string getType(void) const;
		void setType(std::string type);
		
		virtual void makeSound() const; 
};
#endif