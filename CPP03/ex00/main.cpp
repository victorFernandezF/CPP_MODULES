/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/07 19:17:22 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

		
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap claptrap("MAQUINITA");

	claptrap.printStatus();
	claptrap.attack("juan");
	claptrap.printStatus();
	claptrap.takeDamage(2);
	claptrap.printStatus();
	claptrap.beRepaired(5);
	claptrap.printStatus();
	claptrap.attack("Pepe");
	//std::cout<<claptrap.getEnergy()<<std::endl;
	return 0;
}
