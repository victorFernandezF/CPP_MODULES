/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:33:28 by victofer          #+#    #+#             */
/*   Updated: 2023/08/18 13:55:55 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): _maxSrc(4), _idx(0){
}

MateriaSource::~MateriaSource(){}

void MateriaSource::learnMateria(AMateria *mat){
	if (this->_idx == 4)
		this->_idx = 0;
	this->_src[this->_idx] = mat;
	this->_idx = this->_idx + 1;
}

AMateria* MateriaSource::createMateria(std::string const & type){
	AMateria *res;
	for (int i = 0; i < this->_maxSrc; i++)
		std::cout<<"\n test ->\n"<<this->_src[i]->getType()<<std::endl;
		//if (this->_src[i]->getType() == type)
		//	res = this->_src[i];
	return (res);
}