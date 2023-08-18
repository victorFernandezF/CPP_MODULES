/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:31:10 by victofer          #+#    #+#             */
/*   Updated: 2023/08/18 13:50:06 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <iostream>
# include "colours.h"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_src[4];
		int _maxSrc;
		int _idx;
	public:
		MateriaSource();
		~MateriaSource();
		void learnMateria(AMateria *mat);
		AMateria* createMateria(std::string const & type);
};

#endif