/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:37:03 by victofer          #+#    #+#             */
/*   Updated: 2023/08/30 13:40:42 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"


class WrongCat : public Animal{
	private:
		Brain *_brain;

	public:
		WrongCat();	
		WrongCat(const WrongCat &copy);
		WrongCat(std::string type);
		WrongCat &operator=(const WrongCat &copy);	
		~WrongCat();
		
		void makeSound() const;
};

#endif