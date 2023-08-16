/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:34:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/16 13:01:02 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout<<"Brain constructor called"<<std::endl;
}

/* Brain::Brain(Brain &copy){

}	

Brain &Brain::operator=(const Brain &copy){

} */

Brain::~Brain(){
	std::cout<<"Brain Destructor."<<std::endl;
}

