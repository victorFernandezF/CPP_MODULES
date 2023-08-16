/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:53:53 by victofer          #+#    #+#             */
/*   Updated: 2023/08/16 18:57:45 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>
# include "colours.h"

class Ice
{
	private:
		std::string _type;
	public:
		Ice();
		~Ice();
		Ice(const Ice &copy);
		Ice & operator=(const Ice &copy);
		void use(ICharacter &character);
};
#endif