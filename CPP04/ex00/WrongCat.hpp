/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:37:03 by victofer          #+#    #+#             */
/*   Updated: 2023/08/10 19:42:50 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include <iostream>
# include "WrongAnimal.hpp"


class WrongCat : public Animal{
	public:
		WrongCat();	
		WrongCat(std::string type);
		WrongCat(WrongCat &copy);	
		WrongCat &operator=(const WrongCat &copy);	
		~WrongCat();
		void makeSound();
};

#endif