/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:08:34 by victofer          #+#    #+#             */
/*   Updated: 2023/08/24 10:07:44 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

void leaks(void)
{
	std::cout<<"\n___________________________________"<<std::endl;
	std::cout<<M<<" \n-- [ LEAKS ] -- "<<W<<std::endl;
	system("leaks -q ex01");
}

int main(void)
{
	atexit(leaks);
	std::string hordeName;
    Zombie *horde;
    int n;
	
    std::cout<<std::endl<<Y<<"Insert a name for the zombies in the horde: "<<W;
    std::getline(std::cin, hordeName);
	n = 10;
    std::cout<<BM<<"\n -- [ TEST 1 ] --" <<W<<std::endl;
    std::cout<<BB<<"  *Creating a Zomby horde "
	<<"of "<<n<<" zombies"<<G<<std::endl;
	
    horde = zombieHorde(n, hordeName);
    for (int i = 0; i < n; i++)
        horde[i].announce();
    std::cout<<BB<<"\n  *We will now delete the Zomby horde."<<W<<std::endl;
    delete [] horde;
    return (0);
}
