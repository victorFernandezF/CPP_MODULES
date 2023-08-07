/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/07 19:00:04 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

		
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap claptrap;

	claptrap.attack("juan");
	claptrap.takeDamage(2);
	//std::cout<<claptrap.getEnergy()<<std::endl;
	claptrap.beRepaired(5);
	return 0;
}
