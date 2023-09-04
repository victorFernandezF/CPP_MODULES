/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                       :+:      :+:    :+:   */
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

class AAnimal{
	protected:
		std::string _type;
	
	public:
		AAnimal();	
		AAnimal(std::string type);
		AAnimal(AAnimal &copy);	
		AAnimal &operator=(const AAnimal &copy);
		virtual ~AAnimal();
				
		std::string getType(void) const;
		void setType(std::string type);
		
		virtual void makeSound() const = 0;
};
#endif