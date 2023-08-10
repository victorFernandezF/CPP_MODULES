/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:21:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/10 18:16:24 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	std::cout<<BM<<" ◉ -- [TEST 1] -- ◉"<<std::endl
	<<GR<<"	 "<<std::endl<<std::endl;
	{
		DiamondTrap dia("pepito");
		dia.whoAmI();
		dia.printStatus();
	}
	return 0;
}
