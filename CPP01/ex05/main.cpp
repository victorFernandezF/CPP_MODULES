/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:30:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/23 13:41:32 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void printTestHeaders(int test, std::string testh, int line){
	if (line == 1)
		std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<std::endl<<BM<<"◉ -- [TEST "<<test<<" ] -- ◉"<<std::endl
	<<BB<<testh<<W<<std::endl;
}

int main(void)
{
	printTestHeaders(1, TEST1, 0);
	{
		Harl harl;
		harl.complain("debug");
		harl.complain("info");
		harl.complain("warning");
		harl.complain("error");
		harl.complain("doesntexist");
	}
	printTestHeaders(2, TEST2, 1);
	{
		Harl harl2;

		harl2.complain("error");
		harl2.complain("debug");
		harl2.complain("");
		harl2.complain("warning");
	}
	return 0;
}
