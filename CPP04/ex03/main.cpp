/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:42:11 by victofer          #+#    #+#             */
/*   Updated: 2023/08/17 19:16:28 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Character.hpp"

int main(void)
 {
	AMateria *ice = new Ice();
	ICharacter *c = new Character("a");

	c->equip(ice);
	c->equip(ice);
	c->equip(ice);
	c->equip(ice);
	c->equip(ice);
	
	return 0;
 }
 