/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:33:20 by victofer          #+#    #+#             */
/*   Updated: 2023/08/14 18:01:45 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain{
	protected:
		std::string _ideas[100];
	
	public:
		Brain();
		Brain(Brain &copy);	
		Brain &operator=(const Brain &copy);	
		virtual ~Brain();
/* 		std::string getIdeas();
		void setIdeas(str::string[100] ideas); */
};
#endif