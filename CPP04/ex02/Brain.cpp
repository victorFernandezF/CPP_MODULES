/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:34:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/16 13:14:19 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout<<"Brain constructor called"<<std::endl;
}

Brain::Brain(Brain &copy){
	if (this != &copy)
		for (size_t i = 0; i < 100; i++)
			this->_ideas[i] = copy._ideas[i];
}	

Brain &Brain::operator=(const Brain &copy){
	for (size_t i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
	return (*this);
}

Brain::~Brain(){
	std::cout<<"Brain Destructor."<<std::endl;
}

