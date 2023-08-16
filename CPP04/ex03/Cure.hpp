/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:53:53 by victofer          #+#    #+#             */
/*   Updated: 2023/08/16 19:04:07 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>
# include "colours.h"

class Cure
{
	private:
		std::string _type;
	public:
		Cure();
		~Cure();
		Cure(const Cure &copy);
		Cure & operator=(const Cure &copy);
		void use(ICharacter &character);
};
#endif