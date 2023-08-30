/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:43:03 by victofer          #+#    #+#             */
/*   Updated: 2023/08/17 12:55:56 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>
# include "colours.h"
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
	private:
		std::string _type;
	public:
		Ice();
		Ice(Ice const &copy);
		Ice &operator=(const Ice  &copy);
		~Ice();
		
		std::string const & getType() const;
		
		virtual Ice* clone() const;
		void use(ICharacter& target);
};
# endif