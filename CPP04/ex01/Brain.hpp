/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:33:20 by victofer          #+#    #+#             */
/*   Updated: 2023/08/31 18:34:12 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
#include "colours.h"

class Brain{
	protected:
		std::string _ideas[100];
	
	public:
		Brain();
		Brain(Brain &copy);	
		Brain &operator=(const Brain &copy);	
		virtual ~Brain();
};
#endif