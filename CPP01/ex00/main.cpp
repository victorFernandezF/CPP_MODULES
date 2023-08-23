/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:07:07 by victofer          #+#    #+#             */
/*   Updated: 2023/08/23 13:29:00 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "colours.h"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

void leaks(void)
{
	std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<M<<" \n-- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex00");
}

int main(void)
{
	atexit(leaks);
    std::string stackName;
    std::string heapName;
    std::cout<<std::endl<<Y<<"Insert a name for zombie created on stack>"<<W;
    std::getline(std::cin, stackName);
    std::cout<<Y<<"Insert a name for zombie created on heap>"<<W;
    std::getline(std::cin, heapName);
    std::cout<<std::endl;
    Zombie *zombo = newZombie(heapName);
    zombo->announce();
    randomChump(stackName);
    delete zombo;
    return (0);
}
