/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:34:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/14 14:03:27 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout<<B<<"Brain constructor called"<<W<<std::endl;
}

Brain::Brain(Brain &copy){
	for()
	this->_ideas = copy._ideas;
}	

/* Brain &Brain::operator=(const Brain &copy){
	
} */

Brain::~Brain(){
	std::cout<<B<<"Brain Destructor."<<W<<std::endl;
}
