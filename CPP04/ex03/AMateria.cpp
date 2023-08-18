/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:47:52 by victofer          #+#    #+#             */
/*   Updated: 2023/08/18 12:54:25 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"

AMateria::AMateria(){}
AMateria::AMateria(std::string const & type): type(type){}
AMateria::AMateria(AMateria const &copy){
	if (this != &copy)
		*this = copy;
}

AMateria &AMateria::operator=(const AMateria  &copy){
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

AMateria::~AMateria(){}

std::string const & AMateria::getType() const
{
	return(this->type);
}

void AMateria::use(ICharacter& target){
	(void)target;
}