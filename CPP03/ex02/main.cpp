/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/08 18:57:58 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap a("A");
	a.printStatus();
	a.attack("B");
	a.highFivesGuys();
	a.printStatus();
	a.beRepaired(1);
	return 0;
}
