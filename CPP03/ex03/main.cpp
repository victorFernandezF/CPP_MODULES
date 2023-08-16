/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/16 12:50:00 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	std::cout<<BM<<" ◉ -- [TEST 1] -- ◉"<<std::endl
	<<BB<<"	 "<<std::endl<<std::endl;
	{
		DiamondTrap dia("pepito");
		dia.whoAmI();
		dia.printStatus();
	}
	return 0;
}
