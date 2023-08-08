/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/08 18:45:04 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

		
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a("A");
	ScavTrap b(a);
	a.printStatus();
	a.guardGate();
	a.attack("B");
	a.printStatus();
	b.beRepaired(1);
	return 0;
}
