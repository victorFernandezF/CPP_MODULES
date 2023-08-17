/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:16:31 by victofer          #+#    #+#             */
/*   Updated: 2023/08/17 13:16:49 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>
# include "colours.h"
# include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		std::string _type;
	public:
		Cure();
		Cure(Cure const &copy);
		Cure &operator=(const Cure  &copy);
		~Cure();
		std::string const &getType() const;
		virtual Cure* clone() const;
		//virtual void use(ICharacter& target);
};
# endif