/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:34:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/14 12:40:41 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout<<B<<"Brain constructor called"<<W<<std::endl;
}

Brain::Brain(Brain &copy){
	
}	

/* Brain &Brain::operator=(const Brain &copy){
	
} */

Brain::~Brain(){
	std::cout<<B<<"Brain Destructor."<<W<<std::endl;
}
