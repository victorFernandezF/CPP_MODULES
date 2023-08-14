/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:37:03 by victofer          #+#    #+#             */
/*   Updated: 2023/08/14 19:02:14 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"


class Cat : public Animal{
	private:
		Brain *_brain;

	public:
		Cat();	
		Cat(const Cat &copy);
		Cat(std::string type);
		Cat &operator=(const Cat &copy);	
		~Cat();
		void makeSound() const;
};

#endif