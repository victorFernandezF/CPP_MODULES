/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:33:28 by victofer          #+#    #+#             */
/*   Updated: 2023/08/21 18:58:44 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): _maxSrc(4), _idx(0){
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < this->_maxSrc; i++)
		if (this->_src[i])
			delete this->_src[i];
}

void MateriaSource::learnMateria(AMateria *mat){
	if (this->_idx >= 4)
	{
		delete mat;
		return;
	}
	this->_src[this->_idx] = mat;
	this->_idx = this->_idx + 1;
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < this->_maxSrc; i++)
		if (this->_src[i] && this->_src[i]->getType() == type)
			return (this->_src[i]->clone());
	return (0);
}