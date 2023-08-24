/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:30:24 by victofer          #+#    #+#             */
/*   Updated: 2023/08/24 10:23:41 by victofer         ###   ########.fr       */
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
	std::string tag;
	int			j;
	
	std::cout<<BY<<"Insert the complain tag: "<<W;
	std::getline(std::cin, tag);
	j = -1;
	while (tag[++j])
		tag[j] = (char)std::tolower(tag[j]);
	Harl harl;
	harl.complain(tag);
	std::cout<<std::endl;
	return 0;
}
